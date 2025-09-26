CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -O0 -gdwarf-4

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/datetime.hpp ./includes/helper.hpp ./includes/solution.hpp ./src/solution.cc ./src/helper.cc 
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/solution.cc ./src/helper.cc -o $@

bin/tests: ./tests/tests.cc ./includes/datetime.hpp ./includes/helper.hpp ./includes/solution.hpp  ./src/solution.cc ./src/helper.cc
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/solution.cc ./src/helper.cc -o $@



.DEFAULT_GOAL := exec
.PHONY: exec tests

clean:
	rm -rf bin/*