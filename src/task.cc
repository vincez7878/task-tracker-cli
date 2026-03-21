#include "task.hpp"

Task::Task(int identifier, std::string& description) : identifier_(identifier), description_(description), status_("todo") {
    std::time_t curr_time = time(nullptr);
    time_created_ = ctime(&curr_time);
    time_updated_ = ctime(&curr_time);
}

void Task::UpdateTask(std::string& new_description) {
    description_ = new_description;
    std::time_t curr_time = time(nullptr);
    time_updated_ = ctime(&curr_time);
}

void Task::MarkTask(std::string& mark) {
    status_ = mark;
}

std::string Task::TaskOut() {
    std::string task = std::to_string(identifier_) + ": " + description_ + " - " + time_updated_;
    return task;
}

int Task::GetId() const {
    return identifier_;
}

std::string Task::GetDescription() const {
    return description_;
}

std::string Task::GetStatus() const {
    return status_;
}

std::string Task::GetTimeCreated() const {
    return time_created_;
}

std::string Task::GetTimeUpdated() const {
    return time_updated_;
}