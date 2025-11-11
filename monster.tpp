#pragma once

#include<monster.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

Monster::Monster(int id, std::string name, int HP, int ATK, int DEF, int probability, int reward){
    this->id = id;
    this->name = name;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->probability = probability;
    this->reward = reward;
}
