#pragma once

#include<iostream>
#include<string>
#include"monster.h"
#include"graph.h"
#include"linkedList.h"

#define MONSTER_ATTRIB_SIZE 7
#define ADD_VERTEX_ATTRIB_SIZE 2
#define ADD_EDGE_ATTRIB_SIZE 3

using namespace std;

class GameSetUp{
    private:
        LinkedList<Monster*>* monstersList;
        Graph<string>* map;
    public:
        GameSetUp();
        ~GameSetUp();
        LinkedList<Monster*>* uploadMonsters(string fileName);
        Graph<string>* uploadMap(string fileName);
        
        //bool exportStats();
};

#include"gameSetUp.tpp"