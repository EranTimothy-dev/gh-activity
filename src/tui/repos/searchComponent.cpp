#include "components.hpp"
#include "../../models/appState.hpp"
#include "../../models/repo.hpp"
#include "../../github/github_api.hpp"
#include "../../parser/repo_parser.hpp"
#include <typeinfo>

using namespace ftxui;

Component SearchBar(AppState& state, ScreenInteractive& screen) {
    InputOption option = InputOption::Default();
    option.placeholder = "Enter GitHub username...";

    option.on_enter = [&]() {

        std::string captured = state.username;

        if (state.username.empty()) {
            return;
        }

        if (typeid(state.username) == typeid(std::string)) {
            captured = state.username;
        } 

        state.username.clear();

        state.loading = true;
        screen.PostEvent(Event::Custom);

        std::thread([&, captured](){
            std::string data = github::get_all_repos(captured);
            std::vector<repo::Repository> repos = parse_repos(data);
            {
                // lock the mutex while updating shared state
                std::lock_guard<std::mutex> lock(state.repo_mutex);

                state.repo_names.clear();

                for (const auto& repo : repos) {
                    state.repo_names.push_back(repo.name);
                }
            };

            state.loading = false;
            screen.PostEvent(Event::Custom);

        }).detach();
    };

    auto input = Input(&state.username, option);

    return Renderer(input, [=] {
        return vbox({
            text("Username: ") | color(Color::Green) | bold,
            input->Render()
        }) | border;
    });
}
