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



    Lesson one (0, "one", "one", 5600);
    Lesson two (1, "two", "two", 6600);

    Participant tomas{"Tomas", 25, male};
    Participant anna{"Anna", 30, female};

    YogaStudio yoga;

    yoga.addLesson(one);
    yoga.addLesson(two);
    yoga.registerParticipant(1, tomas);
    yoga.registerParticipant(1, anna);

    yoga.getEmptyLessons();
    int min = 3000;
    int max = 6000;
    yoga.getLessonsWithDurationInRange(min, max);

    one.addParticipants(tomas);
    one.addParticipants(anna);

    std::cout << one.getCountFemale();
    std::cout << one.getCountMale();


//    std::cout << yoga.getRatioOfManAndWoman() << std::endl;

    yoga.printTimetable(fileName);
    
    return 0;
}

