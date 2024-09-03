# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -std=c++17 -g -fsanitize=address

# Find all .cpp files recursively in the current directory and subdirectories
SOURCES = $(shell find . -name "*.cpp")

# Directory to store object files
BUILD_DIR = build

# Generate object files for each source file in the build directory
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Target executable name
TARGET = ChessAI

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable from object files
$(TARGET): $(OBJECTS)
	@echo "Linking $@ with $^"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Rule to compile each source file into an object file
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR) $(TARGET)
