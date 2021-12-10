#include "priklad2.h"

UIS::Student::Student(std::string name){
    m_name=name;
}
std::string UIS::Student::getName(){
    return m_name;
}

void UIS::Student::whoAmI(){
    std::cout<<"Som obycajny student"<<std::endl;
}

UIS::RozvolnenyStudent::RozvolnenyStudent(std::string m_datumRozvolneni, std::string name):Student(name){
    this->m_datumRozvolneni=m_datumRozvolneni;
}

std::string UIS::RozvolnenyStudent::getDatumRozvolneni(){
    return m_datumRozvolneni;
}

void UIS::RozvolnenyStudent::whoAmI(){
    std::cout<<"Som rozvolneny student"<<std::endl;
}

UIS::NeuspesneUkoncenyStudent::NeuspesneUkoncenyStudent(std::string datumUkonceni, std::string datumRozvolneni, std::string name):RozvolnenyStudent(datumRozvolneni,name){
    m_datumUkonceni=datumUkonceni;
}

std::string UIS::NeuspesneUkoncenyStudent::getDatumUkonceni(){
    return m_datumUkonceni;
}

void UIS::NeuspesneUkoncenyStudent::whoAmI(){
    std::cout<<"Som neuspesne ukonceny student"<<std::endl;
}

std::string StudentAnalyzer::analyzeStudent(UIS::Student* someStudent){
    std::string result="";

    UIS::RozvolnenyStudent* rozvolneny = 0;
    UIS::NeuspesneUkoncenyStudent* ukonceny = 0;

    if (ukonceny = dynamic_cast<UIS::NeuspesneUkoncenyStudent*>(someStudent)){
        result = ukonceny->getName()+" "+ukonceny->getDatumRozvolneni()+" "+ukonceny->getDatumUkonceni();
    } else if(rozvolneny = dynamic_cast<UIS::RozvolnenyStudent*>(someStudent)){
        result = rozvolneny->getName()+" "+rozvolneny->getDatumRozvolneni();
    } else {
        result = someStudent->getName();
    }

    return result;
}
