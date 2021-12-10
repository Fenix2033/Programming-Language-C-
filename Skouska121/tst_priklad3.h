#ifndef cpp2011z_Header_h
#define cpp2011z_Header_h
#include "priklad3.h"

class TestPrikladu3:public TestSuite::Test{
    
private:
    
    void skladovyList(){
        SkladovyList testList(12345);
        test_(testList.getInventarniCislo() == 12345);
        testList.setInventarniCislo(23456);
        test_(testList.getInventarniCislo() == 23456);    
    }
    
    void zbozi(){
        Zbozi testZbozi("popis s vice slovy", 12345);
        test_(testZbozi.getPopis() == "popis s vice slovy");
        test_(testZbozi.getInventarniCislo() == 12345);
        testZbozi.setInventarniCislo(33333);
        test_(testZbozi.getInventarniCislo() == 33333);
    }

    void zboziKopie(){
        Zbozi testZbozi("popis s vice slovy", 12345);
        Zbozi testZboziKopie(testZbozi);
        // menim hodnotu v puvodni verzi
        testZbozi.setInventarniCislo(666);
        // kopie ma byt samostatna, nezmenena
        test_(testZboziKopie.getInventarniCislo() == 12345);    
    }

    
public:
    void run(){
        skladovyList();
        zbozi();
        zboziKopie();
    }
};

#endif
