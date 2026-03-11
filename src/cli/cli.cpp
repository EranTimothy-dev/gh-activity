#include "cli.hpp"
#include <CLI/CLI.hpp>
#include <iostream>
#include <string>
#include "../github/github_api.hpp"
#include "../parser/event_parser.hpp"

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
        std::string data = github::get_user_events(username);
        std::vector<Event> events = parse_events(data);
        for (const auto& event : events) {
            fprintf(stdout, "Event Type: %s, Repo: %s\n", event.type.c_str(), event.repo.c_str());
        }
        std::cout << "\n" << std::endl;
        std::string formatted = format_response(data);
        fprintf(stdout, "%s\n", data.c_str());
    }

    if (*tuiCmd) {
        std::cout << "Launching TUI for user: " << username << std::endl;
    }

    return 0;
}
