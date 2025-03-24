#pragma once
#include <iostream>
#include <vector>
using namespace std;

class ParticleSystem;

enum MovementType {
    STREAMER,
    BALLISTIC,
    FIREWORK
};

class Particle {
public:
    float x, y; // rows & columns are done here
    float vx, vy;
    int lifetime;
    MovementType movement;

    Particle(float startX, float startY, float startVx, float startVy, int startLifetime, MovementType type)
        : x(startX), y(startY), vx(startVx), vy(startVy), lifetime(startLifetime), movement(type) {}  // Fixed vx initialization 

	void physics(ParticleSystem *part_sys ) {  // Pass particle system to add new particles
        switch (movement) {
            case STREAMER:
                x += vx;
                y += vy;
                break;

            case BALLISTIC:
                vy += 1;  // Gravity effect
                x += vx;
                y += vy;
                break;

            case FIREWORK:
                if (lifetime == 0) {
                    
                    // Generate explosion particles
                    for (int i = 0; i < 8; i++) { // 8 particles spreading out
                        float angle = i * (3.14159f / 4); // 8 directions evenly spaced
                        float speed = 2.0f;
                        float newVx = speed * cos(angle);
                        float newVy = speed * sin(angle);
                       // part_sys-> addParticle(Particle(x, y, newVx, newVy, 30, STREAMER));  // New particles are streamers
						//ERROR ^ wil need to come back to this
                    }
                } else {
                    x += vx;
                    y += vy;
                }
                break;
        }
        if (lifetime > 0) lifetime--;  // Lifetime always decreases
    }

    void draw() {
        cout << "Drawing particle at (" << x << ", " << y << ")" << endl;
    }
};

/////////////////////////////
//ORIGINAL PARTICLE PHYSICS//
/////////////////////////////


/*
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

		Particle(float startX, float startY, float startVx, float startVy, int startLifetime, MovementType type) 
  		: x(startX), y(startY), vx(startVy), lifetime(startLifetime), movement(type) {}

		// add get functions for x, y, vx, vy, lifetime, and movement

		//Kerney said getters and setters are not essential for this file
		float get_x() const { return x;}

		float get_y() const {return y;}

		float get_vx() const {return vx;}

		float get_vy() const {return vy;}

		int get_lifetime() const {return lifetime;}

		MovementType get_movement() const {return movement;	}
// then change the particle system to use these functions to get the current possitions of the particles

		void set_x(float new_x) {x = new_x;}

		void set_y(float new_y) {y = new_y;	}

		void set_vx(float new_vx) {vx = new_vx;}

		void set_vy(float new_vy) {vy = new_vy;}

		void set_lifetime(int new_lifetime) {lifetime = new_lifetime;}

		void set_movement(MovementType new_movement) {movement = new_movement;}

	Particle position ()
		for (auto& particle : particles) {
		cout << "Particle at (" << particle.get_x() << ", " << particle.get_y() << ")" << endl;
	 } 

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
*/
