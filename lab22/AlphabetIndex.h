#pragma once
#include <iostream>
#include "Dictionary.h"
#include <string>
#include "Page.h"

class AlphabetIndex{
public:
    Dictionary elements;


    AlphabetIndex(){}


    AlphabetIndex(std::string all) {
        int b = 0, c = 0;
        all.push_back(' ');
        std::string s;
        for (int i = 0; i <= all.size(); i++){
            if ((all[i] == ' ' || all[i] ==',' || all[i] =='.' || all[i]=='!' || all[i] == '?' || all[i] == ':' || all[i] ==';' ) && s.size() != 0)
            {
                Add(s, b/42 + 1, b % 42 + 1, c + 1);
                c++;
                s.resize(0);
            }
            else
                if (all[i] == '\n'){
                    Add(s, b/42 + 1, b % 42 + 1, c + 1);
                    b++;
                    c = 0;
                    s.resize(0);
                }
                else s.push_back(all[i]);
        }
    }


    AlphabetIndex(Page ram) {
        std::string s;
        int sum = 1;
        for (int i = 0; i < ram.p.size(); i++){
            for (int j = 0; j < ram.p[i].size(); j++){
                if (( ram.p[i][j] == ' ') && s.size() != 0)
                {
                    Add(s, ram.Str(i), i % ram.k + 1 , sum);
                    s.resize(0);
                    sum++;
                }
                else s.push_back(ram.p[i][j]);
            }
            sum = 1;
        }

    }


    std::vector<Tetra> FindWord(std::string s){
        std::vector<Tetra> a;
        if (elements.Find(s) == 0)
            return a;
        else
            return elements.elem[elements.Find(s)].numb;
    }

    void Add(std::string el, int a, int b, int c){
        elements.Add(el, a, b, c);
    }

};


std::ostream& operator<<(std::ostream& out, AlphabetIndex& el){
    out<<el.elements;
    return out;
}


/*h1 = 17
h2 = 31
hash = h1
for (I = 0; I < count; I++
   hash += item[I] * h2
*/