#pragma once
#include "Graph.h"
#include "Hero.h"
#include "CombatSystem.h"

template <typename T>
class GameSave {
private:
    Hero* hero;
    Graph<T>* map;
    Square<T>* currentSquare;
    int moves;
    T squaresVisited;
    bool gameOver;
    bool fightMonster();
    bool treasureCheck();
public:
    GameSave(Hero* h, Graph<T>* map);
    void showNeighbors();
    void move(const T& nameSquare);
    void printCheatBFS();
    void showGameStatus();
    bool isGameOver();
};

#include "GameSave.tpp"