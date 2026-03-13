#include "repos/components.hpp"
#include "../models/appState.hpp"
#include <ftxui/component/screen_interactive.hpp>
#include "ui.hpp"

using namespace ftxui;

Component App(ScreenInteractive& screen) {
    static AppState state;

    auto header = Header();
    auto search_bar = SearchBar(state, screen);
    auto repo_panel = RepoPanel(state);

    auto container = Container::Vertical({
        search_bar,
        repo_panel,
    });

    auto layout = Renderer(container, [=] {
        return vbox({
            header->Render(),
            container->Render(),
            // search_bar->Render(),
            // repo_panel->Render(),
        });
    });

    return layout;
}
