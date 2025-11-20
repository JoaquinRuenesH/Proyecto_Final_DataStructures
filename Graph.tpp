#include <iostream>
using namespace std;

#include "Graph.h"
#include "Queue.h"
#include "LinkedList.h"

template <typename T>
Graph<T>::Graph() {
    adjacencyList = new LinkedList<Square<T>*>();
    treasureSquareName = T{};
}

template <typename T>
Graph<T>::~Graph() {
    Node<Square<T>*>* head = adjacencyList -> getHead();
    Square<T>* tempData;
    while (head) {
        tempData = head -> getData();
        head = head -> getNext();
        delete tempData;
    }
    delete adjacencyList;
}

template <typename T>
void Graph<T>::addSquare(const T& val) {
    if (getSquare(adjacencyList, val)) {
        return;
    }
    Square<T>* newSquare = new Square<T>(val);
    adjacencyList -> pushFront(newSquare);
}

template <typename T>
void Graph<T>::addTreasure(const T& val) {
    treasureSquareName = val;
    Square<T>* treasureSquare = getSquare(adjacencyList, treasureSquareName);
    treasureSquare -> setTreasure(true);
}

template <typename T>
void Graph<T>::addMonster(const T& squareName, Monster* m) {
    Square<T>* square = getSquare(adjacencyList, squareName);
    square -> setMonster(m);
}

template <typename T>
void Graph<T>::addEdge(const T& val1, const T& val2, const T& weight, bool directed) {
    Square<T>* v1 = getSquare(adjacencyList, val1);
    Square<T>* v2 = getSquare(adjacencyList, val2);
    if (!v1 || !v2) {
        cout << "Square or squares not in the graph\n";
        return;
    }
    T* valWeight = new T[2];
    valWeight[0] = val2;
    valWeight[1] = weight;
    (v1 -> neighbors) -> pushFront(valWeight);
    if (!directed) {
        T* valWeight2 = new T[2];
        valWeight2[0] = val1;
        valWeight2[1] = weight;
        (v2 -> neighbors) -> pushFront(valWeight2);
    }
}

template <typename T>
void Graph<T>::cheatBFS(const T& initialSquareName) {
    LinkedList<T*>* ParentSonList = new LinkedList<T*>;
    T* parentSon = new T[2];
    parentSon[0] = T{};
    parentSon[1] = initialSquareName;
    ParentSonList -> pushFront(parentSon);

    Queue<T> q;
    q.enqueue(initialSquareName);
    while (!q.isEmpty()) {
        T currentSquareName = q.dequeue();
        if (currentSquareName != treasureSquareName) {
            Square<T>* currentSquare = getSquare(adjacencyList, currentSquareName);
            if (!(currentSquare -> isVisitedBFS())) {
                currentSquare -> setVisitedBFS(true);
                Node<T*>* neighbor = currentSquare -> neighbors -> getHead();
                while (neighbor) {
                    q.enqueue(neighbor -> getData()[0]);
                    if (!findTuple(ParentSonList, neighbor -> getData()[0])) {
                        T* parentSon = new T[2];
                        parentSon[0] = currentSquareName;
                        parentSon[1] = neighbor -> getData()[0];
                        ParentSonList -> pushFront(parentSon);
                    }
                    neighbor = neighbor -> getNext();
                }
            }
        } else {
            q.clear();
        }
    }

    LinkedList<T>* orderedList = new LinkedList<T>();

    Node<T*>* currentNode = findTuple(ParentSonList, treasureSquareName);
    orderedList -> pushFront(treasureSquareName);
    T parent = currentNode -> getData()[0];
    while (parent != T{}) {
        orderedList -> pushFront(parent);
        currentNode = findTuple(ParentSonList, parent);
        parent = currentNode -> getData()[0];
    }

    orderedList -> printLL();

    delete orderedList;

    Node<T*>* tupleNode = ParentSonList -> getHead();
    while (tupleNode) {
        delete[] tupleNode -> getData();
        tupleNode = tupleNode -> getNext();
    }
    
    delete ParentSonList;

    Node<Square<T>*>* head = adjacencyList -> getHead();
    while (head) {
        head -> getData() -> setVisitedBFS(false);
        head = head -> getNext();
    }
}

