#include <iostream>
#include "/public/colors.h"
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <list>    
#include "particleSys.h"
#include "particleGraphics.h"
#include "particleClass.h"
#include "cell.h"

using namespace std; //Standard Library Linked List
namespace sm{
 
	// Function to generate a random intensity for the aurora effect
/*	char getAuroraChar() {
		char chars[] = {' ', '.', ':', '*', '+', '#', '%', '@'};
		return chars[rand() % 8]; // Randomly select a character
	}

	// Function to generate a shifting aurora pattern
	void generateAurora(vector<string>& grid) {
	rows = 10;
	cols = 10
		for (int x = 0; x < cols; ++x) {
			int height = rand() % (rows / 2) + rows / 4; // Varying wave height
			for (int y = 0; y < rows; ++y) {
				if (y >= height) {
					grid[y][x] = getAuroraChar(); // Set aurora effect
				} else {
					grid[y][x] = ' '; // Empty space
				}
			}
		}
	} */
						 // Get terminal dimensions
	
		int main(){

		auto [rows, cols] = get_terminal_size();  // Get terminal dimensions
		rows--;
		cols--;

	//	vector<string> grid(rows, string(cols, ' ' )); //making the space for where aurora is

		srand(time(0));  //Used for choosing a random spawn position
		
		int lifetime = 100000; // total frames
		
		double FPS = 60; // frames per second

		int num_of_auroras = 10;

		int r = 0;
		int g = 150;
		int b = 155;
		
		ParticleGraphics color (r, g, b);
		
	//	ParticleSystem system();
	//	system.set_new_columns(cols);
	//	system.set_new_rows(rows);
	
//		string star1 = "⭐";
//		string star2 = "✨";
		char chars[] = {' ', '.', ':', '*', '+', '#', '%', '@'};

		// bluish-green color (example values)
		//ParticleGraphics graphics(0, 150, 150);


		int x = 1; // spawns in col 1

		int Vx = 1;
		double up  = 2;
		double frequency = 1;
		double t = 0;

		ParticleSystem part_sys{cols, rows}; // makes a particle sys that is the screen size

		while (lifetime){
		

		// Spawn a number of particles simulating the northern lights in the upper part of the screen.
		//const int initialParticles = 100;
		for (int i = 0; i < num_of_auroras; i++) {
			int x = rand() % cols;
			int y = rand() % (rows / 4);
			int vx = (rand() % 3) - 1; // -1, 0, or 1 for horizontal drift
			int vy = (rand() % 2);     // 0 or 1 for a gentle downward drift
			int lifetime = rand() % 100 + 50;  // Lifetime between 50 and 149 frames

			// Create a streamer particle (typical aurora effects)
			
			Particle p(x, y, vx, vy, lifetime, STREAMER);
			
			Cell *c = new Cell(p, nullptr, nullptr);
			part_sys.addParticle(c);

			// Add particle to the system; assume addParticle accepts a pointer to a new Cell
		//	system.addParticle(new Cell(p));
		}

		part_sys.updateFrame(color);


		usleep(100000); // Pause for 100ms per frame
		
		clearscreen();  // Clear the screen for the next frame
		
		lifetime--;
		t+=1;

		// Run the animation loop for a set number of frames
		//const int totalFrames = 300;
		//for (int frame = 0; frame < totalFrames; frame++) {
		//	system.moveParticles();          // Update particle positions and lifetimes
		//	system.drawParticles(graphics);  // Draw all particles using the provided graphics object

		}

//*****************
/*
int Vx = 1; // Horizontal velocity
int Vy = 1; // Vertical velocity

//  Sets how long the animation lasts, what the ball actually looks like on screen, and the FPS of the animation
int lifetime = 1440; // Total frames
double FPS = 60.;

//  Enables the mouse so you can interact with animation

set_raw_mode(true);     // Mouse can't be enabled unless raw mode is also enabled
set_mouse_mode(true);

//  Hides the cursor in the animation and starts the actually animation by for-looping through each frame

show_cursor(false);

for (int i = 0; i < lifetime; i++) {

	//  Add velocity to the position of the ball to move it along the x and y axis
	x += Vx;
	y += Vy;

*/
	//  If the ball touches the sides of the animation, it despawns
//	if (x < 0 or y < 0 or x >= cols or y >= rows)  generateAurora(grid) /* ball */  = " ";

/*	movecursor(y, x);
	setcolor(0, 150, 150);   // Text color

	cout <<  generateAurora(grid) // ball ;
	cout.flush();
	resetcolor();

	usleep(1'000'000/FPS); // Pause for smooth animation
	clearscreen(); // Clear the screen

}
// When animation is done, restores everything back to normal to avoid issues
show_cursor(true);
resetcolor();
set_raw_mode(true);     // Mouse can't be enabled unless raw mode is also enabled
set_mouse_mode(true);
*/

return 0;
}


}
