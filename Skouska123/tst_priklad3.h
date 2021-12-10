#ifndef cpp2011z_tst_priklad3_h
#define cpp2011z_tst_priklad3_h

#include "priklad3.h"

class TestPrikladu3:public TestSuite::Test{
private:
    void testSize(){
        Strings pokus("David jede. Mama mele. Jana ji maso sama.");
        test_(pokus.getNumberOfSenteces() == 3);
    }

    void testLongest(){
        Strings pokus("David jede. Mama mele. Jana ji maso sama.");
        test_(pokus.getLongestSentence() == "Jana ji maso sama.");
    }

public:
    void run(){
        testSize();
        testLongest();
    }
};
#endif
