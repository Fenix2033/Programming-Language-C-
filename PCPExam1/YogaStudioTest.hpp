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
        Participant tomas{"Tomas", 25, male};
        yoga.addLesson(lesson);
        yoga.registerParticipant(0, tomas);
        try {
            test_(yoga.getEmptyLessons().empty() == true);
        } catch (std::length_error) {
            fail_("Not empty");
            succeed_();
        }
    }
    
    // 4 body
    void testGetLessonsWithDurationInRange(){
        YogaStudio yoga;
        Lesson lesson(0, "lesson", "lesson", 5600);
        yoga.addLesson(lesson);
        try {
            test_(yoga.getLessonsWithDurationInRange(1000, 6000).empty() == false);
        } catch (std::length_error) {
            fail_("Wrong duration");
            succeed_();
        }
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
        try {
            test_(yoga.getRatioOfManAndWoman() == 1);
        } catch (std::length_error) {
            fail_("Wrong");
            succeed_();
        }
    }
    
    void run(){
        testGetEmptyLessons();
        testGetLessonsWithDurationInRange();
        testGetRatioOfManAndWoman();
    }
};

#endif
