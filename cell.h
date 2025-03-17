#include <iostream>
#include "particleSys.h"
#include "particle.h"
using namespace std;

class Cell {
	private:
	Particle data;
    Cell *prev = nullptr;
    Cell *next = nullptr;

	public:

	Cell(Particle* p = nullptr, Cell* prev = nullptr, Cell* next = nullptr)
	: data(p), prev(prev), next(next) {}

~Cell() {
	delete data;
}

Particle* getData() const { return data; }
void setData(Particle* p) { data = p; }

Cell* getNext() const { return next; }
void setNext(Cell* n) { next = n; }

Cell* getPrev() const { return prev; }
void setPrev(Cell* p) { prev = p; }
};

