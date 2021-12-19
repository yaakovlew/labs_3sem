#pragma once
#include <iostream>
#include <cassert>
#include "dynamicarr.h"
#include "LinkedList.h"
#include "SortInputData.h"


void test_constructor1(){
    int arr[5];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(arr, 5);
    for (int i = 0; i < 5; i++)
        assert(*(testclass.GetPointer() + i) == i);
    assert(testclass.GetLength() == 5);
    double arr1[5];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(arr1, 5);
    assert(testclass1.GetLength() == 5);
}

void test_constructor2() {
    DynamicArray<int> testclass = DynamicArray<int>(5);
    for (int i = 0; i < 5; i++)
        assert(*(testclass.GetPointer() + i) == 0);
    assert(testclass.GetLength() == 5);
    DynamicArray<double> testclass1 = DynamicArray<double>(5);
    for (int i = 0; i < 5; i++)
        assert(*(testclass1.GetPointer() + i) == 0);
    assert(testclass1.GetLength() == 5);
}

void test_constructor3() {
    DynamicArray<int> testclass1 = DynamicArray<int>(5);
    DynamicArray<int> testclass2 = DynamicArray<int>(testclass1);
    for (int i = 0; i < testclass1.GetLength(); i++)
        assert(*(testclass2.GetPointer() + i) == *(testclass1.GetPointer() + i));
    assert(testclass2.GetLength() == (testclass1.GetLength()));
    DynamicArray<double> testclass11 = DynamicArray<double>(5);
    DynamicArray<double> testclass22 = DynamicArray<double>(testclass11);
    for (int i = 0; i < testclass1.GetLength(); i++)
        assert(*(testclass22.GetPointer() + i) == *(testclass11.GetPointer() + i));
    assert(testclass22.GetLength() == (testclass11.GetLength()));
}


void test_resize(){
    DynamicArray<int> testclass = DynamicArray<int>(5);
    testclass.Resize(10);
    assert(testclass.GetLength() == 10);
    DynamicArray<double> testclass1 = DynamicArray<double>(5);
    testclass1.Resize(10);
    assert(testclass1.GetLength() == 10);
}


void test_getlength(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    assert(testclass.GetLength() == 10);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    assert(testclass1.GetLength() == 10);
}


void test_Get(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(i) == i);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass1.Get(i) == i);
}


void test_Append(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    testclass.Append(10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(i) == i);
    assert(testclass.GetLength() == 11);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    testclass1.Append(10);
    assert(testclass1.GetLength() == 11);
}


void test_prepend(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    testclass.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass.Get(0) == 0);
    assert(testclass.GetLength() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    testclass1.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass1.Get(0) == 0);
    assert(testclass1.GetLength() == 11);
}


void test_insertat(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    testclass.InsertAt(11, 4);
    assert(testclass.Get(4) == 11);
    assert(testclass.GetLength() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    testclass1.InsertAt(11, 4);
    assert(testclass1.Get(4) == 11);
    assert(testclass1.GetLength() == 11);
}


void test_append(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    testclass.Append(10);
    assert(testclass.Get(10) == 10);
    assert(testclass.Get_length() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    testclass1.Append(10);
    assert(testclass1.Get(10) == 10);
    assert(testclass1.Get_length() == 11);
}

void test_prep(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    testclass.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass.Get(0) == 0);
    assert(testclass.Get_length() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    testclass1.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass1.Get(0) == 0);
    assert(testclass1.Get_length() == 11);
}


void test_constr1(){
    LinkedList<int> clas = LinkedList<int>();
    assert(clas.Get_length() == 0);
    LinkedList<double> clas1 = LinkedList<double>();
    assert(clas1.Get_length() == 0);
}


void test_constr2(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    for (int i = 0; i < 10; i++)
        (testclass.Get(i) == i + 1);
    assert(testclass.Get_length() == 10);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        (testclass1.Get(i) == i + 1);
    assert(testclass1.Get_length() == 10);
}


void test_Getl(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(i) == i + 1);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass1.Get(i) == i + 1);
}


void test_Getfirst(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    assert(testclass.Get(0) == testclass.Get_First());
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(0) == testclass.Get_First());
}


void test_Getlast(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    assert(testclass.Get(9) == testclass.Get_last());
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(9) == testclass.Get_last());
}


void test_InsAt(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    testclass.InsertAt(5,6);
    assert(testclass.Get(6) == 5);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    testclass1.InsertAt(5,6);
    assert(testclass1.Get(6) == 5);
}


void test_const1(){
    float mas[20];
    for (int i = 0; i < 20; i++)
        mas[i] = 20 - i;
    SortInputData<float> r = SortInputData<float>();
    std::vector<float> p = r.Original();
    assert(r.flag(1) == false);
    assert(r.flag(2) == false);
    assert(r.flag(3) == false);
    assert(r.flag(4) == false);
}


void test_const2(){
    float mas[20];
    for (int i = 0; i < 20; i++)
        mas[i] = 20 - i;
    SortInputData<float> r = SortInputData<float>(mas, 20);
    std::vector<float> p = r.Original();
    for (int i = 0; i < 20; i++)
        assert(p[i] == 20 - i);
    assert(r.flag(1) == false);
    assert(r.flag(2) == false);
    assert(r.flag(3) == false);
    assert(r.flag(4) == false);
}


void test_const3(){
    float mas[20];
    for (int i = 0; i < 20; i++)
        mas[i] = 20 - i;
    SortInputData<float> r = SortInputData<float>(20);
    std::vector<float> p = r.Original();
    for (int i = 0; i < 20; i++)
        assert(p[i] == 0);
    assert(r.flag(1) == false);
    assert(r.flag(2) == false);
    assert(r.flag(3) == false);
    assert(r.flag(4) == false);
}


void test_app(){
    float mas[20];
    for (int i = 0; i < 20; i++)
        mas[i] = 20 - i;
    SortInputData<float> r = SortInputData<float>(20);
    std::vector<float> p = r.Original();
    r.Appm(0);
    for (int i = 0; i < 21; i++)
        assert(p[i] == 0);
    assert(r.flag(1) == false);
    assert(r.flag(2) == false);
    assert(r.flag(3) == false);
    assert(r.flag(4) == false);
}



void test_prepen(){
    float mas[20];
    for (int i = 0; i < 20; i++)
        mas[i] = 20 - i;
    SortInputData<float> r = SortInputData<float>(20);
    std::vector<float> p = r.Original();
    r.Prepm(0);
    for (int i = 0; i < 21; i++)
        assert(p[i] == 0);
    assert(r.flag(1) == false);
    assert(r.flag(2) == false);
    assert(r.flag(3) == false);
    assert(r.flag(4) == false);
}


void test_length(){
    float mas[20];
    for (int i = 0; i < 20; i++)
        mas[i] = 20 - i;
    SortInputData<float> r = SortInputData<float>(20);
    std::vector<float> p = r.Original();
    r.Prepm(0);
    for (int i = 0; i < 21; i++)
        assert(p[i] == 0);
    assert(r.flag(1) == false);
    assert(r.flag(2) == false);
    assert(r.flag(3) == false);
    assert(r.flag(4) == false);
    assert(r.Length() == 21);
}





