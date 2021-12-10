#ifndef cpp2011z_priklad2_h
#define cpp2011z_priklad2_h

#include <iostream>

namespace UIS {
    
    /// zakladni typ studenta v infor. systemu
    class Student{
    protected:
        std::string m_name;
    public:
        Student(std::string name);        
        std::string getName(); 
        /// vypise na obrazovku vetu ve smyslu jsem obecny student
        virtual void whoAmI();
    };

    /// potomek studenta, specialni typ, ktery je navic rozvolneny
    /// konstruktory, getry a setry se chovaji jako obvykle
    class RozvolnenyStudent:public Student{
    protected:
        std::string m_datumRozvolneni;
    public:
        RozvolnenyStudent(std::string m_datumRozvolneni, std::string name);        
        std::string getDatumRozvolneni(); 
        /// opet vypise hlasku ve typu jsem rozvolneny student
        virtual void whoAmI();
    };

    /// opet rozsireni studenta, metody se chovaji jako obvykle
    class NeuspesneUkoncenyStudent:public RozvolnenyStudent{
    protected:
        std::string m_datumUkonceni;
    public:
        NeuspesneUkoncenyStudent(std::string datumUkonceni, std::string datumRozvolneni, std::string name);
        std::string getDatumUkonceni();        
        virtual void whoAmI();
    };
}

/**
 * Analyzator obdrzi instanci tridy student nebo jejich potomku. 
 * Na zaklade toho, co byla za instanci predano se vraci nasledujici text
 * a) Obecny student: pouze jmeno ("Karel")
 * b) Rozvolneny st.: jmeno, mezera, datum rozvolneni ("Pepa 1.1.2011")
 * c) Ukonceny st.: jmeno, datum rozvolneni, datum ukonceni ("Jan 1.1.2011 2.1.2012")
 */
class StudentAnalyzer{
public:
    std::string analyzeStudent(UIS::Student* someStudent);
};

#endif
