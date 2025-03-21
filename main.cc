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
    system("echo '\n=== Particle System Menu ===' | lolcat");
    cout << "1. Run Tests\n";
    cout << "2. Add a Particle\n";
    cout << "3. Draw Particles\n";
    cout << "4. Run Physics\n";
    cout << "5. Call ParticleSystem 1 (Coming Soon)\n";
    cout << "6. Call ParticleSystem 2 (Coming Soon)\n";
    cout << "7. Call ParticleSystem 3 (Coming Soon)\n";
    cout << "8. Call ParticleSystem 4 (Coming Soon)\n";
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
    particleSystem tester(5, 10);
    EXPECT_EQ(tester.get_columns(), 5);
    EXPECT_EQ(tester.get_rows(), 10);
    EXPECT_EQ(tester.get_particleCount(), 0);
} */

/* TEST(BasicsTest, RowsAndColumnsSetters) {
    particleSystem tester(5, 10);
    tester.set_columns(22);
    tester.set_rows(33);
    tester.set_particleCount(44);
    EXPECT_EQ(tester.get_columns(), 22);
    EXPECT_EQ(tester.get_rows(), 33);
    EXPECT_EQ(tester.get_particleCount(), 44);
} */

/* (TEST(BasicsTest, Methods) {
    particleSystem tester(5, 10);
    EXPECT_EQ(tester.addParticle(6), 6);
    EXPECT_EQ(tester.numParticles(), tester.get_particleCount());
    EXPECT_EQ(tester.moveParticles(), "stub");
    EXPECT_EQ(tester.drawParticles(), "stub");
} */


// D - Mark 
//TEST
auto [rows,cols] = get_terminal_size();
 
  int main (int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    vector<Particle> particles;

    for (auto& particle : particles) {
      particle.physics();
      particle.draw();
    }

  }
