#ifndef cpp2011l_tst_priklad2_h
#define cpp2011l_tst_priklad2_h

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "priklad2.h"

class TestPrikladu2:public TestSuite::Test{
private:
    void testMetodyHasCorrectStructure(){
    
    }
    
    void testMetodyDecodePosition(){

    }
    
    void testMetodyIsDateEqual(){

    }
    
public:
    void run(){
        testMetodyHasCorrectStructure();
        testMetodyDecodePosition();
        testMetodyIsDateEqual();
    }
};
#endif
