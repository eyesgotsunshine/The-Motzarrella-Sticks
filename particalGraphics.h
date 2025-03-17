#include <iostream>
#include <vector>
#include <string> 

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
	
	void drawPoint(int x, in y){
		std::cout << "Drawing point at (" << x << ", " << y << ") with color "  << color << std::endl;//Point Stub
	}
	
	void drawRectangle(int x, int y, int width, int heigt){
		std::cout << "Drawing retangle at (" << x << ", " << y << ") with width " << color << std::endl;// Rectangle Stub
	}
}
