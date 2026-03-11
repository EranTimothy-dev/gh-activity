#include "repo_parser.hpp"
#include "nlohmann/json_fwd.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<repo::Repository> parse_repos(const std::string& json_str) {
    json j = json::parse(json_str);

    std::vector<repo::Repository> repos;

    for (auto& item : j) {
        repo::Repository repo;
        repo.name = item["name"].get<std::string>(); 
        repo.description = item["description"].is_null() ? "" : item["description"].get<std::string>();
        repo.language = item["language"].is_null() ? "" : item["language"].get<std::string>();
        repo.pushed_at = item["pushed_at"].get<std::string>();
        repo.is_private = item["private"].get<bool>();
        repo.stars = item["stargazers_count"].get<int>();
        repo.forks = item["forks_count"].get<int>();
        repo.open_issues = item["open_issues_count"].get<int>();

        repos.push_back(repo);
    }

    return repos;
}



