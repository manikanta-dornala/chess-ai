# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -std=c++17 -g -fsanitize=address

# Find all .cpp files recursively in the current directory and subdirectories
SOURCES = $(shell find . -name "*.cpp")

# Generate object files for each source file
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable name
TARGET = ChessAI

# Default rule to build the target
all: clean $(TARGET)

# Rule to build the target executable from object files
$(TARGET): $(OBJECTS)
	@echo "Linking $@ with $^"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile each source file into an object file
%.o: %.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(TARGET)
