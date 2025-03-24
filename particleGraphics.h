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
<<<<<<< HEAD
	ParticleGraphics(int new_r = 0, int new_g = 0, int new_b = 0) {
		r = new_r;
		g = new_g;
		b = new_b;
||||||| d347cb6
	particleGraphics(int new_r = 0, int new_g = 0, int new_b = 0)
	r = new_r;
	g = new_g;
	b = new_b;
=======
	ParticleGraphics(int new_r = 0, int new_g = 0, int new_b = 0);
	int r = new_r;
	int g = new_g;
	int b = new_b;
>>>>>>> refs/remotes/origin/main
	}

<<<<<<< HEAD
	int getRed(){
		return r;
||||||| d347cb6
	int getColor(){
	return r;
=======
	int getColorR(){
	return r;
>>>>>>> refs/remotes/origin/main
	}

<<<<<<< HEAD
	int getGreen(){
		return g;
||||||| d347cb6
	int getColor(){
	return g;
=======
	int getColorG(){
	return g;
>>>>>>> refs/remotes/origin/main
	}
<<<<<<< HEAD

	int getBlue(){
		return b;
||||||| d347cb6
	
	int getColor(){
	return b;
=======
	
	int getColorB(){
	return b;
>>>>>>> refs/remotes/origin/main
	}
	void setcolor(int new_r = 0, int new_g = 0, int new_b = 0) {
		r = new_r;
		g = new_g;
		b = new_b;
	}
<<<<<<< HEAD

||||||| d347cb6
	void setColor(const std::string& newColor){
		color = newColor;
	}
	
=======
	void setColor(const std::string& newColor){
		color = newColor;
	}
};
	
>>>>>>> refs/remotes/origin/main
	void drawPoint(int x, int y){ // draws particle point
		resetcolor();
		setbgcolor(int r, int g, int b);
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
<<<<<<< HEAD
};
||||||| d347cb6
};
/*
int main() { //test code I wrote on onlineGBD
    ParticleGraphics particleGraphics; //particleGraphics object(black)

    std::cout << "Initial color: " << particleGraphics.getColor() << std::endl; // Test the getter and setter for color

    particleGraphics.setColor("red");
    std::cout << "Updated color: " << particleGraphics.getColor() << std::endl;// Change the color to (red)

    particleGraphics.drawPoint(10, 20);
    particleGraphics.drawRectangle(30, 50);
    particleGraphics.drawOval(50, 40);
    particleGraphics.drawPolygon(0, 0);
    particleGraphics.drawPolygon(0,0);//({{0, 0}, {10, 10}, {20, 5}});
    particleGraphics.drawLine(0, 10);
    // Test shapes with the color (red)

    return 0;
}*/
=======
}
/*
int main() { //test code I wrote on onlineGBD
    ParticleGraphics particleGraphics; //particleGraphics object(black)

    std::cout << "Initial color: " << particleGraphics.getColor() << std::endl; // Test the getter and setter for color

    particleGraphics.setColor("red");
    std::cout << "Updated color: " << particleGraphics.getColor() << std::endl;// Change the color to (red)

    particleGraphics.drawPoint(10, 20);
    particleGraphics.drawRectangle(30, 50);
    particleGraphics.drawOval(50, 40);
    particleGraphics.drawPolygon(0, 0);
    particleGraphics.drawPolygon(0,0);//({{0, 0}, {10, 10}, {20, 5}});
    particleGraphics.drawLine(0, 10);
    // Test shapes with the color (red)

    return 0;
}*/
>>>>>>> refs/remotes/origin/main
