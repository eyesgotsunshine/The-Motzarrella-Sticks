#pragma once
#include <iostream>
#include "particleSys.h"
#include "particleGraphics.h"
using namespace std;

class Cell { // holds particles
	private:
	ParticleGraphics data; // want the type to be Particle
 	Cell *head = nullptr;
    Cell *tail = nullptr;

	public:
	Cell(ParticleGraphics newData, Cell *prev_new = nullptr, Cell *next_new = nullptr) : 
        data(newData), head(prev_new), tail(next_new) {}

~Cell() {
	
}

ParticleGraphics getData() const { 
	return data; 
}

void setData(ParticleGraphics newData) { 
	data = newData; 
}

Cell *getNext() const { 
	return tail; 
}

void setNext(Cell *next_new) { 
	tail = next_new; 
}

Cell *getPrev() const { 
	return head; 
}

void setPrev(Cell *prev_new) { 
	head = prev_new; 
}
};

