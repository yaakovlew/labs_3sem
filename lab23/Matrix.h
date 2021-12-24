#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Matrix{
public:
    vector<vector<T>> elements;
    int length = 0;


    Matrix(){}


    Matrix(vector<vector<T>> Mat){
        length = Mat.size();
        vector<int> m(length);
        for (int i = 0; i < length; i++)
            elements.push_back(m);
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++) {
                elements[i][j] = Mat[i][j];
            }
    }

    Matrix(const Matrix<T>& matrix) {
        length = matrix.length;
        for (auto& i : matrix.elements) {
            elements.push_back(vector<T>());
            auto len = elements.size() - 1;
            for (auto &j : i) {
                elements[len].push_back(j);
            }
        }
    }


    int size()const{
        return length;
    }


    void append(vector<T> connection){
        length++;
        elements.push_back(connection);
        for (int i = 0; i < length - 1; i++)
            elements[i].push_back(connection[i]);
    }



    const vector<T>& operator[](int el)const{
        return elements[el];
    }


    int operator[](pair<int, int> el)const{
        return elements[el.first][el.second];
    }


    vector<T> operator[](int index1){
        return elements[index1];
    }

};


template <class T>
std::ostream& operator<<(std::ostream &out,const Matrix<T>& el){
    for (int i = 0; i < el.size(); i++) {
        for (int j = 0; j < el[i].size(); j++) {
            out << el[i][j] << ' ';
        }
        out<<std::endl;
    }
    return out;
}

