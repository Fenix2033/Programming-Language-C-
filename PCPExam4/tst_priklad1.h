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

    }

    /// otestujte, zda se povedlo vratit map s nevyssimi teplotami - 5 b
    void testHighestTemperatures(){

    }


     void run(){
         testPressures();
         testHighestTemperatures();
    }
     

};
#endif // TST_PRIKLAD1_H
