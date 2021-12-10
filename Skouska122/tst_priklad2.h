#ifndef cpp2011z_tst_priklad2_h
#define cpp2011z_tst_priklad2_h

#include "priklad2.h"

class TestPrikladu2:public TestSuite::Test{
private:
    
    void student(){
        UIS::Student testStud("Karel");        
        test_(testStud.getName() == "Karel");
    }
    
    void rozvolnenyStudent(){
        UIS::RozvolnenyStudent testObj("1.1.2011", "Pepa");        
        test_(testObj.getName() == "Pepa");
        test_(testObj.getDatumRozvolneni() == "1.1.2011");
    }
 
    void ukoncenyStudent(){
        UIS::NeuspesneUkoncenyStudent testObj("1.2.2012", "1.1.2011", "Josef");        
        test_(testObj.getName() == "Josef");
        test_(testObj.getDatumRozvolneni() == "1.1.2011");
        test_(testObj.getDatumUkonceni() == "1.2.2012");
    }
    
    void analyzer(){
        StudentAnalyzer testAnalyzer;
        UIS::Student* testA = new UIS::Student("Karel");
        UIS::RozvolnenyStudent* testB = new UIS::RozvolnenyStudent("1.1.2011", "Pepa");
        UIS::NeuspesneUkoncenyStudent* testC = new UIS::NeuspesneUkoncenyStudent("1.1.2012", "1.1.2011", "Jan");

        test_(testAnalyzer.analyzeStudent(testA) == "Karel");
        test_(testAnalyzer.analyzeStudent(testB) == "Pepa 1.1.2011");
        test_(testAnalyzer.analyzeStudent(testC) == "Jan 1.1.2011 1.1.2012");
        
        delete testA;
        delete testB;
        delete testC;
    }
    
public:
    void run(){
        student();
        rozvolnenyStudent();
        ukoncenyStudent();
        analyzer();
    }
};
#endif
