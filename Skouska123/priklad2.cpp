#include "priklad2.h"


SecurityIS::Event::Event(std::string area){
    m_area=area;
}

std::string SecurityIS::Event::getArea(){
    return m_area;
}

/// vypise oblast udalosti
void SecurityIS::Event::getInfo(){
    std::cout<<"oblast: "<<m_area<<std::endl;
}

SecurityIS::ErrorEvent::ErrorEvent(std::string area, std::string typeOfError):Event(area){
    m_typeOfError=typeOfError;
}


std::string SecurityIS::ErrorEvent::getTypeOfError(){
    return m_typeOfError;
}

/// vypise oblast a typ chyby
void SecurityIS::ErrorEvent::getInfo(){
    std::cout<<"oblast: "<<m_area<<std::endl;
    std::cout<<"typ chyby: "<<m_typeOfError<<std::endl;
}

SecurityIS::IntrusionEvent::IntrusionEvent(std::string area, std::string typeOfIntrusion):Event(area){
    m_typeOfIntrusion=typeOfIntrusion;
}


std::string SecurityIS::IntrusionEvent::getTypeOfIntrusion(){
    return m_typeOfIntrusion;
}

/// vypise oblast a typ chyby
void SecurityIS::IntrusionEvent::getInfo(){
    std::cout<<"oblast: "<<m_area<<std::endl;
    std::cout<<"typ chyby: "<<m_typeOfIntrusion<<std::endl;
}

bool Analyzer::isIntrusion(SecurityIS::Event* securityEvent){
    bool narusenie=false;
    SecurityIS::IntrusionEvent* instrusionEvent=0;
    if(instrusionEvent=dynamic_cast<SecurityIS::IntrusionEvent*>(securityEvent)) narusenie=true;
    return narusenie;
}
