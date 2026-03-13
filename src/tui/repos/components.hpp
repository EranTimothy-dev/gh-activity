#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "../../models/appState.hpp"

ftxui::Component Header();
ftxui::Component Loading();
ftxui::Component RepoMenu(AppState& state);
ftxui::Component RepoPanel(AppState& state);
ftxui::Component SearchBar(AppState& state, ftxui::ScreenInteractive& screen);
