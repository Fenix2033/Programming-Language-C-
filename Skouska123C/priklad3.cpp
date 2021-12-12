#include "priklad3.h"

/// Konstruktor prevezme predany text a rozdeli jej po vetach do vectoru - 10 bodu
/// Kazda veta konci teckou. Tj. Mama mele maso. Jan ma kolo. bude rozdeleno na dva zaznamy
Strings::Strings(std::string input){
    std::string veta="";
    int zaciatok=0; int koniec=0;

    while(koniec<input.length()){
        koniec=input.find_first_of(".",zaciatok);
        koniec+=1;
        veta=input.substr(zaciatok,koniec-zaciatok);
        m_sentences.push_back(veta);
        zaciatok=koniec+1;
    }
}

/// vraci pocet vet - 3 body
int Strings::getNumberOfSenteces(){
    return m_sentences.size();
}

/// vrati nejdelsi vetu nebo prazdny retezec, pokud je vektor prazdny - 7 bodu
std::string Strings::getLongestSentence(){
    std::string najdlhsiaVeta="";
    std::string pom="";
    for(int i=0; i<m_sentences.size()-1;i++){
        if(m_sentences.at(i).length() > m_sentences.at(i+1).length()){
            pom=m_sentences.at(i);
        }else if(m_sentences.at(i).length() < m_sentences.at(i+1).length()){
            pom=m_sentences.at(i+1);
        }else{
            //co ak su rovnake :D
        }
        if(pom>najdlhsiaVeta) najdlhsiaVeta=pom;
    }
    return najdlhsiaVeta;
}
