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
        YogaStudio yoga;
        Lesson lesson(0, "lesson", "lesson", 5600);
        yoga.addLesson(lesson);
        test_(yoga.getEmptyLessons().empty() == false);
        test_(yoga.getEmptyLessons().at(0).getName() == "lesson");


    }
    
    // 4 body
    void testGetLessonsWithDurationInRange(){
        YogaStudio yoga;
        Lesson lesson(0, "lesson", "lesson", 5600);
        yoga.addLesson(lesson);
        test_(yoga.getLessonsWithDurationInRange(1000, 6000).empty() == false);
        test_(yoga.getLessonsWithDurationInRange(6000, 1000).at(0).getDuration() == 5600);
    }
    
    // 4 body
    void testGetRatioOfManAndWoman() {
        YogaStudio yoga;
        Lesson lesson(0, "lesson", "lesson", 5600);
        Participant tomas{"Tomas", 25, male};
        Participant anna{"Anna", 25, female};
        yoga.addLesson(lesson);
        yoga.registerParticipant(0, tomas);
        yoga.registerParticipant(0, anna);
        test_(yoga.getRatioOfManAndWoman() == 50);

    }
    
    void run(){
        testGetEmptyLessons();
        testGetLessonsWithDurationInRange();
        testGetRatioOfManAndWoman();
    }
};

#endif
