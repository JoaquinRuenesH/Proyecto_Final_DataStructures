#pragma once

#include<iostream>
#include<string>
using namespace std;
#include"GameSave.h"
#include"Hero.h"
#include"Monster.h"
#include"Graph.h"
#include"LinkedList.h"

#define MONSTER_ATTRIB_SIZE 7
#define ADD_VERTEX_ATTRIB_SIZE 2
#define ADD_EDGE_ATTRIB_SIZE 3

class Execution{
    private:
        LinkedList<Monster*>* monstersList;
        Graph<string>* map;
        bool uploadMonsters(string fileName);
        Monster* searchMonster(int id);
        bool uploadMap(string fileName);
        //bool exportData();
    public:
        Execution();
        ~Execution();
        bool start(string monstersFile, string mapFile);
};

#include"Execution.tpp"