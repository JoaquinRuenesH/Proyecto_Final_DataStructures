#include"gameSetUp.h"

GameSetUp::GameSetUp(){
    LinkedList<Monster> monstersList;
}

GameSetUp::~GameSetUp(){
    monstersList.clear();
}

bool GameSetUp::uploadMonsters(std::string fileName){
	std::ifstream file(fileName);
	std::string line;

	if (!file.is_open()){
		std::cerr<<"Error al abrir el archivo: "<<fileName<<std::endl;
		return false;
	}

	// Saltar el encabezado
	if(!getline(file, line)) {
		std::cerr<<"El archivo no tiene header"<<std::endl;
		file.close();
		return false;
	}

	std::cout<<"Cargando archivo: "<<fileName<<std::endl;

	while(getline(file, line)){
		Monster	newMonster;
		std::stringstream ss(line);
		std::string cell;
		int campo = 0;
        int errores = 0;

		while (getline(ss, cell, ',')) {
			if(!cell.length())
				errores++;

			switch(campo) {
                case 0:
                    newMonster.setID(stoi(cell));
                    break;
				case 1:
					newMonster.setName(cell);
					break;
				case 2:
					newMonster.setHP(std::stoi(cell));
					break;
				case 3:
					newMonster.setATK(std::stoi(cell));
					break;
				case 4:
					newMonster.setDEF(std::stoi(cell));
					break;
				case 5:
					newMonster.setProbability(std::stoi(cell));
					break;
				case 6:
					newMonster.setReward(std::stoi(cell));
					break;
				default:
					errores++;
					break;
			}
			campo++;
		}

		// Comparar si son el mismo numero de campos, aqui depende de cuantas 
		// entradas tiene cada clase, el número esta definido en el h
		// como MONSTER_ATTRIB_SIZE
		if (errores || campo != MONSTER_ATRIB_SIZE) {
			std::cerr << "Error en la linea:\n" << line << std::endl;
			file.close();
			return false;
		}

		monstersList.pushFront(newMonster);
	}

    std::cout<<"Archivo cargado con exito"<<std::endl;

	file.close();
	return true;
}