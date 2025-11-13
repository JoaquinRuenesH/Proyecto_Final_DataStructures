#pragma once
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();
    void pushFront(const T& val);
    Node<T>* getHead();
    void printLL();
};

#include "LinkedList.tpp"