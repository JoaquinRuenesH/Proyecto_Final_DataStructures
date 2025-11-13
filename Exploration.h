#pragma once
#include "Graph.h"
#include "Hero.h"

template <typename T>
class Exploration {
private:
    Hero<T>* hero;
    Graph<T>* map;
    Square<T>* currentSquare;
    Square<T>* treasureSquare;
    int numSquaresVisited;
public:
    Exploration(Hero<T>* h, Graph<T>* map);
    void showNeighbors();
    void move(const T& nameSquare);
    void status();
};

#include "Exploration.tpp"