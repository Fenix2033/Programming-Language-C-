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
        try {
            Guest guest(0, "Tomas", 80, "Covid19");
            test_("Valid argument");
        } catch (std::invalid_argument){
            fail_("Invalid argument");
        }


    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Guest s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
        try {
            Guest guest(-5, "", 0, "Covid19");
            fail_("Invalid argument");
        } catch (std::invalid_argument){
            test_("Valid argument");
        }
    }
    
public:
    void run(){
        testValidParameters();
        testInvalidParameters();
    }
};
#endif
