#pragma once
#include <iostream>
#include "particleSys.h"
#include "particleGraphics.h"
#include "ParticleClass.h" //IWYU: pragma keep
using namespace std;

class Cell { // holds particles
	private:
	Particle data; // want the type to be Particle
 	Cell *head = nullptr;
    Cell *tail = nullptr;
	int rows = 0;
	int columns = 0;

	public:
	Cell(Particle newData, Cell *prev_new = nullptr, Cell *next_new = nullptr, int new_rows = 0, int new_columns = 0) :
	 data(newData), head(prev_new), tail(next_new), rows(new_rows), columns(new_columns) {}

	Cell(const Particle& particle) : data(particle) {
			auto position = data.getPosition();
			rows = position.first;
			columns = position.second;
		}
	

~Cell() {
	
}

Particle getData() const { 
	return data; 
}

void setData(Particle newData) { 
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

int get_rows() const { 
	return rows; }

int get_columns() const { 
	return columns; }

};

