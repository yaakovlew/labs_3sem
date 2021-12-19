#include <iostream>
#include "fstream"
#include <string>
#include <vector>
#include "Dictionary.h"
#include "AlphabetIndex.h"
#include "Subsequence.h"
#include "Page.h"
#include "Menu.h"


std::string WorkwithFile(){
    std::string line;

    std::ifstream in("C:\\Users\\andre\\CLionProjects\\lab22\\File.txt");
    if (in.is_open()) {
        while (getline(in, line)) {}
    }
    in.close();
    return line;
}




int main() {
    Menu(1);
}