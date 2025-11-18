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
    Node<T>* getNode(const T& val);
    void printLL();
    void printLLTuples();
};

template <typename U>
class Square;

template <typename U>
static Square<U>* getSquare(LinkedList<Square<U>*>* list, const U& val);

#include "LinkedList.tpp"