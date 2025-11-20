#include"Execution.h"

int main(){

    Execution execution;

    if(!execution.start("monsters.txt", "map.txt")){
        cout<<"Error al ejecutar el juego"<<endl;
    };

    return 0;
}