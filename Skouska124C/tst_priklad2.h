#ifndef cpp2011z_tst_priklad2_h
#define cpp2011z_tst_priklad2_h

#include "priklad2.h"

class TestPrikladu2:public TestSuite::Test{
private:
    
    void testAnalyze(){
        Analyzer pokus;
        test_(pokus.isIntrusion(new SecurityIS::Event("A1")) == false);
        test_(pokus.isIntrusion(new SecurityIS::ErrorEvent("A1", "lowbattery")) == false);
        test_(pokus.isIntrusion(new SecurityIS::IntrusionEvent("A1", "break")) == true);
    }
    
public:
    void run(){
        testAnalyze();
    }
};
#endif
