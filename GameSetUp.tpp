#include"gameSetUp.h"
#include<iostream>

using namespace std;

GameSetUp::GameSetUp(){
    monstersList = new LinkedList<Monster*>;
	map = new Graph<string>;
}

GameSetUp::~GameSetUp(){
    delete monstersList;
	delete map;
}

LinkedList<Monster*>* GameSetUp::uploadMonsters(string fileName){
	ifstream file(fileName);
	string line;
	int errors = 0;

	if (!file.is_open()){
		cerr<<"Error while loading file: "<<fileName<<endl;
		return nullptr;
	}

	// Jump header
	if(!getline(file, line)) {
		cerr<<"File doesnt have header"<<endl;
		file.close();
		return nullptr;
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
			return nullptr;
		}

		monstersList->pushFront(newMonster);
	}

    cout<<"Monsters file loaded successfully"<<endl;

	file.close();
	return monstersList;
}



Graph<string>* GameSetUp::uploadMap(string fileName){
	ifstream file(fileName);
	string line;
	int errors = 0;

	if (!file.is_open()){
		cerr<<"Error while loading file: "<<fileName<<endl;
		return nullptr;
	}

	cout<<"Loading file: "<<fileName<<endl;

	string size;

	if(!getline(file, size)){ // Get first line + save in size variable
		cerr<<"File is empty"<<endl;
		file.close();
		return nullptr;
	} 

	int squares;

	try{
		squares = stoi(size); //number of squares
	}catch(exception& e){
		cerr<<"Error in number of squares"<<endl;
		file.close();
		return nullptr;
	}



	if(!getline(file, size)){ //get second line + save in size variable to get number of edges
		cerr<<"File doesnt have the number of edges"<<endl;
		file.close();
		return nullptr;
	}
	
	int edges;
	
	try{
		edges = stoi(size); //number of edges
	}catch(exception& e){
		cerr<<"Error in number of edges"<<endl;
		file.close();
		return nullptr;
	}

	int i = 0;

	//uploading squares
	while(i<squares && getline(file, line)){
		stringstream ss(line);
		string cell;
		int attrib = 0;
		string currentSquare = "";

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
						map->addMonster(currentSquare, stoi(cell)); //TODO
					}catch(exception& e){
						cout<<"Error in ID on file"<<endl;
						errors++;
					}
                    break;

				default:
					errors++;
					break;
			}

			//std::cout<<"Adding: "<<cell<<endl;

			attrib++;
			
		}

		if (errors || attrib != ADD_VERTEX_ATTRIB_SIZE) {
			cerr<<"Error in line: "<<line<<endl;
			file.close();
			return nullptr;
		}

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
			return nullptr;
		}else{
			map->addEdge(square1, square2, weight);
		}

		i++;

	}

	string treasureSquare;

	if(!getline(file, treasureSquare)){
		cerr<<"File doesnt have the treasure square"<<endl;
		file.close();
		return nullptr;
	}

	map->addTreasure(treasureSquare);

    cout<<"Map file loaded successfully"<<endl;

	file.close();

	return map;
}