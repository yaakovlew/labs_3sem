#pragma once
#include <iostream>
#include "HashTable.h"


template <class T, class R>
class HashDictionary{
public:
    Pair::HashTable<T, R> Elements;
    int Length = 0;


    HashDictionary(){}


    HashDictionary(std::vector<T> a, std::vector<R> b){
        Length = std::min(a.size(), b.size());
        for (int i = 0; i < Length; i++)
            Append(a[i], b[i]);
    }


    void Append(T a, R b){
        Elements.Append(a,b);
    }


    R* FindPtr(T element){
        int i = 0;
        if (Find(element)){
            while(Elements.element.size())
                return Elements.element[i].FindPtr(element)
        }
        else return nullptr;
    }


    void Delete(T el){
        Elements.Delete(el);
        return;
    }

    void AllDelete(T el){
        while (Find(el))
            Delete(el);
        return;
    }


    bool Find(T el){
       return Elements.Find(el);
    }
};

template <class T, class R>
std::ostream& operator<<(std::ostream& out, HashDictionary<T, R>& param) {
    int j = 0;
    for (int i = 0; i < param.Elements.element.size(); i++) {
        Pair::List<T,R>*ptr = &param.Elements.element[i];
        while(ptr) {
            out << j << "'st element: " << ptr->priorety<< " - " <<ptr->data
                << "\n";
            ptr = ptr->next;
            j++;
        }
    }
    return out;
}