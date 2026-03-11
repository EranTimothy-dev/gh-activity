#include "github_api.hpp"
#include "../utils/http.hpp"

namespace github {
    std::string base_url = "https://api.github.com";
    std::string get_user_events(const std::string& username) {
        std::string url = base_url + "/users/" + username + "/events";
        return http::get(url);
    }

    std::string get_user_info(const std::string& username) {
        std::string url = base_url + "/users/" + username;
        return http::get(url);
    }

    std::string get_all_repos(const std::string& username) {
        std::string url = base_url + "/users/" + username + "/repos";
        return http::get(url);
    }

    std::string get_all_orgs(const std::string& username) {
        std::string url = base_url + "/users/" + username + "/orgs";
        return http::get(url);
    }
}
