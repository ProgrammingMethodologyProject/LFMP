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
    if(ListaEVacia(*lista)){
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

//Funcion que comprueba si la lista esta vacia
int ListaEVacia(ListaE lista){ return (lista == NULL); }

//Funcion para listar los equipos existentes
void Listar_equipo(ListaE lista){
    pEquipos auxiliar;
    auxiliar = lista;
    // Si la lista de usuarios esta vacia
    if(ListaEVacia(lista)){ printf("-Lista de equipos vacia\n");
    }else{
        printf("-Lista de equipos:\n");
        // Avanzamos hasta el último elemento
        while(auxiliar){
            if(auxiliar->id <10){
                printf("0%d-%s\n",auxiliar->id,auxiliar->nombre);
            }else{
                printf("%d-%s\n",auxiliar->id,auxiliar->nombre);
            }
            auxiliar = auxiliar->siguiente;
        }
    }
}

//Funcion para localizar un equipo existente
void Localizar_equipo(ListaE *lista){
    int id,op;
    pEquipos auxiliar;
    auxiliar = (pEquipos)malloc(sizeof(T_equipo));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }
    auxiliar = *lista;
    // Si la lista de equipos esta vacia
    if(ListaEVacia(auxiliar)){
        printf("-Lista de equipos vacia\n");
    }else{
        printf("-Numero identificador del equipo que quieres modificar: ");
        fflush(stdin); // Elimina basura
        scanf("%d",&id);
        // Avanzamos hasta el último elemento
        while(auxiliar && auxiliar->id != id){ auxiliar = auxiliar->siguiente; }
        if(auxiliar){
            printf("%d-%s\n",auxiliar->id,auxiliar->nombre);
            fflush(stdin);
            printf("-Modificar nombre?(1 si/2 no): ");
            scanf("%d",&op);
            if(op == 1){
                printf("-Nombre(max 20): ");
                gets(auxiliar->nombre);
            }
            printf("-Equipo modificado:\n");
            printf("%d-%s\n",auxiliar->id,auxiliar->nombre);
        }
    }
}

//Funcion para eliminar un usuario de la lista
void Eliminar_equipo(ListaE *lista){
    int id;
    pEquipos anterior, auxiliar;
    auxiliar = *lista;
    anterior = NULL;
    printf("-Eliminar equipo:\n-Introduce identificador del equipo: ");
    scanf("%d",&id);
    while(auxiliar && auxiliar->id < id){
        anterior = auxiliar;
        auxiliar = auxiliar->siguiente;
    }
    if(!auxiliar || auxiliar->id != id){
        printf("-Equipo no existe\n");
    }else{
        // Eliminamos el equipo
        if(!anterior){
            // 1er elemento
            *lista = auxiliar->siguiente;
        }else{
            anterior->siguiente = auxiliar->siguiente;
        }
        free(auxiliar);
        printf("-Equipo eliminado: ");
    }
}
