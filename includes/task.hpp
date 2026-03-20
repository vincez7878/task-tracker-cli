#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <ctime>

class Task {
    public:
        Task(std::string& description, int identifier);
        void UpdateTask(std::string& new_description); //updates the task description with a new one
        void MarkTask(std::string& mark); //marks a new status e.g in-progress, done
        int GetId() const;
        std::string GetDescription() const;
        std::string GetStatus() const;
        std::string GetTimeCreated() const;
        std::string GetTimeUpdated() const;
    private:
        int identifier_;
        std::string description_;
        std::string status_;
        std::string time_created_;
        std::string time_updated_;
};

#endif