#include "CombatSystem.h"
#include <iostream>
using namespace std;

CombatSystem::CombatSystem(Hero* h, Monster* m) {
    hero = h;
    monster = m;
}

bool CombatSystem::Fight() {
    while (true) {
        HerosTurn();
        if (monster -> HP <= 0) || return 0;
        MonstersTurn();
        if (hero -> HP <= 0) return 1;
    }
}

void CombatSystem::HerosTurn() {
    cout << hero -> name << "'s turn to attack!\n";
    int damage = hero -> ATK - monster -> DEF;
    if (damage < 1) {
        damage = 1;
    }
    monster -> HP -= damage;
    cout << monster -> name << "was attacked! (" << damage << ")\n";
}

void CombatSystem::MonstersTurn() {
    cout << monster -> name << "'s turn to attack!\n";
    int damage = monster -> ATK - hero -> DEF;
    if (damage < 1) {
        damage = 1;
    }
    hero -> HP -= damage;
    cout << hero -> name << "was attacked! (" << damage << ")\n";
}

void CombatSystem::AfterMath() {
    bool heroWon = Fight();
    if (heroWon) {
        cout << hero -> name << " won!";
    } else {
        cout << hero -> name << " lost!";
    }
}