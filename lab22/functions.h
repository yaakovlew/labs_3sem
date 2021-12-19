#pragma once
#include <iostream>
#include "Branch.h"

template <typename T, typename V>
void foo_classic_pair(Branch<T,V> my_pair){
    std::cout << "'" << my_pair.getValue().getValue() << "'";
}

template <typename T, typename V>
Branch<T,V>* foo_classic_pair_get(Branch<T,V> my_pair){
    std::cout << my_pair.getValue().getValue();
}


template <typename T, typename V>
void foo_own_structures(Branch<T,V> my_pair){
    std::cout << "set: ";
    my_pair.getKey().getValue().print();
//    std::cout << my_pair.getKey().getValue();
    std::cout << " ";
    std::cout << " count : " << my_pair.getValue().getValue() << " ";
    std::cout << "\n";
}
