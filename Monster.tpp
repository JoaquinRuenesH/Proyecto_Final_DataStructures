#pragma once

#include"Monster.h"
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
    this->probability = 0.0;
    this->reward = 0;
}

Monster::Monster(int id, std::string name, int HP, int ATK, int DEF, float probability, int reward){
    this->id = id;
    this->name = name;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->probability = probability;
    this->reward = reward;
}

void Monster::setId(int num){
    id = num;
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

void Monster::setProbability(float prob){
    probability = prob;
}

void Monster::setReward(int rwd){
    reward = rwd;
}

int Monster::getId(){
    return id;
}

std::string Monster::getName(){
    return name;
}
        
int Monster::getHP(){
    return HP;
}
        
int Monster::getATK(){
    return ATK;
}
        
int Monster::getDEF(){
    return DEF;
}
        
float Monster::getProbability(){
    return probability;
}

int Monster::getReward(){
    return reward;
}