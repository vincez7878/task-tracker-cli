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

  std::vector<Task> tasks;
  Task t(static_cast<int>(tasks.size()) + 1, cmd_line_args[2]);
  std::cout << t.TaskOut() << '\n';
  std::string new_description = "Wtf are we doing lol";
  t.UpdateTask(new_description);
  std::cout << t.TaskOut() << '\n';
}
