#pragma once
#include <string>

namespace github {
    std::string get_user_events(const std::string& username);
    std::string get_user_info(const std::string& username);
    std::string get_all_repos(const std::string& username);
    std::string get_all_orgs(const std::string& username);
}
