//
// Created by andre on 19.09.2021.
//

#ifndef LAB21_SORTINPUTDATA_H
#define LAB21_SORTINPUTDATA_H
#pragma once
#include <iostream>
#include "ArrSequence.h"
#include <vector>
#include <ctime>
#include <chrono>
#include <functional>
#include "Algorithms.h"

template <class T>
class SortCallInfo{
public:
    std::function<void(std::vector<T>& , int, int)> Sort;
    std::string NameOfSort;
    std::vector<T> SortData;
    unsigned long int Time;


    SortCallInfo(std::string s, std::function<void (std::vector<T>& , int, int)> el, std::vector<T> data) {
        NameOfSort = s;
        Sort = el;
        SortData = data;
        SortCallMeasureTime();
    }


    void SortCallMeasureTime(){
        auto start = std::chrono::high_resolution_clock::now();
        Sort(SortData, 0, SortData.size());
        auto end = std::chrono::high_resolution_clock::now();
        Time = std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }
};


//SortInputData
//вектор сортировок
//вектор флагов
//sortCalls[I](…);
//List<SortResultInfo>* info;
//…
//infos->Append(sortCalls[i](...));
//map["bubble] = sortCalls[indexOfBubbleSort](…);
//

template <class T>
class SortInputData {
private:
    std::vector<T> OriginalData;
    int arLength = 0;


    void AppendInData(T element){
        OriginalData.push_back(element);
    }


public:
    std::vector<SortCallInfo<T>> Data;


    SortInputData(T* elements, int length){
        arLength = length;
        for (int i = 0; i < length; i++)
            AppendInData(elements[i]);
    }


    SortInputData(std::vector<T> el){
        arLength = el.size();
        for (int i = 0; i < el.size(); i++)
            AppendInData(el[i]);
    }


    SortInputData(){
        arLength = 0;
    }


    SortInputData(int length){
        arLength = length;
        for (int i = 0; i < length; i++)
            AppendInData(length - i);
    }


    int Length()const{
        return arLength;
    }


    std::vector<T> Original(){
        return OriginalData;
    }


    void AppendAlgorithmOfSort(std::string s, std::function<void(std::vector<T>&, int, int)> Algorithm){
        Data.push_back(SortCallInfo<T>(s, Algorithm, OriginalData));
    }


    void InsertElement(T element, int index){
        T replacement = OriginalData[index];
        std::vector<T> copy;
        for (int i = 0; i < OriginalData.size() - index; i++)
            copy.push_back(OriginalData[index + i]);
        OriginalData.push_back(replacement);
        OriginalData[index] = element;
        for (int i = index + 1; i < OriginalData.size(); i++)
            OriginalData[i] = copy[i - index - 1];
        arLength++;
        for (int j = 0; j < Data.size(); j++)
            Data[j] = SortCallInfo<T>(Data[j].NameOfSort, Data[j].Sort, OriginalData);
    }

    void Append(T element){
        OriginalData.push_back(element);
        arLength++;
        for (int j = 0; j < Data.size(); j++)
            Data[j] = SortCallInfo<T>(Data[j].NameOfSort, Data[j].Sort, OriginalData);
    }


    void Prepand(T element){
        InsertElement(element, 0);
    }


/*
    unsigned long int BubbleSortCall(){
        auto start = std::chrono::high_resolution_clock::now();
        BubbleSort(mas1.Get_pointer(), arLength);
        flag1 = true;
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }


    unsigned int QuickSortCall(){
        auto start = std::chrono::high_resolution_clock::now();
        QuickSortCall(mas2.Get_pointer(), 0, arLength - 1);
        flag2 = true;
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }


    unsigned int MergeCall(){
        auto start = std::chrono::high_resolution_clock::now();
        MergeSort(mas3.Get_pointer(), 0, arLength - 1);
        flag3 = true;
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }


    unsigned int CtrlV(){
        auto start = std::chrono::high_resolution_clock::now();
        CtrlV(mas4.Get_pointer(), arLength);
        flag4 = true;
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }
*/

};


#endif //LAB21_SORTINPUTDATA_H
