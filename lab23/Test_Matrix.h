#pragma once
#include <iostream>
#include "assert.h"
#include <vector>
#include "Matrix.h"
using namespace std;

void Test_matrix1(){
    vector<vector<int>> el(5);
    vector<int> k(5);
    for (int i = 0; i < 5; i++){
        el[i] = k;
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            el[i][j] = i;
        Matrix<int> m(el);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            assert(m[i][j] == i);
    assert(m.size() == 5);
}


void Test_matrix2(){
    Matrix<int> m;
    assert(m.size() == 0);
}


void Test_matrix_append(){
    vector<vector<int>> el(5);
    vector<int> k(5);
    for (int i = 0; i < 5; i++){
        el[i] = k;
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            el[i][j] = i;
    Matrix<int> m(el);
    vector<int> elem = {1 , 2, 3, 4, 5, 6};
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            assert(m[i][j] == i);
    assert(m.size() == 5);
    m.append(elem);
    for (int i = 0; i < 6; i++) {
        assert(m[5][i] == elem[i]);
        assert(m[i][5] == elem[i]);
    }
    assert(m.size() == 6);
}

void Test_matrix_operators(){
    vector<vector<int>> el(5);
    vector<int> k(5);
    for (int i = 0; i < 5; i++){
        el[i] = k;
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            el[i][j] = i;
    Matrix<int> m(el);
    assert(m[0][0] == 0);
}