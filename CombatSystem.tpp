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
        cout << "\n---------------\n";
        if (monster -> getHP() == 0) return true;
        monstersTurn();
        cout << "\n---------------\n";
        if (hero -> getHP() == 0) return false;
    }
}

void CombatSystem::herosTurn() {
    cout << hero -> getName() << "'s turn to attack!\n";
    int damage = hero -> getATK() - monster -> getDEF();
    if (damage < 1) {
        damage = 1;
    }
    cout << monster -> getName() << " was attacked! (-" << damage << " HP)";
    cout << "\nHP: " << monster -> getHP();
    monster -> setHP(monster -> getHP() - damage);
    if (monster -> getHP() < 0) {
        monster -> setHP(0);
    }
    cout << " -> " << monster -> getHP();
    attackMoves++;
}

void CombatSystem::monstersTurn() {
    cout << monster -> getName() << "'s turn to attack!\n";
    int damage = monster -> getATK() - hero -> getDEF();
    if (damage < 1) {
        damage = 1;
    }
    cout << hero -> getName() << " was attacked! (-" << damage << " HP)";
    cout << "\nHP: " << hero -> getHP();
    hero -> setHP(hero -> getHP() - damage);
    if (hero -> getHP() < 0) {
        hero -> setHP(0);
    }
    cout << " -> " << hero -> getHP();
}

void CombatSystem::upgrade() {
    float attributeRewardCoefficient = 1.4;

    cout << "Hero:";
    cout << "\nName: " << hero -> getName();

    cout << "\nHP: " << hero -> getHP();
    hero -> setHP(hero -> getHP() + 15);
    if (hero -> getHP() > 100) {
        hero -> setHP(100);
    }
    cout << " -> " << hero -> getHP();

    cout << "\nATK: " << hero -> getATK();
    hero -> setATK(hero -> getATK() + 15);
    if (hero -> getATK() > 100) {
        hero -> setATK(100);
    }
    cout << " -> " << hero -> getATK();

    cout << "\nDEF: " << hero -> getDEF();
    hero -> setDEF(hero -> getDEF() + 15);
    if (hero -> getDEF() > 100) {
        hero -> setDEF(100);
    }
    cout << " -> " << hero -> getDEF();

    cout << "\nReward Points: " << hero -> getRewardPoints();
    hero -> setRewardPoints(hero -> getRewardPoints() + monster -> getReward()); 
    cout << " -> " << hero -> getRewardPoints();

    if(hero -> getRewardPoints() >= 10) {
        hero -> setCoolDownAbility(true);
        cout<<"\nCooldown: NOW Available (10 Reward Points)";
    } else {
        cout<<"\nCooldown: Not Available";
    }

    if(hero -> getRewardPoints() >= 20) {
        hero -> setTemporaryUpgrade(true);
        cout<<"\nTemporary Upgrade: NOW Available (20 Reward Points)";
    } else {
        cout<<"\nTemporary Upgrade: Not Available";
    }
}

bool CombatSystem::fight() {
    cout << "FIGHT!!!";
    cout << "\n---------------\n";
    cout << "Preview:";
    cout << "\n---------------\n";
    hero -> displayInfo();
    cout << "\n---------------\n";
    monster -> displayInfo();
    cout << "\n---------------\n";
    requestUseCoolDown();
    if (hero -> getRewardPoints() >= 20) {
        requestUseTemporaryUpgrade();
    }
    
    string hold;
    cout << "Press any letter to start the fight: ";
    getline(cin, hold);
    cout << "---------------\n";
    cout << "Turn Log:";
    cout << "\n---------------\n"; //
    bool heroWon = turns();
    if (heroWon) {
        cout << hero -> getName() << " defeated " << monster -> getName() << "!";
        cout << "\n---------------\n";
        cout << "Moves to defeat: " << attackMoves;
        cout << "\n---------------\n";
        cout << "Post-Fight Recap:";
        cout << "\n---------------\n";
        cout << "Winner\n";
        hero -> displayInfo();
        cout << "\n---------------\n";
        cout << "Loser\n";
        monster -> displayInfo();
        cout << "\n---------------\n";
        cout << "Upgrade Recap\n";
        upgrade();
        cout << "\n---------------\n";
    } else {
        cout << hero -> getName() << " was defeated by " << monster -> getName() << "!";
        cout << "\n---------------\n";
        cout << "Post-Fight Recap:";
        cout << "\n---------------\n";
        cout << "Winner\n";
        monster -> displayInfo();
        cout << "\n---------------\n";
        cout << "Loser\n";
        hero -> displayInfo();
        cout << "\n---------------\n";
    }

    return heroWon;
}

