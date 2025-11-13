#pragma once

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node(const T& val);
    T getData();
    void setData(const T& val);
    Node<T>* getNext();
    void setNext(Node<T>* nextNode);
};

#include "Node.tpp"