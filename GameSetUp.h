#pragma once

#include<iostream>
#include<string>
#include"monster.h"
#include"graph.h"
#include"linkedList.h"

#define MONSTER_ATRIB_SIZE 7

using namespace std;

class GameSetUp{
    private:
        LinkedList<Monster*>* monstersList;
        Graph<string>* map;
    public:
        GameSetUp();
        ~GameSetUp();
        bool uploadMonsters(string fileName);
        bool uploadMap(string fileName);
        //bool exportStats();
};

#include"gameSetUp.tpp"