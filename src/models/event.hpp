#pragma once
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace event {

    struct Event {
        std::string type;
        std::string repo;
    };

    inline void to_json(json& j, const Event& event) {
        j = json{
            {"type", event.type},
            {"repo", event.repo}
        };
    };

}
