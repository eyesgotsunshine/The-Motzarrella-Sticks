#pragma once
#include <iostream>
#include "particleSys.h"
#include "particleGraphics.h"
#include "particleClass.h" //IWYU: pragma keep
using namespace std;

class Cell { // holds particles
	private:
		Particle data; // want the type to be Particle
		Cell *head = nullptr;
		Cell *tail = nullptr;

	public:
		Cell(Particle newData, Cell *prev_new = nullptr, Cell *next_new = nullptr) :
			data(newData), head(prev_new), tail(next_new) {}


		~Cell() {

		}

		Particle& getData() { 
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

};

