#pragma once
#include "ComutatedNets.h"
#include <assert.h>


void Test_commutated_net1(){
    vector<vector<int>> steps = {{1,5,3}, {2,1}, {1}};
    vector<string> name = {"Russia", "Germany", "England", "Poland"};
    pair<string, string> el1("Germany", "England");
    pair<string, string> el2("Russia", "England");
    pair<string, string> el3("England", "Russia");
    vector<pair<string, string>> direction = {el1, el2, el3};
    int amount = 2;
    Matrix<int> m(steps);
    ComutatedNets Net(name, steps, direction, 2);
    assert(Net.amount_for_broke_server == 2);
    assert(Net.direction == direction);
    assert(Net.names_of_graph == name);
}


void Test_commutated_net2(){
    vector<vector<int>> steps = {{1,5,3}, {2,1}, {1}};
    vector<string> name = {"Russia", "Germany", "England", "Poland"};
    pair<string, string> el1("Germany", "England");
    pair<string, string> el2("Russia", "England");
    pair<string, string> el3("England", "Russia");
    vector<pair<string, string>> direction = {el1, el2, el3};
    int amount = 2;
    Matrix<int> m(steps);
    ComutatedNets Net(name, m, direction, 2);
    assert(Net.amount_for_broke_server == 2);
    assert(Net.direction == direction);
    assert(Net.names_of_graph == name);
}


void Test_commutated_net3(){
    vector<vector<int>> steps = {{1,5,3}, {2,1}, {1}};
    vector<string> name = {"Russia", "Germany", "England", "Poland"};
    pair<string, string> el1("Germany", "England");
    pair<string, string> el2("Russia", "England");
    pair<string, string> el3("England", "Russia");
    vector<pair<string, string>> direction = {el1, el2, el3};
    int amount = 2;
    Matrix<int> m(steps);
    ComutatedNets Net(name, m, direction, 2);
    assert(Net.amount_for_broke_server == 2);
    assert(Net.direction == direction);
    assert(Net.names_of_graph == name);
}


void Test_ping(){
    vector<vector<int>> steps = {{1,5,3}, {2,1}, {1}};
    vector<string> name = {"Russia", "Germany", "England", "Poland"};
    pair<string, string> el1("Germany", "England");
    pair<string, string> el2("Russia", "England");
    pair<string, string> el3("England", "Russia");
    vector<pair<string, string>> direction = {el1, el2, el3};
    int amount = 2;
    Matrix<int> m(steps);
    ComutatedNets Net(name, m, direction, 2);
    assert(Net.amount_for_broke_server == 2);
    assert(Net.direction == direction);
    assert(Net.names_of_graph == name);
    assert(Net.GetPing("Germany", "Germany") == 0);
}


void Test_packeges(){
    vector<vector<int>> steps = {{1,5,3}, {2,1}, {1}};
    vector<string> name = {"Russia", "Germany", "England", "Poland"};
    pair<string, string> el1("Germany", "England");
    pair<string, string> el2("Russia", "England");
    pair<string, string> el3("England", "Russia");
    vector<pair<string, string>> direction = {el1, el2, el3};
    int amount = 2;
    Matrix<int> m(steps);
    ComutatedNets Net(name, m, direction, 2);
    assert(Net.amount_for_broke_server == 2);
    assert(Net.direction == direction);
    assert(Net.names_of_graph == name);
    assert(Net.GetPing("Germany", "Germany") == 0);
    vector<vector<int>> el = Net.SendPackegies();
    assert(el[0][0] == 1);
}

