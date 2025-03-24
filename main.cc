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
//#include "particleGraphics.h"

using namespace std;

void die() {
	cout << "BAD INPUT\n";
	//	exit(EXIT_FAILURE);
}

void Menu() {
	system("echo '\n====== Particle System Menu ======\n' | lolcat");
	cout << "1. Run Tests\n";
	cout << "2. Add a Particle\n";
	cout << "3. Draw Particles\n";
	cout << "4. Run Physics\n";
	cout << "5. Call ParticleSystem 1 (loading...)\n";
	cout << "6. Call ParticleSystem 2 (loading...)\n";
	cout << "7. Call ParticleSystem 3 (loading)\n";
	cout << "8. Call ParticleSystem 4 (RIP Terry)\n";
	cout << "9. Exit\n";
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

	ParticleSystem my_system;  // Empty particle system
	ParticleGraphics part_graph;
	part_graph.drawPoint(5,10);
	return 0;
	int choice = 0;

	while (true) {
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
		} else if (choice == 2) {
			float x, y, vx, vy;
			int lifetime;
			cout << "Enter x, y position: ";
			cin >> x >> y;
			cout << "Enter vx, vy velocity: ";
			cin >> vx >> vy;
			cout << "Enter lifetime: ";
			cin >> lifetime;

			Particle newParticle(x, y, vx, vy, lifetime, STREAMER);
			my_system.addParticle(new Cell(newParticle));  // Add particle to system
			cout << "Particle added.\n";
		} else if (choice == 3) {
			my_system.drawParticles(part_graph);
		} else if (choice == 4) {
			my_system.moveParticles();
			cout << "Physics updated.\n";
		} else if (choice >= 5 && choice <= 8) {
			cout << "This is under construction. Beep, beep.\n";
		} else if (choice == 9) {
			cout << "Exiting program.\n";
			system("echo 'G O O D    B Y E' | lolcat");
			break;
		} else {
			 system("echo 'Invalid choice. Try again.\n' | lolcat");
		}
	}

	//return 0;
}

