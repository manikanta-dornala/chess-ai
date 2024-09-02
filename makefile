# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Find all .cpp files recursively in the current directory and subdirectories
SOURCES = $(shell find . -name "*.cpp")

# Generate object files for each source file
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable name
TARGET = ChessAI

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable from object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)
