//
//  MatrixTest.cpp
//  dynamicka_matice_vzor
//
//  Created by David Procházka on 15/11/2018.
//

#include "MatrixTest.hpp"

void MatrixTest::run() {
    testConstructor();
    testInsert();
    testAddRow();
    testAddColumn();
    testDeleteRow();
    testDeleteColumn();
}

void MatrixTest::testConstructor() {
    Matrix matrix(5, 10);
    test_(matrix.getWidth() == 5);
    test_(matrix.getHeight() == 10);
    test_(matrix.getValue(0, 0) == 0);
    test_(matrix.getValue(9, 4) == 0);
    
    Matrix matrix2(10, 5);
    test_(matrix2.getWidth() == 10);
    test_(matrix2.getHeight() == 5);
    test_(matrix2.getValue(0, 0) == 0);
    test_(matrix2.getValue(4, 9) == 0);
    
    Matrix matrix3(0, 0);
    test_(matrix3.getWidth() == 1);
    test_(matrix3.getHeight() == 1);
    test_(matrix3.getValue(0, 0) == 0);
    
    Matrix matrix4(-3, -4);
    test_(matrix4.getWidth() == 1);
    test_(matrix4.getHeight() == 1);
    test_(matrix4.getValue(0, 0) == 0);
}

void MatrixTest::testInsert(){
    Matrix m1(10, 5);
    m1.insert(0, 0, 7);
    test_(m1.getValue(0, 0) == 7);
    
    m1.insert(3, 0, 8);
    test_(m1.getValue(3, 0) == 8);
    
    m1.insert(4, 9, 6);
    test_(m1.getValue(4, 9) == 6);
    
    try {
        m1.insert(4, 10, 101);
        fail_("We must raise exception when row is too high");
    } catch (std::out_of_range){
        succeed_();
    }
    
    try {
        m1.insert(-10, 4, 101);
        fail_("We must raise exception when row is too low");
    } catch (std::out_of_range){
        succeed_();
    }
}

void MatrixTest::testAddRow() {
    // normal matrix
    Matrix matrix(3, 3);
    test_(matrix.getHeight() == 3);
    matrix.addRow();
    test_(matrix.getHeight() == 4);
    test_(matrix.getValue(3, 0) == 0);
    
    // 1x1 matrix
    Matrix matrix2(0, 0);
    test_(matrix2.getHeight() == 1);
    matrix2.addRow();
    test_(matrix2.getHeight() == 2);
    test_(matrix2.getValue(1, 0) == 0);
}

void MatrixTest::testAddColumn() {
    // normal matrix
    Matrix matrix(3, 3);
    test_(matrix.getWidth() == 3);
    matrix.addColumn();
    test_(matrix.getWidth() == 4);
    test_(matrix.getValue(0, 3) == 0);
    
    // 1x1 matrix
    Matrix matrix2(1, 1);
    test_(matrix2.getWidth() == 1);
    matrix2.addColumn();
    test_(matrix2.getWidth() == 2);
    test_(matrix2.getValue(0, 1) == 0);
}

void MatrixTest::testDeleteRow() {
    // normal matrix
    Matrix matrix(3, 3);
    test_(matrix.getHeight() == 3);
    matrix.deleteRow();
    test_(matrix.getHeight() == 2);
    try {
        test_(matrix.getValue(2, 0) == 0);
        fail_("Must throw.");
    } catch (std::out_of_range) {
        succeed_();
    }
    
    // 1x1 matrix
    Matrix matrix2(1, 1);
    test_(matrix2.getHeight() == 1);
    try {
        matrix2.deleteRow();
        fail_("Must throw an exception when deleting the last row.");
    } catch (std::length_error) {
        succeed_();
    }
}

void MatrixTest::testDeleteColumn() {
    // normal matrix
    Matrix matrix(3, 3);
    test_(matrix.getWidth() == 3);
    matrix.deleteColumn();
    test_(matrix.getWidth() == 2);
    try {
        test_(matrix.getValue(0, 2) == 0);
        fail_("Must throw.");
    } catch (std::out_of_range) {
        succeed_();
    }
    
    // 1x1 matrix
    Matrix matrix2(0, 0);
    test_(matrix2.getWidth() == 1);
    try {
        matrix2.deleteColumn();
        fail_("Must throw an exception when deleting the last column.");
    } catch (std::length_error) {
        succeed_();
    }
}
