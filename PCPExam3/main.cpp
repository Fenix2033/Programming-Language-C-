#include "TestSuite/Suite.h"
#include "GuestTest.hpp"
#include "SkiResortTest.hpp"

int main (int argc, const char * argv[])
{
    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new GuestTest);
    tests.addTest(new SkiResortTest);

    tests.run();
    tests.report();


    return 0;
}

