#include "taskjson.hpp"

using json = nlohmann::json;

void ToJson(json& j, const std::vector<Task>& tasks) {
    //loop through tasks and append each task to a json array (MAKE SURE JSON J IS EMPTY TO BEGIN)
    for (unsigned int i = 0; i < tasks.size(); ++i) {
        j.push_back({{"ID", tasks.at(i).GetId()}, {"Description", tasks.at(i).GetDescription()}, 
        {"Status", tasks.at(i).GetStatus()}, {"Created At", tasks.at(i).GetTimeCreated()}, 
        {"Updated At", tasks.at(i).GetTimeUpdated()}});
    }
}

void FromJson(const json& j, std::vector<Task>& tasks) {
    //parse the json file and push back each member to tasks
    for (const auto& task : j) {
        Task curr_task(task["ID"], task["Description"], 
        task["Status"], task["Created At"], task["Updated At"]);
        tasks.push_back(curr_task);
    }
}