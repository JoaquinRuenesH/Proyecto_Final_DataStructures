#pragma once
#include "Node.h"

template <typename T>
class Queue {
private:
    Node<T>* head;
public:
    Queue();
    ~Queue();
    void enqueue(const T& val);
    T dequeue();
    bool isEmpty();
    void clear();
};

#include "Queue.tpp"