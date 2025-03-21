#pragma once
#include <iostream>
#include <vector>
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

    Particle(float startX, float startY, float startVx, float startVy, int startLifetime, MovementType type)
        : x(startX), y(startY), vx(startVx), vy(startVy), lifetime(startLifetime), movement(type) {}  // Fixed vx initialization

    void physics(vector<Particle>& particleSystem) {  // Pass particle system to add new particles
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
                    cout << "Firework exploded at (" << x << ", " << y << ")" << endl;
                    
                    // Generate explosion particles
                    for (int i = 0; i < 8; i++) { // 8 particles spreading out
                        float angle = i * (3.14159f / 4); // 8 directions evenly spaced
                        float speed = 2.0f;
                        float newVx = speed * cos(angle);
                        float newVy = speed * sin(angle);
                        particleSystem.push_back(Particle(x, y, newVx, newVy, 30, STREAMER));  // New particles are streamers
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
*/
