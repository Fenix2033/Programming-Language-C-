#ifndef TST_PRIKLAD1_H
#define TST_PRIKLAD1_H

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "priklad1.h"

/// Testy: 10 b
/// Oba testy ukazte na prikladu mereni ze souboru pisemky
class TestPrikladu1:public TestSuite::Test{
public:

    /// otestujte, zda se povedlo vratit seznam mereni z daneho mista minimalne s danym tlakem - 5 b
    void testPressures(){
        BallotList ballot;
        test_(ballot.getBallotsFromPlace("BRNO", 120).at(0).temperature == 13.5);
    }

    /// otestujte, zda se povedlo vratit map s nevyssimi teplotami - 5 b
    void testHighestTemperatures(){
        BallotList ballot;
        std::map<std::string, StationMeasurent> map = ballot.getHighestTemperatures();
        std::map<std::string, StationMeasurent>::iterator it = map.begin();
        test_(it->first == "BRNO" and it->second.temperature == 14.5);
        it++;
        test_(it->first == "OSTRAVA" and it->second.temperature == 14.5);
        it++;
        test_(it->first == "PRAGUE" and it->second.temperature == 15.5);
    }


     void run(){
         testPressures();
         testHighestTemperatures();
    }
     

};
#endif // TST_PRIKLAD1_H
