CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -Werror -O0 -gdwarf-4

tasky: bin/tasky

tests: bin/tests

bin/tasky: ./src/driver.cc ./src/task.cc ./includes/task.hpp ./src/taskmanager.cc ./includes/taskmanager.hpp ./src/readwrite.cc ./includes/readwrite.hpp ./src/taskjson.cc ./includes/taskjson.hpp
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/task.cc ./src/taskmanager.cc ./src/readwrite.cc ./src/taskjson.cc -o $@

bin/tests: ./tests/tests.cc ./src/task.cc ./includes/task.hpp ./src/taskmanager.cc ./includes/taskmanager.hpp ./src/readwrite.cc ./includes/readwrite.hpp ./src/taskjson.cc ./includes/taskjson.hpp
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/task.cc ./src/taskmanager.cc ./src/readwrite.cc ./src/taskjson.cc -o $@

.DEFAULT_GOAL := tasky
.PHONY: tasky tests clean


clean:
	rm -rf bin/*