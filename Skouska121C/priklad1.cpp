#include "priklad1.h"
StationRecord::StationRecord(std::string place, int x, int y, float value){
    m_place=place;
    m_x=x;
    m_y=y;
    m_value=value;
}

StationCount::StationCount(std::string stationName){
    m_stationName=stationName;
}

bool StationCount::operator()(StationRecord& rec){

}

void PrintRecord::operator()(StationRecord& rec){

}

int Records::getRecordsAmount(){
    return m_records.size();
}

void Records::addRecord(StationRecord record){
    m_records.push_back(record);
}

void Records::loadRecordsFromTextFile(std::string fileName) throw (std::domain_error){
    std::string place;
    int x;
    int y;
    float value;
    std::ifstream in(fileName.c_str());
    if(in.is_open()){
        while(in.peek()!=EOF){
            in>>place>>x>>y>>value;
            m_records.push_back(StationRecord(place,x,y,value));
        }
        in.close();
    }else{
        throw std::domain_error("zly nazov suboru");
    }
}

int Records::getRecordsAmountFromStation(std::string place){
    for(int i=0;i<m_records.size();i++){
       // if(m_records[i].)
    }
}

StationRecord Records::getRecordValues(int index) throw (std::range_error){

}

void Records::deleteRecordsFromStation(std::string place){

}

void Records::printRecords(){

}
