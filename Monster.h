#pragma once

#include<iostream>
#include<string>

class Monster{
    private:
        int id;
        std::string name;
        int HP; //health
        int ATK; //attack
        int DEF; //defense
        float probability; //appearance probability
        int reward; //reward for hero when defeating monster
    public:
        Monster();
        Monster(int id, std::string name, int HP, int ATK, int DEF, float probability, int reward);
        void setId(int num);
        void setName(std::string nme);
        void setHP(int hp);
        void setATK(int atk);
        void setDEF(int def);
        void setProbability(float prob);
        void setReward(int rwd);
        int getId();
        std::string getName();
        int getHP();
        int getATK();
        int getDEF();
        float getProbability();
        int getReward();
};

#include"monster.tpp"