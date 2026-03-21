#include "taskmanager.hpp"



void RouteCommands(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands[1] == "add") {
        AddTask(commands, tasks);
        return;
    }

    if (commands[1] == "update") {
        UpdateTask(commands, tasks);
        return;
    }

    if (commands[1] == "delete") {
        DeleteTask(commands, tasks);
        return;
    }

    if (commands[1] == "mark") {
        MarkTask(commands, tasks);
        return;
    }

    if (commands[1] == "list" && commands.size() == 2) { //list all
        return;
    }

    if (commands[1] == "list" && (commands[2] == "todo" || commands[2] == "in-progress"
        || commands[2] == "done")) {
        return;
    }

    throw std::runtime_error("Invalid command");
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

void UpdateTask(std::vector<std::string>& commands, std::vector<Task>& tasks) { //Something fishy here
    if (commands.size() != 4) {
        throw std::runtime_error("Invalid Command");
    }

    if (tasks.empty()) {
        throw std::runtime_error("No tasks yet!");
    }

    int id_to_update = stoi(commands[2]);
    for (unsigned int i = 0; i < tasks.size(); ++i) {
        if (id_to_update == tasks.at(i).GetId()) {
            tasks.at(i).UpdateTask(commands[3]);
            std::cout << "task updated successfully - ID: " << std::to_string(id_to_update) << '\n';
            return;
        }
    }
    throw std::runtime_error("task ID not found");
}

//expect form: ./bin/exec delete ID
void DeleteTask(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 3) { //Check if command arguments are right
        throw std::runtime_error("Invalid Command");
    }

    if (tasks.empty()) {
        throw std::runtime_error("No tasks yet!");
    }

    int id_to_del = stoi(commands[2]);
    for (unsigned int i = 0; i < tasks.size(); ++i) {
        if (id_to_del == tasks.at(i).GetId()) {
            tasks.erase(tasks.begin() + i);
            std::cout << "task deleted successfully - ID: " << std::to_string(id_to_del) << '\n';
            return;
        }
    }
    throw std::runtime_error("task ID not found");
}

//expect form: ./bin/exec mark 1 in-progress
void MarkTask(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 4) {
        throw std::runtime_error("Invalid Command");
    }

    if (tasks.empty()) {
        throw std::runtime_error("No tasks yet!");
    }

    if (commands[3] != "in-progress" && commands[3] != "done") {
        throw std::runtime_error("Please mark task either in-progress or done");
    }
    int id_to_mark = stoi(commands[2]);
    for (unsigned int i = 0; i < tasks.size(); ++i) {
        if (id_to_mark == tasks.at(i).GetId()) {
            tasks.at(i).MarkTask(commands[3]);
            std::cout << "task marked successfully - ID: " << std::to_string(id_to_mark) << '\n';
            return;
        }
    }
    throw std::runtime_error("task ID not found");
}

void ListTasks(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 2) {
        throw std::runtime_error("Invalid Command");
    }

    if (tasks.empty()) {
        std::cout << "No tasks yet!" << '\n';
    }

    for (unsigned int i = 0; i < tasks.size(); ++i) {
        std::cout << tasks.at(i).TaskOut() << '\n' << '\n';
    }
}

void ListTasksByStatus() {};