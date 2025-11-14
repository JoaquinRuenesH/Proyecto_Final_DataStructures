#pragma once
#include "Graph.h"
#include "Hero.h"

template <typename T>
class GameSave {
private:
    Hero<T>* hero;
    Graph<T>* map;
    Square<T>* currentSquare;
    int moves;
    T squaresVisited;
public:
    GameSave(Hero* h, Graph<T>* map);
    void showNeighbors();
    void move(const T& nameSquare);
    void printCheatBFS();
    void showGameStatus();
};

#include "GameSave.tpp"