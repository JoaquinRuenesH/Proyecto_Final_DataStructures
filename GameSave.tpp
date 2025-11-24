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
    lastMonster = "";
    win = false;
    gameOver = false;
}

template <typename T>
void GameSave<T>::showNeighbors() {
    LinkedList<T*>* squareOptions = currentSquare -> neighbors;
    cout << "Square to move options: ";
    squareOptions -> printLLFirstTupleVal();
    cout << "\n---------------\n";
}

template <typename T>
bool GameSave<T>::move(int index) {
   Node<T*>* nextSquare = currentSquare -> neighbors -> elementAt(index);
    if(!nextSquare){
        cout << "Invalid move. Unexistent square." << "\n";
        return false;
    }

    string nameSquare = nextSquare->getData()[0];
    currentSquare = getSquare(map -> getAdjacencyList(), nameSquare);
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
            win = true;
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

    return true;
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
            win = true;
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
    lastMonster = monster -> getName();
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
string GameSave<T>::getLastMonster(){
    return lastMonster;
} 

template <typename T>
bool GameSave<T>::getWin(){
    return win;
}

template <typename T>
Square<T>* GameSave<T>::getCurrentSquare(){
    return currentSquare;
}

template <typename T>
bool GameSave<T>::isGameOver() {
    if (currentSquare -> hasTreasure() && !currentSquare -> getMonster()) {
        gameOver = true;
    }
    return gameOver;
}


template <typename T>
void GameSave<T>::saveCurrentGameStatus() {
    currentGameStatus = "Last Square visited: " + currentSquare -> getName() + 
                        "\nMoves: " + to_string(moves) + 
                        "\nSquares Visited: [" + squaresVisited + "]" + 
                        "\nMonsters defeated: " + hero -> getMonstersDefeated() -> getLLTuples() + 
                        "\nHero:" + 
                        "\nName: " + hero -> getName() + 
                        "\nHP: " + to_string(hero -> getHP()) + 
                        "\nATK: " + to_string(hero -> getATK()) +
                        "\nDEF: " + to_string(hero -> getDEF()) +
                        "\nReward Points: " + to_string(hero -> getRewardPoints()) +
                        "\n---------------\n";
}


template <typename T>
string GameSave<T>::getCurrentGameStatus() {
    return currentGameStatus;
}

template<typename T>
void GameSave<T>::showSquares(){
    LinkedList<T*>* squareOptions = currentSquare -> neighbors;
    int numSquares = squareOptions -> getSize();
    string space = "               ";
    int currentSquareSize = currentSquare -> getName().length();

    if(currentSquareSize < 15){
        currentSquareSize = 15;
    }

    if(numSquares % 2 == 0){
        space = "       ";
    }

        
    for(int i = 0; i<(numSquares/2); i++){
        cout << space;
    }
    for(int i = 0; i<(currentSquareSize + 4); i++){
        cout << "-";
    }
    cout << "\n";


    for(int i = 0; i<(numSquares/2); i++){
        cout << space;
    }
    cout<<"|";
    for(int i = 0; i<((currentSquareSize - 11)/2 + 1); i++){
        cout<<" ";
    }
    cout<<"You are here";
    for(int i = 0; i<((currentSquareSize - 11)/2 + 1); i++){
        cout<<" ";
    }
    cout<<"|\n";


    for(int i = 0; i<(numSquares/2); i++){
        cout << space;
    }
    cout<<"|";
    for(int i = 0; i<((19-(currentSquare->getName().length()))/2); i++){
        cout<<" ";
    }
    cout<< currentSquare -> getName();
    for(int i = 0; i<((18-(currentSquare->getName().length()))/2); i++){
        cout<<" ";
    }
    if((currentSquare->getName().length()) %2 == 0){
        cout<<" |\n";
    }else{
        cout<<"|\n";
    }


    for(int i = 0; i<(numSquares/2); i++){
        cout << space;
    }
    for(int i = 0; i<(currentSquareSize + 4); i++){
        cout << "-";
    }
    cout << "\n";


    if (!squareOptions -> getHead()) {
        cout<<"\n";
    }else{
        Node<T*>* current = squareOptions -> getHead();
        while (current) {
            int currentLength = current->getData()[0].length();
            for(int i = 0; i<(currentLength + 4)/2; i++){
                cout << " ";
            }
            cout<<"|";
            for(int i = 0; i<(currentLength + 6)/2; i++){
                cout << " ";
            }
            current = current->getNext();
            cout<<"     ";
        }
        cout<<"\n";

        cout<<"  ";
        current = squareOptions -> getHead();   
        while (current) {
            int currentLength = current->getData()[0].length();
            for(int i = 0; i<(currentLength + 4); i++){
                cout << "-";
            }
            cout<<"      ";
            current = current->getNext();
        }
        cout<<"\n";

        current = squareOptions -> getHead();
        int count = 1;
        while (current) {
            cout<<"| "<<count<<". "<<current -> getData()[0]<<" |   ";
            current = current->getNext();
            count++;
        }
        cout<<"\n";

        cout<<"  ";
        current = squareOptions -> getHead();   
        while (current) {
            int currentLength = current->getData()[0].length();
            for(int i = 0; i<(currentLength + 4); i++){
                cout << "-";
            }
            cout<<"      ";
            current = current->getNext();
        }
        cout<<"\n";

    }

}