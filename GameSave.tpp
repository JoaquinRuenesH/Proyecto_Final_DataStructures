#include "GameSave.h"

template <typename T>
GameSave<T>::GameSave(Hero* h, Graph<T>* map) {
    hero = h;
    this -> map = map;
    currentSquare = map -> adjacencyList[0];
    currentSquare -> setVisited(true);
    moves = 0;
    squaresVisited = currentSquare -> getName();
}

template <typename T>
void GameSave<T>::showNeighbors() {
    LinkedList<T>* squareOptions = currentSquare -> neighbors;
    cout << "Square options: \n";
    squareOptions -> printLL();
    cout << "\n";
}

template <typename T>
void GameSave<T>::move(const T& nameSquare) {
    currentSquare = map -> getAdjacencyList()[map -> indexOf(nameSquare)];
    currentSquare -> setVisited(true);
    squaresVisited += " -> " + currentSquare -> getName();
    moves++;
}

template <typename T>
void GameSave<T>::printCheatBFS() {
    cout << "The fastest route from your square is: ";
    map -> CheatBFS(currentSquare -> getName());
    cout << "\n";
}

template <typename T>
void GameSave<T>::showGameStatus() {
    cout << "Current Square: " << currentSquare -> getName() << "\n";
    cout << "Moves: " << moves << "\n";
    cout << "Squares Visited: [" << squaresVisited << "]\n";
    hero -> displayInfo();
}