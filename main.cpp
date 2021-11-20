#include <iostream>
#include "SortInputData.h"
#include <time.h>
#include "Menu.h"
#include <random>
#include "Algorithms.h"

std::ostream& operator<< (std::ostream &out, SortInputData<int> &type){
    out<<"Length: "<< type.Length();
    out<<std::endl;
    out<<"Original data: ";
    for (int i = 0; i < type.Length(); i++)
        out << type.Original()[i] << ' ';
    out<<std::endl;
    for (int i = 0; i < type.Data.size(); i++){
        out<<type.Data[i].NameOfSort<<": "<<std::endl;
        for (int j = 0; j < type.Data[i].SortData.size(); j++)
            out<<type.Data[i].SortData[j]<<" ";
        out<<std::endl<<"Time of "
            <<type.Data[i].NameOfSort
            <<": "<<type.Data[i].Time
            <<" mcs"
            <<std::endl;
    }
    return out;
}


int main() {
    /*int rep = 1;
    while (rep != 0) {
        std::cout << GREEN
                  << "1 - To create new vector"
                  << std::endl
                  << RED
                  << "0 - To EXIT"
                  << GREEN
                  << std::endl
                  <<"Your choose: ";
        std::cin>>rep;
        std::cout<<std::endl;
        Menu<int> p;
    }
     */
    std::vector<int> p;
    for (int i = 0; i < 10000; i++)
        p.push_back(rand() * 100000 );
    SortInputData<int> test = SortInputData<int>(p);
    test.AppendAlgorithmOfSort("Quick Sort", QuickSort<int>);
    test.AppendAlgorithmOfSort("Bubble Sort", BubbleSort<int>);
    std::cout<<test;
    return 0;
}
//174267  843547
