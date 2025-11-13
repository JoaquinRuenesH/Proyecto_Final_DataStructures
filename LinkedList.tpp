#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    Node<T>* temp;
    while (current) {
        temp = current;
        current = current -> getNext();
        delete temp;
    }
    head = nullptr;
}

template <typename T>
void LinkedList<T>::pushFront(const T& val) {
    Node<T>* newNode = new Node<T>(val);

    if (!head) {
        head = newNode;
    } else {
        newNode -> setNext(head);
        head = newNode;
    }
}

template <typename T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

template <typename T>
void LinkedList<T>::printLL() {
    if (!head) {
        cout << "[]";
        return;
    }
    Node<T>* current = head;
    cout << "[";
    while (current -> getNext()) {
        cout << current -> getData() << ", ";
        current = current -> getNext();
    }
    cout << current -> getData() << "]";
}