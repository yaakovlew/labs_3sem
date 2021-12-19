#include <iostream>
#include "AVLTree.h"

using namespace std;

void test_tree_find(){
    AVLTree<int,int> tree;
    PairKV<int, int> pair(5, 10);
    tree.insert(pair);
    if(tree.find(5)){
        cout << "Test passed";
    }else{
        cout << "Test failed";
    }
};

void test_tree_get(){
    AVLTree<int,int> tree;
    PairKV<int, int> pair(5, 10);
    tree.insert(pair);
    int answer = tree.get(5).getValue().getValue();
    if(answer == 10){
        cout << "Test passed";
    }else{
        cout << "Test failed";
    }

}

