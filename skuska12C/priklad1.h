#ifndef cpp2014_priklad1_h
#define cpp2014_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

// celkem 27 bodu + 10 bodu za testy =  37 bodu

/// jeden zaznam o mereni teploty
struct StationRecord{
    std::string place;  ///< jmeno mista mereni
    float value;        ///< honota mereni
    int x;              ///< souradnice x mereneho mista
    int y;              ///< souradnice y mereneho mista
};

/// definice oblasti, hodnoty popisuje levy horni a pravy dolni roh obdelniku
struct Area{
    int minX;
    int minY;
    int maxX;
    int maxY;
};

class Records{
private:
    /// seznam vsech mereni
    std::vector<StationRecord> m_records;
    
public:
    int getRecordsAmount();
    void addRecord(StationRecord record);    
    void loadRecordsFromTextFile(std::string fileName) throw (std::domain_error);    
    int getRecordsAmountFromStation(std::string place);    
    std::vector<StationRecord> getRecordValuesFromLocation(Area area) throw (std::range_error);
    void deleteRecordsFromStation(std::string place);    
};

#endif
