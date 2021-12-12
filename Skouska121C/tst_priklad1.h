#ifndef cpp2011z_tst_priklad1_h
#define cpp2011z_tst_priklad1_h

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "priklad1.h"

class TestPrikladu1:public TestSuite::Test{
public:
    void stationCount(){
        StationRecord testRecord("lokace",1,2,3.5);
        test_(testRecord.m_place == "lokace");
        test_(testRecord.m_x == 1);
        test_(testRecord.m_y == 2);
        test_(testRecord.m_value == 3.5);    
    }
    
    void records(){
        Records testRecords;
        testRecords.addRecord(StationRecord("lokace1",1,2,1.0));
        testRecords.addRecord(StationRecord("lokace2",3,4,2.0));
        testRecords.addRecord(StationRecord("lokace3",5,6,3.0));
        testRecords.addRecord(StationRecord("lokace3",7,8,4.0));
        
        test_(testRecords.getRecordsAmount() == 4);
        test_(testRecords.getRecordsAmountFromStation("lokace3") == 2);
        
        StationRecord tmpRecord = testRecords.getRecordValues(0); 
        test_(tmpRecord.m_place == "lokace1");
        test_(tmpRecord.m_x == 1);
        test_(tmpRecord.m_y == 2);
        test_(tmpRecord.m_value == 1.0);
        
        try{
            testRecords.getRecordValues(10);
            fail_("Nevyhozena vyjimka u spatne lokace");
        } catch(...){ 
            succeed_();
        }
        
        testRecords.deleteRecordsFromStation("lokace3");
        test_(testRecords.getRecordsAmount() == 2);
        test_(testRecords.getRecordsAmountFromStation("lokace3") == 0);
        
        try{
            testRecords.loadRecordsFromTextFile("neexistuje.txt");   
            fail_("Nevyhozena vyjimka neexistujiciho souboru");
        } catch(...){
            succeed_();
        }
        
        Records fileRecords;
        fileRecords.loadRecordsFromTextFile("lokace.txt");  
        test_(fileRecords.getRecordsAmount() == 66);
    }
    
    void run(){
        stationCount();
        records();
    }
};

#endif
