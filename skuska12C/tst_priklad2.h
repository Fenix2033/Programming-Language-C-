#ifndef cpp2014_tst_priklad2_h
#define cpp2014_tst_priklad2_h

#include "priklad2.h"

class TestPrikladu2:public TestSuite::Test{
private:
    
    // otestujte, ze se korektne inicializuje obecny objekt (2 body)
    void object(){
        Objects::Object* objekt = new Objects::Object("objekt");

        test_(objekt->getName()=="objekt");
        delete objekt;
       
    }
    
    // otestujte, ze se korektne inicializuje drateny objekt (2 body)
    void wiredObject(){
        Objects::WiredObject* objekt = new Objects::WiredObject("lineColor","objekt");
        
        test_(objekt->getName()=="objekt");
        test_(objekt->getLineColor()=="lineColor");
        delete objekt;
    }
 
    
    // otestujte, ze se korektne inicializuje vyplneny objekt (2 body)
    void solidObject(){
        Objects::SolidObject* objekt = new Objects::SolidObject("solidColor","lineColor","objekt");
            
        test_(objekt->getName()=="objekt");
        test_(objekt->getLineColor()=="lineColor");
        test_(objekt->getFillColor()=="solidColor");
        delete objekt;
    }

    
    // otestujte, ze se korektne funguje analyzator, tj. vraci spravne retezce (4 body)
    void analyzer(){
    
            Objects::WiredObject* objekt = new Objects::WiredObject("lineColor","objekt");
            Analyzer analyze;
            test_(analyze.analyzeColors(objekt)==objekt->getName()+objekt->getLineColor());
            delete objekt;
            //delete &analyze;
    }
    
public:
    void run(){
        object();
        wiredObject();
        solidObject();
        analyzer();
    }
};
#endif
