#ifndef cpp2014_priklad2_h
#define cpp2014_priklad2_h

#include <iostream>

// 5 bodu priklad, 10 bodu test

namespace Objects {
    
    class Object{
    protected:
        std::string m_name;
    public:
        Object(std::string name);        
        std::string getName();        
        virtual void whoAmI();
    };

    class WiredObject:public Object{
    protected:
        std::string m_lineColor;
    public:
        WiredObject(std::string lineColor, std::string name);        
        std::string getLineColor();        
        virtual void whoAmI();
    };

    class SolidObject:public WiredObject{
    protected:
        std::string m_fillColor;
    public:
        SolidObject(std::string fillColor, std::string lineColor, std::string name);
        std::string getFillColor();        
        virtual void whoAmI();
    };
}

class Analyzer{
public:
    /// Teto metode muze byt predan obecny objekt nebo jeden z jeho potomku.
    /// Pokud je ji predan nejaky drateny objekt, tak se vrati jeho jmeno a barva cary,
    /// pokud je ji predan nejaky vyplneny (solid) objekt, tak se vrati jeho jmeno a
    /// barva vyplne. Ve vsech ostatnich pripadech se vrati pouze jmeno objektu. (5 bodu)
    std::string analyzeColors(Objects::Object* someObject);
};

#endif
