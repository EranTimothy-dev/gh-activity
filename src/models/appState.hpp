#pragma once
#include <string>
#include <vector>
#include <atomic>
#include <mutex>

struct AppState {
    std::string username;
    std::vector<std::string> repo_names;
    int selected_repo = 0;
    std::atomic<bool> loading = false;
    std::mutex repo_mutex;
    bool error = false;
};
