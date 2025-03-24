#include <iostream>
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <list>                 //Standard Library Linked List
using namespace std;

/*
struct ball{
    int x = 0;
    int y = 0;
    string graphic = "•"; // The object to animate
    auto [rows, cols] = get_terminal_size(); //Gets the screen size of the terminal
    rows--;                                  //Makes screen one size smaller than above size just to be safe
    cols--;                                  //Makes screen one size smaller than above size just to be safe
    cout << "ROWS: " << rows << endl;        //cout size of screen, not necessary for function, just FYI
    cout << "COLS: " << cols << endl;        //cout size of screen, not necessary for function, just FYI


};
*/

int main(){


    srand(time(0));  //Used for choosing a random spawn position for the balls
//  ball.getscreen();


    int x = 0;
    int y = 0;
    string ball = "•"; // The object to animate
    auto [rows, cols] = get_terminal_size(); //Gets the screen size of the terminal
    rows--;                                  //Makes screen one size smaller than above size just to be safe
    cols--;                                  //Makes screen one size smaller than above size just to be safe
    cout << "ROWS: " << rows << endl;        //cout size of screen, not necessary for function, just FYI
    cout << "COLS: " << cols << endl;        //cout size of screen, not necessary for function, just FYI

//  Sets random position of ball


//  Sets starting speed of ball
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


    //  If the ball touches the sides of the animation, it despawns
        if (x < 0 or y < 0 or x >= cols or y >= rows) ball = " ";

        movecursor(y, x);
        setcolor(200, 37, 111);   // Text color
        cout << ball;
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
    }
