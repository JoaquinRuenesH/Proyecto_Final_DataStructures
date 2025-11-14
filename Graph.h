#pragma once
#include "Square.h"

template <typename T>
class Graph {
private:
    int numSquares;
    Square<T>** adjacencyList;
    int count;
    T treasureSquareName;
public:
    Graph(int capacity);
    ~Graph();
    int indexOf(const T& val);
    void addSquare(const T& val);
    void addTreasure(const T& val);
    void addEdge(const T& val1, const T& val2, bool directed = false);
    void CheatBFS(const T& initialSquareName);
    Square<T>** getAdjacencyList();
};

#include "Graph.tpp"