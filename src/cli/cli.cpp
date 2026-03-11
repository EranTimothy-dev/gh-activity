#include "cli.hpp"
#include <CLI/CLI.hpp>
#include <iostream>
#include <string>
#include "../github/github_api.hpp"
#include "../parser/event_parser.hpp"

int CLIApp::run(int argc, char** argv) {

    CLI::App app{"GitHub Activity CLI"};

    std::string username;
    // bool getRepos = false;
    // bool getOrgs = false;

    auto userCmd = app.add_option("-u, --username", username, "Get info for username");

    auto eventCmd = app.add_subcommand("events", "Get user events");
    eventCmd->add_option("-u, --username", username)->required();

    auto tuiCmd = app.add_subcommand("tui", "Launch TUI");
    tuiCmd->add_option("-u, --username", username)->required();

    // app.add_flag("-r, --repos", getRepos, "Get repositories for username");
    // app.add_flag("-o, --orgs", getOrgs, "Get organizations for username");
    auto reposCmd = app.add_subcommand("repos", "Get repositories for user");
    reposCmd->add_option("-u, --username", username)->required();

    CLI11_PARSE(app, argc, argv);

    if (*userCmd) {
        std::cout << "Fetching total repositories for user: " << username << std::endl;
        std::string data = github::get_user_info(username);
        std::string formatted = format_response(data);
        std::cout << "Total Repositories: " << formatted << std::endl;
    }

    if (*eventCmd) {
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

    if (*reposCmd) {
        std::cout << "Fetching repositories for user: " << username << std::endl;
        std::string data = github::get_all_repos(username);
        std::string formatted = format_response(data);
        std::cout << formatted << std::endl;
    }

    if (*tuiCmd) {
        std::cout << "Launching TUI for user: " << username << std::endl;
    }

    return 0;
}
