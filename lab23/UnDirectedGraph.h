#pragma once
#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

template <class T>
class UnDirectedGraph {
public:
    Matrix<int> distance;
    vector<T> weight;
    int amount = 0;

    UnDirectedGraph(vector<vector<int>> MatrixDistance, vector<T> Matrix_s_weight){
        weight = Matrix_s_weight;
        distance = Matrix<int>(MatrixDistance);
        amount = Matrix_s_weight.size();
    }
//пропускная способность
//неориент граф

    UnDirectedGraph(Matrix<int> lem, vector<T> w){
        distance = lem;
        weight = w;
        amount = w.size();
    }

    UnDirectedGraph(){}


    int size()const{
        return amount;
    }

    void append(vector<int> dist, T w){
        amount++;
        distance.append(dist);
        weight.push_back(w);
    }


    Matrix<int> matrix_incedention(){
        vector<vector<int>> mat;
        vector<int> l;
        for (int i = 0; i < amount; i++)
            l.push_back(0);
        for (int i = 0; i < amount; i++)
            mat.push_back(l);
        for(int i = 0; i < amount; i++){
            for (int j = 0; j < amount; j++){
                if (distance[i][j] != 0)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        Matrix<int> m(mat);
        return m;
    }


    T get_weight(int h){
        h--;
        return weight[h];
    }


    int get_distance(int h1, int h2){
        if (h1 == h2)
            return 0;
        h1--;
        h2--;
        if (distance[h1][h2] != 0)
            return distance[h1][h2];
        else
            return -1;
    }


    int shortest_length(int h1, int h2) {
        if (h1 == h2)
            return 0;
        h1--;
        h2--;
        int SIZE = distance.size();
        Matrix<int> a = distance;
        int d[SIZE];
        int v[SIZE];
        int temp, minindex, min;
        int begin_index = h1;
        for (int i = 0; i < SIZE; i++) {
            d[i] = 10000;
            v[i] = 1;
        }
        d[begin_index] = 0;
        do {
            minindex = 10000;
            min = 10000;
            for (int i = 0; i < SIZE; i++) {
                if ((v[i] == 1) && (d[i] < min)) {
                    min = d[i];
                    minindex = i;
                }
            }
            if (minindex != 10000) {
                for (int i = 0; i < SIZE; i++) {
                    if (a[minindex][i] > 0) {
                        temp = min + a[minindex][i];
                        if (temp < d[i]) {
                            d[i] = temp;
                        }
                    }
                }
                v[minindex] = 0;
            }
        } while (minindex < 10000);
        return d[h2];
    }


    string shortest_way(int h1,int h2){
        if (h1 == h2) {
            return "";
        }
        h1--;
        h2--;
        int SIZE = distance.size();
        Matrix<int> a = distance;
        int d[SIZE];
        int v[SIZE];
        int temp, minindex, min;
        int begin_index = h1;
        for (int i = 0; i < SIZE; i++) {
            d[i] = 10000;
            v[i] = 1;
        }
        d[begin_index] = 0;
        do {
            minindex = 10000;
            min = 10000;
            for (int i = 0; i < SIZE; i++) {
                if ((v[i] == 1) && (d[i] < min)) {
                    min = d[i];
                    minindex = i;
                }
            }
            if (minindex != 10000) {
                for (int i = 0; i < SIZE; i++) {
                    if (a[minindex][i] > 0) {
                        temp = min + a[minindex][i];
                        if (temp < d[i]) {
                            d[i] = temp;
                        }
                    }
                }
                v[minindex] = 0;
            }
        } while (minindex < 10000);
        int ver[SIZE];
        int end = h2;
        ver[0] = end + 1;
        int k = 1;
        int wght = d[end];

        while (end != begin_index)
        {
            for (int i = 0; i<SIZE; i++)
                if (a[i][end] != 0)
                {
                    int temp = wght - a[i][end];
                    if (temp == d[i])
                    {
                        wght = temp;
                        end = i;
                        ver[k] = i + 1;
                        k++;
                    }
                }
        }
        string s;
        for (int i = k - 1; i >= 0; i--) {
            s += to_string(ver[i]);
            if (i != 0) {
                s.push_back('-');
                s.push_back('>');
            }
        }
        return s;
    }
};


template <class T>
ostream& operator<<(ostream& out, const UnDirectedGraph<T>& elem){
    for (int i = 0; i < elem.size(); i++) {
        out << i + 1
            << "'st vertex and connection: "
            << endl;
        for (int j = 0; j < elem.size(); j++){
            if (elem.distance[i][j] != 0){
                out<<j + 1
                   <<"'st and distance = "
                   <<elem.distance[i][j]
                   <<endl;
            }
        }
        out << endl;
    }
    return out;
}
