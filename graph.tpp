#include <iostream>
using namespace std;

#include "Graph.h"
#include "Queue.h"

template <typename T>
Graph<T>::Graph(int capacity) {
    numSquares = capacity;
    adjacencyList = new Square<T>*[numSquares];
    for (int i = 0; i < numSquares; i++) {
        adjacencyList[i] = nullptr;
    }
    count = 0;
}

template <typename T>
Graph<T>::~Graph() {
    for (int i = 0; i < count; i++) {
        delete adjacencyList[i];
    }
    delete[] adjacencyList;
}

template <typename T>
int Graph<T>::indexOf(const T& val) {
    for (int i = 0; i < count; i++) {
        if (adjacencyList[i] -> getData() == val) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Graph<T>::addSquare(const T& val) {
    if (count >= numSquares) {
        cout << "This graph has reached full capacity\n";
        return;
    }
    Square<T>* newSquare = new Square<T>(val);
    adjacencyList[count++] = newSquare;
}

template <typename T>
void Graph<T>::addEdge(const T& val1, const T& val2, bool directed) {
    int indexVal1 = indexOf(val1);
    int indexVal2 = indexOf(val2);
    if (indexVal1 == -1 || indexVal2 == -1) {
        cout << "Square or Squares not in the graph\n";
        return;
    }
    (adjacencyList[indexVal1] -> neighbors) -> insert(val2);
    if (!directed) {
        (adjacencyList[indexVal2] -> neighbors) -> insert(val1);
    }
}

template <typename T>
void Graph<T>::BFS(const T& val) {
    Queue<T> q;
    q.enqueue(val);
    while (!q.isEmpty()) {
        T currentVal = q.dequeue();
        Square<T>* currentSquare = adjacencyList[indexOf(currentVal)];
        if (!(currentSquare -> isVisited())) {
            currentSquare -> setVisited(true);
            cout << currentSquare -> getData() << " -> ";
            Node<T>* neighbor = currentSquare -> neighbors -> getHead();
            while (neighbor) {
                q.enqueue(neighbor -> getData());
                neighbor = neighbor -> getNext();
            }
        }
    }
    for (int i = 0; i < count; i++) {
        adjacencyList[i] -> setVisited(false);
    }
}

template <typename T>
Square<T>** Graph<T>::getAdjacencyList() {
    return adjacencyList;
}