#ifndef cpp_tst_priklad1_h
#define cpp_tst_priklad1_h

#include "TestSuite/Test.h"
#include "YogaStudio.hpp"

// 12 bodu
/// U testu jednotlivych metod staci uvest pouze jeden
/// testovaci pripad. Jde o to ukazat myslenku testu.
/// V kazdem testu si nejprve pripravte studio s nejakymi lekcemi
/// a pak overte funkcnost dane metody.
class YogaStudioTest:public TestSuite::Test{
public:
    // 4 body
    void testGetEmptyLessons(){
        
    }
    
    // 4 body
    void testGetLessonsWithDurationInRange(){
        
    }
    
    // 4 body
    void testGetRatioOfManAndWoman() {
        
    }
    
    void run(){
        testGetEmptyLessons();
        testGetLessonsWithDurationInRange();
        testGetRatioOfManAndWoman();
    }
};

#endif
