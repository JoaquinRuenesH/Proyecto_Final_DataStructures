#include"Execution.h"

int main(){
    srand(time(nullptr));

    Execution execution;

    if(!execution.start("monstersSpiderMan.txt", "mapSpiderMan.txt")){
        cout<<"Error al ejecutar el juego"<<endl;
    }

    return 0;
}