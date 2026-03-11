#pragma once
#include <cstddef>
#include <string>

static std::size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer);

namespace http {
    std::string get(const std::string& url);
    std::string post(const std::string& url);
}

