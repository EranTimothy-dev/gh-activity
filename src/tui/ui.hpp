#pragma once
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>

int launch_tui();
ftxui::Component App(ftxui::ScreenInteractive& screen);
int dashboard();
