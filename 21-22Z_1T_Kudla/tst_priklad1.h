#ifndef TST_PRIKLAD1_H
#define TST_PRIKLAD1_H

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "priklad1.h"

/// Testy: 10 b
/// Oba testy ukazte na kratky prikladech napr. 3-5 volebnich listku
class TestPrikladu1:public TestSuite::Test{
public:
    /// otestujte, zda se povedlo vratit spravnou vysledkovou listinu podle vzoroveho souboru - 5 b
    void testResults(){
        BallotList ballot;
        std::map<Candidate, long> test;
        test = ballot.getBallotsCount();
        try {
            test_(test.empty() == false);
        } catch (std::invalid_argument){
            fail_("Invalid argument");
            succeed_();
        }


    }

    /// otestujte, zda se korektne vraci validni listky daneho typu z daneho regionu - 5 b
    void testValidBallotsFromRegion(){
            BallotList ballot;
            std::vector<Ballot> test;
            test = ballot.getBallots(State::Faked, "Plzensky kraj");
            try {
                test_(test.size() == 5);
            } catch (std::length_error){
                fail_("Lenght error");
                succeed_();
            }
    }

    void run(){
        testResults();
        testValidBallotsFromRegion();
    }
};
#endif // TST_PRIKLAD1_H
