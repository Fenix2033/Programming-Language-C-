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
//        Guest guest(0, "Tomas", 80, "Covid19");
//        test_(guest.getID() == 0);
//        test_(guest.getName() == "Tomas");
//        test_(guest.getAge(80) == 80);
//        test_(guest.getDoctorMessage("Covid19") == true);
    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Guest s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
//        Guest guest(-1, "", 0, "19");
//        test_(guest.getID() == 0);
//        test_(guest.getName() == "A");
//        test_(guest.getAge(0) == 1);
//        test_(guest.getDoctorMessage("19") == true);
    }
    
public:
    void run(){
        testValidParameters();
        testInvalidParameters();
    }
};
#endif
