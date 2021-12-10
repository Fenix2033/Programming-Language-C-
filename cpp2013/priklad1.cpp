#include "priklad1.h"

Pixel::Pixel(int r, int g, int b, int alpha){
 
}


int Image::getMinRowColorComponentValue(int colorComponent, int index)throw (std::range_error){

}

/// vrati pixel v poli
Pixel Image::getPixel(int x, int y) throw (std::range_error){

}

/// nahradi zvoleny pixel v poli
void Image::replacePixel(int x, int y, Pixel newPixel) throw (std::range_error){

}

void Image::loadImageFromTextFile(std::string fileName, int width, int height) throw (std::domain_error){
    
}   

int Image::getImageWidth() throw (std::range_error){

}

int Image::getImageHeight() throw (std::range_error){

}

void Image::printImageInColor(int colorComponent){

}

bool Comparator::CompareImages(Image first, Image second){
    return true;
}
