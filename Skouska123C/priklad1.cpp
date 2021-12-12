#include "priklad1.h"

Event::Event(std::string area, std::string typeOfProblem, float length){
    m_area=area;
    m_typeOfProblem=typeOfProblem;
    m_length=length;
}

/// nahraje ulozene udalosti ze skouboru,
/// pokud je zadano spatne jmeno, vyhodi vyjimku - 9 bodu
void BezpecnostniIS::loadImageFromTextFile(std::string fileName) throw (std::domain_error){
    std::ifstream in(fileName.c_str());
    if(in.is_open()){
        std::string area;   std::string typeOfProblem;  float length;   int datum;
        while(in>>datum and in>>area and in>>typeOfProblem and in>>length){
            m_events.insert(std::pair<long,Event>(datum,Event(area,typeOfProblem,length)));
        }
        in.close();
    }else
        throw std::domain_error("nejde otvorit subor");
}

/// vrati pocet bezpecnostnich zaznamu, ktere odpovidaji danemu typu (typeOfProblem) - 5 b
int BezpecnostniIS::getNumberOfEvents(std::string typeOfProblem){
    int pocet=0;
    for(std::map<long,Event>::iterator it=m_events.begin();it!=m_events.end();it++){
        if(it->second.m_typeOfProblem==typeOfProblem) pocet++;
    }
    return pocet;
}

/// vymaze veskere bezpecnostni udalosti pred zvolenym datumem - 5 b
void BezpecnostniIS::eraseBefore(long timeStamp){
    for(std::map<long,Event>::iterator it=m_events.begin();it!=m_events.end();it++){
        if(it->first<timeStamp) it=m_events.erase(it);
    }
}

/// vypise veskere udalosti zvoleneho typu - 5 b
void BezpecnostniIS::printEvents(std::string typeOfProblem){
    for(std::map<long,Event>::iterator it=m_events.begin();it!=m_events.end();it++){
        if(it->second.m_typeOfProblem==typeOfProblem){
            std::cout<<"Datum: "<<it->first<<std::endl;
            std::cout<<"oblast: "<<it->second.m_area<<std::endl;
            std::cout<<"typ problemu: "<<it->second.m_typeOfProblem<<std::endl;
            std::cout<<"dlzka: "<<it->second.m_length<<std::endl;
        }
    }
}

/// vrati casove razitko posledni udalosti ve zvolene lokaci,
/// 0 pokud zaznam z lokace neni - 5 b
long BezpecnostniIS::findLastEventinArea(std::string area){
    long datum=0;
    for(std::map<long,Event>::iterator it=m_events.begin();it!=m_events.end();it++){
        if(it->second.m_area==area){
            datum=it->first;
        }
    }
    return datum;
}
