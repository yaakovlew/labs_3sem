#pragma once

#include <iostream>
#include "UnDirectedGraph.h"
#include <vector>
#include <string>
#include <string_view>


using namespace std;


class ComutatedNets {

public:

    UnDirectedGraph<int> elements;
    vector<string> names_of_graph;
    vector<pair<string, string>> direction;
    int amount_for_broke_server = 0;


    ComutatedNets(vector<string> names, UnDirectedGraph<int> el, vector<pair<string, string>> direct, int amount) {
        names_of_graph = names;
        elements = el;
        direction = direct;
        amount_for_broke_server = amount;
    }


    ComutatedNets(vector<string> names, vector<vector<int>> MatrixDistance, vector<pair<string, string>> direct,
                  int amount) {
        names_of_graph = names;
        vector<int> weight;
        for (int i = 0; i < names.size(); i++)
            weight.push_back(0);
        elements = UnDirectedGraph<int>(MatrixDistance, weight);
        direction = direct;
        amount_for_broke_server = amount;
    }


    ComutatedNets(vector<string> names, Matrix<int> MatrixDistance, vector<pair<string, string>> direct, int amount) {
        names_of_graph = names;
        vector<int> weight;
        for (int i = 0; i < names.size(); i++)
            weight.push_back(0);
        elements = UnDirectedGraph<int>(MatrixDistance, weight);
        direction = direct;
        amount_for_broke_server = amount;
    }


    ComutatedNets() {
        elements = UnDirectedGraph<int>();
    }


    void AppendNetvertex(string name, vector<int> connection, int ping) {
        names_of_graph.push_back(name);
        elements.append(connection, ping);
    }


    int GetPing(string name1, string name2) {
        int index1 = 0;
        for (int i = 0; i < names_of_graph.size(); i++) {
            if (names_of_graph[i] == name1)
                index1 = i + 1;
        }
        int index2 = 0;
        for (int i = 0; i < names_of_graph.size(); i++) {
            if (names_of_graph[i] == name2)
                index2 = i + 1;
        }
        return elements.get_distance(index1, index2);
    }


    vector<vector<int>> SendPackegies() {
        auto direct = direction;
        UnDirectedGraph<int> copy = elements;
        vector<vector<int>> steps(direct.size());
        vector<vector<int>> broke(elements.size());
        for (int i = 0; i < direct.size(); i++) {
            steps[i].push_back(GetIndex(direct[i].first));
            copy.weight[GetIndex(direct[i].first)]++;
        }
        for (int i = 0; i < elements.size(); i++) {
            for (int j = 0; j < steps.size(); j++) {

                auto last_step = [&](int offset = 1) {
                    return steps[j][steps[j].size() - offset];
                };

                if (last_step() != GetIndex(direct[j].second)) {
                    int next = GetPathPackage(copy, last_step(), GetIndex(direct[j].second));
                    steps[j].push_back(next);
                        copy.distance[steps[j].size() - 1][steps[j].size() - 2] *= 2;
                        copy.distance[steps[j].size() - 1][steps[j].size() - 2] *= 2;
                    if (steps[j].size() > 2) {
                        copy.distance[steps[j].size() - 2][steps[j].size() - 3] /= 2;
                        copy.distance[steps[j].size() - 3][steps[j].size() - 2] /= 2;
                    }
                    if (copy.weight[last_step()] >= amount_for_broke_server){
                        broke[last_step()] = copy.distance[last_step()];
                        for (int i = 0; i < copy.distance[last_step()].size(); i++) {
                            copy.distance[last_step()][i] = 0;
                            copy.distance[i][last_step()] = 0;
                        }
                    }
                    }
                }
            for (int i = 0; i < broke.size(); i++){
                if (broke[i].size() != 0) {
                    copy.distance[i] = broke[i];
                }
                for (int j = 0; j < broke[i].size(); j++){
                    copy.distance[j][i] = broke[i][j];
                }
            }
            }
        return steps;
    }


private:

    string GetName(int index) {
        return names_of_graph[index];
    }


    int GetIndex(string name) {
        int index = -1;
        for (int i = 0; i < elements.size(); i++) {
            if (names_of_graph[i] == name)
                index = i;
        }
        return index;
    }


    int GetPathPackage(UnDirectedGraph<int> copy, int index1, int index2) {
        string s = copy.shortest_way(++index1, ++index2);
        string_view sv = s;
        int count = sv.find("->");
        sv.remove_prefix(count + 2);
        count = sv.find("->");
        int k = stoi(string(sv.substr(0, count)));
        k--;
        return k;
    }
};


ostream &operator<<(ostream &out, const ComutatedNets &copy) {
    out << "Available Networks:"
        << endl;
    for (int i = 0; i < copy.names_of_graph.size(); i++)
        out << copy.names_of_graph[i] << ' ';
    out << endl
        << endl
        << copy.elements.distance
        << endl
        << "Required operations: "
        << endl;
    for (int i = 0; i < copy.direction.size(); i++)
        out << copy.direction[i].first
            << " -> "
            << copy.direction[i].second
            << endl;
    return out;
}



/*while (k < elements.size()){
            for (int i = 0; i < direct.size(); i++){
                if ( k != 0 && steps[i][k - 1] != GetIndex(direct[i].second) - 1) {
                    steps[i].push_back(GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second)) - 1);
                    copy.distance[steps[i][k] - 1][GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second)) - 1] = copy.distance[steps[i][k] - 1][GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second)) - 1] * 2;
                    copy.weight[steps[i][k] - 1]--;
                    copy.weight[GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second)) - 1]++;
                    if (copy.weight[GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second)) - 1] >= amount_for_broke_server){
                        broke[GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second))] = copy.distance[GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second))];
                        for (int chet = 0 ; chet < elements.size(); chet++){
                            copy.distance[chet][GetPathPackage(copy, steps[i][k], GetIndex(direct[i].second)) - 1] = 0;
                        }
                    }
                }*/