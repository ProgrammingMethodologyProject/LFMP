#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion.h"
#include "jugadores_plantillas.h"
#include "plantilla.h"


void Crear_Plantilla(T_Plantilla *plantilla,int *identificador_propietario, int *ident, char *nombre_equipo, int *presupuesto, int *puntuacion){
    //Creamos nueva plantilla
    plantilla nuevo;
    nuevo = (plantilla)malloc(sizeof(T_plantilla));
    if(nuevo == NULL){
        fprintf(stderr,"Error de asignacion de memoria");
        exit(1);
    }
    nuevo->identificador_propietario = identificador_propietario;
    strcpy(nuevo->identificador_propietario,identificador_propietario);
    strcpy(nuevo->ident,ident);
    strcpy(nuevo->nombre_equipo,nombre_equipo);
    strcpy(nuevo->presupuesto,presupuesto);
    strcpy(nuevo->puntuacion,puntuacion);
    // Si la plantilla esta vacia
    if(*plantilla == NULL){ // SIN TERMINAR
        nuevo->siguiente = *plantilla;
        *lista = nuevo;
    }else{}
}

void Leer_plantilla(T_plantilla *plantilla)
{    
    int identificador_propietario;
    int ident;
    char nombre_equipo[30];
    int presupuesto;
    int puntuacion;
    
    FILE *fichP;
    fichP=fopen("Plantillas.txt","r"); //Lee el fichero
    if(!(fichP)){ //Si no existe le fichero, lo crea
        fichP=fopen("Plantillas.txt","w");
    }else{
        // Obtenemos del fichero los datos de los usuarios guardados
        while((fscanf(fichP,"%d-",&identificador_propietario))!=EOF){ // identificador
            int u=0;
            char c[1];
            fgets(ident,11,fichP); // identificador de plantilla
            fgetc(fichP); // saltamos el caracter '-'
            fgets(perfil,14,fichP); // perfil
            hile((c[0]=fgetc(fichP))!='-'){
                user[u] = c[0];
                u++;
            }
            user[u]='\0';
            fgets(pass,9,fichP); // password
            Nuevo_user(head,id,nombre,perfil,user,pass);
        }
        fclose(fichP);
    }
}

void Configurar_Plantilla(T_plantilla *plantilla)
{
    
    
}

