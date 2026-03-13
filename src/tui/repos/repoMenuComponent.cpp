#include "components.hpp"
#include "../../models/appState.hpp"
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Component RepoMenu(AppState& state) {
    // create a menu component
    auto menu = Menu(&state.repo_names, &state.selected_repo);

    // render the menu component with a title and border
    return Renderer(menu, [menu, &state] {
        return vbox({
            text("Repositories of user:") | color(Color::Green) | bold,
            text(state.username),
            separator(),
            menu->Render() | border,
        }) | border | color(Color::Cyan);
    });
}
