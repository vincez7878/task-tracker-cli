#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <ctime>

class Task {
    public:
        Task(int identifier, const std::string& description, const std::string& status, 
        const std::string& time_created, const std::string& time_updated);
        Task(int identifier, const std::string& description);
        void UpdateTask(const std::string& new_description); //updates the task description with a new one
        void MarkTask(const std::string& mark); //marks a new status e.g in-progress, done
        std::string TaskOut(); //returns a string describing the task in format ID: Description - time updated
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