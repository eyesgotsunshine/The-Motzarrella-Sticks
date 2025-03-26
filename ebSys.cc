#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "cell.h"
#include "particleSys.h"
#include "particleClass.h"
#include "particleGraphics.h"
using namespace std;

/////////////
//Checklist//
/////////////

//	-Step 1:	Get screen size												DONE
//	-Step 2:	Set ball start point										DONE
//	-Step 3:	while (true){												DONE
//					- add balls to the left side							DONE
//						- add balls to the linked list						DONE
//					- move the balls										DONE
//						- apply physics										DONE
//						- clear screen										DONE
//						- lifetime--										DONE
//					- delete balls if on right side							DONE
//					- draw balls for some reason							DONE
//					- usleep and clearscreen								DONE









namespace eb{  //From what I remember, all .cc files need a main function, so I need a namespace to avoid weird issues in the actual main.cc file
int main(){

	/////////////////////
	//Starter Variables//
	/////////////////////

	srand(time(0));  //Used for choosing a random spawn position for the balls
    int lifetime = 100; // Total frames
    double FPS = 60.;  //Frames per Second
	int numOfBalls = 10;
	int r = 200;
	int g = 37;
	int b = 20;
	ParticleGraphics color(r, g, b);

	///////////////////
	//Get Screen Size//
	///////////////////

    string ball = "•"; // The object to animate
    auto [rows, cols] = get_terminal_size(); //Gets the screen size of the terminal
    rows--;                                  //Makes screen one size smaller than above size just to be safe
    cols--; 								 //Makes screen one size smaller than above size just to be safe
	
	///////////////////////////
	//X&Y Start Pos, and VX&Y//
	///////////////////////////


	int x = 1;						//Particle Spawns in Column 1
	int y = rand() % rows;			//Particle Spawns in random row
	int Vx = 1;						//Moves to the right by one space every frame
	int Vy = sin(x);				//Moves in a sin pattern

	ParticleSystem part_sys{cols, rows};     //Creates a particle system that is the size of the screen

    cout << "ROWS: " << rows << endl;        //cout size of screen, not necessary for function, just FYI
    cout << "COLS: " << cols << endl;        //cout size of screen, not necessary for function, just FYI

	while (lifetime){

		for (int i = 0; i < numOfBalls; i++){ 		//Spawns numOfBalls on the left side of screen
			Particle p(x, y, Vx, Vy, lifetime, STREAMER);
			Cell c(p);
			addParticle(c);
	}
		part_sys.updateFrame(color);
		usleep(1000000/FPS);
		clearscreen();
}
}
