#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "Usuarios.h"
#include "Equipos.h"
#include "Configuracion.h"

int main(){
    ListaE l_equipos=NULL; // Indice para el listado de equipos
    ListaU l_usuarios=NULL; // Indice para el listado de usuarios
    ListaC l_config=NULL; // Indice para el listado de la configuracion
    Leer_equipo(&l_equipos); //Funcion que recorre el fichero Equipos.txt
    Leer_user(&l_usuarios); //Funcion que recorre el fichero Usuarios.txt
    Leer_config(&l_config); //Funcion que recorre el fichero Configuracion.txt
    int S=1,op=0;
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
                    case 1: Listar_equipo(&l_equipos);// Listar Equipos
                            getch(); system("cls"); op = 1; break;
                    case 2: Localizar_equipo(&l_equipos);// Modificar equipos
                            getch(); system("cls"); op = 1; break;
                    case 3: if(TotalEquipos(&l_equipos) < Configuracion(&l_config,1)){
                                Alta_equipo(&l_equipos);// Agregar equipos
                            }else{
                                printf("-Limite de equipos permitidos\n");
                            }
                            getch(); system("cls"); op = 1; break;
                    case 4: Eliminar_equipo(&l_equipos);// Eliminar equipos
                            getch(); system("cls"); op = 1; break;
                    case 5: system("cls"); op = 0; break;
                }
            }
            while(op == 2){ // Futbolistas
                switch(menu(7)){
                    case 1: Listar_futbolista(&l_fut);// Listar futbolistas
                            getch(); system("cls"); op = 2; break;
                    case 2: Localizar_futbolista(&l_fut);// Modificar futbolistas
                            getch(); system("cls"); op = 2; break;
                    case 3: printf("-Equipo al que quieres agregar un nuevo jugador (introducir id):\n");
                            fflush(stdin);
                            scanf("%d",&op);
                            if(op <= TotalEquipos(&l_equipos)){
                                if(TotalJugadores(&l_fut,op) < Configuracion(&l_config,3)){
                                    Alta_futbolista(&l_fut,op);// Agregar futbolista a cierto equipo
                                }else{
                                    printf("-Limite de jugadores para este equipo permitidos.\n");
                                }
                            }else{
                                printf("-Id de equipo no encontrado\n");
                            }
                            getch(); system("cls"); op = 2; break;
                    case 4: //Eliminar_futbolista(&l_fut);// Eliminar futbolistas
                            getch(); system("cls"); op = 2; break;
                    case 5: system("cls"); op = 0; break;
                }
            }
            while(op == 3){ // Usuarios
                switch(menu(5)){
                    case 1: Listar_user(&l_usuarios); // Listar usuarios
                            getch(); system("cls"); op = 3; break;
                    case 2: Localizar_user(&l_usuarios);// Modificar usuarios
                            getch(); system("cls"); op = 3; break;
                    case 3: Alta_user(&l_usuarios);// Agregar usuarios
                            getch(); system("cls"); op = 3; break;
                    case 4: Eliminar_user(&l_usuarios);// Eliminar usuarios
                            getch(); system("cls"); op = 3; break;
                    case 5: system("cls"); op = 0; break;
                }
            }
            while(op == 3){ //Configuracion
                switch(menu(6)){
                    case 1: Listar_config(&l_config); // Listar todos los campos de configuracion
                            getch(); system("cls"); op = 3; break;
                    case 2: Localizar_config(&l_config,1); // Numero maximo de equipos
                            getch(); system("cls"); op = 3; break;
                    case 3: Localizar_config(&l_config,2);// Presupuesto por defecto
                            getch(); system("cls"); op = 3; break;
                    case 4: Localizar_config(&l_config,3);// Numero maximo de jugadores por equipo
                            getch(); system("cls"); op = 3; break;
                    case 5: system("cls"); op = 0; break;
                }
            }
            if(op == 4){ S=0; }
            op = 1;
        }
        if(op == 2){ // Menu cronista
            op = menu(op); system("cls");
            if(op == 1){ Listar_equipo(&l_equipos); }// Listar Equipos
            while(op == 2){}
            if(op == 3){ S=0; }
            op = 2;
        }
        if(op == 3){ // Menu participante
            while(S){
                switch(menu(3)){
                    case 1: // Crear plantilla
                            getch(); system("cls"); op = 3; break;
                    case 2: // Configurar disponibles
                            getch(); system("cls"); op = 3; break;
                    case 3: // Listar plantilla
                            getch(); system("cls"); op = 3; break;
                    case 4: // Eliminar plantilla
                            getch(); system("cls"); op = 3; break;
                    case 5: // Ranking
                            getch(); system("cls"); op = 3; break;
                    case 6: system("cls"); S=0; break;
                }
            }
        }
    }
    Update_equipos(&l_equipos); Update_user(&l_usuarios); Update_config(&l_config); Update_futbolistas(&l_fut);// Actualiza los ficheros
return 0;
}
