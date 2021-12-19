
#include <vector>
#include "AVLTree.h"
#include "functions.h"

template<typename T, typename V>
class AVLDictionary {
private:
    AVLTree<T, V> *tree;
    std::vector<ThereElement<T>> *keys;
    int size{};
public:
    AVLDictionary();

    void add(T key, V value);

    ThereElement<V> get(T key);

    ThereElement<T> getMaxKey();

    bool hasKey(T key);

    ThereElement<T> getMaxElKey();

    ThereElement<V> operator[](T key);

    std::vector<ThereElement<T>>* getKeys();

    void print();

    ~AVLDictionary();
};

template<typename T, typename V>
AVLDictionary<T, V>::AVLDictionary() {
    this->tree = new AVLTree<T,V> ();
    this->size = 0;
    this->keys = new std::vector<ThereElement<T>>();
}

template<typename T, typename V>
AVLDictionary<T, V>::~AVLDictionary() {
    delete tree;
    this->size = 0;
}

template<typename T, typename V>
void AVLDictionary<T, V>::add(T key, V value) {
    ThereElement<T> el(key);
    this->keys->push_back(el);
    Branch<T, V> pair(key, value);
    this->tree->insert(pair);
    this->size++;
}

template<typename T, typename V>
ThereElement<V> AVLDictionary<T, V>::get(T key) {
    return this->tree->get(key).getValue();
}

template<typename T, typename V>
ThereElement<T> AVLDictionary<T, V>::getMaxKey() {
    return this->tree->findMax().getValue();
}

template<typename T, typename V>
bool AVLDictionary<T, V>::hasKey(T key) {
    return this->tree->find(key);
}

template<typename T, typename V>
ThereElement<V> AVLDictionary<T, V>::operator[](T key) {
    return this->tree->get(key).getValue();
}

template<typename T, typename V>
ThereElement<T> AVLDictionary<T, V>::getMaxElKey() {
    ThereElement<T> key("0");
    for (int i = 0; i < this->keys->size() - 1; ++i) {
        if(this->get(keys->getEl(i).getValue()).getValue() > this->get(keys->getEl(i+1).getValue()).getValue()){
            key = this->keys->getEl(i);
        }
    }
    return key;
}

template<typename T, typename V>
std::vector<ThereElement<T>> *AVLDictionary<T, V>::getKeys() {
    return this->keys;
}

















































template<typename T, typename V>
void AVLDictionary<T, V>::print() {
    this->tree->traversal(foo_own_structures<T,V>);
}


