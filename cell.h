#include <iostream>
#include "particleSys.h"
//#include "particle.h"
using namespace std;

class Cell { // holds particles
	private:
	int data; // want the type to be Particle
 	Node *prev = nullptr;
    	Node *next = nullptr;

	public:
	Cell(int newData = nullptr, Node prev_new = nullptr, next_new = nullptr) : 
        data(newData), prev(prev_new), next(next_new) {}

~Cell() {
	delete data;
}

Cell *getData() const { 
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

