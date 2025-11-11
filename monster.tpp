#pragma once

#include<monster.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

bool uploadMonsters(string fileName) {
	ifstream file(fileName);
	string line;
	unsigned int size = 0;

	if (!file.is_open()) {
		cerr << "Error al abrir el archivo: " << fileName << endl;
		return false;
	}

	// Saltar el encabezado
	if(!getline(file, line)) {
		cerr << "El archivo no tiene header" << endl;
		file.close();
		return false;
	}

	cout << "Cargando archivo: " << fileName << endl;

	while (getline(file, line)) {
		Monster	newMonster;
		stringstream ss(line);
		string cell;
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
			cerr << "Error en la linea:\n" << line << endl;
			file.close();
			return false;
		}

		if(size < arraySize) {
			partArray[size] = newPart;
			size++;
		}
		else {
			cerr << "Error, el arreglo es muy pequeño" << endl;
			file.close();
			return false;
		}
	}

	file.close();
	return true;
}
