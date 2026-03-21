#include "taskmanager.hpp"



void RouteCommands(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands[1] == "add") {
        AddTask(commands, tasks);
        return;
    }

    if (commands[1] == "update") {
        return;
    }

    if (commands[1] == "delete") {
        return;
    }

    if (commands[1] == "mark") {
        return;
    }

    if (commands[1] == "list") {
        return;
    }

    throw std::runtime_error("invalid command");
}

void AddTask(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 3) {
        throw std::runtime_error("Invalid Command");
    }
    std::string descr = commands[2];
    Task curr_task(static_cast<int>(tasks.size()) + 1, descr);
    tasks.push_back(curr_task);
    std::cout << "task added successfully - ID: " << std::to_string(curr_task.GetId()) << '\n';
}