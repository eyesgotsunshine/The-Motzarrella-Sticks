# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -fsanitize=address -g

# Find all .cc and .h files automatically
SRC := $(wildcard *.cc)
OBJ := $(SRC:.cc=.o)
EXEC := a.out  # Change this to your desired executable name

# Default target
all: $(EXEC)

# Link all object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cc file into a .o file
%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets (not actual files)
.PHONY: all clean

