#ifndef cpp_tst_priklad2_h
#define cpp_tst_priklad2_h

#include "TestSuite/Test.h"
#include "Lesson.hpp"

// 4 body
class LessonTest:public TestSuite::Test{
private:
    // 2 bod
    /// Overte, ze pri vytvoreni objektu Lesson se spravnymi parametry se nevyhodi vyjimka.

    void testValidParameters(){
        try {
            Lesson lesson(5, "fds", "sdf", 5);
            test_("Valid argument");
        } catch (std::invalid_argument){
            fail_("Invalid argument");
        }
    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Lesson s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
        try {
            Lesson lesson(-1, "111", "", 0);
            fail_("Invalid argument");
        } catch (std::invalid_argument){
            test_("Valid argument");
        }
    }
    
public:
    void run(){
        testValidParameters();
        testInvalidParameters();
    }
};
#endif
