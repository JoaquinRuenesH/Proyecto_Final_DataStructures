#pragma once

#include<iostream>
#include<string>
#include"monster.h"
#include"linkedList.h"

class GameSetUp{
    private:
        LinkedList<Monster> monstersList; 
    public:
        bool uploadMonsters(std::string fileName); //TODO
};

#include"gameSetUp.tpp"