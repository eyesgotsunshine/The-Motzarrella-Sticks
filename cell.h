#include <iostream>
#include "particleSys.h"
#include "particalGraphics.h"
using namespace std;

class Cell { // holds particles
	private:
	Particle data; // want the type to be Particle
 	Cell *prev = nullptr;
    	Cell *next = nullptr;

	public:
	Cell(int newData = nullptr, Cell *prev_new = nullptr, Cell *next_new = nullptr) : 
        data(newData), prev(prev_new), next(next_new) {}

~Cell() {
	
}

Particle getData() const { 
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

