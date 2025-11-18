#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

#include "GameSave.h"

int main() {
    //Probability seed
    srand(time(nullptr));

    // Creation and Load of Hero, Map and Monsters
    Hero* Batman = new Hero(1, "Batman", 100, 30, 30);
    Graph<string>* Arkham = new Graph<string>;
    Arkham -> addSquare("Arkham Asylum");
    Arkham -> addSquare("Police Department");
    Arkham -> addSquare("Gotham's Hospital");
    Arkham -> addSquare("The Sewers");
    Arkham -> addSquare("The Pit");
    Arkham -> addSquare("City Hall");
    Arkham -> addSquare("Batcave");
    Arkham -> addEdge("Arkham Asylum", "Police Department");
    Arkham -> addEdge("Police Department", "Gotham's Hospital");
    Arkham -> addEdge("Police Department", "City Hall");
    Arkham -> addEdge("Gotham's Hospital", "The Sewers");
    Arkham -> addEdge("The Sewers", "The Pit");
    Arkham -> addEdge("City Hall", "Batcave");
    Arkham -> addEdge("The Sewers", "Batcave");
    Arkham -> addTreasure("Arkham Asylum");
    Monster* TwoFace = new Monster(1, "Two-Face", 100, 50, 20, 0.5, 4);
    Monster* KillerCroc = new Monster(2, "KillerCroc", 100, 5, 14, 0.8, 4);
    Monster* Bane = new Monster(3, "Bane", 100, 80, 50, 0.9, 10);
    Monster* Penguin = new Monster(4, "The Penguin", 100, 50, 30, 0.7, 4);
    Monster* Riddler = new Monster(5, "The Riddler", 100, 80, 23, 0.6, 8);
    Monster* Joker = new Monster(6, "The Joker", 100, 95, 70, 1, 20);
    Arkham -> addMonster("City Hall", TwoFace);
    Arkham -> addMonster("The Sewers", KillerCroc);
    Arkham -> addMonster("The Pit", Bane);
    Arkham -> addMonster("Gotham's Hospital", Penguin);
    Arkham -> addMonster("Police Department", Riddler);
    Arkham -> addMonster("Arkham Asylum", Joker);

    // GameSave Creation
    GameSave<string>* player1 = new GameSave<string>(Batman, Arkham);

    // Moves that the user should make simulating a gameplay
    string cityName;
    player1 -> showGameStatus();
    player1 -> printCheatBFS();
    
    while (!player1 -> isGameOver()) {
        player1 -> showNeighbors();
        cout << "Where to move: ";
        getline(cin, cityName);
        player1 -> move(cityName);
        player1 -> showGameStatus();
    }

    delete player1;
    delete Batman;
    delete Arkham;
    delete TwoFace;
    delete KillerCroc;
    delete Bane;
    delete Penguin;
    delete Riddler;
    delete Joker;

    return 0;
}