#include "TestSuite/Suite.h"
#include "YogaStudioTest.hpp"
#include "LessonTest.hpp"
#include "Lesson.hpp"
#include "YogaStudio.hpp"
#include "Participant.h"

int main (int argc, const char * argv[])
{
    std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam1/table.txt";

    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new LessonTest);
    tests.addTest(new YogaStudioTest);

    tests.run();
    tests.report();



    return 0;
}

