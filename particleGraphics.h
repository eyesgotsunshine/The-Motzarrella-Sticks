#pragma once
#include <iostream>
#include <vector>
#include <string> 
#include "cell.h"
#include "particleClass.h"
#include "particleSys.h"
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>

class ParticleGraphics {
	int r, g, b;
	public:
	ParticleGraphics(int new_r = 0, int new_g = 0, int new_b = 0) {
		r = new_r;
		g = new_g;
		b = new_b;
	}

	int getRed(){
		return r;
	}

	int getGreen(){
		return g;
	}

	int getBlue(){
		return b;
	}
	void setcolor(int new_r = 0, int new_g = 0, int new_b = 0) {
		r = new_r;
		g = new_g;
		b = new_b;
	}

	void drawPoint(int x, int y){ // draws particle point
		resetcolor();
		setbgcolor(r, g, b);
		int col = x;
		int row = y;
		cout << " ";
		cout.flush();
		resetcolor();
	}
	void drawRectangle(int min_x, int max_x, int min_y, int max_y, int r, int g, int b) {
		assert(min_x < max_x); 
		assert(min_y < max_y);
		resetcolor();
		setbgcolor(r,g,b);
		for (int row = min_x; row <= max_x; row++) {
			for (int col = min_y; col <= max_y; col++) {
				movecursor(row,col);
				cout << " ";
			}
		}
		cout.flush();
		resetcolor();
	}

	void drawOval(double x, double y){
		return;
	}
	void drawPolygon(double x, double y){
		return;
	}
	void drawLine(double x, double y){
		return;
	}
};
