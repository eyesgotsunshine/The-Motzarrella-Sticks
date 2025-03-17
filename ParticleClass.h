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

				case BALLISTIC:
					vy += 1;
					x += vx;
					y += vy;

				case FIREWORK:
					if (lifetime <= 0) {
						cout << "Firework exploded" << endl;
					}

			}
			if (lifetime >0) lifetime--;
		}
		
		void draw() {
			cout << "Drawing particle at (" << x << ", " << y << ")" << endl;
		}
};

int main() {
	Particle p1(0.0f, 0.0f, 1.0f, 0.5f, 100, STREAMER);

	Particle p2(0.0f, 0.0f, 1.0f, 1.0f, 100, BALLISTIC);

	p.physics();
	p.draw();

	return 0;
}
