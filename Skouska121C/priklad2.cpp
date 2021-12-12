#include "priklad2.h"

Objects::Object::Object(std::string name){
    m_name=name;
}

 std::string Objects::Object::getName(){
    return m_name;
 }

 void Objects::Object::whoAmI(){
    std::cout<<"volam sa:"<<getName()<<std::endl;
 }

Objects::WiredObject::WiredObject(std::string lineColor, std::string name):Object(name){
    m_lineColor=lineColor;
}

std::string Objects::WiredObject::getLineColor(){
    return m_lineColor;
}

void Objects::WiredObject::whoAmI(){
    std::cout<<"volam sa:"<<getName()<<std::endl;
    std::cout<<"farba linie"<<getLineColor()<<std::endl;
}

Objects::SolidObject::SolidObject(std::string fillColor, std::string lineColor, std::string name):WiredObject(lineColor,name){
    m_fillColor=fillColor;
}

std::string Objects::SolidObject::getFillColor(){
    return m_fillColor;
}

void Objects::SolidObject::whoAmI(){
    std::cout<<"volam sa:"<<getName()<<std::endl;
    std::cout<<"farba linie:"<<getLineColor()<<std::endl;
    std::cout<<"farba vyplne:"<<getFillColor()<<std::endl;
}

std::string Analyzer::analyzeColors(Objects::Object* someObject){
    Objects::SolidObject* test3;
    if (test3=dynamic_cast<Objects::SolidObject*>(someObject))
        return test3->getLineColor()+" "+test3->getFillColor();

    Objects::WiredObject* test2;
    if (test2=dynamic_cast<Objects::WiredObject*>(someObject))
        return test2->getLineColor();

    Objects::Object* test1;
    if (test1=dynamic_cast<Objects::Object*>(someObject))
        return "";
 }
