CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
LDFLAGS = -lsqlite3
TEST_LDFLAGS = -lgtest -lgtest_main -lpthread -lsqlite3

SOURCE = $(wildcard src/*.cpp)
OBJ = $(SOURCE:src/%.cpp=bin/%.o)
APP = ./build/employee_app

TEST_SOURCE = $(wildcard test/*.cpp)
TEST_OBJ = $(filter-out bin/main.o, $(OBJ)) $(TEST_SOURCE:test/%.cpp=bin/test_%.o)
TEST_APP = ./build/database_tests

all: $(APP)

test: $(TEST_APP)
	./$(TEST_APP)
	
$(APP): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(APP) $(OBJ) $(LDFLAGS)

$(TEST_APP): $(TEST_OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(TEST_APP) $(TEST_OBJ) $(TEST_LDFLAGS)

bin/%.o: src/%.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/test_%.o: test/%.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf bin/ $(APP)

run:
	./$(APP)

.PHONY: all test clean run
