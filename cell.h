#include <iostream>
#include "particleSys.h"
#include "particleGraphics.h"
using namespace std;

class Cell { // holds particles
	private:
	ParticleGraphics data; // want the type to be Particle
 	Cell *prev = nullptr;
    	Cell *next = nullptr;

	public:
	Cell(ParticleGraphics newData, Cell *prev_new = nullptr, Cell *next_new = nullptr) : 
        data(newData), prev(prev_new), next(next_new) {}

~Cell() {
	
}

ParticleGraphics getData() const { 
	return data; 
}

void setData(int *newData) { 
	data = newData; 
}

Cell *getNext() const { 
	return next; 
}

void setNext(Cell *next_new) { 
	next = next_new; 
}

Cell *getPrev() const { 
	return prev; 
}

void setPrev(Cell *prev_new) { 
	prev = prev_new; 
}
};

