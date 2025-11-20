#pragma once
#include "LinkedList.h"
#include "Monster.h"

template <typename T>
class Square {
private:
    T name;
    bool visited;
    bool visitedBFS;
    int id;
    double encounterProbability;
    Monster* monster;
    bool treasure;
public:
    LinkedList<T*>* neighbors;
    Square(const T& val);
    ~Square(); 
    T getName();
    void setName(const T& val);
    bool isVisited();
    void setVisited(bool state);
    bool isVisitedBFS();
    void setVisitedBFS(bool state);
    void setId(int id);
    int getId();
    void setEP(double EP);
    double getEP();
    void setMonster(Monster* m);
    Monster* getMonster();
    void setTreasure(bool t);
    bool hasTreasure();
};

#include "Square.tpp"