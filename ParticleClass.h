#pragma once
#include <iostream>
using namespace std;

enum MovementType {
	STREAMER,
	BALLISTIC,
	FIREWORK
};

class Particle {
	public:
		float x, y;
		float vx, vy;
		int lifetime;
		MovementType movement;

		Particle(float startX, float startY, float startVx, float startVy, int startLifetime, MovementType type) : x(startX), y(startY), vx(startVy), lifetime(startLifetime), movement(type) {}

		void physics() {
			switch (movement) {
				case STREAMER:
					x += vx;
					y += vy;
					break;

				case BALLISTIC:
					vy += 1;
					x += vx;
					y += vy;
					break;

				case FIREWORK:
					if (lifetime <= 0) {
						cout << "Firework exploded" << endl;
					}  else {  // Firework moves normally, and lifetime decreases
				            x += vx;
				            y += vy;
				        }
				        break;

			}
			if (lifetime >0) lifetime--;
		}
		
		void draw() {
			cout << "Drawing particle at (" << x << ", " << y << ")" << endl;
		}
};