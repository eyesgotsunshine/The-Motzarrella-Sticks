#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "cell.h"
#include "particleSys.h"
#include "particleClass.h"
#include "particleGraphics.h"
using namespace std;

using namespace gj{
int main(){
	srand(time(0));

	int x = 1;
	int Vx = 0; // horz vel
	int y = 0;
	int Vy = 0; // vert vel
	double amp = 3;
	double freq = 0;
	double t = 0;

	int numOfBullets = 100;
    int r = 255;
    int g = 182;
    int b = 193;
    particleGraphics color(r, g, b);
	ParticleSystem part_sys{cols, rows}; 
	
	string bullet = "•"; //bullets
	auto [rows, cols] = get_terminal_size();
    rows--;
    col--;


	int life time =1440;
	double FPS = 60;

	//set_raw_mode(true);
	//set_raw_mode(true);
	//show_cursor(true);
	while (lifetime){
	for (int i = 0; i < numberOfBullets; i ++){
	/*x += Vx;// add vel to pos of the bullet y and x
	y += Vy;

	if (x < 0 || y < 0 || x>= cols || y >= rows) bullet = " ";
	*/
		int y= rows;
		double Vy = amp * sin(freq * (x + t));
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

         

/*
	movecursor(y, x);
	secolor(255,182,193); //set to blue,pink
	cout << bullet;
	cout.flesh();
	resetcolor();

	usleep(1'000'000/FPS); 
	cleansreen(); // screen wipe

}

	show_cursor(true);// reset screen so it doesnt freeze
	resetcolor();
	set_raw_mode(true);
	set_mouse_mode(true);

}
*/
