#pragma once
#include <iostream>
//#include "particle.h" TODO: Uncomment when finished
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
		Cell *current = head;  // Start at the head 
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
            newCell->setPrev(tail);        // Update the tail to the new cell
        }
        particleCount++;  // Increase particle count
    }

	
	int numParticles(){
	 //TODO: Remove this line after testing
		return get_particleCount();
	}

	string moveParticles(){
		return "stub"; //TODO: Unstub this function when ready
	}

	string drawParticles(){
		return "stub";	// TODO: Unstub this function when ready
	}

	//Apparently some other method goes here that we need
	//Waiting for further explanation

};



