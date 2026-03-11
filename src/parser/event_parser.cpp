// #include "../models/event.hpp"
#include "event_parser.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<Event> parse_events(const std::string& json_str) {
        json j = json::parse(json_str);

        std::vector<Event> events;

        for (auto& item : j) {
            Event event;
            event.type = item["type"].get<std::string>();
            event.repo = item["repo"]["name"].get<std::string>();

            events.push_back(event);
        }

        return events;
}

std::string format_response(const std::string& json_str) {
    json j = json::parse(json_str);
    std::string formatted = j.dump(4);

    return formatted;
}
