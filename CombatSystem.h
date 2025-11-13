#pragma once
#include "Hero.h"
#include "monster.h" //M

class CombatSystem {
private:
    Hero* hero;
    Monster* monster;
public:
    CombatSystem(Hero* h, Monster* m);
    bool Fight();
    void HerosTurn();
    void MonstersTurn();
    void AfterMath();
};

#include "CombatSystem.tpp"