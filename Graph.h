#pragma once
#include "Square.h"

template <typename T>
class Graph {
private:
    LinkedList<Square<T>*>* adjacencyList;
    T treasureSquareName;
    Node<T*>* findTuple(LinkedList<T*>* parentSonList, const T& val, int index = 1);
    T* getInfo(LinkedList<T*>* verticesInfo, const T& val);
public:
    Graph();
    ~Graph();
    void addSquare(const T& val);
    void addTreasure(const T& val);
    void addMonster(const T& squareName, Monster* m);
    void addEdge(const T& val1, const T& val2, const T& weight = "1", bool directed = false);
    void cheatBFS(const T& initialSquareName);
    void dijkstra(const T& initialSquareName);
    LinkedList<Square<T>*>* getAdjacencyList();
    T getTreasureSquareName();
};

#include "Graph.tpp"