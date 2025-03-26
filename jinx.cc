#include <iostream>
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <list>                 //Standard Library Linked List
using namespace std;


int main(){
	//srand(time(0));

	int x = 0;
	int y = 0;
	string bullet = "•"; //bullets
	auto [rows, cols] = get_terminal_size();
    rows--;
    col--;

	int Vx = 1; // horz vel
	int Vy = 1; // vert vel

	int life time =1440;
	double FPS = 60;

	set_raw_mode(true);
	set_raw_mode(true);

	show_cursor(true);

	for (int i = 0; i < lifetime; i ++){
	x += Vx;// add vel to pos of the bullet y and x
	y += Vy;

	if (x < 0 || y < 0 || x>= cols || y >= rows) bullet = " ";


	movecursor(y, x);
	secolor(255,255,255); //set to blue,pink
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

