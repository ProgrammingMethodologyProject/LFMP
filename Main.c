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
                    getch(); system("cls"); break;
            case 2: op = Login_user(&l_usuarios); // Acceso con usuario existente
                    S=0; break;
            case 3: //Salir
                    S=0; break;
        }
    }
    S=1;
    while(S){
        if(op == 0){ S=0; } // Salir
        if(op == 1){ //Menu administrador
            op = menu(op); system("cls");
            while(op == 1){ // Equipos
                switch(menu(4)){
                    case 1: // Listar Equipos
                            getch(); system("cls"); op = 1; break;
                    case 2: // Modificar equipos
                            getch(); system("cls"); op = 1; break;
                    case 3: // Agregar equipos
                            getch(); system("cls"); op = 1; break;
                    case 4: // Eliminar equipos
                            getch(); system("cls"); op = 1; break;
                    case 5: S=0; system("cls"); op = 0; break;
                }
            }
            while(op == 2){ // Usuarios
                switch(menu(5)){
                    case 1: Listar_user(l_usuarios); // Listar usuarios
                            getch(); system("cls"); op = 2; break;
                    case 2: Localizar_user(&l_usuarios);// Modificar usuarios
                            getch(); system("cls"); op = 2; break;
                    case 3: Alta_user(&l_usuarios);// Agregar usuarios
                            getch(); system("cls"); op = 2; break;
                    case 4: Eliminar_user(&l_usuarios);// Eliminar usuarios
                            getch(); system("cls"); op = 2; break;
                    case 5: system("cls"); op = 0; break;
                }
            }
            while(op == 3){ //Configuracion
                switch(menu(6)){
                    case 1: // Numero maximo de equipos
                            getch(); system("cls"); op = 3; break;
                    case 2: // Presupuesto por defecto
                            getch(); system("cls"); op = 3; break;
                    case 3: // Numero maximo de jugadores por equipo
                            getch(); system("cls"); op = 3; break;
                    case 4: system("cls"); op = 0; break;
                }
            }
            if(op == 4){ S=0; }
            op = 1;
        }
        if(op == 2){ // Menu cronista
            op = menu(op); system("cls");
            op = 2;
        }
        if(op == 3){ // Menu participante
            op = menu(op); system("cls");
            op = 3;
        }
    }
return 0;
}
