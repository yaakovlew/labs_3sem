#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "List.h"




class Tetra{
public:
    int list = 0;
    int stb = 0;
    int str = 0;


    Tetra(){}


    Tetra(int a, int b, int c){
        list = a;
        stb = b;
        str = c;
    }
};


std::ostream& operator<<(std::ostream& out, Tetra& param){
    out<< "page: "<<param.list<<"   "<< "column: "<<param.stb<< "   "<<"number: "<<param.str;
    return out;
}


bool operator==(Tetra ap, Tetra bp){
    if (ap.str == bp.str && ap.stb == bp.stb && ap.list == bp.list)
        return true;
    return false;
}


class El{
public:
    std::string a;
    std::vector<Tetra> numb;

    void Append(int a, int b, int c){
        bool flag = true;
        for (int i = 0; i < numb.size(); i++)
            if (numb[i] == Tetra(a,b,c))
                return;
        numb.push_back(Tetra(a,b,c));
    }

    El(std::string e, int p, int b, int c){
        a = e;
        Append(p,b,c);
    }

    El(std::string n){
        a = n;
    }
};


std::ostream& operator<<(std::ostream& out, El& param){
    out<<param.a<<std::endl;
    for (int i = 0; i < param.numb.size(); i++){
        out<<i + 1<< "'st time: "<<param.numb[i]<<std::endl;
    }
    return out;
}


class Dictionary{
public:
    std::vector<El> elem;

    Dictionary(){};

    Dictionary(std::string k, int a, int b, int c){
        elem.push_back(El(k,a,b,c));
    }


    int Find(std::string e){
        for (int i = 0; i < elem.size(); i++){
            if (e == elem[i].a)
                return i;
        }
        return -1;
    }


    void Add(std::string k, int a, int b, int c) {
        if (Find(k) == -1) {
            elem.push_back(El(k, a, b, c));
        }
        else{
            elem[Find(k)].Append(a,b,c);
        }
    }
    };


std::ostream& operator<<(std::ostream& out, Dictionary& param){
    for (int i = 0; i < param.elem.size(); i++){
        out<<param.elem[i]<<std::endl;
    }
    return out;
}