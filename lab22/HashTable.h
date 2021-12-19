#pragma once
#include <iostream>
#include "List.h"
#include <vector>
#include <cmath>


    namespace Single {
        template<class T>
        class HashTable {
        public:
            std::vector<Single::List<T>> element;


            HashTable() {}

            HashTable(std::vector<T> v) {
                for (int i = 0; i < v.size(); i++)
                    Append(v[i]);
            }


            void Append(T elem) {
                int rez = HashFunction(elem);
                if (rez == element.size()) {
                    element.push_back(List<T>(elem));
                } else if (rez < element.size()) {
                    element[rez].Append(elem);
                } else if (rez > element.size()) {
                    while (rez > element.size()) {
                        element.push_back(List<T>());
                    }
                    element.push_back(List<T>(elem));
                }
            }


            HashTable(T *v, int length) {
                for (int i = 0; i < length; i++) {
                    int rez = HashFunction(v[i], length);
                    while (element.size() < rez - 1)
                        element.push_back(List<T>());
                    element.push_back(List<T>(v[i]));
                }
            }


            void Delete(T el){
                int rez = HashFunction(el), i = 0;
                Single::List<T>* ptr = &element[rez];
                while (ptr != nullptr){
                    ptr = ptr->next;
                    i++;
                }
                if (i == 1 && element[rez].data == el) {
                    element[rez] = List<T>();
                    return;
                }
                element[rez].Delete(el);
            }


            bool Find(T elem) {
                int k = HashFunction(elem);
                if (element[k].Find(elem)) return true;
                else return false;
            }


        private:

            int HashFunction(T element) {
                return sqrt(abs(element));
            }

        };


        template<class T>
        std::ostream &operator<<(std::ostream &out, HashTable<T> &param) {
            for (int i = 0; i < param.element.size(); i++)
                if (param.element[i].flag == true)
                    out << param.element[i] << ' ';
            return out;
        }
    }



namespace Pair {
    template<class T, class R>
    class HashTable {
    public:
        std::vector<Pair::List<T,R>> element;


        HashTable() {}

        HashTable(std::vector<T> v, std::vector<R> prior) {
            for (int i = 0; i < v.size(); i++)
                Append(v[i], prior[i]);
        }


        void Append(T elem, R prior) {
            int rez = HashFunction(elem);
            if (rez == element.size()) {
                element.push_back(Pair::List<T,R>(elem, prior));
            } else if (rez < element.size()) {
                element[rez].Append(elem, prior);
            } else if (rez > element.size()) {
                while (rez > element.size()) {
                    element.push_back(List<T,R>());
                }
                element.push_back(List<T,R>(elem, prior));
            }
        }


        void Delete(T el){
            int rez = HashFunction(el), i = 0;
            Pair::List<T,R>* ptr = &element[rez];
            while (ptr != nullptr){
                ptr = ptr->next;
                i++;
            }
            if (i == 1 && element[rez].data == el) {
                element[rez] = List<T,R>();
                return;
            }
            element[rez].Delete(el);
        }



        HashTable(T *v,R* p, int length) {
            for (int i = 0; i < length; i++) {
                int rez = HashFunction(v[i], length);
                while (element.size() < rez - 1)
                    element.push_back(List<T,R>());
                element.push_back(List<T,R>(v[i], p[i]));
            }
        }


        bool Find(T elem) {
            int k = HashFunction(elem);
            if (element[k].Find(elem)) return true;
            else return false;
        }


    private:

        int HashFunction(T element) {
            return sqrt(abs(element));
        }

    };


    template<class T, class R>
    std::ostream &operator<<(std::ostream &out, HashTable<T,R> &param) {
        for (int i = 0; i < param.element.size(); i++)
            if (param.element[i].flag == true)
                out << param.element[i] << ' ';
        return out;
    }
}
