#include "ui.hpp"
#include <ftxui/screen/color.hpp>
#include <string>
// #include "../parser/repo_parser.hpp"
// #include "../github/github_api.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <vector>

using namespace ftxui;

int launch_tui() {
    std::string username;
    std::vector<std::string> history;

    InputOption name_style = InputOption::Default();
    name_style.placeholder = "Enter GitHub username...";

    name_style.on_enter = [&]() {
        if (!username.empty()) {
            history.push_back(username);
            username = "";
        }
    };

    auto username_input = Input(&username, name_style);

    auto inputs = Container::Vertical({
        username_input
    });

    auto renderer = Renderer(inputs, [&] {
        auto header = vbox({
            text("GitHub Dashboard") | color(Color::Blue) | bold,
            separator()
        });

        auto name_row = hbox({
            text("Username: ") | color(Color::Green),
            username_input->Render() | flex,
        });

        //render history
        std::vector<Element> history_elements;
        for (const auto& name: history) {
            history_elements.push_back(text(name));
        }
        auto history_panel = vbox(history_elements) | border | color(Color::Yellow);

        auto input_panel = vbox({
            name_row,
        }) | border;

        return vbox({
            header,
            input_panel,
            text("History:"),
            history_panel,
        });
    });

    ScreenInteractive::TerminalOutput().Loop(renderer);
    return 0;
}
