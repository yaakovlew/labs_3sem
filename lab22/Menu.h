#pragma once
#include <iostream>
#include "Subsequence.h"
#include "Page.h"
#include "AlphabetIndex.h"


void Menu(int);

void MenuAlphabet(Page k) {
    AlphabetIndex a(k);
    std::cout << "1 - to show Index of Alphabet";
    std::cout << std::endl;
    std::cout << "2 - to add element, if you know it possition";
    std::cout << std::endl;
    std::cout << "0 - to exit in main Menu";
    std::cout << std::endl;
    std::cout << "everyone number to exit from programm";
    std::cout << std::endl;
    std::cout << "Your choose: ";
    int ch;
    std::cin >> ch;
    std::cout << std::endl;
    while (ch == 1 || ch == 2 || ch == 0) {
        if (ch == 1) {
            std::cout << a;
            std::cout << "1 - to show Index of Alphabet";
            std::cout << std::endl;
            std::cout << "2 - to add element, if you know it possition";
            std::cout << std::endl;
            std::cout << "0 - to exit in main Menu";
            std::cout << std::endl;
            std::cout << "everyone number to exit from programm";
            std::cout << std::endl;
            std::cout << "Your choose: ";
            std::cin>>ch;
            std::cout<<std::endl;
        }
        else if (ch == 2) {
            std::string s;
            std::cout<<"Write word: ";
            getline(std::cin, s);
            getline(std::cin, s);
            std::cout << std::endl;
            int fd, b, c;
            std::cout << "Write possition page, line, nubmer on line: ";
            std::cin >> fd >> b >> c;
            a.Add(s, fd, b, c);
            std::cout << "1 - to show Index of Alphabet";
            std::cout << std::endl;
            std::cout << "2 - to add element, if you know it possition";
            std::cout << std::endl;
            std::cout << "0 - to exit in main Menu";
            std::cout << std::endl;
            std::cout << "everyone number to exit from programm";
            std::cout << std::endl;
            std::cout << "Your choose: ";
            std::cin>>ch;
            std::cout<<std::endl;
        } else if (ch == 0) {
            Menu(0);
            return;
        } else return;
    }
}



void MenuSequence(Page k) {
    Subsequence a(k);
    std::cout << "1 - to show most common element";
    std::cout << std::endl;
    std::cout << "2 - to find element";
    std::cout << std::endl;
    std::cout << "0 - to exit in main Menu";
    std::cout << std::endl;
    std::cout << "everyone number to exit from programm";
    std::cout << std::endl;
    std::cout << "Your choose: ";
    int ch;
    std::cin >> ch;
    std::cout << std::endl;
    while (ch == 1 || ch == 2 || ch == 0) {
        if (ch == 1) {
            std::cout<<a;
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout << "1 - to show most common element";
            std::cout << std::endl;
            std::cout << "2 - to find element";
            std::cout << std::endl;
            std::cout << "0 - to exit in main Menu";
            std::cout << std::endl;
            std::cout << "everyone number to exit from programm";
            std::cout << std::endl;
            std::cout << "Your choose: ";
            std::cin>>ch;
            std::cout<<std::endl;
        }
        else
            if(ch == 2){
                std::string s;
                std::string p;
                getline(std::cin, s);
                std::cout<<"Write word: ";
                getline(std::cin, s);
                std::cout<<std::endl;
                if (a.Find(s) == true)
                    std::cout<<"Found"<<std::endl;
                else
                    std::cout<<"Not Found"<<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;
                std::cout << "1 - to show most common element";
                std::cout << std::endl;
                std::cout << "2 - to find element";
                std::cout << std::endl;
                std::cout << "0 - to exit in main Menu";
                std::cout << std::endl;
                std::cout << "everyone number to exit from programm";
                std::cout << std::endl;
                std::cout << "Your choose: ";
                std::cin>>ch;
                std::cout<<std::endl;
            }
        else if (ch == 0) {
            Menu(0);
                return;
        } else return;
    }
}



void Menu(int arep) {
    std::cout << "1 - to write page";
    std::cout << std::endl;
    std::cout << "Your choose: ";
    std::cin>>arep;
        if (arep == 1) {
            int a, b;
            std::cout << "How much symbols you would like to use in the page: ";
            std::cin >> a;
            std::cout << "How much lines you would like to use in the page: ";
            std::cin >> b;
            std::cout << std::endl;
            Page k(a, b);
            std::string s;
            getline(std::cin, s);
            std::cout << "Include text from page in line: ";
            getline(std::cin, s);
            k.Pushback(s);
            std::cout << std::endl;
            int choose;
            std::cout << "1 - to use Index of Alphabet"
                      << std::endl
                      << "2 - to use Subsequence"
                      << std::endl
                      << "3 - to show page"
                      << std::endl
                      << "0 - to exit "
                      << std::endl << "Your choose:";
            std::cin >> choose;
            while (choose == 1 || choose == 2 || choose == 3) {
                if (choose == 1)
                    MenuAlphabet(k);
                else if (choose == 2)
                    MenuSequence(k);
                else
                    if (choose == 3) {
                    std::cout << k;
                    std::cout << ::std::endl;
                }
                std::cout << "1 - to use Index of Alphabet"
                          << std::endl
                          << "2 - to use Subsequence"
                          << std::endl
                          << "3 - to show page"
                          << std::endl
                          << "0 - to exit "
                          << std::endl << "Your choose:";
                std::cin >> choose;
            }
        }
}