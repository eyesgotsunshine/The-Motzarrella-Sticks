#include <iostream>
#include "particleSys.h"
#include <gtest/gtest.h>
using namespace std;

/////////
//INTRO//
/////////

// WELCOME TO THE particleSys.h DRIVER!!!
// This is a simple seperate .cc file that is used for testing the particleSys header file
// This file is not important to the function of this project and doesn't need to be included or compiled with any of the main files for this project

////////////////
//TESTING MAIN//
////////////////

TEST(BasicsTest, RowsAndColumnsGetters) {
	particleSystem tester(5, 10);
    EXPECT_EQ(tester.get_columns(), 5);
    EXPECT_EQ(tester.get_rows(), 10);
    EXPECT_EQ(tester.get_particleCount(), 0);
}

TEST(BasicsTest, RowsAndColumnsSetters) {	
	particleSystem tester(5, 10);
	tester.set_columns(22);
	tester.set_rows(33);
	tester.set_particleCount(44);
    EXPECT_EQ(tester.get_columns(), 22);
    EXPECT_EQ(tester.get_rows(), 33);
    EXPECT_EQ(tester.get_particleCount(), 44);
}

TEST(BasicsTest, Methods) {
    particleSystem tester(5, 10);
	EXPECT_EQ(tester.addParticle(6), 6);
    EXPECT_EQ(tester.numParticles(), tester.get_particleCount());
    EXPECT_EQ(tester.moveParticles(), "stub");
	EXPECT_EQ(tester.drawParticles(), "stub");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//Original Test Driver:

/*
int main(){
	particleSystem tester(5, 10);
	
	cout << "Tester columns should be 5, they are: " << tester.get_columns() << endl;
	cout << "Tester rows should be 10, they are: " << tester.get_rows() << endl;
	cout << "Tester particleCount should be 0, it is: " << tester.get_particleCount() << endl;

	cout << endl;
	cout << "Now we are setting tester to 22, 33, and 44:" << endl;
	cout << endl;

	tester.set_columns(22);
	tester.set_rows(33);
	tester.set_particleCount(44);

	cout << "Tester columns should now be 22, they are: " << tester.get_columns() << endl;
	cout << "Tester rows should now be 33, they are: " << tester.get_rows() << endl;
	cout << "Tester particleCount should now be 44, it is: " << tester.get_particleCount() << endl;

	cout << endl;
	cout << "Now we are going to test the class methods:" << endl;
	cout << endl;

	cout << "Add Particle should be 6" << endl;
	tester.addParticle(6);
	tester.numParticles();
	tester.moveParticles();
	tester.drawParticles();
}
*/





