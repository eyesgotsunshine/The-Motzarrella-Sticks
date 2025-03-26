# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -Wno-unused-variable -Wno-unused-parameter
LIBS = -lgtest -pthread

a.out: main.cc particleClass.h particleGraphics.h particleSys.h cell.h ebSys.cc Das-Motschenbacher.cc 

	$(CXX) $(CXXFLAGS) main.cc $(LIBS)

clean:
	rm -rf a.out core *.o
