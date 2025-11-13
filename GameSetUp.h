#pragma once

#include<iostream>
#include<string>
#include"monster.h"
#include"linkedList.h"

#define MONSTER_ATRIB_SIZE 7

class GameSetUp{
    private:
        LinkedList<Monster> monstersList; 
    public:
        GameSetUp();
        bool uploadMonsters(std::string fileName);
        //bool uploadBoard(std::string fileName);
        //bool exportStats();
};

#include"gameSetUp.tpp"