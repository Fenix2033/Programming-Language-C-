#ifndef cpp2011z_tst_priklad1_h
#define cpp2011z_tst_priklad1_h

#include "TestSuite/Test.h"
#include "priklad1.h"

class TestPrikladu1:public TestSuite::Test{
public:
    void pixel(){
        Pixel testPixel(1, 2, 3, 200);
        test_(testPixel.m_rgb[0] = 1);
        test_(testPixel.m_rgb[1] = 2);
        test_(testPixel.m_rgb[2] = 3);
        test_(testPixel.m_rgb[2] = 200);
    }
        
    void image(){
        Image testImage;
        
        try {
            testImage.loadImageFromTextFile("neni", 5, 5);
            fail_("nekontroluje otevreni souboru");
        } catch(...){
            succeed_();
        }
        
        testImage.loadImageFromTextFile("data.txt", 5, 5);
        test_(testImage.getImageWidth() == 5);
        test_(testImage.getImageHeight() == 5);
        
        test_(testImage.getMinRowColorComponentValue(0, 1) == 9);
    }

    void replacePixel(){
        Image testImage;
        
        testImage.loadImageFromTextFile("data.txt", 5, 5);
        test_(testImage.getImageWidth() == 5);
        test_(testImage.getImageHeight() == 5);
        
        testImage.replacePixel(1, 1, Pixel(100, 100, 100, 100));
        test_(testImage.getMinRowColorComponentValue(0, 1) == 100);
    }

    void getPixel(){
        Image testImage;
        
        testImage.loadImageFromTextFile("data.txt", 5, 5);
        test_(testImage.getImageWidth() == 5);
        test_(testImage.getImageHeight() == 5);
        
        Pixel returned = testImage.getPixel(0, 0);
        test_(returned.m_rgb[0] == 10);
        test_(returned.m_rgb[1] == 41);
        test_(returned.m_rgb[2] == 30);
    }
    
    void run(){
        pixel();
        replacePixel();
        getPixel();
        image();
    }
};

#endif
