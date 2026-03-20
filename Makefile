CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -Werror -O0 -gdwarf-4

exec: bin/exec

tests: bin/tests

bin/exec: ./src/driver.cc ./src/task.cc
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/task.cc -o $@

bin/tests: ./tests/tests.cc ./src/task.cc
	$(CXX) $(CXX_FLAGS) ./src/tests.cc ./src/task.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/*