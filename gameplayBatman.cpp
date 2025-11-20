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
    Graph<string>* Gotham = new Graph<string>;
    Gotham -> addSquare("Arkham Asylum");
    Gotham -> addSquare("Police Department");
    Gotham -> addSquare("Gotham's Hospital");
    Gotham -> addSquare("The Sewers");
    Gotham -> addSquare("The Pit");
    Gotham -> addSquare("City Hall");
    Gotham -> addSquare("Batcave");
    Gotham -> addEdge("Arkham Asylum", "Police Department", "10");
    Gotham -> addEdge("Police Department", "Gotham's Hospital", "4");
    Gotham -> addEdge("Police Department", "City Hall", "8");
    Gotham -> addEdge("Gotham's Hospital", "The Sewers", "3");
    Gotham -> addEdge("The Sewers", "The Pit", "9");
    Gotham -> addEdge("City Hall", "Batcave", "7");
    Gotham -> addEdge("The Sewers", "Batcave", "2");
    Gotham -> addTreasure("Arkham Asylum");
    Monster* TwoFace = new Monster(1, "Two-Face", 100, 50, 20, 0.5, 4);
    Monster* KillerCroc = new Monster(2, "KillerCroc", 100, 5, 14, 0.8, 4);
    Monster* Bane = new Monster(3, "Bane", 100, 80, 50, 0.9, 10);
    Monster* Penguin = new Monster(4, "The Penguin", 100, 50, 30, 0.7, 4);
    Monster* Riddler = new Monster(5, "The Riddler", 100, 80, 23, 0.6, 8);
    Monster* Joker = new Monster(6, "The Joker", 100, 95, 70, 1, 20);
    Gotham -> addMonster("City Hall", TwoFace);
    Gotham -> addMonster("The Sewers", KillerCroc);
    Gotham -> addMonster("The Pit", Bane);
    Gotham -> addMonster("Gotham's Hospital", Penguin);
    Gotham -> addMonster("Police Department", Riddler);
    Gotham -> addMonster("Arkham Asylum", Joker);

    // GameSave Creation
    GameSave<string>* player1 = new GameSave<string>(Batman, Gotham);

    // Moves that the user should make simulating a gameplay
    string cityName;
    player1 -> showGameStatus();
    player1 -> printCheatBFS();
    player1 -> printDijkstra();
    
    while (!player1 -> isGameOver()) {
        player1 -> showNeighbors();
        cout << "Where to move: ";
        getline(cin, cityName);
        player1 -> move(cityName);
        player1 -> showGameStatus();
    }

    delete player1;
    delete Batman;
    delete Gotham;
    delete TwoFace;
    delete KillerCroc;
    delete Bane;
    delete Penguin;
    delete Riddler;
    delete Joker;

    return 0;
}