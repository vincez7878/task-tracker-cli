CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -Werror -O0 -gdwarf-4

exec: bin/exec

tests: bin/tests

bin/exec: ./src/driver.cc ./src/task.cc ./includes/task.hpp ./src/taskmanager.cc ./includes/taskmanager.hpp
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/task.cc ./src/taskmanager.cc -o $@

bin/tests: ./tests/tests.cc ./src/task.cc ./includes/task.hpp ./src/taskmanager.cc ./includes/taskmanager.hpp
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/task.cc ./src/taskmanager.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean


clean:
	rm -rf bin/*