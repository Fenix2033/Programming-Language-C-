#ifndef cpp2011z_priklad1_h
#define cpp2011z_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

/**
 * Trida vyuzivana pro ukladani informaci, konstruktor uklada do atributu
 */
class StationRecord{
public:
    std::string m_place;
    int m_x;
    int m_y;
    float m_value;

    StationRecord(std::string place, int x, int y, float value);
};

/**
 * Trida vyuzivana algoritmem pro scitani stanic se specifickym nazvem
 * ulozenym v konstruktoru
 */
class StationCount{
private:
    std::string m_stationName;
public:
    StationCount(std::string stationName);
    bool operator()(StationRecord& rec);
};

/**
 * Trida vyuzivana algoritmem for_each pro vypsani informaci na obrazovku
 */
class PrintRecord{
public:
    void operator()(StationRecord& rec);
};

/**
 * Trida obsahujici zaznamy o merenich
 */
class Records{
private:
    std::vector<StationRecord> m_records;

public:
    /// Metoda vracejici pocet zaznamu ve vectoru
    int getRecordsAmount();
    /// Metoda pridavajici nove mereni do vectoru
    void addRecord(StationRecord record);
    /// Metoda nacitajici mereni ze souboru s danym jmenem, pri spatnem jmene vyhozena vyjimka
    void loadRecordsFromTextFile(std::string fileName) throw (std::domain_error);
    /// Vraci pomoci algoritmu pocet mereni ze stanice s danym jmenem
    int getRecordsAmountFromStation(std::string place);
    /// Vraci zaznam ulozeny pod danym indexem, pokud dany zaznam neexistuje vyhazuje se vyjimka
    StationRecord getRecordValues(int index) throw (std::range_error);
    /// Smaze zaznamy z dane stanice
    void deleteRecordsFromStation(std::string place);
    /// Vypise pomoci algorimu vsechny zaznamy na obrazovku
    void printRecords();
};

#endif
