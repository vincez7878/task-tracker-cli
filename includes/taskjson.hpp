#ifndef TASKJSON_HPP
#define TASKJSON_HPP

#include "task.hpp"
#include "taskmanager.hpp"
#include "nlohmann/json.hpp"

void ToJson(nlohmann::json& j, const std::vector<Task>& tasks);
void FromJson(const nlohmann::json& j, std::vector<Task>& tasks);

#endif