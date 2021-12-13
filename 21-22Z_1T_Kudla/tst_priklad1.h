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
        try {
            test_(ballot.getBallotsCount().empty() == false);
        } catch (std::invalid_argument){
            fail_("Invalid argument");
            succeed_();
        }

        std::map<Candidate, long> test;
        test = ballot.getBallotsCount();

//        for(std::map<Candidate, long>::iterator it = test.begin(); it != test.end(); it++){
//            test_(it->second == 0);
//        }
    }

    /// otestujte, zda se korektne vraci validni listky daneho typu z daneho regionu - 5 b
    void testValidBallotsFromRegion(){
            BallotList ballot;
            std::vector<Ballot> test;
            test = ballot.getBallots(State::Faked, "Plzensky kraj");
            try {
                test_(test.empty() == true);
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
