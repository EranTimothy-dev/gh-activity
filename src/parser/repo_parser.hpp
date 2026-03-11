#pragma once
#include <vector>
#include "../models/repo.hpp"

std::vector<repo::Repository> parse_repos(const std::string& json_strl);
