cmake_minimum_required(VERSION 3.21)
project(7Matrix)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(TestSuite)

add_executable(7Matrix
        TestSuite/Suite.cpp
        TestSuite/Suite.h
        TestSuite/Test.cpp
        TestSuite/Test.h
        main.cpp
        Matrix.cpp
        Matrix.h
        MatrixTest.cpp
        MatrixTest.hpp)
