#include "TestSuite/Suite.h"
#include "tst_priklad1.h"
#include "tst_priklad2.h"
#include "tst_priklad3.h"


int main (int argc, const char * argv[])
{
    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new TestPrikladu1);
    tests.addTest(new TestPrikladu2);
    tests.addTest(new TestPrikladu3);

    tests.run();
    tests.report();

    return 0;
}

