#a.out: particleSys.o particleGraphics.o ParticleClass.o cell.o main.o
#	g++ -g -pthread -lgtest -fsanitize=address -std=c++23 particleSys.o particleGraphics.o ParticleClass.o cell.o main.o

#main.o: main.cc particleSys.h
#	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest particleSys.h

#particleSys.o: particleSys.h cell.h 
#	g++ -g -c -lgtest -fsanitize=address -std=c++23 -fPIC particleSys.h

#particleGraphics.o: particleGraphis.h cell.h ParticleClass.h
#	g++ -g -c -fsanitize=address -std=c++23 -fPIC -lgtest particleGraphics.h

#cell.o: cell.h ParticleClass.h
#	g++ -g -c -lgtest -fsanitize=address -std=c++23 -fPIC cell.h

#ParticleClass.o: ParticleClass.h
#	g++ -g -c  -lgtest -fsanitize=address -std=c++23 -fPIC ParticleClass.h

#clean:
#	rm -f *.o a.out core



# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Source Files
SRC = main.cc read.cc
TEST_SRC = main.cc read.cc

# Object Files
OBJ = $(SRC:.cc=.o)
TEST_OBJ = $(TEST_SRC:.cc=.o)

# Executables
EXEC = rpn_calculator
TEST_EXEC = test_rpn

# Google Test Flags
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Build All
default: $(EXEC) $(TEST_EXEC)

# Build Main Executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Build Test Executable
$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(GTEST_LIBS)

# Compile Object Files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(EXEC) $(TEST_EXEC) $(OBJ) $(TEST_OBJ)




