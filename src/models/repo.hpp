#pragma once
#include "nlohmann/json_fwd.hpp"
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace repo {

    struct Repository {
        std::string name;
        std::string description;
        std::string language;
        std::string pushed_at;
        bool is_private;
        int stars;
        int forks;
        int open_issues;
    };

    // inline avoids multiple definition errors when including this header in multiple files
    inline void to_json(json& j, const Repository& repo) {
        j = json{
            {"name", repo.name},
            {"description", repo.description},
            {"language", repo.language},
            {"pushed_at", repo.pushed_at},
            {"private", repo.is_private},
            {"stargazers_count", repo.stars},
            {"forks_count", repo.forks},
            {"open_issues_count", repo.open_issues}
        };
    }
}
