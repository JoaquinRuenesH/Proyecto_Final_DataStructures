#pragma once
#include<iostream>
#include<string>

class Hero {
private:
    int id;
    std::string name;
    int HP;
    int ATK;
    int DEF;
public:
    Hero(int id, std::string name, int HP, int ATK, int DEF);
};

#include "Hero.tpp"