#ifndef READWRITE_HPP
#define READWRITE_HPP

#include <fstream>
#include <stdexcept>
#include "nlohmann/json.hpp"

nlohmann::json ReadFile(const std::string& filename);
void WriteFile(const nlohmann::json& j, const std::string& filename);

#endif