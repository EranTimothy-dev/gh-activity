#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <mutex>
#include <nlohmann/json.hpp>
#include "ui.hpp"
#include <ftxui/screen/color.hpp>
#include <string>
#include "../parser/repo_parser.hpp"
#include "../github/github_api.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "ftxui/component/animation.hpp"       // for BackOut, Duration
#include <vector>
#include <chrono>  // for operator""ms, literals
#include <thread>
#include <atomic>
#include <fstream>


using namespace ftxui;
using json = nlohmann::json;
using namespace std::chrono_literals;

int launch_tui() {
    std::string username;
    std::vector<repo::Repository> repos;
    std::vector<std::string> repo_names;
    int tab_selected = 0;
    std::atomic<bool> loading = false;
    std::mutex repo_mutex;

    auto screen = ScreenInteractive::TerminalOutput();

    // create input component with placeholder and on_enter callback to fetch repos
    InputOption name_style = InputOption::Default();
    name_style.placeholder = "Enter GitHub username...";

    name_style.on_enter = [&]() {
        if (!username.empty()) {
            std::string captured = username;
            username = "";
            loading = true;
            screen.PostEvent(Event::Custom); // trigger a re-render after fetching repos 

            std::thread([&, captured](){
                std::string data = github::get_all_repos(captured);
                std::ofstream log("debug.log");
                log << "data length: " << data.size() << std::endl;
                log << "data: " << data.substr(0, 200) << std::endl;
                {
                    std::lock_guard<std::mutex> lock(repo_mutex);
                    if (!data.empty()) {
                        repo_names.clear(); // clear previous repo names
                        repos = parse_repos(data);
                        for (const auto& repo : repos) {
                            repo_names.push_back(repo.name);
                            log << "repo: " << repo.name << std::endl;
                        }
                    }


                }

                loading = false;
                screen.PostEvent(Event::Custom);
            }).detach();
        }
    };


    auto username_input = Input(&username, name_style);

    MenuOption option = MenuOption::VerticalAnimated();
    option.underline.follower_delay = 250ms;
    auto menu = Menu(&repo_names, &tab_selected, option);

    auto container = Container::Vertical({
        username_input,
        menu,
    });


    auto renderer = Renderer(container, [&] {
        auto header = vbox({
            text("GitHub Dashboard") | color(Color::Blue) | bold,
            separator()
        });

        auto name_row = hbox({
            text("Username: ") | color(Color::Green),
            username_input->Render() | flex,
        });

        auto input_panel = vbox({
            name_row,
        }) | border;

        Element repo_panel;
        if (loading) {
            repo_panel = text("Fetching repositories...") | color(Color::Yellow) | borderEmpty;
        } else if (repo_names.empty()) {
            repo_panel = text("No repositories found. Please enter a valid username.") | color(Color::Red) | borderEmpty;
        } else {
            std::lock_guard<std::mutex> lock(repo_mutex);
            repo_panel = menu->Render() | border | color(Color::Cyan);
        }

        return vbox({
            header,
            input_panel,
            text("Loading: " + std::string(loading ? "yes" : "no")),
            text("Repo count: " + std::to_string(repo_names.size())),
            repo_panel,
        });
    });


    screen.Loop(renderer);
    return 0;
}

int dashboard() {
    auto screen = ScreenInteractive::TerminalOutput();
    Component app = App(screen);

    app |= CatchEvent([&] (Event event) {
        // quit on 'alt+c'
        if (event == Event::CtrlC) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    screen.Loop(app);
    return 0;
}

