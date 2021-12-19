#pragma once
#include <string>
#include <vector>
#include <iostream>




class Page {
public:
    std::vector<std::string> p;
    int kol = 0;
    int k = 0;

    Page(int a, int b){
        kol = a;
        k = b;
    }

    void Pushback(std::string all){
            all.push_back(' ');
            std::string s;
            for (int i = 0; i < all.size(); i++){
                if ((all[i] == ' ') && s.size() != 0)
                {
                    Add(s);
                    s.resize(0);
                }
                else
                    if (all[i] != ' ')
                        s.push_back(all[i]);
            }

    }


    void Add(std::string s){
        s.push_back(' ');
        if (p.size() == 0) {
            p.push_back(s);
            return;
        }
        else
        if (p[p.size() - 1].size() + s.size() > kol) {
            p.push_back(s);
            return;
        }
        for (int i = 0; i < s.size(); i++)
            p[p.size() - 1].push_back(s[i]);
        return;
    }


    int Str(int p){
        return p/k + 1;
    }
};




std::ostream& operator<<(std::ostream& out, Page& r){
    for(int i = 0; i < r.p.size(); i++){
        out<<r.p[i]<< std::endl;
    }
    return out;
}


