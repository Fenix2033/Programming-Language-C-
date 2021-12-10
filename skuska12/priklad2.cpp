#include "priklad2.h"


Objects::Object::Object(std::string name){
    m_name = name;
}

std::string Objects::Object::getName(){
    return m_name;
}

void Objects::Object::whoAmI(){
    std::cout << "General object" << std::endl;
}

Objects::WiredObject::WiredObject(std::string lineColor, std::string name):Object(name){
    m_lineColor = lineColor;
}

std::string Objects::WiredObject::getLineColor(){
    return m_lineColor;
}

void Objects::WiredObject::whoAmI(){
    std::cout << "Wired object" << std::endl;
}

Objects::SolidObject::SolidObject(std::string fillColor, std::string lineColor, std::string name):WiredObject(lineColor, name){
    m_fillColor = fillColor;
}

std::string Objects::SolidObject::getFillColor(){
    return m_fillColor;
}

void Objects::SolidObject::whoAmI(){
    std::cout << "Solid object" << std::endl;
}


std::string Analyzer::analyzeColors(Objects::Object* someObject){
    std::string retazec;
    Objects::SolidObject* pomSolid=new Objects::SolidObject("fillcolor","linecolor","name");
    Objects::WiredObject* wirPom=new Objects::WiredObject("lineColor","name");
    
    if(pomSolid = dynamic_cast<Objects::SolidObject*>(someObject)){
        retazec = pomSolid->getName() + pomSolid->getFillColor() + pomSolid->getLineColor();
    }else if (wirPom = dynamic_cast<Objects::WiredObject*>(someObject)){
        retazec = wirPom->getName()  + wirPom->getLineColor();
    }else{
        retazec = someObject->getName();
    }
    
    return retazec;
}
