CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
LDFLAGS = -lsqlite3

SOURCE = $(wildcard src/*.cpp)
OBJ = $(SOURCE:src/%.cpp=bin/%.o)
TARGET = ./build/employee_app

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

bin/%.o: src/%.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf bin/ $(TARGET)

run:
	./$(TARGET)
