#ifndef cpp2011z_tst_priklad1_h
#define cpp2011z_tst_priklad1_h

#include "TestSuite/Test.h"
#include "priklad1.h"

class TestPrikladu1:public TestSuite::Test{
public:

    void testFile(){
        BezpecnostniIS pokus;
        try {
            pokus.loadImageFromTextFile("blbe");
            fail_("Nevyhazuje vyjimku pri otevreni chybneho souboru");
        } catch (std::domain_error &err){
            succeed_();
        }

        try {
            pokus.loadImageFromTextFile("udalosti.txt");
            test_(pokus.getNumberOfEvents("intrusion") == 4);
        } catch (std::domain_error &err) {
            std::cerr << "Pozor spatne nacitate ze souboru!!!" << std::endl;
        }
    }

    void testErase(){
        BezpecnostniIS pokus;
        pokus.loadImageFromTextFile("udalosti.txt");
        pokus.eraseBefore(20110101);
        test_(pokus.getNumberOfEvents("intrusion") == 3);

    }

    void testLast(){
        BezpecnostniIS pokus;
        pokus.loadImageFromTextFile("udalosti.txt");
        test_(pokus.findLastEventinArea("Q1") == 20121012);
    }


    void run(){
        testFile();
        testErase();
        testLast();
    }
};

#endif
