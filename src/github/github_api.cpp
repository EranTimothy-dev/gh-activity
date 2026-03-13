#include "github_api.hpp"
#include "../utils/http.hpp"
#include <cctype>
#include <string_view>

static std::string_view sanitize_username(std::string_view username) {
    while (!username.empty() && std::isspace(static_cast<unsigned char>(username.front()))) username.remove_prefix(1);
    while (!username.empty() && std::isspace(static_cast<unsigned char>(username.back()))) username.remove_suffix(1);
    return username;
}

static bool is_valid_username(const std::string_view& username) {
    if (username.empty() || username.size() > 39) return false;
    if (username.front() == '-' || username.back() == '-') return false;

    char prev = '\0';
    for (unsigned char c : username) {
        // fprintf(stdout, "Checking char: %c\n", c);
        bool ok = std::isalnum(c) || c == '-';
        if (!ok) return false;
        if (c == '-' && prev == '-') return false;
        prev = static_cast<char>(c);
    }
    // fprintf(stdout, "Sanitized username: %.*s\n", static_cast<int>(username.size()), username.data());
    return true;
}

namespace github {
    std::string base_url = "https://api.github.com";
    std::string get_user_events(const std::string& username) {
        std::string_view sanitized = sanitize_username(username);
        bool valid = is_valid_username(sanitized);
        if (!valid) {
            fprintf(stderr, "Invalid username: %s\n", username.c_str());
            return "";
        }
        std::string url = base_url + "/users/" + std::string(sanitized) + "/events";
        return http::get(url);
    }

    std::string get_user_info(const std::string& username) {
        std::string_view sanitized = sanitize_username(username);
        bool valid = is_valid_username(sanitized);
        if (!valid) {
            fprintf(stderr, "Invalid username: %s\n", username.c_str());
            return "";
        }
        std::string url = base_url + "/users/" + std::string(sanitized);
        return http::get(url);
    }

    std::string get_all_repos(const std::string& username) {
        std::string_view sanitized = sanitize_username(username);
        bool valid = is_valid_username(sanitized);
        if (!valid) {
            fprintf(stderr, "Invalid username: %s\n", username.c_str());
            return "";
        }
        std::string url = base_url + "/users/" + std::string(sanitized) + "/repos";
        return http::get(url);
    }

    std::string get_all_orgs(const std::string& username) {
        std::string_view sanitized = sanitize_username(username);
        bool valid = is_valid_username(sanitized);
        if (!valid) {
            fprintf(stderr, "Invalid username: %s\n", username.c_str());
            return "";
        }
        std::string url = base_url + "/users/" + std::string(sanitized) + "/orgs";
        return http::get(url);
    }
}
