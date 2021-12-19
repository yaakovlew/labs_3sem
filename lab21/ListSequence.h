#pragma once
#include <iostream>
#include "IndexOutOfRange.h"

using namespace std;


template <class T>
class LinkedList{

public:

    typedef struct List{
        T data_element;
        struct List* point_to_next_element;
    }List;


    void Prepend(T item){
        List *element1 = new List;
        element1->data_element = item;
        element1->point_to_next_element = nullptr;
        length++;
        if (head == nullptr){
            head = element1;
            end = element1;
            return;
        }
        element1->point_to_next_element = head;
        head = element1;
    }

    void Append(T item){
        List *element1 = new List;
        element1->data_element = item;
        element1->point_to_next_element = nullptr;

        length++;

        if (head == nullptr){
            head = element1;
            end = element1;
            return;
        }

        end->point_to_next_element = element1;
        end = element1;
    }

    LinkedList (T* items, int count){
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }

    LinkedList(){};

    LinkedList (const LinkedList<T>&copy){
        head = copy.head;
        end = copy.end;
        length = copy.length;
    }


    void InsertAt(T item, int index) {
        IndexOutOfRangeexeption ex;
        if (index < 0 || index > length) {
            cout << ex.er1 << endl;
            return;
        }

        if (index == length){
            Append(item);
            return;
        }

        if (index == 0){
            Prepend(item);
            return;
        }
        List *newlist = new List;
        newlist->data_element = item;
        List *ptr_earlier, *ptr = head, *ptr_next;
        for (int i = 0; i < index; i++) {
            if (i + 1 == index)
                ptr_earlier = ptr;
            ptr = ptr->point_to_next_element;
        }
        ptr_next = ptr->point_to_next_element;
        ptr_earlier->point_to_next_element = newlist;
        newlist->point_to_next_element = ptr;
        length++;
    }

    T Get_First(){
        return head->data_element;
    }


    T Get_last(){
        return end->data_element;
    }

    int Get_length(){
        return length;
    }

    T Get(int index)const{
        IndexOutOfRangeexeption ex;
        if (index < 0 || index >= length)
            throw ex.er;
        List *ptr = head;
        for (int i = 0; i < index; i++)
            ptr = ptr->point_to_next_element;
        return ptr->data_element;
    }


    void Concat(LinkedList* copy){
        length = length + copy->length;
        List* ptr = copy->head;
        for (int i = 0; i < copy->length; i++){
            Append(ptr->data_element);
            ptr = ptr->point_to_next_element;
        }

    }


    LinkedList* GetSubList(int startIndex, int endIndex) {
        List* ptr = new List;
        ptr = head;
        int i = 0;
        T arr[endIndex - startIndex];
        for (i = 0; i < startIndex; i++)
            ptr = ptr->point_to_next_element;
        for (i; i < endIndex; i++) {
            arr[i - startIndex] = ptr->data_element;
            ptr = ptr->point_to_next_element;
        }
        LinkedList<T> *elem = new LinkedList<T>(arr, endIndex - startIndex);
        return elem;
    }





private:
    int length = 0;
    List* head = nullptr;
    List* end = nullptr;

};
