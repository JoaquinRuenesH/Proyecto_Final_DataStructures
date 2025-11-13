#pragma once
#include "LinkedList.h"

template <typename T>
class Square {
private:
    T name;
    bool visited;
    int id;
    double encounterProbability;
public:
    LinkedList<T>* neighbors;
    Square(const T& val);
    ~Square();
    T getName();
    void setName(const T& val);
    bool isVisited();
    void setVisited(bool state);
    void setId(int id);
    int getId();
    void setEP(double EP);
    double getEP();
};

#include "Square.tpp"