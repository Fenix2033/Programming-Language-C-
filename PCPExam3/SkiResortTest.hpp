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
        
    }
    
    // 4 body
    void testGetSortedGuests(){
        
    }
    
    // 4 body
    void testGetCountOfChildren() {
        
    }
    
    void run(){
        testGetRatioOfCovidPositiveGuests();
        testGetSortedGuests();
        testGetCountOfChildren();
    }
};

#endif
