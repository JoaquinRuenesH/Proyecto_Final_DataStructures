#include"Execution.h"

int main(){
    srand(time(nullptr));

    Execution execution;

    if(!execution.start("monstersBatman.txt", "mapBatman.txt")){
        cout<<"Error al ejecutar el juego"<<endl;
    }

    return 0;
}