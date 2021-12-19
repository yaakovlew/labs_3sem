#pragma once
#include "AlphabetIndex.h"
#include <string>
#include <vector>
#include "Page.h"


class Subsequence{
public:
    AlphabetIndex elem;

    Subsequence(){}



    Subsequence(std::string all) {
        int b = 0, c = 0;
        all.push_back(' ');
        std::string s;
        std::vector<std::string> e;
        for (int i = 0; i <= all.size(); i++) {
            if ((all[i] == ' ' || all[i] == ',' || all[i] == '.' || all[i] == '!' || all[i] == '?' || all[i] == ':' ||
                 all[i] == ';') && s.size() != 0) {
                e.push_back(s);
                c++;
                s.resize(0);
            } else if (all[i] == '\n') {
                e.push_back(s);
                b++;
                c = 0;
                s.resize(0);
            } else s.push_back(all[i]);
        }
        e.push_back("End");


        for (int i = 0; i < e.size() - 1; i++) {
            e[i].push_back(' ');
            elem.Add(e[i] + e[i + 1], i, i, i);
        }
    }


    Subsequence(Page ram) {
        std::string s;
        int sum = 1;
        for (int i = 0; i < ram.p.size(); i++){
            for (int j = 0; j < ram.p[i].size(); j++){
                if (( ram.p[i][j] == ' ') && s.size() != 0)
                {
                    elem.Add(s, ram.Str(i), i % ram.k + 1 , sum);
                    s.resize(0);
                    sum++;
                }
                else s.push_back(ram.p[i][j]);
            }
            sum = 1;
        }

    }


    bool Find(std::string s){
        if (elem.FindWord(s).size() != 0)
            return true;
        return false;
    }



    std::string Max(){
        int amount = 0;
        std::string s;
        for (int i = 0; i <= elem.elements.elem.size(); i++){
            if (elem.elements.elem[i].numb.size() > amount){
                amount = elem.elements.elem[i].numb.size();
                s =  elem.elements.elem[i].a;
        }
    }
        return s;
}
};




std::ostream& operator<<(std::ostream& out, Subsequence& el) {
    out << el.Max();
    return out;
}
