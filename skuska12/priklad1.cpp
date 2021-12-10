#include "priklad1.h"

/// Metoda vrati pocet zaznamu v seznamu (2 body)
int Records::getRecordsAmount(){
    
    return m_records.size();
}

/// Metoda prida novy zaznam do seznamu mereni (2 body)
void Records::addRecord(StationRecord record){
    m_records.push_back(record);
}

/// Metoda nacte zaznamy ze soubouru. Pokud soubor neexistuje, vyhodi se vyjimka.
/// Soubor ma strukturu: oznaceni lokace, jeji x a y pozice a ukladana hodnota mereni
/// (8 bodu)
void Records::loadRecordsFromTextFile(std::string fileName) throw (std::domain_error){
    std::ifstream in(fileName);
    if (in.is_open()){
        std::string lokace;
        int pozX;
        int pozY;
        int hodnota;
        while (in.peek()!=EOF) {
            in >> lokace >> pozX >> pozY >> hodnota;
            StationRecord novy;
            novy.value=hodnota;
            novy.x=pozX;
            novy.y=pozY;
            novy.place=lokace;
            m_records.push_back(novy);
        }
        
        
    }else{
        throw std::domain_error("soubor neotevren");
    }
    in.close();
}

/// Metoda vrati soucet zaznamenanych hodnot ze vsech mereni dane stanice.
/// Pouzijte pro pruchod a soucet algoritmus s lambda vyrazem (5 bodu)
int Records::getRecordsAmountFromStation(std::string place){
    int hodnota=0;
    for_each(m_records.begin(),m_records.end(),[=, &hodnota](StationRecord i)->void{
        if(i.place==place){
        hodnota = hodnota + i.value;
        }
    });
    return hodnota;
}

/// Vrati vsechny zaznamy z dane oblasti. Pokud oblast neobsahuje zadne zaznamy,
/// je vyhozena vyjimka (5 bodu)
std::vector<StationRecord> Records::getRecordValuesFromLocation(Area area) throw (std::range_error){
    std::vector<StationRecord> novyVektor;
    for_each(m_records.begin(),m_records.end(),[=,&novyVektor](StationRecord i)->void
             {
                 if (i.x>area.minX && i.x<area.maxX && i.y>area.minY && i.y<area.maxY) {
                     novyVektor.push_back(i);
                 }
             });
    if (novyVektor.size()==0){
        throw std::range_error("out of area");
    }
    return novyVektor;
}

/// Metoda smaze vsechny zaznamy z dane stanice (5 bodu)
void Records::deleteRecordsFromStation(std::string place){
    m_records.erase(m_records.begin(), m_records.end());
}
