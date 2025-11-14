#pragma once
#include "Hero.h"
#include "Monster.h"

class CombatSystem {
private:
    Hero* hero;
    Monster* monster;
    int attackMoves;
    bool turns();
    void herosTurn();
    void monstersTurn();
    void upgrade();
public:
    CombatSystem(Hero* h, Monster* m);
    bool fight();
    void useCoolDownAbility();
    void useTemporaryUpgrade();
};

#include "CombatSystem.tpp"