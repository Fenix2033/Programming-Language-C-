#ifndef TST_PRIKLAD1_H
#define TST_PRIKLAD1_H

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "priklad1.h"

/// Testy: 10 b
/// Oba testy ukazte na kratky prikladech napr. 3-5 volebnich listku
class TestPrikladu1:public TestSuite::Test{
public:

    /// otestujte, zda se povedlo vratit zaznamy daneho kandidata - 5 b
    void testCandidate(){
        BallotList ballot;
        std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam2/votes.txt";
        ballot.loadFile(fileName);
        test_(ballot.getBallotsCount(State::Invalid).empty() == false);
    }

    /// otestujte, zda se korektne vraci listky daneho typu - 5 b
    void testValid(){
            BallotList ballot;
            std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam2/votes.txt";
            ballot.loadFile(fileName);

            test_(ballot.getBallots(State::Invalid).empty() == false);
    }


     void run(){
         testCandidate();
         testValid();
    }
     

};
#endif // TST_PRIKLAD1_H
