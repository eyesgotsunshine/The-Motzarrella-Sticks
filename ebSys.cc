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
    int lifetime = 100000; // Total frames
    double FPS = 60.;  //Frames per Second
	int numOfBalls = 10;
	int r = 0;
	int g = 0;
	int b = 222;
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
	//int y = rand() % rows;			//Particle Spawns in random row
	int Vx = 1;						//Moves to the right by one space every frame
	double amp = 3;
	double freq = 0.2; 				//Moves in a sin pattern
	double t = 0;

	ParticleSystem part_sys{cols, rows};     //Creates a particle system that is the size of the screen

    cout << "ROWS: " << rows << endl;        //cout size of screen, not necessary for function, just FYI
    cout << "COLS: " << cols << endl;        //cout size of screen, not necessary for function, just FYI

	while (lifetime){
/*
	for (int i = 0; i < 10; i++) {
    int x = rand() % cols;  // Random column within screen width
    int y = rand() % rows;  // Random row within screen height

    movecursor(y, x);
    setcolor(255, 255, 255);   // Text color
    cout << ball;
    cout.flush();
    resetcolor();
}
*/

		for (int i = 0; i < numOfBalls; i++){//Spawns numOfBalls on the left side of screen
//			int y = 1000;  // rand() % rows;
//			int Vy = 1;
	  // Spawn on the left
     //      double y = (rows / 2) + amp * sin(freq * x);  // Start along sine wave
			double y = (rows / 2) + amp * sin(freq * x);
			double Vy = amp * freq * cos(freq * x);
            // Each particle follows the sine wave as it moves right 
 //      	double Vy = sin(getData().physics(this));


			Particle p(x, y, Vx, Vy, lifetime, STREAMER);
			Cell *c = new Cell(p, nullptr, nullptr);
			part_sys.addParticle(c);
	}
		part_sys.updateFrame(color);
		usleep(1000000/FPS);
		clearscreen();
		lifetime--;
		t += 1.0;
}
	return 0;
}
}
