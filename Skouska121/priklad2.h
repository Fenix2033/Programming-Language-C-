#ifndef cpp2011z_priklad2_h
#define cpp2011z_priklad2_h

#include <iostream>

namespace Objects {

    /// Zakladni objekt pouzivany pro odvozovani
    class Object{
    protected:
        std::string m_name;
    public:
        /// Konstruktor uklada jmeno
        Object(std::string name);
        /// Vraci jmeno v atributu
        std::string getName();
        /// Vypise na obrazovku hlasku o svem typu
        virtual void whoAmI();
    };

    /// Prvni potomek, metody jsou zjevne
    class WiredObject:public Object{
    protected:
        std::string m_lineColor;
    public:
        WiredObject(std::string lineColor, std::string name);
        std::string getLineColor();
        virtual void whoAmI();
    };

    /// Potomek druhe urovne, metody opet zjevne
    class SolidObject:public WiredObject{
    protected:
        std::string m_fillColor;
    public:
        SolidObject(std::string fillColor, std::string lineColor, std::string name);
        std::string getFillColor();
        virtual void whoAmI();
    };
}

/// Analyzuje typ objektu a podle toho reaguje
class Analyzer{
public:
    /**
     * Teto metode je predhozen objekt libovolne z vyse uvedenych trid.
     * V pripade, ze predana instance tridy Object, vrati se prazdny retezec.
     * V pripade WidedObjectu se vraci barva linie.
     * V pripade SolidObjectu se vraci barva linie, mezera a barva vyplne (tj. "red blue").
     */
    std::string analyzeColors(Objects::Object* someObject);
};

#endif
