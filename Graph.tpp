#include <iostream>
using namespace std;

#include "Graph.h"
#include "Queue.h"
#include "LinkedList.h"

template <typename T>
Graph<T>::Graph(int capacity) {
    numSquares = capacity;
    adjacencyList = new Square<T>*[numSquares];
    for (int i = 0; i < numSquares; i++) {
        adjacencyList[i] = nullptr;
    }
    count = 0;
    treasureSquare = T{};
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
        if (adjacencyList[i] -> getName() == val) {
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
void Graph<T>::addTreasure(const T& val) {
    treasureSquareName = val;
    adjacencyList[indexOf(treasureSquare)] -> setTreasure(true);
}

template <typename T>
void Graph<T>::addEdge(const T& val1, const T& val2, bool directed) {
    int indexVal1 = indexOf(val1);
    int indexVal2 = indexOf(val2);
    if (indexVal1 == -1 || indexVal2 == -1) {
        cout << "Square or Squares not in the graph\n";
        return;
    }
    (adjacencyList[indexVal1] -> neighbors) -> pushFront(val2);
    if (!directed) {
        (adjacencyList[indexVal2] -> neighbors) -> pushFront(val1);
    }
}

template <typename T>
void Graph<T>::CheatBFS(const T& initialSquareName) {
    T* pastSquareNames = new T[numSquares];
    Queue<T> q;
    q.enqueue(initialSquareName);
    while (!q.isEmpty() || currentVal != treasureSquare) {
        T currentVal = q.dequeue();
        Square<T>* currentSquare = adjacencyList[indexOf(currentVal)];
        if (!(currentSquare -> isVisited())) {
            currentSquare -> setVisited(true);
            cout << currentVal << " -> ";
            Node<T>* neighbor = currentSquare -> neighbors -> getHead();
            while (neighbor) {
                q.enqueue(neighbor -> getName());
                pastSquareNames[indexOf(neighbor -> getName())] = currentVal;
                neighbor = neighbor -> getNext();
            }
        }
    }

    LinkedList<T>* shortestPath = new LinkedList();
    T next = treasureSquareName;
    while (next != initialSquareName) {
        shortestPath -> pushFront(next);
        next = pastSquareNames[indexOf(next)]
    }
    shortestPath -> pushFront(next);

    shortestPath -> printLL();

     
    for (int i = 0; i < count; i++) {
        adjacencyList[i] -> setVisited(false);
    }

    delete inversePath;
    delete[] pastSquareVals;
}

template <typename T>
Square<T>** Graph<T>::getAdjacencyList() {
    return adjacencyList;
}