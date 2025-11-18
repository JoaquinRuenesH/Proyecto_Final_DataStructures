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
    int rewardPoints;
    bool coolDownAbility;
    bool temporaryUpgrade;
    LinkedList<string*>* monstersDefeated;
public:
    Hero(int id, std::string name, int HP, int ATK, int DEF);
    ~Hero();
    void setId(int num);
    void setName(std::string nme);
    void setHP(int hp);
    void setATK(int atk);
    void setDEF(int def);
    void setRewardPoints(int pts);
    void setCoolDownAbility(bool value);
    void setTemporaryUpgrade(bool value);
    int getId();
    std::string getName();
    int getHP();
    int getATK();
    int getDEF();
    int getRewardPoints();
    bool getCoolDownAbility();
    bool getTemporaryUpgrade();
    void displayInfo();
    LinkedList<string*>* getMonstersDefeated();
};

#include "Hero.tpp"