#pragma once
#include <iostream>
#include "particleClass.h" //IWYU: pragma keep
#include "particleGraphics.h" //IWYU: pragma keep
#include "cell.h" 
using namespace std;

///////////////////////
//SECTION DESCRIPTION//
///////////////////////

/*

A ParticleSystem class that will handle all the logic for the simulation. 

	- It needs to hold the size of the screen (in columns and rows),                                                        DONE

	- It needs to hold the linked list of particles (with a head and tail pointer), 										WAITING FOR TEAM TO IMPLEMENT LL AND PARTICLES

	- An add method to add a new particle, 																					ALMOST DONE (NEED TO INCLUDE PARTICLE CLASS ^ )

	- A numParticles() method that returns how many particles are in the system, 											ALMOST DONE (NEED TO INCLUDE PARTICLE CLASS ^ )

	- A moveParticles() method that will call the move method on each particle (stub it out),								DONE 
	
	- A drawParticles() method that will call the draw method on each particle (stub it out) 								DONE

	- Additional graphics as needed like the rectangles of a window.														DONE

*/

/////////////////////////
//PARTICLE SYSTEM CLASS//
/////////////////////////

class ParticleSystem {
	
	int columnsY = 0;
	int rowsX = 0;
	Cell *head = nullptr;  // Head pointer for linked list
    Cell *tail = nullptr;  // Tail pointer for linked list
	int particleCount = 0;

	public:

	///////////////
	//Constructor//
	///////////////

	ParticleSystem(){ //TODO: LL contructor stuff goes here
		const auto [Cols, Rows] = get_terminal_size();
		columnsY = Cols;
		rowsX = Rows;
/*		head = nullptr;       Kerney had me comment these out
        	tail = nullptr;
        	particleCount = 0;
*/	}

	// Destructor - clean up memory (delete linked list nodes)
	~ParticleSystem() {
		Cell *current = head;  // Starting pt
		while (current != nullptr) {
			Cell *temp = current;     // Store current node
	current = current->getNext();
			delete temp;              // Delete current node
		}
}
	///////////
	//Getters//
	///////////

	const int& get_columns() const{
		return columnsY;
	}

	const int& get_rows() const{
        return rowsX;
    }

	//TODO: Getter for linked list

	const int& get_particleCount() const{
        return particleCount;
    }
	
	///////////
	//Setters//
	///////////

 	void set_columns(int new_columns = 0){
        columnsY = new_columns; //may have these switched, EVALUATE
    }

	void set_rows(int new_rows = 0){
        rowsX = new_rows;
    }

	//TODO: Setter for linked list
	// Kerney said to comment this out
	/*void set_particleCount(int new_particleCount = 0){
        particleCount = new_particleCount;
    }
	*/

	/////////////////
	//Class Methods//
	/////////////////

	void addParticle(Cell *newCell) {
        if (head == nullptr) {  // If list is empty
            head = newCell;
            tail = newCell;
        } else {
            tail->setNext(newCell);  // Link the new cell to the end of the list
            newCell->setPrev(tail);    // Updating the tail to the new cell
            tail = newCell;
        }
        particleCount++;  // Increase particle count
    }

	
	int numParticles(){
		return get_particleCount();
	}

	// Move particles: for every particle in particles, call physics on it
	void moveParticles(){
		Cell *curCell = head;
		while (curCell != nullptr){
		//TODO: Review below code to very if move() exits somewhere
			curCell->getData().physics(this);
			curCell = curCell ->getNext();
		}
	}

	void drawParticles(ParticleGraphics &graphics){
		Cell *curCell = head;
		while (curCell != nullptr){
			int tempRow = curCell->getData().x;
			int tempCol = curCell->getData().y;
			//TODO: Review and Verify code with Justus	
			if (tempRow >= 0 && tempRow < rowsX && tempCol >= 0 && tempCol < columnsY){
				graphics.drawPoint(tempRow, tempCol);
			}
			curCell = curCell->getNext();
		}
	}

	void cullParticles() {
    Cell* cur = head;
    while (cur != nullptr) {
        Cell* next = cur->getNext();
		Particle p = cur->getData(); // to make a shorter/simplier if statement
        if (p.lifetime <= 0 || p.x < 0 || p.x >= columnsY ||
            p.y < 0 || p.y >= rowsX) { // x is supposed to be colmns
            // Remove cur from the list
            if (cur == head) head = cur->getNext();
            if (cur == tail) tail = cur->getPrev();
            if (cur->getPrev()) cur->getPrev()->setNext(cur->getNext());
            if (cur->getNext()) cur->getNext()->setPrev(cur->getPrev());

            delete cur;
            particleCount--;
        }
        cur = next;
    }
}
	void updateFrame(ParticleGraphics &graphics) {
    	moveParticles(); // Apply physics
    	cullParticles(); // Remove dead/out-of-bounds particles
	    drawParticles(graphics); // Render the remaining particles
}


	//Space for any other methods required for setting the scene in our animation.

};