void CombatSystem::useCoolDownAbility() {
    float coolDownCoefficient = 0.8;

    cout << "Reward Points: " << hero -> getRewardPoints();
    hero -> setRewardPoints(hero -> getRewardPoints() - 10);
    cout << " -> " << hero -> getRewardPoints();

    cout << "\n---------------\n";
    cout << "Cool Down Ability Recap\n";

    cout << "Monster:";
    cout << "\nName: " << monster -> getName();

    cout << "\nHP: " << monster -> getHP();
    monster -> setHP(monster -> getHP() * coolDownCoefficient);
    cout << " -> " << monster -> getHP();

    cout << "\nATK: " << monster -> getATK();
    monster -> setATK(monster -> getATK() * coolDownCoefficient);
    cout << " -> " << monster -> getATK();

    cout << "\nDEF: " << monster -> getDEF();
    monster -> setDEF(monster -> getDEF() * coolDownCoefficient);
    cout << " -> " << monster -> getDEF();

    cout << "\n---------------\n";

    hero -> setCoolDownAbility(false);
}

void CombatSystem::useTemporaryUpgrade() {
    float upgradeCoefficient = 1.5;

    cout << "Reward Points: " << hero -> getRewardPoints();
    hero -> setRewardPoints(hero -> getRewardPoints() - 20);
    cout << " -> " << hero -> getRewardPoints();

    cout << "\n---------------\n";
    cout << "Cool Down Ability Recap\n";

    cout << "Hero:";
    cout << "\nName: " << hero -> getName();

    cout << "\nHP: " << hero -> getHP();
    hero -> setHP(hero -> getHP() * upgradeCoefficient);
    if (hero -> getHP() > 100) {
        hero -> setHP(100);
    }
    cout << " -> " << hero -> getHP();

    cout << "\nATK: " << hero -> getATK();
    hero -> setATK(hero -> getATK() * upgradeCoefficient);
    if (hero -> getATK() > 100) {
        hero -> setATK(100);
    }
    cout << " -> " << hero -> getATK();

    cout << "\nDEF: " << hero -> getDEF();
    hero -> setDEF(hero -> getDEF() * upgradeCoefficient);
    if (hero -> getDEF() > 100) {
        hero -> setDEF(100);
    }
    cout << " -> " << hero -> getDEF();

    cout << "\n---------------\n";

    hero -> setTemporaryUpgrade(false);
}

void CombatSystem::requestUseCoolDown() {
   if (!hero -> getCoolDownAbility()) {
        return;
   } else {
        string answer;
        cout << "Press 'C' to use your ability 'Cooldown'\n";
        cout << "Press any other letter to continue:\n";
        getline(cin, answer);
        if (answer == "C" || answer == "c") {
            cout << "---------------\n";
            useCoolDownAbility();
        }
   }
}

void CombatSystem::requestUseTemporaryUpgrade() {
   if (!hero -> getTemporaryUpgrade()) {
        return;
   } else {
        string answer;
        cout << "Press 'T' to use your ability 'Temporary Upgrade'\n";
        cout << "Press any other letter to continue:\n";
        getline(cin, answer);
        if (answer == "T" || answer == "t") {
            cout << "---------------\n";
            useTemporaryUpgrade();
        }
   }
}

int CombatSystem::getAttackMoves() {
   return attackMoves;
}