template <typename T>
void Graph<T>::dijkstra(const T& initialSquareName) {
    Node<Square<T>*>* head = adjacencyList -> getHead();
    LinkedList<T*>* verticesInfo = new LinkedList<T*>;
    while (head) {
        T* info = new T[4];
        info[0] = head -> getData() -> getName(); // Vertex name
        info[1] = to_string(INT_MAX); // Min distance found
        info[2] = "notVisited"; // Visited
        info[3] = T{}; // Parent
        verticesInfo -> pushFront(info);
        head = head -> getNext();
    }
    getInfo(verticesInfo, initialSquareName)[1] = "0";
    
    T currentSquareName = initialSquareName;
    Square<T>* currentSquare = getSquare(adjacencyList, currentSquareName);
    while (getInfo(verticesInfo, treasureSquareName)[2] == "notVisited") {
        T minDistanceVertexName = T{};
        int minDistance = INT_MAX;
        Node<T*>* current = verticesInfo -> getHead();
        while (current) {
            if (current -> getData()[2] == "notVisited" && stoi(current -> getData()[1]) < minDistance) {
                minDistance = stoi(current -> getData()[1]);
                minDistanceVertexName = current -> getData()[0];
            }
            current = current -> getNext();
        }
        if (minDistanceVertexName == T{} || getInfo(verticesInfo, minDistanceVertexName) == nullptr) {
            break;
        }
        getInfo(verticesInfo, minDistanceVertexName)[2] = "Visited";
        currentSquareName = minDistanceVertexName;
        currentSquare = getSquare(adjacencyList, currentSquareName);
        Node<T*>* neighbor = currentSquare -> neighbors -> getHead();
        int currentSquareDistance = stoi(getInfo(verticesInfo, currentSquareName)[1]);
        while (neighbor) {
            T neighborName = neighbor -> getData()[0];
            int neighborWeight = stoi(neighbor -> getData()[1]);
            T* neighborInfo = getInfo(verticesInfo, neighborName);
            if (neighborInfo[2] == "notVisited" && currentSquareDistance + neighborWeight < stoi(neighborInfo[1])) {
                neighborInfo[1] = to_string(currentSquareDistance + neighborWeight);
                neighborInfo[3] = currentSquareName;
            }
            neighbor = neighbor -> getNext();
        }
    }

    LinkedList<T>* shortestPath = new LinkedList<T>;
    shortestPath -> pushFront(treasureSquareName);
    T parentSquareName = getInfo(verticesInfo, treasureSquareName)[3];
    while (parentSquareName != T{}) {
        shortestPath -> pushFront(parentSquareName);
        parentSquareName = getInfo(verticesInfo, parentSquareName)[3];
    }

    shortestPath -> printLL();

    Node<T*>* current = verticesInfo -> getHead();
    while (current) {
        delete[] current -> getData();
        current = current -> getNext();
    }
    delete verticesInfo;
    delete shortestPath;
}

template <typename T>
Node<T*>* Graph<T>::findTuple(LinkedList<T*>* parentSonList, const T& val, int index) {
    Node<T*>* current = parentSonList -> getHead();
    while (current) {
        if (current -> getData()[index] == val) {
            return current;
        }
        current = current -> getNext();
    }
    return nullptr;
}

template <typename T>
T* Graph<T>::getInfo(LinkedList<T*>* verticesInfo, const T& val) {
    Node<T*>* current = verticesInfo -> getHead();
    while (current) {
        if (current -> getData()[0] == val) {
            return current -> getData();
        }
        current = current -> getNext();
    }
    return nullptr;
}

template <typename T>
LinkedList<Square<T>*>* Graph<T>::getAdjacencyList() {
    return adjacencyList;
}

template <typename T>
T Graph<T>::getTreasureSquareName() {
    return treasureSquareName;
}