#ifndef cpp_tst_priklad2_h
#define cpp_tst_priklad2_h

#include "TestSuite/Test.h"
#include "Guest.hpp"

// 4 body
class GuestTest: public TestSuite::Test{
private:
    // 2 bod
    /// Overte, ze pri vytvoreni objektu Guest se spravnymi parametry se nevyhodi vyjimka.
    void testValidParameters(){
        
    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Guest s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
        
    }
    
public:
    void run(){
        testValidParameters();
        testInvalidParameters();
    }
};
#endif
