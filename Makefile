# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -mwindows
LIBS = -static -lraylib -lwinmm -lgdi32 -lopengl32 -lm

# Directories
SRC_DIR = source
INCLUDE_DIR = headers
MAIN_DIR = main
OBJ_DIR = obj
BIN_DIR = bin

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
MAIN_FILES = $(wildcard $(MAIN_DIR)/*.cpp)
ALL_CPP = $(SRC_FILES) $(MAIN_FILES)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(ALL_CPP)))

# Target binary
TARGET = $(BIN_DIR)/PoisonCandy.exe

# Default target
all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

# Create bin and obj directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Link object files into final binary
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LIBS)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the game
run: all
	./$(TARGET)

.PHONY: all clean run
