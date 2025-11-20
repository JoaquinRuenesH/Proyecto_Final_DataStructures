#include"Execution.h"

using namespace std;

Execution::Execution(){
    monstersList = new LinkedList<Monster*>;
	map = new Graph<string>;
}

Execution::~Execution(){
    Node<Monster*>* current = monstersList->getHead();
    while(current){
        delete current->getData();
        current = current->getNext();
    }

    delete monstersList;

	delete map;
}

bool Execution::start(string monstersFile, string mapFile){

    if(!uploadMonsters(monstersFile)) return false;

    if(!uploadMap(mapFile)) return false;

    string name;
    cout<<"Enter your name: ";
    getline(cin, name);

    Hero* hero = new Hero(1, name, 100, 30, 30); // se mete esto al constructor?

    GameSave<string>* player = new GameSave<string>(hero, map);

    string cityName;
    player -> showGameStatus();
    player -> printCheatBFS();
    
    while (!player -> isGameOver()) {
        player -> showNeighbors();
        cout << "Where to move: ";
        getline(cin, cityName);
        player -> move(cityName);
        player -> showGameStatus();
    }

    delete player;
    delete hero;

    return true;
}






bool Execution::uploadMonsters(string fileName){
	ifstream file(fileName);
	string line;
	int errors = 0;

	if (!file.is_open()){
		cerr<<"Error while loading file: "<<fileName<<endl;
		return false;
	}

	// Jump header
	if(!getline(file, line)) {
		cerr<<"File doesnt have header"<<endl;
		file.close();
		return false;
	}

	cout<<"Loading file: "<<fileName<<endl;

	while(getline(file, line)){
		Monster* newMonster = new Monster;
		stringstream ss(line);
		string cell;
		int attrib = 0;

		while (getline(ss, cell, ',')) {
			if(!cell.length()){
				errors++;
			}

			switch(attrib) {
                case 0:
				try{
                    newMonster->setId(stoi(cell));
				}catch(exception& e){
					cout<<"Error in ID on file"<<endl;
					errors++;
				}
                    break;
				case 1:
					newMonster->setName(cell);
					break;
				case 2:
					try{
						newMonster->setHP(stoi(cell));
					}catch(exception& e){
						cout<<"Error in HP on file"<<endl;
						errors++;
					}
					break;
				case 3:
					try{
						newMonster->setATK(stoi(cell));
					}catch(exception& e){
						cout<<"Error in ATK on file"<<endl;
						errors++;
					}
					break;
				case 4:
					try{
						newMonster->setDEF(stoi(cell));
					}catch(exception& e){
						cout<<"Error in DEF on file"<<endl;
						errors++;
					}
					break;

				case 5:
					try{
						newMonster->setProbability(stoi(cell));
					}catch(exception& e){
						cout<<"Error in Probability on file"<<endl;
						errors++;
					}
					break;
				case 6:
					try{
						newMonster->setReward(stoi(cell));
					}catch(exception& e){
						cout<<"Error in Reward on file"<<endl;
						errors++;
					}
					break;
				default:
					errors++;
					break;
			}
			attrib++;
		}

		if (errors || attrib != MONSTER_ATTRIB_SIZE) {
			cerr<<"Error in line: "<<line<<endl;
			file.close();
			return false;
		}

		monstersList->pushFront(newMonster);
	}

    cout<<"Monsters file loaded successfully"<<endl;

	file.close();

	return true;
}


Monster* Execution::searchMonster(int id){
    Node<Monster*>* current = monstersList->getHead();
    while(current){
        if(current->getData()->getId() == id){
            return current->getData();
        }
        current = current->getNext();
    }

    return nullptr;
}



bool Execution::uploadMap(string fileName){
	ifstream file(fileName);
	string line;
	int errors = 0;

	if (!file.is_open()){
		cerr<<"Error while loading file: "<<fileName<<endl;
		return false;
	}

	cout<<"Loading file: "<<fileName<<endl;

	string size;

	if(!getline(file, size)){ // Get first line + save in size variable
		cerr<<"File is empty"<<endl;
		file.close();
		return false;
	} 

	int squares;

	try{
		squares = stoi(size); //number of squares
	}catch(exception& e){
		cerr<<"Error in number of squares"<<endl;
		file.close();
		return false;
	}



	if(!getline(file, size)){ //get second line + save in size variable to get number of edges
		cerr<<"File doesnt have the number of edges"<<endl;
		file.close();
		return false;
	}
	
	int edges;
	
	try{
		edges = stoi(size); //number of edges
	}catch(exception& e){
		cerr<<"Error in number of edges"<<endl;
		file.close();
		return false;
	}

	int i = 0;

	//uploading squares
	while(i<squares && getline(file, line)){
		stringstream ss(line);
		string cell;
		int attrib = 0;
		string currentSquare = "";
        int monsterId;
        Monster* ptrMonster = nullptr;

		while (getline(ss, cell, ',')) {
			if(!cell.length()){
				errors++;
			}


			switch(attrib){
				case 0:
					map->addSquare(cell);
					currentSquare = cell;
					break;
				case 1:
					try{
                        monsterId = stoi(cell);
					}catch(exception& e){
						cout<<"Error in Monster ID on file"<<endl;
						errors++;
					}

                    ptrMonster = searchMonster(monsterId);

                    if(!ptrMonster){
                        cout<<"Error in Monster ID on file"<<endl;
                        errors++;
                    }

                    break;

				default:
					errors++;
					break;
			}

			attrib++;
			
		}

		if (errors || attrib != ADD_VERTEX_ATTRIB_SIZE) {
			cerr<<"Error in line: "<<line<<endl;
			file.close();
			return false;
		}

        map->addMonster(currentSquare, ptrMonster);
		i++;
	}


	//Uploading edges
	i = 0;
	while(i<edges && getline(file, line)){
		stringstream ss(line);
		string cell;
		int attrib = 0;
		string square1 = "";
		string square2 = "";
		string weight = "";

		while (getline(ss, cell, ',')){
			if(!cell.length()){
				errors++;
			}

			switch(attrib){
				case 0:
					square1 = cell;
					break;
				case 1:
					square2 = cell;
					break;
				case 2:
					weight = cell;
					break;
			}

			attrib++;
		}

		if (errors || attrib != ADD_EDGE_ATTRIB_SIZE) {
			cerr<<"Error in line: "<<line<<endl;
			file.close();
			return false;
		}else{
			map->addEdge(square1, square2, weight); //TODO
		}

		i++;

	}

	string treasureSquare;

	if(!getline(file, treasureSquare)){
		cerr<<"File doesnt have the treasure square"<<endl;
		file.close();
		return false;
	}

	map->addTreasure(treasureSquare);

    cout<<"Map file loaded successfully"<<endl;

	file.close();

	return true;
}