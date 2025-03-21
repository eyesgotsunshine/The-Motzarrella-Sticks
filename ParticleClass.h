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

		// add get functions for x, y, vx, vy, lifetime, and movement

		float get_x() const {
			return x;
		}

		float get_y() const {
			return y;
		}

		float get_vx() const {
			return vx;
		}

		float get_vy() const {
			return vy;
		}

		int get_lifetime() const {
			return lifetime;
		}

		MovementType get_movement() const {
			return movement;
		}
// then change the particle system to use these functions to get the current possitions of the particles

		void set_x(float new_x) {
			x = new_x;
		}

		void set_y(float new_y) {
			y = new_y;
		}

		void set_vx(float new_vx) {
			vx = new_vx;
		}

		void set_vy(float new_vy) {
			vy = new_vy;
		}

		void set_lifetime(int new_lifetime) {
			lifetime = new_lifetime;
		}

		void set_movement(MovementType new_movement) {
			movement = new_movement;
		}

	/*Particle position ()
		for (auto& particle : particles) {
		cout << "Particle at (" << particle.get_x() << ", " << particle.get_y() << ")" << endl;
	 } */

	 pair<int, int> getPosition() const {
		return {static_cast<int>(x), static_cast<int>(y)};
	}

		// add a physics function that moves the particle based on its movement type
		// and decreases the lifetime if the particle is a firework

// the comment is what the tutor told me to do and the float code below is from the AI

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