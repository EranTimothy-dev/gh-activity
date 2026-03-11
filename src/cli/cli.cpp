#include "cli.hpp"
#include <CLI/CLI.hpp>
#include <iostream>
#include <string>
#include "../utils/formatter.hpp"
#include "../github/github_api.hpp"
#include "../parser/event_parser.hpp"
#include "../parser/repo_parser.hpp"

int CLIApp::run(int argc, char** argv) {

    CLI::App app{"GitHub Activity CLI"};

    std::string username;
    json j;

    // app.add_option("-u, --username", username, "Get info for username");
    auto userCmd = app.add_subcommand("user", "Get info for a user");
    userCmd->add_option("-u,--username", username, "Username")->required();

    auto eventCmd = app.add_subcommand("events", "Get user events");
    std::string eventsUser;
    eventCmd->add_option("-u, --username", eventsUser, "Username")->required();

    auto tuiCmd = app.add_subcommand("tui", "Launch TUI");
    std::string tuiUser;
    tuiCmd->add_option("-u, --username", tuiUser, "Username")->required();

    auto reposCmd = app.add_subcommand("repos", "Get repositories for user");
    std::string reposUser;
    reposCmd->add_option("-u, --username", reposUser, "Username")->required();

    CLI11_PARSE(app, argc, argv);

    if (app.got_subcommand(userCmd)) {
        std::cout << "Fetching total repositories for user: " << username << std::endl;
        std::string data = github::get_user_info(username);
        std::string formatted = format_response(data);
        std::cout << "Total Repositories: " << formatted << std::endl;
    } else if (app.got_subcommand(eventCmd)) {
        std::cout << "Fetching activity for user: " << username << std::endl;
        std::string data = github::get_user_events(eventsUser);
        std::vector<Event> events = parse_events(data);
        for (const auto& event : events) {
            fprintf(stdout, "Event Type: %s, Repo: %s\n", event.type.c_str(), event.repo.c_str());
        }
        // std::cout << "\n" << std::endl;
        // std::string formatted = format_response(data);
        // fprintf(stdout, "%s\n", data.c_str());
    } else if (app.got_subcommand(reposCmd)) {
        std::cout << "Fetching repositories for user: " << username << std::endl;
        std::string data = github::get_all_repos(reposUser);
        std::vector<repo::Repository> repos = parse_repos(data);
        std::cout << "Total Repositories: " << repos.size() << std::endl;
        for (const auto& repo : repos) {
            // fprintf(stdout, "Repo: %s, Description: %s, Language: %s, Stars: %d, Last Pushed: %s \n", 
            //     repo.name.c_str(), repo.description.c_str(), repo.language.c_str(), repo.stars, repo.pushed_at.c_str());
            j = repo;
            std::cout << j.dump(4) << std::endl;
        }
        // std::string formatted = format_response(data);
        // std::cout << formatted << std::endl;
    } else if (app.got_subcommand(tuiCmd)) {
        std::cout << "Launching TUI for user: " << tuiUser << std::endl;
    } else {
        std::cout << app.help() << std::endl;
    }

    return 0;
}
