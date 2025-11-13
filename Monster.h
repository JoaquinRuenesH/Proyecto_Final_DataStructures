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
        int probability; //appearance probability
        int reward; //reward for hero when defeating monster
    public:
        Monster();
        Monster(int id, std::string name, int HP, int ATK, int DEF, int probability, int reward);
        void setId(int num);
        void setName(std::string nme);
        void setHP(int hp);
        void setATK(int atk);
        void setDEF(int def);
        void setProbability(int prob);
        void setReward(int rwd);

};

#include"monster.tpp"