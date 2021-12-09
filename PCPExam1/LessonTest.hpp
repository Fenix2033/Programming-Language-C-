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
        Lesson lesson(5, "fds", "sdf", 5);
        test_(lesson.getId() == 5);
        test_(lesson.getName() == "fds");
        test_(lesson.getContent() == "sdf");
        test_(lesson.getDuration() == 5);
    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Lesson s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
        Lesson lesson(-1, "", "", -5);
        test_(lesson.getId() == -1);
        test_(lesson.getName() == "");
        test_(lesson.getContent() == "");
        test_(lesson.getDuration() == -5);
    }
    
public:
    void run(){
        testValidParameters();
        testInvalidParameters();
    }
};
#endif
