#ifndef cpp2011z_priklad1_h
#define cpp2011z_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

/// CELKEM 30
/// Trida reprezentujici jeden pixel obrazu, poradi barev v poli je vzdy RGB
class Pixel{
public:
    int m_rgb[4];
    
    Pixel(int r, int g, int b, int alpha);
};

class Image{
private:
    /// struktura ukladajici obraz
    std::vector< std::vector<Pixel> > m_image;
    
public:
    /// Nahraje pixely ze souboru kde jsou ulozeny za sebou RGBA a jejich pozice komponenty
    /// oddeleny mezerou. Kontrololuje se otevreni.
    /// Priklad 100 100 100 255 0 0 = pixel kde RGB komponenty maji hodnotu 100, alfa je 255
    /// a pozice pixelu je [0,0] (7 bodu)
    void loadImageFromTextFile(std::string fileName, int width, int height) throw (std::domain_error);    
    /// vrati sirku obrazu (ne max index), pozor, zda je obraz naplnen,
    /// pokud ne vyhazuje vyjimku (1 body)
    int getImageWidth() throw (std::range_error);  
    /// vrati vysku obrazu (ne max index), pozor, zda je obraz naplnen,
    /// pokud ne vyhazuje vyjimku (1 body)
    int getImageHeight() throw (std::range_error); 
    /// vykresli obraz pomoci algoritmu, vzdy pouze jednu komponentu obrazu
    /// pouzijte vyctove for cykly a lambda vyraz (5 bodu)
    void printImageInColor(int colorComponent); 
    /// Nahradi zvoleny pixel v poli, opet kontroluje rozsah (2 body)
    void replacePixel(int x, int y, Pixel newPixel) throw (std::range_error);    
    /// Vrati pixel na dane pozici, pokud existuje, jinak vyjimku (2 body)
    Pixel getPixel(int x, int y) throw (std::range_error);
    /// Projde dany vnoreny vektor v obrazu a vrati celkove nejvetsi hodnotu R, G, B nebo Aplha pixelu.
    /// Pouzijte algoritmus min_element, pro nalezeni je potreba aby algoritmus mohl 
    /// porovnat velikost dvou pixelu pomoci funkcniho objektu. Pro porovnani dvou pixelu
    /// pro algoritmus pouzijte lamda vyraz.
    /// Algoritmus vraci iterator na nejvetsi prvek. Kontroluje rozsah indexu. (6 bodu)
    int getMinRowColorComponentValue(int colorComponent, int index) throw (std::range_error);
};

class Comparator{
    /// Metoda porovna jestli jsou dva obrazky obsahove shodne.
    /// Mohou mit ruznou alfu, ale musi mit stejne rozmery a RGB komponenty (6 bodu)
    static bool CompareImages(Image first, Image second); 
};

#endif
