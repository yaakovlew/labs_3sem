#pragma once
#include "DirectionGraph.h"
#include "UnDirectedGraph.h"
#include <iostream>
#include "Matrix.h"
using namespace std;

void MenuNtGraph(UnDirectedGraph<int> g);

void MenuDGraph(DirectionGraph<int> g);

void MenuNtAction(UnDirectedGraph<int> g){
    cout << "1 - to append vertex"
         << endl
         << "2 - to get size"
         << endl
         << "3 - to get incedention's matrix"
         << endl
         << "4 - to get weight"
         << endl
         << "5 - to get distance between graphs"
         << endl
         << "6 - to get shortest length"
         << endl
         << "7 - to get shortest way"
         << endl
         << "8 - to get distantance's matrix"
         <<endl
         << "9 - to exit in main menu"
         << endl
         << "0 - EXIT"
         <<endl
         <<"Your choose: ";
    int ch;
    cin >> ch;
    cout << endl;
    if ( ch == 1){
    }
    if (ch == 2){
        cout << "size:" << g.size() << endl;
        MenuNtAction(g);
    }
    if (ch == 3){
        cout << "Incedention's graph "
             << endl
             << g.matrix_incedention();
        MenuNtAction(g);
    }
    else
    if (ch == 4){
        int h;
        cout << "get vertex: ";
        cin >> h;
        cout << endl
             << "weight: "
             << g.get_weight(h)
             << endl;
        MenuNtAction(g);
    }
    else
    if (ch == 5) {
        cout << endl
             << "write first vertex: ";
        int h1;
        cin >> h1;
        cout << endl
             << "write second vertex: ";
        int h2;
        cin >> h2;
        if (g.get_distance(h1, h2) == -1) {
            cout << "NOT FOUND !!!";
            MenuNtAction(g);
        }
        else {
            cout << "Length: "
                 << g.get_distance(h1, h2)
                 << endl;
            MenuNtAction(g);
        }
    }
    else
    if (ch == 6){
        cout << endl
             << "write first vertex: ";
        int h1;
        cin >> h1;
        cout << endl
             << "write second vertex: ";
        int h2;
        cin >> h2;
        cout << endl
             << "shortest length: "
             << g.shortest_length(h1, h2)
             << endl;
        MenuNtAction(g);
    }
    else
    if (ch == 7){
        cout << endl
             << "write first vertex: ";
        int h1;
        cin >> h1;
        cout << endl
             << "write second vertex: ";
        int h2;
        cin >> h2;
        cout << endl
             << "shortest length: "
             << g.shortest_way(h1, h2)
             << endl;
        MenuNtAction(g);
    }
    else
    if (ch == 8){
        cout << "Distance's matrix:"
             << endl
             << g.distance;
        MenuNtAction(g);
    }
    else
    if (ch == 9){
        MenuNtGraph(g);
    }
    else
    if (ch == 0)
        return;
    else
        MenuNtAction(g);
}


void MenuNtGraph(UnDirectedGraph<int> g) {
    cout << " 1 - to use old graph"
         << endl
         << " 2 - to use new graph"
         << endl
         << " 0 - EXIT"
         << endl
         << "Your choose: ";
    int ch;
    cin >> ch;
    if (ch == 1) {
        MenuNtAction(g);
        return;
    } else if (ch != 1 && ch != 2)
        return;
    else {
        int size;
        cout << "How much elements you would like to use: ";
        cin >> size;
        cout << endl;
        vector<vector<int>> el;
        vector<int> k(size);
        int ch;
        for (int i = 0; i < size; i++)
            el.push_back(k);
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                cout << "Distance "
                     << i + 1
                     << " -> "
                     << j + 1
                     << ": ";
                cin >> el[i][j];
                el[j][i] = el[i][j];
                cout<<endl;
            }
        }
        for (int i = 0; i < size; i++) {
            cout << "   weight " << i + 1 << ": ";
            cin >> k[i];
        }
        UnDirectedGraph<int> graph(el, k);
        MenuNtAction(graph);
        return;
    }
}

void MenuActionDGraph(DirectionGraph<int> g){
    cout << "1 - to append vertex"
         << endl
         << "2 - to get size"
         << endl
         << "3 - to get incedention's matrix"
         << endl
         << "4 - to get weight"
         << endl
         << "5 - to get distance between graphs"
         << endl
         << "6 - to get distantance's matrix"
         <<endl
         << "7 - to exit in main menu"
         << endl
         << "0 - EXIT"
         <<endl
         <<"Your choose: ";
    int ch;
    cin >> ch;
    cout << endl;
    if ( ch == 1){
    }
    if (ch == 2){
        cout << "size:" << g.size() << endl;
        MenuActionDGraph(g);
    }
    if (ch == 3){
        cout << "Incedention's graph "
             << endl
             << g.matrix_incedention();
        MenuActionDGraph(g);
    }
    else
    if (ch == 4){
        int h;
        cout << "get vertex: ";
        cin >> h;
        cout << endl
             << "weight: "
             << g.get_weight(h)
             << endl;
        MenuActionDGraph(g);
    }
    else
    if (ch == 5) {
        cout << endl
             << "write first vertex: ";
        int h1;
        cin >> h1;
        cout << endl
             << "write second vertex: ";
        int h2;
        cin >> h2;
        if (g.get_distance(h1, h2) == -1) {
            cout << "NOT FOUND !!!"
                 << endl;
            MenuActionDGraph(g);
        }
        else {
            cout << "Length: "
                 << g.get_distance(h1, h2)
                 << endl;
            MenuActionDGraph(g);
        }
    }
    else
    if (ch == 6){
        cout << "Distance's matrix:"
             << endl
             << g.distance;
        MenuActionDGraph(g);
    }
    else
    if (ch == 7){
        MenuDGraph(g);
    }
    else
    if (ch == 0)
        return;
    else
        MenuActionDGraph(g);
}


void MenuDGraph(DirectionGraph<int> g){
    cout << " 1 - to use old graph"
         << endl
         << " 2 - to use new graph"
         << endl
         << " 0 - EXIT"
         << endl
         << "Your choose: ";
    int ch;
    cin >> ch;
    if (ch == 1) {
        MenuActionDGraph(g);
        return;
    } else if (ch != 1 && ch != 2)
        return;
    else {
        int size;
        cout << "How much elements you would like to use: ";
        cin >> size;
        cout << endl;
        vector<vector<int>> el;
        vector<int> k(size);
        for (int i = 0; i < size; i++)
            el.push_back(k);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    cout << "Distance "
                         << i + 1
                         << " -> "
                         << j + 1
                         << ": ";
                    cin >> el[i][j];
                    cout << endl;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            cout << "   weight " << i + 1 << ": ";
            cin >> k[i];
        }
        DirectionGraph<int> graph(el, k);
        MenuActionDGraph(graph);
        return;
    }
}


void Menu(){
    cout<<"1 - to use direction graph"
        <<endl
        <<"2 - to use not direction graph"
        <<endl
        <<"0 - to EXIT"
        <<endl
        <<"Your choose: ";
    int ch;
    cin >> ch;
    cout << endl;
    if (ch == 1) {
        DirectionGraph<int> g;
        MenuDGraph(g);
    }
    else
        if ( ch == 2 ) {
            UnDirectedGraph<int> g;
            MenuNtGraph(g);
        }
        else
            return;
}