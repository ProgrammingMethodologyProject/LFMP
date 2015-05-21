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
            case 2: op = Login_user(&l_usuarios); // Acceso con usuario existente
                    S=0; break;
            case 3: //Salir
                    S=0; break;
        }
    }
    S=1;
    while(S){
        if(op == 1){
            switch(menu(op)){
                case 1: // Equipos
                        system("pause"); system("cls"); break;
                case 2: // Usuarios
                        system("pause"); system("cls"); break;
                case 3: // Configuracion
                        system("pause"); system("cls"); break;
                case 4: S=0; system("cls"); break;
            }
        }
        if(op == 2){
            switch(menu(op)){
                case 1: //
                        system("pause"); system("cls"); break;
                case 2: //
                        system("pause"); system("cls"); break;
                case 3: S=0; system("cls"); break;
            }
        }
        if(op == 3){
            switch(menu(op)){
                case 1: //
                        system("pause"); system("cls"); break;
                case 2: // system("pause");
                        system("cls"); break;
                case 3: // system("pause");
                        system("cls"); break;
                case 4: // system("pause");
                        system("cls"); break;
                case 5: // system("pause");
                        system("cls"); break;
                case 6: S=0; system("cls"); break;
            }
        }
    }
return 0;
}
