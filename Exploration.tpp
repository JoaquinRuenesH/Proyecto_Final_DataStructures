#include "Exploration.h"

template <typename T>
Exploration<T>::Exploration(Hero<T>* h, Graph<T>* map) {
    hero = h;
    this -> map = map;
    currentSquare = map -> adjacencyList[0];
    treasureSquare = nullptr; //?
    numSquaresVisited = 0;
}

template <typename T>
void Exploration<T>::showNeighbors() {
    LinkedList<T>* squareOptions = currentSquare -> neighbors;
    cout << "Square options: \n";
    squareOptions -> printLL();
    cout << "\n";
}

template <typename T>
void Exploration<T>::move(const T& nameSquare) {
    currentSquare = map -> getAdjacencyList()[map -> indexOf(nameSquare)];
    currentSquare -> setVisited(true);
    squaresVisited++;
}

template <typename T>
void Exploration<T>::status() {
    cout << "Current Square: " << currentSquare -> getName() << "\n";
    cout << "Squares Visited: " << numSquaresVisited << "\n";
}