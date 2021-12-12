#ifndef cpp2011z_priklad1_h
#define cpp2011z_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

/// Trida reprezentujici jeden pixel obrazu, poradi barev v poli je vzdy RGB
class Pixel{
public:
    int m_rgb[3];

    Pixel(int r, int g, int b);
};

/// ComparePixels se pouziva pro porovnani dvou pixelu pri vyberu nejvetsiho prvku
/// Porovnava se podle hodnoty zvolene konstruktorem
class ComparePixels{
private:
    int m_selectedComponent;
public:
    // uklada zvolenou komponentu
    ComparePixels(int selectedComponent);
    // vraci true, pokud prvni ma mensi komponentu zvolenou konstruktorem
    bool operator()(Pixel& first, Pixel& second);
};

/// Funkcni trida pouzita pro vykresleni barvy pixelu
class PrintColorComponent{
private:
    int m_selectedComponent;
public:
    /// v konstruktoru vyberu ktera komponenta se vykresluje 0=red, atp.
    PrintColorComponent(int selectedComponent);
    /// pomoci metody operator() zajistim vzdy vykresleni dane komponenty
    void operator()(Pixel& pixel);
};

class Image{
private:
    /// struktura ukladajici obraz
    std::vector< std::vector<Pixel> > m_image;

public:
    /// Nahraje pixely ze souboru kde jsou ulozeny za sebou RGB a jejich pozice komponenty
    /// oddeleny mezerou. Kontrololuje se otevreni.
    void loadImageFromTextFile(std::string fileName, int width, int height) throw (std::domain_error);
    /// vrati sirku obrazu (ne max index), pozor, zda je obraz naplnen, pokud ne vraci 0
    int getImageWidth();
    /// vrati vysku obrazu (ne max index), pozor, zda je obraz naplnen, pokud ne vraci 0
    int getImageHeight();
    /// vykresli obraz pomoci algoritmu, vzdy pouze jednu komponentu obrazu
    /// muzete pouzit for cyklus na radky/sloupci a v ramci jednoho radku/sloupce pak alg.
    void printImageInColor(int colorComponent);
    /// Nahradi zvoleny pixel v poli, opet kontroluje rozsah
    void replacePixel(int x, int y, Pixel newPixel) throw (std::range_error);
    /// Vrati pixel na dane pozici, pokud existuje
    Pixel getPixel(int x, int y) throw (std::range_error);
    /// Projde dany vnoreny vektor v obrazu a vrati celkove nejvetsi hodnotu R, G nebo B pixelu.
    /// Pouzijte algoritmus max_element, pro nalezeni je potreba aby algoritmus mohl
    /// porovnat velikost dvou pixelu pomoci funkcniho objektu.
    /// Algoritmus vraci iterator na nejvetsi prvek. Kontroluje rozsah indexu.
    int getMaxColumnColorComponentValue(int colorComponent, int index) throw (std::range_error);
};

#endif
