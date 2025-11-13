#include "Square.h"

template <typename T>
Square<T>::Square(const T& val) {
    data = val;
    visited = false;
    neighbors = new LinkedList<T>;
}

template <typename T>
Square<T>::~Square() {
    delete neighbors;
}

template <typename T>
T Square<T>::getName() {
    return name;
}

template <typename T>
void Square<T>::setName(const T& val) {
    name = val;
}

template <typename T>
bool Square<T>::isVisited() {
    return visited;
}

template <typename T>
void Square<T>::setVisited(bool state) {
    visited = state;
}

template <typename T>
void Square<T>::setId(int id) {
    this -> id = id;
}

template <typename T>
int Square<T>::getId() {
    return id;
}

template <typename T>
void Square<T>::setEP(double EP) {
    encounterProbability = EP;
}

template <typename T>
double Square<T>::getEP() {
    return encounterProbability;
}