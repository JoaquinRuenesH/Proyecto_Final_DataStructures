#include "CombatSystem.h"
#include <iostream>
using namespace std;

CombatSystem::CombatSystem(Hero* h, Monster* m) {
    hero = h;
    monster = m;
    attackMoves = 0;
}

bool CombatSystem::turns() {
    while (true) {
        herosTurn();
        if (monster -> getHP() <= 0) return true;
        monstersTurn();
        if (hero -> getHP() <= 0) return false;
    }
}

void CombatSystem::herosTurn() {
    cout << hero -> getName() << "'s turn to attack!\n";
    int damage = hero -> getATK() - monster -> getDEF();
    if (damage < 1) {
        damage = 1;
    }
    monster -> setHP(monster -> getHP() - damage);
    cout << monster -> getName() << "was attacked! (-" << damage << " HP)\n";
    attackMoves++;
}

void CombatSystem::monstersTurn() {
    cout << monster -> getName() << "'s turn to attack!\n";
    int damage = monster -> getATK() - hero -> getDEF();
    if (damage < 1) {
        damage = 1;
    }
    hero -> setHP(hero -> getHP() - damage);
    cout << hero -> getName() << "was attacked! (-" << damage << " HP)\n";
}

void CombatSystem::upgrade() {
    hero -> setRewardPoints(hero -> getRewardPoints() + monster -> getReward());
    float attributeReward = 1.0 + monster -> getReward() / 10.0;
    hero -> setATK(hero -> getATK() * attributeReward);
    hero -> setDEF(hero -> getATK() * attributeReward);
    hero -> setHP(hero -> getATK() * attributeReward);
}

bool CombatSystem::fight() {
    bool heroWon = turns();
    if (heroWon) {
        cout << hero -> getName() << " defeated " << monster -> getName() << "!\n";
        upgrade();
    } else {
        cout << hero -> getName() << " was defeated by" << monster -> getName() << "!\n";
    }
}

void CombatSystem::useCoolDownAbility() {
    monster -> setATK(monster -> getATK() * 0.5);
    monster -> setDEF(monster -> getATK() * 0.5);
    monster -> setHP(monster -> getATK() * 0.5);
    hero -> setCoolDownAbility(false);
}

void CombatSystem::useTemporaryUpgrade() {
    hero -> setATK(hero -> getATK() * 1.5);
    hero -> setDEF(hero -> getATK() * 1.5);
    hero -> setHP(hero -> getATK() * 1.5);
    hero -> setTemporaryUpgrade(false);
}