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
    bool coolDownAbility;
    bool temporaryUpgrade;
public:
    Hero(int id, std::string name, int HP, int ATK, int DEF);
    void setId(int num);
    void setName(std::string nme);
    void setHP(int hp);
    void setATK(int atk);
    void setDEF(int def);
    void setCoolDownAbility(bool value);
    void setTemporaryUpgrade(bool value);
    int getId();
    std::string getName();
    int getHP();
    int getATK();
    int getDEF();
    bool getCoolDownAbility();
    bool getTemporaryUpgrade();
};

#include "Hero.tpp"