#include <iostream>
#include <vector>
#include <string> 
//#include "cell.h"
//#include "ParticleClass.h"
//#include "particleSys.h"
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>

//srand(time(0));//seed the random number generator
class ParticleGraphics{
	std::string color;// private value

	public:
	ParticleGraphics(std::string intialColor = "Black") : color(intialColor){}// Const 
	std::string getColor() const{// color getter
		return color;
	}
/*
	//colors version 1 -just echos color to cout
	const auto [rows,cols] = get_terminal_size();
	cout << "ROWS " << rows << endl;
	coutn << "COLS " << cols << endl;
	cout << RED << "YO!" << RESET << endl;
	setbgcolor(0,0,0);
	setcolor(255,255,255);
	rows --;
	cols --;
	int x = rand() % cols;
	int y = rand() % rows;
	int dx = 1;//velocity
	int dy = 1;//"       "
	string DVD_logo = "🍕"
	double FPS = 24.;
	show_cursor(false);
	int life time = 100;
	for (int i = 0; i < life time; i++){
		//phase 1 update pos
		x += dx;
		y += dy;
		//phase 1.5 bounce if we hit edge
		if (x < 0){
		x *= -1;
		dx *= -1; //bounce
		}
		if (y < 0){
		y *= -1;
		dy *= -1; //bounce
		}
		if (y < 0){
		y *= -1;
		dy *= -1; //bounce
		//phase 2 upadte velocisty
		dx += 0;
		dy += 1;// add gravity
		//phase 3 draw partical
	 movecursor(x,y);
	 setbgcolor();
	 setcolor();
	 cout << DVD_logo;
	 cout.flush();
	 resetcolor();
		//phase 4 delete partical maybe?
		usleep(100'000); // pause for .1s
		clearscreen();

		}
	//cout << "🍕";//fn, control+cmd+space
	//C++ 17 Structured Binding
	resetcolor();//partical



*/
	void setColor(const std::string& newColor){
		color = newColor;
	}
	
	void drawPoint(int x, int y){
		//std::cout << "Drawing point at (" << x << ", " << y << ") with color "  << color << std::endl;//Point Stub
		return;
	}
/*	void draw_square(int min_x, int max_x, int min_y, int max_y){
	assert(min_x < max_x)//enforces precondions on pain of death
	assert(min_y < min_y)
	resetcolor();
	setbgcolor(r,g,b);
	for (int row = min_x; row <= max_x; row++){
		for(int col = min_y; col <=max_y; col++){
	movercursor(row,col);
	cout << " ";


	
		}
	}
}

*/   
	void drawRectangle(int x, int y, int width, int hight){
		//std::cout << "Drawing retangle at (" << x << ", " << y << ") with width " << width << " and hight " << hight << " with color " << color << std::endl;// Rectangle Stub
		return;
	}
	
	void drawOval(int x, int y, int width, int hight){
		//std::cout << "Drawing oval at (" << x << ", " << y << ") with width " << width << " and hight " << " with color " << color << std::endl;// Oval Stub
		return;
	}
	
	void drawPolygon(double x, double y){
	//void drawPolygon(const std::vector < std::pair<int, int>& points){
		//std::cout << "Drawing polygon with " << points.size << " points with color  " << color << std::endl;// Polygon Stub
		return;
	}
	void drawLine(int x1, int y1, int x2, int y2) {
    	//std::cout << "Drawing line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ") with color " << color << std::endl;
    	return;
	}
};

int main() { //test code I wrote on onlineGBD
    ParticleGraphics particleGraphics; //particleGraphics object(black)

    std::cout << "Initial color: " << particleGraphics.getColor() << std::endl; // Test the getter and setter for color

    particleGraphics.setColor("red");
    std::cout << "Updated color: " << particleGraphics.getColor() << std::endl;// Change the color to (red)

    particleGraphics.drawPoint(10, 20);
    particleGraphics.drawRectangle(30, 40, 100, 50);
    particleGraphics.drawOval(50, 60, 80, 40);
    particleGraphics.drawPolygon(0, 0);
    //particleGraphics.drawPolygon({{0, 0}, {10, 10}, {20, 5}});
    particleGraphics.drawLine(0, 0, 10, 10);
    // Test shapes with the color (red)

    return 0;
}
