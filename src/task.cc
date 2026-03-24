#include "task.hpp"

Task::Task(int identifier, const std::string& description, const std::string& status, 
    const std::string& time_created, const std::string& time_updated) : identifier_(identifier), 
    description_(description), status_(status), time_created_(time_created), 
    time_updated_(time_updated) {};

Task::Task(int identifier, const std::string& description) : identifier_(identifier), description_(description), status_("todo") {
    std::time_t curr_time = time(nullptr);
    time_created_ = ctime(&curr_time);
    time_updated_ = ctime(&curr_time);
}

void Task::UpdateTask(const std::string& new_description) {
    description_ = new_description;
    std::time_t curr_time = time(nullptr);
    time_updated_ = ctime(&curr_time);
}

void Task::MarkTask(const std::string& mark) {
    status_ = mark;
}

std::string Task::TaskOut() {
    std::string task = std::to_string(identifier_) + ": " + description_ + " <" 
    + status_ + "> " + time_updated_;
    if (task.back() == '\n') {
        task.pop_back();
    }
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