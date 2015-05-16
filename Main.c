#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Usuarios.h"

int main(){
    T_usuario *head = NULL;
    Leer_user(head); //Funcion que recorre el fichero Usuarios.txt
    int S=1;
    while(S){
        switch(menu(0)){ // Menu(0) nos devuelve la opcion de navegacion por el men principal
            case 1: // Menu(1) de registro
                    system("cls"); break;
            case 2: // Menu(2) de acceso
                    system("cls"); break;
            case 3: //Salir
                    S=0;
                    system("cls"); break;
        }
    }
return 0;
}
