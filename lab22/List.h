#pragma once
#include <iostream>


namespace Single {
    template<class T>
    class List {
    public:
        T data;
        List *next = nullptr;
        bool flag = false;


        List(T el) {
            data = el;
            next = nullptr;
            flag = true;
        }

        List() {}


        List(const List<T> &el) {
            const List *ptr = &el;
            data = el.data;
            flag = el.flag;
            while (ptr->next) {
                ptr = ptr->next;
                Append(ptr->data);

            }
        }


        void Delete(T el){
            if (FindPtr(el) == nullptr)
                return;
                List *np = this,*ptr = FindPtr(el);
                if (ptr->next == nullptr) {
                    while (np->next != ptr)
                        np = np->next;
                    np->next = nullptr;
                    return;
                }
            if (data == el){
                data = next->data;
                flag = next->flag;
                next = next->next;
                return;
            }
            while (np->next != ptr)
                np = np->next;
            np->next = np->next->next;
            return;
        }


        void Append(T element) {
            List *ptr = next, *np = this;
            while (ptr != nullptr) {
                np = ptr;
                ptr = ptr->next;
            }
            np->flag = true;
            np->next = new List<T>(element);
        }


        bool Find(T elem) {
            if (data == elem)
                return true;
            List *ptr = next;
            while (ptr) {
                if (ptr->data == elem)
                    return true;
                ptr = ptr->next;
            }
            return false;
        }


        List* FindPtr(T elem) {
            if (data == elem)
                return this;
            List *ptr = next;
            while (ptr) {
                if (ptr->data == elem)
                    return ptr;
                ptr = ptr->next;
            }
            return nullptr;
        }



        ~List() {
            delete next;
        }


        List &operator=(List<T> el) {
            std::swap(data, el.data);
            std::swap(next, el.next);
            std::swap(flag, el.flag);
            return *this;
        }
    };

    template<class T>
    std::ostream &operator<<(std::ostream &out, List<T> &param) {
        List<T> *ptr = &param;
        out << "{ ";
        while (ptr) {
            if (ptr->flag == true) {
                out << ptr->data;
                if (ptr->next != nullptr)
                    out << " -> ";
            }
            ptr = ptr->next;
        }
        out << " }";
        return out;
    }
}




namespace Pair{
        template<class T, class R>
        class List {
        public:
            T data;
            List *next = nullptr;
            bool flag = false;
            R priorety;

            List(T el, R prior) {
                data = el;
                next = nullptr;
                flag = true;
                priorety = prior;
            }

            List() {}


            List(const List<T,R> &el) {
                const List *ptr = &el;
                data = el.data;
                flag = el.flag;
                priorety = el.priorety;
                while (ptr->next) {
                    ptr = ptr->next;
                    Append(ptr->data, ptr->priorety);
                }
            }


            List* FindPtr(T elem) {
                if (data == elem)
                    return this;
                List *ptr = next;
                while (ptr) {
                    if (ptr->data == elem)
                        return ptr;
                    ptr = ptr->next;
                }
                return nullptr;
            }


            void Append(T element, R prior) {
                List *ptr = next, *np = this;
                while (ptr != nullptr) {
                    np = ptr;
                    ptr = ptr->next;
                }
                np->flag = true;
                np->next = new List<T,R>(element, prior);
            }


            void Delete(T el){
                if (FindPtr(el) == nullptr)
                    return;
                List *np = this,*ptr = FindPtr(el);
                if (ptr->next == nullptr) {
                    while (np->next != ptr)
                        np = np->next;
                    np->next = nullptr;
                    return;
                }
                if (data == el){
                    data = next->data;
                    flag = next->flag;
                    priorety = next->priorety;
                    next = next->next;
                    return;
                }
                while (np->next != ptr)
                    np = np->next;
                np->next = np->next->next;
                return;
            }


            bool Find(T elem) {
                if (data == elem)
                    return true;
                List *ptr = next;
                while (ptr) {
                    if (ptr->data == elem)
                        return true;
                    ptr = ptr->next;
                }
                return false;
            }


            ~List() {
                delete next;
            }


            List &operator=(List<T,R> el) {
                std::swap(data, el.data);
                std::swap(next, el.next);
                std::swap(flag, el.flag);
                std::swap(priorety, el.priorety);
                return *this;
            }
        };

        template<class T, class R>
        std::ostream &operator<<(std::ostream &out, List<T,R> &param) {
            List<T,R> *ptr = &param;
            out << "{ ";
            while (ptr) {
                if (ptr->flag == true) {
                    out << ptr->data;
                    if (ptr->next != nullptr)
                        out << " -> ";
                }
                ptr = ptr->next;
            }
            out << " }";
            return out;
        }
    }