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
        try{
            test_(ballot.getBallotsCount(State::Invalid).empty() == false);
        } catch (std::length_error){
//            fail_("Not empty");
//            succeed_();
        }
    }

    /// otestujte, zda se korektne vraci listky daneho typu - 5 b
    void testValid(){
            BallotList ballot;
            std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam2/votes.txt";
            ballot.loadFile(fileName);
            try {
                test_(ballot.getBallots(State::Invalid).empty() == false);
            } catch (std::invalid_argument){
                //            fail_("Not empty");
                //            succeed_();
            }
    }


     void run(){
         testCandidate();
         testValid();
    }
     

};
#endif // TST_PRIKLAD1_H
