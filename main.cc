#include <gtest/gtest.h>
#include "/public/read.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath> //IWYU: prgama keep
#include <stack>
//#include "cell.h"
#include <string>
#include "particleSys.h"
#include "ebSys.cc"
#include "jinx.cc"
//#include "particleGraphics.h"
#include "Das-Motschenbacher.cc"
using namespace std;

void die() {
	cout << "BAD INPUT\n";
	//	exit(EXIT_FAILURE);
}

void Menu() {
	system("echo 'P a r t i c l e \n  S y s t e m \n \t \t \t   M e n u' | figlet | lolcat");
	cout << "1. Run Tests\n";
	cout << "2. Add a Particle\n";
	cout << "3. Draw Particles\n";
	cout << "4. Run Physics\n";
	cout << "5. Call ParticleSystem 1 (Stefanie's)\n";
	cout << "6. Call Big Man Blastoise Cannonball! (Mark's)\n";
	cout << "7. Call ParticleSystem 3 (Evan's)\n";
	cout << "8. Exit\n";
	cout << "Please Choose an option: ";
}

/* A - Stefanie
   Test default constructor
   TEST(CellTest, DefaultConstructor) {
   ParticleGraphics p;
   Cell cell(p);
//EXPECT_EQ(cell.getData(), 2);
EXPECT_EQ(cell.getNext(), nullptr);
EXPECT_EQ(cell.getPrev(), nullptr);
} */


// B - Terry
//TEST

// C - Evan
//TEST

//These tests are up to date as of particleSys.h V2
//I have run them and they have returned 100% working on a personal driver.cc file

/* TEST(BasicsTest, RowsAndColumnsGetters) {
   ParticleSystem tester(5, 10);
   EXPECT_EQ(tester.get_columns(), 5);
   EXPECT_EQ(tester.get_rows(), 10);
   EXPECT_EQ(tester.get_particleCount(), 0);
   } */

/* TEST(BasicsTest, RowsAndColumnsSetters) {
   ParticleSystem tester(5, 10);
   tester.set_columns(22);
   tester.set_rows(33);
   tester.set_particleCount(44);
   EXPECT_EQ(tester.get_columns(), 22);
   EXPECT_EQ(tester.get_rows(), 33);
   EXPECT_EQ(tester.get_particleCount(), 44);
   } */

/* (TEST(BasicsTest, Methods) {
   ParticleSystem tester(5, 10);
   EXPECT_EQ(tester.addParticle(6), 6);
   EXPECT_EQ(tester.numParticles(), tester.get_particleCount());
   EXPECT_EQ(tester.moveParticles(), "stub");
   EXPECT_EQ(tester.drawParticles(), "stub");
   } */


// D - Mark
//TEST
auto [rows, cols] = get_terminal_size();

int main(int argc, char **argv) {
	clearscreen();
	ParticleSystem my_system;  // Empty particle system
	ParticleGraphics part_graph(255, 255, 255); // 255, 255, 255
//	part_graph.drawPoint(13, 20); 
	int choice = 0;

	while (true) {
		movecursor(30,0);
		Menu();
		cin >> choice;
		if (choice == !cin) {
			system("echo 'Invalid choice. Try again.\n' | lolcat");
			continue;
		}
		if (choice == 1) {
			cout << "Running tests. Calling for GTest externally... still figuring this out.\n";
			::testing::InitGoogleTest(&argc, argv);
			return RUN_ALL_TESTS();
		} 
		else if (choice == 2) {
			float x = 0 , y = 0, vx = 0, vy = 0;
			int lifetime = 0;
			int style = 0;
			cout << "Enter x, y position: ";
			cin >> x >> y;
			cout << "Enter vx, vy velocity: ";
			cin >> vx >> vy;
			cout << "Enter lifetime: ";
			cin >> lifetime;
			cout << "Do you want it to be:" << endl;
			cout << "1) streamer" << endl;
			cout << "2) ballistic" << endl;
			cout << "3) firework" << endl;
			cin >> style;

			if (style == 1){
				Particle newParticle(x, y, vx, vy, lifetime, STREAMER);
 my_system.addParticle(new Cell(newParticle));
	
			}
			if (style == 2){
				Particle newParticle(x, y, vx, vy, lifetime, BALLISTIC);
			 my_system.addParticle(new Cell(newParticle));
			}
				if (style == 3){
					Particle newParticle(x, y, vx, vy, lifetime, FIREWORK);
				 my_system.addParticle(new Cell(newParticle));
				}

	//		Particle newParticle(x, y, vx, vy, lifetime, STREAMER);
	//		my_system.addParticle(new Cell(newParticle));  // Add particle to system
			cout << "Particle added.\n";
			clearscreen();
		} 
		else if (choice == 3) {
			clearscreen();
			my_system.drawParticles(part_graph);
		} else if (choice == 4) {
			clearscreen();
			my_system.moveParticles();
			my_system.drawParticles(part_graph);
		} else if (choice == 5) { // Stefanie's particles
			cout << "This is under construction. Beep, beep.\n";
			sm::main();
		}  else if (choice == 6) { // Mark's particles
			cout << (" 'Big Man Blastiose!' | figlet | lolcat");
           	bmb::main();
			//cout << "This is under construction. Beep, beep.\n";
        } else if (choice == 7) { // Evan's particles
			eb::main();
        }else if (choice == 8) {
			cout << "\n Exiting program.\n \n";
			system("echo ' G O O D    B Y E ' | figlet | lolcat");
			cout << "\n" << endl;
			break;
		} else {
			 system("echo 'Invalid choice. Try again.\n' | lolcat");
		}
	}

	//return 0;
}

