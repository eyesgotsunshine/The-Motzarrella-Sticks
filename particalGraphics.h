#include <iostream>
#include <vector>
#include <string> 
#include "particle.h"
#include "particalSystem.h"
#include "/public/colors.h"

class ParticalGraphics{
	std::string color;// private value

	public:
	ParticalGraphics(std::string initalColor = "Black") : color(intialColor){}// Const 
	std::string getColor() const{// color getter
		return color;
	}

	void setColor(const std::string& newColor){
		color = newColor;
	}
	
	void drawPoint(int x, int y){
		//std::cout << "Drawing point at (" << x << ", " << y << ") with color "  << color << std::endl;//Point Stub
		return 0;
	}
	
	void drawRectangle(int x, int y, int width, int hight){
		//std::cout << "Drawing retangle at (" << x << ", " << y << ") with width " << width << " and hight " << hight << " with color " << color << std::endl;// Rectangle Stub
		return 0;
	}
	
	void drawOval(int x, int y, int width, int hight){
		//std::cout << "Drawing oval at (" << x << ", " << y << ") with width " << width << " and hight " << " with color " << color << std::endl;// Oval Stub
		return 0;
	}
	
	void drawPolygon(const std::vector<std::pair<int, int>& points){
		//std::cout << "Drawing polygon with " << points.size << " points with color  " << color << std::endl;// Polygon Stub
		return 0;
	}
	void drawLine(int x1, int y1, int x2, int y2) {
    	//std::cout << "Drawing line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ") with color " << color << std::endl;
    	return 0;
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
    particleGraphics.drawPolygon({{0, 0}, {10, 10}, {20, 5}});
    particleGraphics.drawLine(0, 0, 10, 10);
    // Test shapes with the color (red)

    return 0;
}
