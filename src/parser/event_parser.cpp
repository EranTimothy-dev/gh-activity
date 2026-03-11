#include "event_parser.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<event::Event> parse_events(const std::string& json_str) {
    json j = json::parse(json_str);

    std::vector<event::Event> events;

    for (auto& item : j) {
        event::Event event;
        event.type = item["type"].get<std::string>();
        event.repo = item["repo"]["name"].get<std::string>();

        events.push_back(event);
    }

    return events;
}
