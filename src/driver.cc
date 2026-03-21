#include "task.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

int main(int argc, char* argv[]) {
  std::vector<std::string> cmd_line_args;
  for (int i = 0; i < argc; ++i) {
    std::string curr_string = argv[i];
    cmd_line_args.push_back(curr_string);
  }

  std::vector<Task> tasks; //vector with all current tasks opened
}
