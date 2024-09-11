# Compiler and flags
CXX = clang++
WASM = em++
CXXFLAGS = -Wall -std=c++17
DEBUG_FLAGS = -g -fsanitize=address  # Debug-specific flags
PROD_FLAGS = -O2                    # Production-specific flags
WASM_FLAGS = -O3 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1  -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' --std=c++17 --bind 

# Find all .cpp files recursively in the current directory and subdirectories
SOURCES = $(shell find . -name "*.cpp")

# Exclude chessailib.cpp from prod and debug builds
EXCLUDED_CPP = ./chessailib.cpp
SOURCES_EXCLUDE = $(filter-out $(EXCLUDED_CPP), $(SOURCES))

# Directory to store object files
BUILD_DIR = build

# Generate object files for each source file in the build directory
DEBUG_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/debug/%.o, $(SOURCES_EXCLUDE))
PROD_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/prod/%.o, $(SOURCES_EXCLUDE))
WASM_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/wasm/%.o, $(SOURCES))

# Target executable names
DEBUG_TARGET = ChessAI_debug
PROD_TARGET = ChessAI
WASM_TARGET = ChessAI.html 
WASM_TARGET_REACT = ../public/ai.js

# Default rule to build the production target
all: prod

# Rule to build the production target
prod: $(PROD_TARGET)

# Rule to build the debug target
debug: $(DEBUG_TARGET)

# Rule to build the WebAssembly target
wasm: $(WASM_TARGET)
wasm_react: $(WASM_TARGET_REACT)

# Rule to build the production executable from object files
$(PROD_TARGET): $(PROD_OBJECTS)
	@echo "Linking $@ with $^"
	$(CXX) $(CXXFLAGS) $(PROD_FLAGS) -o $@ $(PROD_OBJECTS)

# Rule to build the debug executable from object files
$(DEBUG_TARGET): $(DEBUG_OBJECTS)
	@echo "Linking $@ with $^"
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -o $@ $(DEBUG_OBJECTS)

# Rule to build the WebAssembly output
$(WASM_TARGET): $(WASM_OBJECTS)
	@echo "Linking (WASM) $@ with $^"
	$(WASM) $(WASM_FLAGS) -o $@ $(WASM_OBJECTS)

# Rule to build the WebAssembly output
$(WASM_TARGET_REACT): $(WASM_OBJECTS)
	@echo "Linking (WASM) $@ with $^"
	$(WASM) $(WASM_FLAGS) -o $@ $(WASM_OBJECTS)

# Rule to compile each source file into an object file for production
$(BUILD_DIR)/prod/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling (prod) $<"
	$(CXX) $(CXXFLAGS) $(PROD_FLAGS) -c $< -o $@

# Rule to compile each source file into an object file for debugging
$(BUILD_DIR)/debug/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling (debug) $<"
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Rule to compile each source file into an object file for WebAssembly
$(BUILD_DIR)/wasm/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling (WASM) $<"
	$(WASM) $(WASM_FLAGS) -c $< -o $@

# Clean up build files
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR) $(PROD_TARGET) $(DEBUG_TARGET) $(WASM_TARGET) $(WASM_TARGET_REACT)
