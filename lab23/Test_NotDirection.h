#pragma once
#include "UnDirectedGraph.h"
#include <iostream>
#include <assert.h>
using namespace std;


void Test_NotDirection1(){
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
        k[i] = 5;
    UnDirectedGraph<int> elements(el, k);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            assert(elements.distance[i][j] == i);
            assert(elements.weight[i] == 5);
        }
    assert(m.elements.size() == 5);
}


void Test_NotDirection2(){
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
        k[i] = 5;
    UnDirectedGraph<int> elements(m, k);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            assert(elements.distance[i][j] == i);
            assert(elements.weight[i] == 5);
        }
    assert(m.elements.size() == 5);
}


void Test_NotDirection3(){
    UnDirectedGraph<int> r;
    assert(r.size() == 0);
    assert(r.weight.size() == 0);
    assert(r.distance.size() == 0);
    assert(r.amount == 0);
}


void Test_NotDirection_Operators(){
    vector<vector<int>> el(5);
    vector<int> k(5);
    for (int i = 0; i < 5; i++){
        el[i] = k;
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            el[i][j] = 1;
    Matrix<int> m(el);
    for (int i = 0; i < 5; i++)
        k[i] = 5;
    UnDirectedGraph<int> elements(m, k);
    assert(elements.size() == 5);
    assert(elements.get_weight(3) == 5);
    Matrix<int> opor = elements.matrix_incedention();
}