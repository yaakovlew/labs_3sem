#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ComutatedNets.h"
using namespace std;

void MenuNetActions(ComutatedNets count);


void MenuNet() {
    cout << "How much servers u would like to use: ";
    int amount;
    cin >> amount;
    vector<string> name;
    string s;
    for (int i = 0; i < amount; i++) {
        cout << "Server's name: ";
        cin >> s;
        getchar();
        name.push_back(s);
    }
    vector<vector<int>> el;
    vector<int> k(amount);
    int ck;
    for (int i = 0; i < amount; i++)
        el.push_back(k);
    cout << "Connection over servers (if there is connection write ping over they, else write zero): ";
    for (int i = 0; i < amount; i++) {
             cout << endl;
        for (int j = i + 1; j < amount; j++){
            cout << name[i]
                 <<" -> "
                 <<name[j]
                 <<": ";
            cin >> el[i][j];
            el[j][i] = el[i][j];
        }
    }
    cout << "How much packeges u would like to send:";
    int number;
    cin >> number;
    vector<pair<string, string>> vec(number);
    cout << endl;
    for (int i = 0; i < number; i++) {
        cout << "write from: ";
        string s1, s2;
        cin >> s1;
        getchar();
        cout << "wtrite to: ";
        cin >> s2;
        getchar();
        pair<string ,string> pairs(s1,s2);
        vec[i] = pairs;
    }
    cout << endl
         <<"Write dangerous meaning: ";
    int mean;
    cin >> mean;
    ComutatedNets count(name, el, vec, mean);
    MenuNetActions(count);
    return;
}

void MenuNetActions(ComutatedNets count){
    cout << "1 - to get server's ping"
         <<endl
         << "2 - to append server "
         <<endl
         << "3 - to send packegies"
         <<endl
         <<"4 - to out servers"
         <<endl
         <<"0 - to EXIT"
         <<endl
         <<"Your choose: ";
    int ch = 0;
    cin >> ch;
    if (ch == 1){
        cout << "First server: ";
        string s1;
        cin >> s1;
        getchar();
        cout << "Second server: ";
        string s2;
        cin >> s2;
        getchar();
        cout <<"Ping: "<< count.GetPing(s1, s2) << endl;
        MenuNetActions(count);
    }
    else
        if (ch == 2){
            cout << "write name: ";
            string sname;
            cin >> sname;
            getchar();
            vector<int> p(count.elements.size());
            for (int i = 0; i < count.elements.size(); i++){
                cout << "write ping from " << sname <<" to "<< count.names_of_graph[i] << ": ";
                cin >> p[i];
                cout << endl;
            }
            count.elements.distance.append(p);
            cout << "Ready" << endl;
            MenuNetActions(count);
        }
        else
            if (ch == 3){
                vector<vector<int>> steps = count.SendPackegies();
                for (int i = 0; i < steps.size(); i++){
                    for (int j = 0; j < steps[i].size(); j++){
                        cout << count.names_of_graph[steps[i][j]];
                        if (j + 1 != steps[i].size())
                            cout << " -> ";
                    }
                    cout << endl;
                }
                cout << endl;
                MenuNetActions(count);
            }
    if(ch == 4){
        cout << count << endl;
        MenuNetActions(count);
    }
    else return;
}