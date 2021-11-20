#pragma once
#include <iostream>


template <class T>
class Sequence{
public:

    virtual T GetFirst()const = 0;
    virtual T GetLast()const = 0;
    virtual T Get(int index)const = 0;
    virtual int Size() const = 0;
    virtual void Prepand(T item) = 0;
    virtual void Append (T item) = 0;
    virtual void InsertAt(T element, int index) = 0;
    virtual void Swap(int index1, int index2) = 0;
};