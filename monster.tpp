#pragma once

#include<monster.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

Monster::Monster(int id, std::string name, int HP, int ATK, int DEF, int probability, int reward){
    this->id = id;
    this->name = name;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->probability = probability;
    this->reward = reward;
}

bool Monster::uploadMonsters(std::string fileName) { //TODO
	std::ifstream file(fileName);
	std::string line;
	unsigned int size = 0;

	if (!file.is_open()) {
		std::cerr << "Error al abrir el archivo: " << fileName << std::endl;
		return false;
	}

	// Saltar el encabezado
	if(!getline(file, line)) {
		std::cerr << "El archivo no tiene header" << std::endl;
		file.close();
		return false;
	}

	std::cout << "Cargando archivo: " << fileName << std::endl;

	while (getline(file, line)) {
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
					newPart.setName(cell);
					break;
				case 1:
					newPart.setPrice(stod(cell));
					break;
				case 2:
					newPart.setType(cell);
					break;
				case 3:
					newPart.setBrand(cell);
					break;
				case 4:
					newPart.setPower(stoi(cell));
					break;
				case 5:
					newPart.setCapacity(stoi(cell));
					break;
				case 6:
					newPart.setCategory(cell);
					break;
				default:
					errores++;
					break;
			}
			campo++;
		}

		// Comparar si son el mismo numero de campos, aqui depende de cuantas 
		// entradas tiene cada clase, el número esta definido en el h
		// como PCPART_ATTRIB_SIZE
		if (errores || campo != PCPART_ATTRIB_SIZE) {
			std::cerr << "Error en la linea:\n" << line << std::endl;
			file.close();
			return false;
		}

		if(size < arraySize) {
			partArray[size] = newPart;
			size++;
		}
		else {
			std::cerr << "Error, el arreglo es muy pequeño" << std::endl;
			file.close();
			return false;
		}
	}

	file.close();
	return true;
}
