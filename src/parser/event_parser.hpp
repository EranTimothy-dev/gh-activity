#pragma once
#include <vector>
#include "../models/event.hpp"

std::vector<Event> parse_events(const std::string& json_str);
std::string format_response(const std::string& json_str);


 
