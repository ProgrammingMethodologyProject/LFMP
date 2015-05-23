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
            Nuevo_user(lista,id,nombre,perfil,user,pass);
        }
        fclose(fichE);
    }
}

//Funcion para introducir nuevo equipo
void Nuevo_equipo(ListaE *lista,int id,char *nombre){

}
