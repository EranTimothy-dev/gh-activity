#include "formatter.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string format_response(const std::string& json_str) {
    json j = json::parse(json_str);
    std::string formatted = j.dump(4);

    return formatted;
}
