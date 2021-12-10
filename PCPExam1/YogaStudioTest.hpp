#ifndef cpp_tst_priklad1_h
#define cpp_tst_priklad1_h

#include "TestSuite/Test.h"
#include "YogaStudio.hpp"

// 12 bodu
/// U testu jednotlivych metod staci uvest pouze jeden
/// testovaci pripad. Jde o to ukazat myslenku testu.
/// V kazdem testu si nejprve pripravte studio s nejakymi lekcemi
/// a pak overte funkcnost dane metody.
class YogaStudioTest:public TestSuite::Test{
public:
    // 4 body
    void testGetEmptyLessons(){
//        YogaStudio yoga;
//        std::vector<Lesson> empty;
//        Lesson lesson(0, "fsd", "fsd", 3600);
//        Lesson lesson1(1, "fsd", "fsd", 3600);
//        yoga.addLesson(lesson);
//        yoga.addLesson(lesson1);
//        empty.push_back(lesson);
//        empty.push_back(lesson1);
//        test_(yoga.getEmptyLessons() == empty);
    }
    
    // 4 body
    void testGetLessonsWithDurationInRange(){
        YogaStudio yoga;
        long min = 1000;
        long max = 2000;
        test_(max > min);

        Lesson lesson(0, "fsd", "fsd", 1500);
        std::vector<Lesson> testL;
        testL.push_back(lesson);
        yoga.addLesson(lesson);
//        test_(yoga.getLessonsWithDurationInRange(min, max) == lesson);

//        min = 2000;
//        max = 1000;
//        test_(max > min);

    }
    
    // 4 body
    void testGetRatioOfManAndWoman() {
        
    }
    
    void run(){
        testGetEmptyLessons();
        testGetLessonsWithDurationInRange();
        testGetRatioOfManAndWoman();
    }
};

#endif
