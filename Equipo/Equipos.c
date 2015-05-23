#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Equipos.h"

//Funcion que recoge todos los datos de los equipos guardados en el fichero Equipos.txt
void Leer_equipo(ListaE *lista){
    int id;
    char *nombre;
    nombre = (char*)calloc(20,sizeof(char));

    FILE *fichE; fichE=fopen("Equipos.txt","r"); // Lee el fichero
    if(!(fichE)){ // Si no existe le fichero, lo crea
        fichU=fopen("Equipos.txt","w");
    }else{
        // Obtenemos del fichero los datos de los usuarios guardados
        while((fscanf(fichE,"%d-",&id))!=EOF){ // identificador
            fgets(nombre,21,fichE); // nombre
            printf(":%d:%s:\n",id,nombre);
            Nuevo_user(lista,id,nombre);
        }
        fclose(fichE);
    }
}

//Funcion para introducir nuevo equipo
void Nuevo_equipo(ListaE *lista,int id,char *nombre){
    //Creamos un nuevo equipo
    pEquipos nuevo, ultimo;
    nuevo = (pEquipos)malloc(sizeof(T_equipo));
    if(nuevo == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }

    nuevo->id = id;
    nuevo->nombre = nombre;
    printf(":%d:%s:\n",nuevo->id,nuevo->nombre);
    // Si la lista de usuarios esta vacia
    if(ListaVacia(*lista)){
        // Anadimos la lista a continuación del nuevo equipo
        nuevo->siguiente = *lista;
        // Ahora el comienzo de la lista es nuevo equipo
        *lista = nuevo;
    }else{
        ultimo = *lista;
        // Avanzamos hasta el último elemento
        while(ultimo->siguiente != NULL){
            ultimo = ultimo->siguiente;
        }
        // Insertamos nuevo equipo después del ultimo
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
    }
}
