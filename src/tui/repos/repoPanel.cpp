#include "components.hpp"
#include <ftxui/component/component_base.hpp>

using namespace ftxui;

Component RepoPanel(AppState& state) {
    auto loading_component = Loading();
    auto repo_menu = RepoMenu(state);

    return Renderer(repo_menu, [loading_component, repo_menu, &state] {
        if (state.loading) {
            return loading_component->Render() | border;
        }

        if (state.repo_names.empty()) {
            return text("No repositories.") | border | color(Color::Cyan);
        }

        return repo_menu->Render() | border;
    });
}
