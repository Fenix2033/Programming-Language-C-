cmake_minimum_required(VERSION 3.17)
project(zkouska_ZS2021_1T)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(TestSuite)

add_executable(zkouska_ZS2021_1T
        TestSuite/Suite.cpp
        TestSuite/Suite.h
        TestSuite/Test.cpp
        TestSuite/Test.h
        priklad1.h
        priklad1.cpp
        priklad2.h
        priklad2.cpp
        tst_priklad1.h
        main.cpp
        votes.txt)
