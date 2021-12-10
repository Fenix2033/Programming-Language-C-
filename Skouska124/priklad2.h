#ifndef cpp2011z_priklad2_h
#define cpp2011z_priklad2_h

#include <iostream>
// CELKEM 15 b, za pomocne trity 7, za analyzator 8
namespace SecurityIS {
    
    /// zakladni typ udalosti v bezpecnostnim IS, metody maji obvykly ucel
    class Event{
    protected:
        std::string m_area;
    public:
        Event(std::string area);        
        std::string getArea(); 
        /// vypise oblast udalosti
        virtual void getInfo();
    };

    /// potomek udalosti resici chyby v systemu
    class ErrorEvent:public Event{
    protected:
        std::string m_typeOfError;
    public:
        ErrorEvent(std::string area, std::string typeOfError);        
        std::string getTypeOfError(); 
        /// vypise oblast a typ chyby
        virtual void getInfo();
    };
    
    /// potomek udalosti resici naruseni
    class IntrusionEvent:public Event{
    protected:
        std::string m_typeOfIntrusion;
    public:
        IntrusionEvent(std::string area, std::string typeOfIntrusion);        
        std::string getTypeOfIntrusion(); 
        /// vypise oblast a typ naruseni
        virtual void getInfo();
    };
}

/**
 * Metoda trity obdrzi nekterou z udalosti. Pokud se jedna o typ udalosti naruseni nebo
 * o nektereho jejiho potomka je nutne spustit alarm. V tomto pripade vraci metoda true.
 */
class Analyzer{
public:
    bool isIntrusion(SecurityIS::Event* securityEvent);
};

#endif
