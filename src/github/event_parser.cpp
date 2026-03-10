#include "../models/event.hpp"
#include <nlohmann/json.hpp>
#include <vector>

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


