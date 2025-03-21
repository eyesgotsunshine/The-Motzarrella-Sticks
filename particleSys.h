#pragma once
#include <iostream>
#include "ParticleClass.h" //IWYU: pragma keep
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

	- Additional graphics as needed like the rectangles of a window.														HUH? WAITING FOR EXPLANATION AND PLANS

*/

/////////////////////////
//PARTICLE SYSTEM CLASS//
/////////////////////////

class particleSystem {
	
	int columns = 0;
	int rows = 0;
	Cell *head = nullptr;  // Head pointer for linked list
    Cell *tail = nullptr;  // Tail pointer for linked list
	int particleCount = 0;

	public:

	///////////////
	//Constructor//
	///////////////

	particleSystem(int newCol = 0, int newRow = 0){ //TODO: LL contructor stuff goes here
		columns = newCol;
		rows = newRow;
		head = nullptr;
        	tail = nullptr;
        	particleCount = 0;
	}

	// Destructor - clean up memory (delete linked list nodes)
	~particleSystem() {
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
		return columns;
	}

	const int& get_rows() const{
        return rows;
    }

	//TODO: Getter for linked list

	const int& get_particleCount() const{
        return particleCount;
    }
	
	///////////
	//Setters//
	///////////

 	void set_columns(int new_columns = 0){
        columns = new_columns;
    }

	void set_rows(int new_rows = 0){
        rows = new_rows;
    }

	//TODO: Setter for linked list

	void set_particleCount(int new_particleCount = 0){
        particleCount = new_particleCount;
    }

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
        }
        particleCount++;  // Increase particle count
    }

	
	int numParticles(){
	 //TODO: Remove this line after testing
		return get_particleCount();
	}

	void moveParticles(){
		Cell *curCell = head;
		while (curCell != nullptr){
		//TODO: Review below code to very if move() exits somewhere
			//curCell.physics();  this is not compiling atm, will check later
			curCell = curCell ->getNext();
		}
	}

	void drawParticles(ParticleGraphics &graphics){
		Cell *curCell = head;
		while (curCell != nullptr){
			int tempRow = curCell->get_rows();
			int tempCol = curCell->get_columns();
			//TODO: Review and Verify code with Justus	
			if (tempRow >= 0 && tempRow < rows && tempCol >= 0 && tempCol < columns){
				graphics.drawPoint(tempRow, tempCol);
			}
			curCell = curCell->getNext();
		}
	}

	void cullParticles() {
    Cell* cur = head;
    while (cur != nullptr) {
        Cell* next = cur->getNext();
        if (cur->getLifetime() <= 0 || cur->getX() < 0 || cur->getX() >= columns ||
            cur->getY() < 0 || cur->getY() >= rows) {
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



