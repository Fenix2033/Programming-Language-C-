#ifndef cpp2014_tst_priklad1_h
#define cpp2014_tst_priklad1_h

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "priklad1.h"

class TestPrikladu1:public TestSuite::Test{
public:
    /// metoda otestuje, zda se spravne vraci stanice z dane lokace (5 bodu)
    void stationCount(){
        Records test;
        StationRecord novy;
        StationRecord novy2;
        StationRecord novy3;
        novy.place = "Brno";
        novy.value = 10;
        novy2.place = "Brno";
        novy2.value = 15;
        novy3.place = "Praha";
        novy3.value = 20;
        test.addRecord(novy);
        test.addRecord(novy2);
        test.addRecord(novy3);
        test_(test.getRecordsAmountFromStation("Brno")==25);
        /*
        delete &test;
        delete &novy;
        delete &novy2;
        delete &novy3;
        */
        
    }
    
    /// metoda otestuje, zda se spravne nactou zaznamy ze souboru (5 bodu)
    void records(){
        Records test;
        try {
            test.loadRecordsFromTextFile("neexistuje.nottxt");
            fail_("nacetlo neexistujici soubor");
        } catch (std::domain_error) {
            succeed_();
        }
        
    }
    
    void run(){
        stationCount();
        records();
    }
};

#endif

