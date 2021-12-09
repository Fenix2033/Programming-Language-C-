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
        Guest.cpp
        Guest.hpp
        GuestTest.hpp
        main.cpp
        SkiResort.cpp
        SkiResort.hpp
        SkiResortTest.hpp)
