#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "task.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

void RouteCommands(std::vector<std::string>& commands, std::vector<Task>& tasks);
void AddTask(std::vector<std::string>& commands, std::vector<Task>& tasks);
void UpdateTask(std::vector<std::string>& commands, std::vector<Task>& tasks);
void DeleteTask(std::vector<std::string>& commands, std::vector<Task>& tasks);
void MarkTask(std::vector<std::string>& commands, std::vector<Task>& tasks);
void ListTasks(std::vector<std::string>& commands, std::vector<Task>& tasks);
void ListTasksByStatus(std::vector<std::string>& commands, std::vector<Task>& tasks);

#endif