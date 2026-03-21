#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "task.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

void RouteCommands(std::vector<std::string>& commands, std::vector<Task>& tasks);

void AddTask(std::vector<std::string>& commands, std::vector<Task>& tasks);

void UpdateTask();

void DeleteTask();

void MarkTask();

void ListTasks();

#endif