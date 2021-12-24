#pragma once
#include "Matrix.h"
#include <vector>
#include <iostream>
using namespace std;


template <class T>
class DirectionGraph{
public:
    Matrix<int> distance;
    vector<T> weight;
    int amount = 0;


    DirectionGraph(vector<vector<int>> el, vector<T> w){
        weight = w;
        distance = Matrix<int>(el);
        amount = w.size();
    }


    DirectionGraph(Matrix<int> lem, vector<T> w){
        distance = lem;
        weight = w;
        amount = w.size();
    }


    DirectionGraph(){}


    int size()const{
        return amount;
    }


    void append(vector<int> dist){
        amount++;
        distance.append(dist);
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
                if (distance[i][j] != 0) {
                    mat[i][j] = 1;
                    if (distance[j][i] == 0)
                        mat[j][i] = -1;
                    else
                        mat[j][i] = 1;
                }
                else
                    if (mat[j][i] == 0) {
                        mat[i][j] = 0;
                    }
                    else
                    {
                        mat[i][j] = -1;
                    }
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
        h1--;
        h2--;
        if (distance[h1][h2] != 0)
            return distance[h1][h2];
        else
            return -1;
    }

};


template <class T>
ostream& operator<<(ostream& out, const DirectionGraph<T>& elem){
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