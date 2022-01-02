#ifndef cpp_tst_priklad1_h
#define cpp_tst_priklad1_h

#include "TestSuite/Test.h"
#include "SkiResort.hpp"

// 12 bodu
/// U testu jednotlivych metod staci uvest pouze jeden
/// testovaci pripad. Jde o to ukazat myslenku testu.
/// V kazdem testu si nejprve pripravte studio s nejakymi lekcemi
/// a pak overte funkcnost dane metody.
class SkiResortTest: public TestSuite::Test{
public:
    // 4 body
    void testGetRatioOfCovidPositiveGuests(){
        Guest tomas (0, "Tomas", 15, "Covid19");
        Guest anna (1, "Anna", 20, "");
        SkiResort ski;
        ski.addGuest(tomas);
        ski.addGuest(anna);
        test_(ski.getRatioOfCovidPositiveGuests() == 50.0);
    }
    
    // 4 body
    void testGetSortedGuests(){
        Guest anna (1, "Anna", 20, "");
        Guest tomas (0, "Tomas", 15, "Covid19");
        SkiResort ski;
        ski.addGuest(anna);
        ski.addGuest(tomas);
        test_(ski.getSortedGuests().at(0).getName() == "Tomas");
    }
    
    // 4 body
    void testGetCountOfChildren() {
        Guest anna (1, "Anna", 20, "");
        Guest tomas (0, "Tomas", 15, "Covid19");
        SkiResort ski;
        ski.addGuest(anna);
        ski.addGuest(tomas);
        test_(ski.getCountOfChildren() == 1);
    }
    
    void run(){
        testGetRatioOfCovidPositiveGuests();
        testGetSortedGuests();
        testGetCountOfChildren();
    }
};

#endif
