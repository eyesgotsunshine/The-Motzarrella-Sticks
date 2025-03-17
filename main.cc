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

using namespace std;

void die() {
  cout << "BAD INPUT\n";
//	exit(EXIT_FAILURE);
}	

// A - Stefanie
// Test default constructor
TEST(CellTest, DefaultConstructor) {
  Cell cell;
  EXPECT_EQ(cell.getData(), nullptr);
  EXPECT_EQ(cell.getNext(), nullptr);
  EXPECT_EQ(cell.getPrev(), nullptr);
}
  
// B - Terry
//TEST
  
// C - Evan
//TEST
  
// D - Mark 
//TEST
  
  int main (int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }