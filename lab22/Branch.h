#pragma once
#include <iostream>
#include "ThereElement.h"

template<typename T, typename V>
class Branch {
private:
    ThereElement<T> *key;
    ThereElement<V> *value;
public:
    Branch();

    explicit Branch(Branch<T, V> *pair);

    Branch(T key, V value);

    void setKey(T key);

    void setValue(V value);

    ThereElement<V> getValue();

    ThereElement<T> getKey();

    ~Branch();
};

template<typename T, typename V>
Branch<T, V>::Branch() {
    this->key = new ThereElement<T>[1];
    this->value = new ThereElement<V>[1];
}

template<typename T, typename V>
Branch<T, V>::Branch(T key, V value) {
    this->key = new ThereElement<T>(key);
    this->value = new ThereElement<V>(value);
}

template<typename T, typename V>
void Branch<T, V>::setKey(T new_key) {
    if (this->key->avalability()) {
        this->key->setValue(new_key);
    } else {
        this->key = new ThereElement<T>(new_key);
    }
}

template<typename T, typename V>
void Branch<T, V>::setValue(V new_value) {
    if (this->value->avalability()) {
        this->value->setValue(new_value);
    } else {
        this->value = new ThereElement<V>(new_value);
    }
}

template<typename T, typename V>
ThereElement<V> Branch<T, V>::getValue() {
    if (this->value->avalability()) {
        return *(this->value);
    } else {
        throw exceptions::OptionExceptions("Has no value!", __LINE__, __FILE__);
    }
}

template<typename T, typename V>
ThereElement<T> Branch<T, V>::getKey() {
    if (this->key->avalability()) {
        return *(this->key);
    } else {
        throw exceptions::OptionExceptions("Has no key!", __LINE__, __FILE__);
    }
}

template<typename T, typename V>
Branch<T, V>::Branch(Branch<T, V> *pair) {
    this->key = new ThereElement<T>(pair->getKey().getValue());
    this->value = new ThereElement<V>(pair->getValue().getValue());
}

template<typename T, typename V>
Branch<T, V>::~Branch() = default;

