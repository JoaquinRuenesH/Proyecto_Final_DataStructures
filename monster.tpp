#pragma once

#include<monster.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

Monster::Monster(){
    this->id = -1;
    this->name = "default";
    this->HP = 0;
    this->ATK = 0;
    this->DEF = 0;
    this->probability = 0;
    this->reward = 0;
}

Monster::Monster(int id, std::string name, int HP, int ATK, int DEF, int probability, int reward){
    this->id = id;
    this->name = name;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->probability = probability;
    this->reward = reward;
}

void Monster::setName(std::string nme){
    name = nme;
}

void Monster::setHP(int hp){
    HP = hp;
}

void Monster::setATK(int atk){
    ATK = atk;
}

void Monster::setDEF(int def){
    DEF = def;
}

void Monster::setProbability(int prob){
    probability = prob;
}

void Monster::setReward(int rwd){
    reward = rwd;
}