//
// Created by andre on 10.05.2021.
//

#ifndef UNTITLED_ARRSEQUENCE_H
#define UNTITLED_ARRSEQUENCE_H
#include "Sequence.h"
#include "dynamicarr.h"


template <class T>
class ArrSequence:Sequence<T> {


private:
    DynamicArray<T> dyarr;


public:

    ArrSequence( T* items, int count){
        dyarr = DynamicArray<T>(items, count);
    }



    ArrSequence(){
        dyarr = DynamicArray<T>();
    }


    ArrSequence(const DynamicArray<T>& dynamicArray){
        dyarr = DynamicArray<T>(dynamicArray);
    }


    ArrSequence(int count){
        dyarr = DynamicArray<T>(count);
    }


    ArrSequence(const ArrSequence<T>&arrayseq){
        dyarr = arrayseq.dyarr;
    }


    int GetLength()const{
        return dyarr.GetLength();
    }


    T* Get_pointer(){
        return dyarr.GetPointer();
    }


    void Resize(int NewSize){
        dyarr.Resize(NewSize);
    }


    T Get(int index)const{
        return dyarr.Get(index);
    }


    void Append(T element){
        return dyarr.Append(element);
    }


    void Prepand(T element){
        return dyarr.Prepend(element);
    }


    DynamicArray<T>* GetSubARR(int startIndex, int endIndex){
        return dyarr.GetSubArr(startIndex, endIndex);
    }


    void Swap(int index1, int index2){
        T element;
        element = dyarr.Get(index2);
        dyarr.GetPointer()[index2] = dyarr.Get(index1);
        dyarr.GetPointer()[index1] = element;
    }


    int Size()const{
        return dyarr.GetLength();
    }

    T GetFirst()const{
        return dyarr.Get(0);
    }

    void InsertAt(T element, int index){
        dyarr.InsertAt(element, index);
    }


    T GetLast()const{
        return dyarr.Get(dyarr.GetLength());
    }


};


#endif //UNTITLED_ARRSEQUENCE_H
