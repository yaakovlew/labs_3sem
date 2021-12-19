#include <vector>
#include "AVLTree.h"
#include "functions.h"

template<typename V>
class AVLSet {
private:
    AVLTree<V, V> *tree;
    int size = 0;
public:
    AVLSet();

    explicit AVLSet(V value);

    int getSize();

    bool hasValue(V value);

    ThereElement<V> get(V key);

    void add(V value);

    V* get_values();

    void print();

    template <typename V1> friend bool operator== (const AVLSet<V1> &c1, const AVLSet<V1> &c2);

    template <typename V1> friend bool operator< (const AVLSet<V1> &c1, const AVLSet<V1> &c2);


    ~AVLSet();
};

template<typename V>
AVLSet<V>::AVLSet() {
    this->tree = new AVLTree<V, V>();
    this->size = 0;

}

template<typename V>
int AVLSet<V>::getSize() {
    return this->size;
}

template<typename V>
bool AVLSet<V>::hasValue(V value) {
    return this->tree->find(value);
}

template<typename V>
void AVLSet<V>::add(V value) {
    if (!this->tree->find(value)) {
        Branch<V, V> pair(value, value);
        this->tree->insert(pair);
        this->size++;
    }
}

template<typename V>
ThereElement<V> AVLSet<V>::get(V key) {
    return this->tree->get(key).getValue();
}

template<typename V>
void AVLSet<V>::print() {
    this->tree->traversal(foo_classic_pair<V,V>);
}


template<typename V>
bool operator==(const AVLSet<V> &c1, const AVLSet<V> &c2) {
    return c1.size == c1.size;
}

template<typename V>
bool operator<(const AVLSet<V> &c1, const AVLSet<V> &c2) {
    return c1.size < c1.size;
}

template<typename V>
AVLSet<V>::AVLSet(V value) {
    Branch<V, V> pair(value, value);
    this->tree->insert(pair);
    this->size++;
}

template<typename V>
V *AVLSet<V>::get_values() {
    auto result = new V [size];
    Branch<V,V>* buff = this->tree->get_pairs();
    for (int i = 0; i < size; ++i) {
        result[i] = buff[i].getValue().getValue();
    }
    return result;
}

template<typename V>
AVLSet<V>::~AVLSet() = default;

