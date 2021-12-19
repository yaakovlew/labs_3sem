#pragma once
#include "HashTable.h"
#include <vector>


template <class T>
class HashSet{
public:
    Single::HashTable<T> A;

    HashSet(std::vector<T> v){
        for (int i = 0; i < v.size(); i++)
            Append(v[i]);
    }

    void Append(T elem){
        if (Find(elem)) return;
        A.Append(elem);
    }

    bool Find(T elem){
        if (A.Find(elem)) return true;
        return false;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& out, HashSet<T>& param){
    out<<"{ ";
    std::vector<T> el;
    for (int i = 0; i < param.A.element.size(); i++){
        Single::List<T>* ptr = &param.A.element[i];
        while (ptr) {
            if (ptr->flag == true) {
                out << ptr->data;
                if ((i < param.A.element.size() - 1) || ptr->next)
                    out<<" ,";
            }
            ptr = ptr->next;
        }
    }
    out<<" }";
    return out;
}