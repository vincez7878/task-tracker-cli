#include "task.hpp"
#include "taskmanager.hpp"
#include "taskjson.hpp"
#include "readwrite.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

int main(int argc, char* argv[]) {

  try {
    std::vector<std::string> cmd_line_args;
    std::vector<Task> tasks;
    const std::string kJsonFilename = "./output/taskfile.json"; //fill in with expected file name
    nlohmann::json j;
    j = ReadFile(kJsonFilename);
    FromJson(j, tasks);
  
    for (int i = 0; i < argc; ++i) {
      std::string curr_string = argv[i];
      cmd_line_args.push_back(curr_string);
    }

    if (cmd_line_args.size() < 2) {
      throw std::runtime_error("not enough commands :(");
    }

    if (cmd_line_args.size() > 4) {
      throw std::runtime_error("too many commands :(");
    }
    RouteCommands(cmd_line_args, tasks);
    //empty the json object first
    j = nlohmann::json::array();
    ToJson(j, tasks);
    WriteFile(j, kJsonFilename);
  }
  catch(std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
