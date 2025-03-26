# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -Wno-unused-variable -Wno-unused-parameter
LIBS = -lgtest -pthread

a.out: main.cc Das-Motschenbacher.cc particleClass.h particleGraphics.h particleSys.h cell.h
	$(CXX) $(CXXFLAGS) main.cc $(LIBS)

clean:
	rm -rf a.out core *.o
