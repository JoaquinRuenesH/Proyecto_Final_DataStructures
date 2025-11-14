#include "Hero.h"

Hero::Hero(int id, std::string name, int HP, int ATK, int DEF){
    this->id = id;
    this->name = name;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
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

bool Hero::getCoolDownAbility(){
    return coolDownAbility;
}

bool Hero::getTemporaryUpgrade(){
    return temporaryUpgrade;
}