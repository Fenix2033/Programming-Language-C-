#include "TestSuite/Suite.h"
#include "YogaStudioTest.hpp"
#include "LessonTest.hpp"
#include "Lesson.hpp"
#include "YogaStudio.hpp"

int main (int argc, const char * argv[])
{
    std::string fileName = "/home/xkudla/Documents/Mendel/PCP/Zkouska/PCPExam1/table.txt";

    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new LessonTest);
    tests.addTest(new YogaStudioTest);

    tests.run();
    tests.report();

    Lesson *one = new Lesson(0, "one", "one", 5600);
    Lesson *two = new Lesson(1, "two", "two", 6600);

    YogaStudio *yoga = new YogaStudio();

    yoga->addLesson(*one);
    yoga->addLesson(*two);
    yoga->getEmptyLessons();
    yoga->printTimetable(fileName);
    
    return 0;
}

