#include <gtest/gtest.h>
#include "/public/read.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath> //IWYU: prgama keep
#include <stack>
#include "cell.h"
#include <string>
#include "particleSys.h"
#include "particleGraphics.h"

using namespace std;

void die() {
  cout << "BAD INPUT\n";
//	exit(EXIT_FAILURE);
}	

// A - Stefanie
// Test default constructor
TEST(CellTest, DefaultConstructor) {
 // ParticleGraphics 2;
  Cell cell(2);
  //EXPECT_EQ(cell.getData(), 2);
  EXPECT_EQ(cell.getNext(), nullptr);
  EXPECT_EQ(cell.getPrev(), nullptr);
} 
  
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
  
  int main (int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
