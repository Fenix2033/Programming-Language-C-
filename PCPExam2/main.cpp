#include <iostream>
#include "priklad1.h"
#include "priklad2.h"

#include "tst_priklad1.h"

int main(int argc, const char * argv[])
{
    
    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new TestPrikladu1);

    BallotList ballot;
    std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam2/votes.txt";

//    Hero* artus = new Hero("Artus");
//    Weapon* sword = new Weapon("sword", 15);
//    Weapon* hammer = new Weapon("hammer", 35);
//    artus->addWeapon(*sword);
//    artus->addWeapon(*hammer);
//    artus->printWeapons();
//
//    delete artus;
//    tests.run();
//    tests.report();
//
    return 0;
}

