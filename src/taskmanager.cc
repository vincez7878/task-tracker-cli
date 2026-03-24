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

    if (commands[1] == "list") {
        if (commands.size() == 2) {
             ListTasks(commands, tasks);
            return;
        }
        
        if (commands.size() == 3 && (commands[2] == "todo" || commands[2] == "in-progress" //something up here
        || commands[2] == "done")) {
            ListTasksByStatus(commands, tasks);
            return;
        }
    }
    throw std::runtime_error("Invalid command");
}

//expect form: ./bin/exec add "task description"
void AddTask(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 3) {
        throw std::runtime_error("Invalid Command");
    }
    std::string descr = commands[2];
    Task curr_task(MakeId(tasks), descr);
    tasks.push_back(curr_task);
    std::cout << "task added successfully - ID: " << std::to_string(curr_task.GetId()) << '\n';
}

//expect form: ./bin/exec update 1 "update message"
void UpdateTask(std::vector<std::string>& commands, std::vector<Task>& tasks) {
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

//expect form: ./bin/exec list
void ListTasks(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 2) {
        throw std::runtime_error("Invalid Command");
    }

    if (tasks.empty()) {
        std::cout << "No tasks yet!" << '\n';
        return;
    }

    for (unsigned int i = 0; i < tasks.size(); ++i) {
        std::cout << tasks.at(i).TaskOut() << '\n' << '\n';
    }
}

//expect form: ./bin/exec list todo
void ListTasksByStatus(std::vector<std::string>& commands, std::vector<Task>& tasks) {
    if (commands.size() != 3) {
        throw std::runtime_error("Invalid Command");
    }

    if (tasks.empty()) {
        std::cout << "No tasks yet!" << '\n';
        return;
    }

    if (commands[2] == "todo") {
        for (unsigned int i = 0; i < tasks.size(); ++i) {
            if (tasks.at(i).GetStatus() == "todo") {
                std::cout << tasks.at(i).TaskOut() << '\n' << '\n';
            }
        }
    }

    if (commands[2] == "in-progress") {
        for (unsigned int i = 0; i < tasks.size(); ++i) {
            if (tasks.at(i).GetStatus() == "in-progress") {
                std::cout << tasks.at(i).TaskOut() << '\n' << '\n';
            }
        }
    }

    if (commands[2] == "done") {
        for (unsigned int i = 0; i < tasks.size(); ++i) {
            if (tasks.at(i).GetStatus() == "done") {
                std::cout << tasks.at(i).TaskOut() << '\n' << '\n';
            }
        }
    }
}

int MakeId(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        return 1;
    }

    int curr_max_id = tasks.at(0).GetId();
    for (unsigned int i = 0; i < tasks.size(); ++i) {
        if (tasks.at(i).GetId() > curr_max_id) {
            curr_max_id = tasks.at(i).GetId();
        }
    }

    return curr_max_id + 1;
}