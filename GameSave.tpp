#include "GameSave.h"
#include <sstream>

template <typename T>
GameSave<T>::GameSave(Hero* h, Graph<T>* map) {
    hero = h;
    this -> map = map;
    currentSquare = map -> getAdjacencyList() -> getHead() -> getData();
    currentSquare -> setVisited(true);
    moves = 0;
    squaresVisited = currentSquare -> getName();
    gameOver = false;
}

template <typename T>
void GameSave<T>::showNeighbors() {
    LinkedList<T*>* squareOptions = currentSquare -> neighbors;
    cout << "Square options: ";
    squareOptions -> printLLFirstTupleVal();
    cout << "\n---------------\n";
}

template <typename T>
void GameSave<T>::move(const T& nameSquare) {
    currentSquare = getSquare(map -> getAdjacencyList(), nameSquare);
    if (!currentSquare) {
        cout << "No square named " << nameSquare << "\n";
        return;
    }
    currentSquare -> setVisited(true);
    squaresVisited += " -> " + currentSquare -> getName();
    moves++;
    cout << "Welcome to '" << currentSquare -> getName() << "'";
    cout << "\n---------------\n";
    if (treasureCheck()) {
        cout << "You have reached the final square! Defeat the monster to win";
        cout << "\n---------------\n";
        if (fightMonster()) {
            cout << "Congratulations! You have defeated the final boss and gotten the treasure!";
            cout << "\n---------------\n";
        } else {
            cout << "You lost to the final boss! Try again!";
            cout << "\n---------------\n";
        }
        gameOver = true;
    } else {    
        gameOver = !fightMonster();
        if (gameOver) {
            cout << "You lost! Try again!";
            cout << "\n---------------\n";
        }
    }
}

template <typename T>
void GameSave<T>::printCheatBFS() {
    if (map -> getTreasureSquareName() == T{}) {
        cout << "There is no treasure left in this map\n";
        return;
    }
    cout << "The shortest route from your square to the treasure is: ";
    map -> cheatBFS(currentSquare -> getName());
    cout << "\n---------------\n";
}

template <typename T>
void GameSave<T>::printDijkstra() {
    if (map -> getTreasureSquareName() == T{}) {
        cout << "There is no treasure left in this map\n";
        return;
    }
    cout << "The best route from your square to the treasure is: ";
    map -> dijkstra(currentSquare -> getName());
    cout << "\n---------------\n";
}

template <typename T>
void GameSave<T>::showGameStatus() {
    cout << "Current Square: " << currentSquare -> getName() << "\n";
    cout << "Moves: " << moves << "\n";
    cout << "Squares Visited: [" << squaresVisited << "]\n";
    cout << "Monsters defeated: ";
    hero -> getMonstersDefeated() -> printLLTuples();
    cout << "\n";
    hero -> displayInfo();
    cout << "\n---------------\n";
}

template <typename T>
bool GameSave<T>::fightMonster() {
    Monster* monster = currentSquare -> getMonster();
    stringstream ss(squaresVisited);
    string firstSquare;
    getline(ss, firstSquare, '-');
    if (currentSquare -> getName() + " " == firstSquare){
        cout << "You are back in the initial square!";
        cout << "\n---------------\n";
        return true;
    }
    if (!monster) {
        cout << "You have already defeated the monster in '" << currentSquare -> getName();
        cout << "'\n---------------\n";
        return true;
    }
    rand();
    float randomNum = (float)rand() / RAND_MAX;
    if (randomNum > monster -> getProbability()) {
        cout << "There is no monster in '" << currentSquare -> getName();
        cout << "' this time...";
        cout << "'\n---------------\n";
        return true;
    }
    CombatSystem* duel = new CombatSystem(hero, monster);
    bool result = duel -> fight();
    if (result) {
        currentSquare -> setMonster(nullptr);
        string* monsterMoves = new string[2];
        monsterMoves[0] = monster -> getName();
        monsterMoves[1] = to_string(duel -> getAttackMoves());
        hero -> getMonstersDefeated() -> pushFront(monsterMoves);
    }
    delete duel;
    return result;
}

template <typename T>
bool GameSave<T>::treasureCheck() {
    return currentSquare -> hasTreasure();
}

template <typename T>
bool GameSave<T>::isGameOver() {
    if (currentSquare -> hasTreasure() && !currentSquare -> getMonster()) {
        gameOver = true;
    }
    return gameOver;
}