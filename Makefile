
CXXFLAGS = -std=c++17 -O2 -Wall
CXX = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(OBJ) $(TARGET)
