#include "cli.hpp"
#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

int CLIApp::run(int argc, char** argv) {

    CLI::App app{"GitHub Activity CLI"};

    std::string username;

    auto userCmd = app.add_subcommand("user", "Get user activity");
    userCmd->add_option("-u, --username", username, "Github username")->required();

    auto tuiCmd = app.add_subcommand("tui", "Launch TUI");
    tuiCmd->add_option("-u, --username", username)->required();

    CLI11_PARSE(app, argc, argv);

    if (*userCmd) {
        std::cout << "Fetching activity for user: " << username << std::endl;
    }

    if (*tuiCmd) {
        std::cout << "Launching TUI for user: " << username << std::endl;
    }

    return 0;
}
