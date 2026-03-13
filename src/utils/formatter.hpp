#pragma once
#include <string>
#include <string_view>

std::string format_response(const std::string& json_str);
static bool sanitize_username(const std::string_view username);
static bool is_valid_username(const std::string_view username);
