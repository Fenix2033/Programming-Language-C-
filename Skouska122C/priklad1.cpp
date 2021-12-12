#include "priklad1.h"

Pixel::Pixel(int r, int g, int b){
    m_rgb[0]=r;
    m_rgb[1]=g;
    m_rgb[2]=b;
}

ComparePixels::ComparePixels(int selectedComponent){
    m_selectedComponent=selectedComponent;
}

bool ComparePixels::operator()(Pixel& first, Pixel& second){
    return (first.m_rgb[m_selectedComponent] < second.m_rgb[m_selectedComponent]);
}

PrintColorComponent::PrintColorComponent(int selectedComponent){
    m_selectedComponent=selectedComponent;
}

void PrintColorComponent::operator()(Pixel& pixel){
    std::cout << pixel.m_rgb[m_selectedComponent]<< " " << std::endl;
}

void Image::loadImageFromTextFile(std::string fileName, int width, int height) throw (std::domain_error){
    std::vector<Pixel> column(height,Pixel(0,0,0));
    m_image.resize(width);
    for(int i=0; i<width; i++)
        m_image[i] = column;

    std::ifstream in(fileName.c_str());
    if(in.is_open()){
        int r=0;    int g=0;    int b=0;
        int x=0;    int y=0;
        while(in.peek()!=EOF and (x!=width-1 or y!=height-1)){
            in>>r>>g>>b>>x>>y;
            m_image.at(x).at(y)=Pixel(r,g,b);
        }
        in.close();
    } else {
        throw std::domain_error("nejde otvorit subor");
    }
}

int Image::getImageWidth(){
    return m_image.size();
}

int Image::getImageHeight(){
    int velkost=0;
    if (m_image.size()>0)
        velkost=m_image[0].size();
    return velkost;
}

void Image::printImageInColor(int colorComponent){
    for(unsigned int i=0; i<m_image.size(); i++)
        for_each(m_image[i].begin(), m_image[i].end(), PrintColorComponent(colorComponent));
}

void Image::replacePixel(int x, int y, Pixel newPixel) throw (std::range_error){
    if ((x>=0) and (x<m_image.size()) and (m_image.size()>0)){
        if ((y>=0) and (y<m_image[x].size())){
            m_image[x][y] = newPixel;
        } else
            throw std::range_error("zla pozicia y");
    } else
        throw std::range_error("zla pozicia x");
}


Pixel Image::getPixel(int x, int y) throw (std::range_error){
    if ((x>=0) and (x<m_image.size()) and (m_image.size()>0)){
        if ((y>=0) and (y<m_image[x].size())){
            return m_image[x][y];
        } else
            throw std::range_error("zla pozicia y");
    } else
        throw std::range_error("zla pozicia x");
}

int Image::getMaxColumnColorComponentValue(int colorComponent, int index) throw (std::range_error){
    std::vector<Pixel>::iterator max;

    if(index>=0 and index<getImageHeight()){
        max=max_element(m_image.at(index).begin(),m_image.at(index).end(),ComparePixels(colorComponent));
    }else
        throw std::range_error("mimo rozsah");

    return max->m_rgb[colorComponent];
}
