#include "Node.h"

template <typename T>
Node<T>::Node(const T& val) {
    data = val;
    next = nullptr;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setData(const T& val) {
    data = val;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T>* nextNode) {
    next = nextNode;
}