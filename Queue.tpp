#include "Queue.h"

template <typename T>
Queue<T>::Queue() {
    head = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
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
void Queue<T>::enqueue(const T& val) {
    Node<T>* newNode = new Node<T>(val);

    if (!head) {
        head = newNode;
    } else {
        newNode -> setNext(head);
        head = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (!head) {
        return T{};
    } else {
        Node<T>* current = head;
        Node<T>* last = head -> getNext();
        if (!last && current) {
            T returnData = current -> getData();
            delete current;
            head = nullptr;
            return returnData;
        }
        while (last -> getNext()) {
            current = current -> getNext();
            last = last -> getNext();
        }
        T returnData = last -> getData();
        current -> setNext(nullptr);
        delete last;
        return returnData;
    }
}

template <typename T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}