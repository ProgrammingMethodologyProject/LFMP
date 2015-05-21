#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Usuarios.h"

int main(){
    Lista l_usuarios=NULL; // Indice para el listado de usuarios
    Leer_user(&l_usuarios); //Funcion que recorre el fichero Usuarios.txt
    int S=1;
    while(S){
        switch(menu(0)){ // Menu(0) nos devuelve la opcion de navegacion por el men principal
            case 1: Alta_user(&l_usuarios); // Registro de nuevo usuario
                    system("cls"); break;
            case 2: Login_user(&l_usuarios); // Acceso con usuario existente
                    system("cls"); break;
            case 3: //Salir
                    S=0; break;
        }
    }
return 0;
}
