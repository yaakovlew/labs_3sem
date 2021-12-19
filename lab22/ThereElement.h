#include "Exceptions.h"
#pragma once
#include <iostream>

template<typename T>
class ThereElement {
private:
    T data;
    bool availability = false;
public:
    ThereElement();

    explicit ThereElement(T);

    T getValue() const;

    void setValue(T);

    bool avalability() const;

    bool operator==(const ThereElement &right);

    bool operator!=(const ThereElement &right);

    ~ThereElement();
};


template<typename T>
ThereElement<T>::ThereElement() {
    this->availability = false;
}

template<typename T>
ThereElement<T>::ThereElement(T data) {
    this->data = data;
    this->availability = true;
}


template<typename T>
T ThereElement<T>::getValue() const {
    if (this->availability) {
        return this->data;
    } else {
        throw exceptions::OptionExceptions("Has no value!", __LINE__, __FILE__);
    }
}

template<typename T>
void ThereElement<T>::setValue(T value) {
    this->data = value;
    if (!this->availability) {
        this->availability = true;
    }
}

template<typename T>
bool ThereElement<T>::operator==(const ThereElement<T> &right) {
    if (this->availability && right.avalability()) {
        return this->data == right.getValue();
    } else {
        throw exceptions::OptionExceptions("Can't compare options!", __LINE__, __FILE__);
    }
}

template<typename T>
bool ThereElement<T>::operator!=(const ThereElement<T> &right) {
    if (this->availability && right.avalability()) {
        return this->data != right.getValue();
    } else {
        throw exceptions::OptionExceptions("Can't compare options!", __LINE__, __FILE__);
    }
}

template<typename T>
bool ThereElement<T>::avalability() const {
    return this->availability;
}

template<typename T>
ThereElement<T>::~ThereElement() = default;

