#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "particleSys.h"
#include "particleGraphics.h"
#include "particleClass.h"
#include "cell.h"
#include "/public/colors.h"
using namespace std;
namespace bmb{
/*
		void shoot(int rows, int cols, ParticleSystem& part_sys, int lifetime){//ParticleSystem& part_sys
	int numOfBullets = 10;
    int r = 255;
    int g = 255;
    int b = 255;
	ParticleGraphics color(r, g, b);
	for (int i = 0; i < numOfBullets; i ++){
		int Vy = 0; //amp * sin(freq * click_col + t);
		int Vx = 1;
		Particle p(rows, cols, Vx,Vy, lifetime, STREAMER);
            Cell *c = new Cell(p, nullptr, nullptr);
            part_sys.addParticle(c);
	}
	part_sys.updateFrame(color);
	}	
*/
int main(){

	cout <<  "Big Man Blastiose!" << endl;// | figlet | lolcat");
	
	srand(time(0));	
	int lifetime = 100000;
	double FPS = 30;
	int numOfBullets = 30;
    
	int r1 = 65;
    int g1 = 105;
    int b1 = 255;
	ParticleGraphics color1(r1, g1, b1);
	
    int r2 = 255;
    int g2 = 255;
    int b2 = 255;
	ParticleGraphics color2(r2, g2, b2);
	
	string bullet = "•"; //bullets	
	auto [rows, cols] = get_terminal_size();
   	rows--;
   	cols--;

	//set_raw_mode(true);
	//set_mouse_mode(true);
	show_cursor(false);
	
	int x = 1;
	int Vx1 = 2; // horz vel
	int Vx2 = 1; // horz vel
	//int y = 1;
	//int Vy = 0; // vert vel
	double amp = .65;
	double freq = .15;
	double t = 0;


	double amp2 = .75;
	double freq2 = 0.25;

	ParticleSystem part_sys{rows, cols}; 
	
	cout << "ROWS: " << rows << endl;
	cout << "COLS: " << cols << endl;

	while (lifetime){
	for (int i = 0; i < numOfBullets; i++){
	//on_mousedown([&](int x, int y){
	int y = rows/2;
	double Vy1 = amp * sin(freq * (x + t));
	double Vy2 = amp2 * sin(freq2 * (x + t));
	//movecursor(mouse_y, mouse_x);
	//cout << bullet;
	////////
	if (x >= cols || x <= 0){
		Vx1 = -Vx1;
		Vx2 = -Vx2;
	}
	///////


	Particle p1(x, y, Vx1, Vy1, lifetime, STREAMER);
    Cell *c1 = new Cell(p1, nullptr, nullptr);
	part_sys.addParticle(c1);

	
	Particle p2(x, y, Vx2, Vy2, lifetime, STREAMER);
    Cell *c2 = new Cell(p2, nullptr, nullptr);
	part_sys.addParticle(c2); 
	////////
	x += Vx1;
	///////
	}
		part_sys.updateFrame(color1);
		part_sys.updateFrame(color2);
        usleep(1000000/FPS);
        clearscreen();
        lifetime--;
        t += 1.0;
	//set_mouse_mode(false);
	//set_raw_mode(false);
   	//show_cursor(true);
	cout.flush();
	resetcolor();
		}
   	return 0;
	}
}
