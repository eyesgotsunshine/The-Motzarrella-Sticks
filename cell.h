#include <iostream>
#include "particleSys.h"
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
};

