#pragma once
#include <iostream>
#include "HashTable.h"
#include <algorithm>

template <class T>
class HashQueue {
public:

    Pair::HashTable<T, int> elements;
    int Length = 0;


    void Append(T el, int rep){
        elements.Append(el, rep);
    }


    HashQueue(){}


    HashQueue(std::vector<T> a, std::vector<int> b){
        Length = std::min(a.size(), b.size());
        for (int i = 0; i < Length; i++)
            elements.Append(a[i],b[i]);
    }

    T Take(){
        int mex = -1;
        T rez;
        for (int i = 0; i < elements.element.size(); i++){
            Pair::List<T, int>* ptr = &elements.element[i];
            while (ptr){
                if (ptr->priorety > mex){
                    mex = ptr->priorety;
                    rez = ptr->data;
                }
                ptr = ptr->next;
            }
        }
        elements.Delete(rez);
        return rez;
    }


   /* bool Find(T el){

    }*/
};

template <class T>
std::ostream& operator<<(std::ostream& out, HashQueue<T>& param){
    for (int i = 0; i < param.Length; i++)
        out<< param.Take()<<' ';
    return out;
}

