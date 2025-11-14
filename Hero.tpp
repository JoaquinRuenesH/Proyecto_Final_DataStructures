#include "Hero.h"
#include<iostream>

Hero::Hero(int id, std::string name, int HP, int ATK, int DEF){
    this->id = id;
    this->name = name;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->rewardPoints = 0;
}

void Hero::setId(int num){
    id = num;
}

void Hero::setName(std::string nme){
    name = nme;
}

void Hero::setHP(int hp){
    HP = hp;
}

void Hero::setATK(int atk){
    ATK = atk;
}

void Hero::setDEF(int def){
    DEF = def;
}

void Hero::setRewardPoints(int pts){
    rewardPoints = pts;
}

void Hero::setCoolDownAbility(bool value){
    coolDownAbility = value;
}

void Hero::setTemporaryUpgrade(bool value){
    temporaryUpgrade = value;
}

int Hero::getId(){
    return id;
}

std::string Hero::getName(){
    return name;
}
        
int Hero::getHP(){
    return HP;
}
        
int Hero::getATK(){
    return ATK;
}
        
int Hero::getDEF(){
    return DEF;
}

int Hero::getRewardPoints(){
    return rewardPoints;
}

bool Hero::getCoolDownAbility(){
    return coolDownAbility;
}

bool Hero::getTemporaryUpgrade(){
    return temporaryUpgrade;
}

void Hero::displayInfo(){
    std::cout<<"Hero:";
    std::cout<<"\nName: "<<name;
    std::cout<<"\nHP: "<<HP;
    std::cout<<"\nATK: "<<ATK;
    std::cout<<"\nDEF: "<<DEF;
    std::cout<<"\nReward Points: "<<rewardPoints;

    if(coolDownAbility){
        std::cout<<"\nCooldown: Available";
    }else{
        std::cout<<"\nCooldown: Not Available";
    }
    
    if(temporaryUpgrade){
        std::cout<<"\nTemporary Upgrade: Available";
    }else{
        std::cout<<"\nTemporary Upgrade: Not Available";
    }
}