#ifndef cpp2011z_tst_priklad2_h
#define cpp2011z_tst_priklad2_h

#include "priklad2.h"

class TestPrikladu2:public TestSuite::Test{
private:
    
    void object(){
        Objects::Object testObj("koule");        
        test_(testObj.getName() == "koule");
    }
    
    void wiredObject(){
        Objects::WiredObject testObj("red", "dratena koule");        
        test_(testObj.getName() == "dratena koule");
        test_(testObj.getLineColor() == "red");
    }
 
    void solidObject(){
        Objects::SolidObject testObj("blue", "red", "dratena koule");        
        test_(testObj.getName() == "dratena koule");
        test_(testObj.getLineColor() == "red");
        test_(testObj.getFillColor() == "blue");
    }
    
    void analyzer(){
        Analyzer testAnalyzer;
        Objects::Object* testA = new Objects::Object("A");
        Objects::WiredObject* testB = new Objects::WiredObject("red", "A");
        Objects::SolidObject* testC = new Objects::SolidObject("green", "red", "A");

        test_(testAnalyzer.analyzeColors(testA) == "");
        //test_(testAnalyzer.analyzeColors(testB) == "red");
        //test_(testAnalyzer.analyzeColors(testC) == "red green");
        
        delete testA;
        delete testB;
        delete testC;
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
