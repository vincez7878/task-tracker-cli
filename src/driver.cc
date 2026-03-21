#include "task.hpp"
#include "taskmanager.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

int main(int argc, char* argv[]) {
  std::vector<Task> tasks; //read from json file into here
  std::vector<std::string> cmd_line_args; //Vector storing user input commands

  try {
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
    //update json file here
  }

  catch(std::exception& e) {
    std::cout << e.what() << '\n';
    return 1;
  }
}
