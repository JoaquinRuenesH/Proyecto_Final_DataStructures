#include"gameSetUp.h"

using namespace std;

GameSetUp::GameSetUp(){
    monstersList = new LinkedList<Monster*>;
	map = new Graph<string>;
}

GameSetUp::~GameSetUp(){
    delete monstersList;
	delete map;
}


bool GameSetUp::uploadMonsters(string fileName){
	ifstream file(fileName);
	string line;

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
        int errors = 0;

		while (getline(ss, cell, ',')) {
			if(!cell.length()){
				errors++;
			}

			switch(attrib) {
                case 0:
                    newMonster->setId(stoi(cell));
                    break;
				case 1:
					newMonster->setName(cell);
					break;
				case 2:
					newMonster->setHP(stoi(cell));
					break;
				case 3:
					newMonster->setATK(stoi(cell));
					break;
				case 4:
					newMonster->setDEF(stoi(cell));
					break;
				case 5:
					newMonster->setProbability(stoi(cell));
					break;
				case 6:
					newMonster->setReward(stoi(cell));
					break;
				default:
					errors++;
					break;
			}
			attrib++;
		}

		if (errors || attrib != MONSTER_ATRIB_SIZE) {
			cerr << "Error in line:\n" << line << endl;
			file.close();
			return false;
		}

		monstersList->pushFront(newMonster);
	}

    cout<<"Monsters file loaded successfully"<<endl;

	file.close();
	return true;
}





bool GameSetUp::uploadMap(string fileName){
	ifstream file(fileName);
	string line;

	if (!file.is_open()){
		cerr<<"Error while loading file: "<<fileName<<endl;
		return false;
	}

	cout<<"Loading file: "<<fileName<<endl;

	string size;

	// Jump header + save in size variable
	if(!getline(file, size)){
		cerr<<"File doesnt have number of squares"<<endl;
		file.close();
		return false;
	}

	int squares = stoi(size); //number of squares

	// Jump line + save in size variable to get number of edges
	if(!getline(file, size)){
		cerr<<"File doesnt have the number of edges"<<endl;
		file.close();
		return false;
	}
	
	int edges = stoi(size); //number of edges

	int i = 0;

	//uploading squares
	while(i<squares && getline(file, line)){
		stringstream ss(line);
		string cell;
        int errors = 0;

		while (getline(ss, cell)) {
			if(!cell.length()){
				errors++;
			}

			map->addSquare(cell);
			//std::cout<<"Adding: "<<cell<<"\n";
			
		}

		if (errors) {
			cerr << "Error in line:\n" << line << endl;
			file.close();
			return false;
		}

		i++;
	}


	//Uploading edges
	i = 0;
	while(i<edges && getline(file, line)){
		stringstream ss(line);
		string cell;
        int errors = 0;
		int time = 0;
		string square1;
		string square2;

		while (getline(ss, cell, ',')){
			if(!cell.length()){
				errors++;
			}

			//If time%2 == 0, means it's the first square of the edge
			if(time%2 == 0){
				square1 = cell;
			}else{
				square2 = cell;
			}
			
			//If time%2 == 1, means both squares for adding the edge had been asigned
			if(time%2 == 1){
				map->addEdge(square1, square2);
				//cout<<"Adding edge: "<<square1<<", "<<square2<<"\n";
			}

			time++;
		}

		if (errors) {
			cerr << "Error in line:\n" << line << endl;
			file.close();
			return false;
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