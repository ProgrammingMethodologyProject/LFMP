#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Configuracion.h"

//Funcion que recoge todos los datos de los equipos guardados en el fichero Configuracion.txt
void Leer_config(ListaC *lista){
    int id;
    int presupuesto;
    int max_players;

    FILE *fichC; fichC=fopen("Configuracion.txt","r"); // Lee el fichero
    if(!(fichC)){ // Si no existe le fichero, lo crea
        fichC=fopen("Configuracion.txt","w");
    }else{
        // Obtenemos del fichero los datos de configuracion guardados
        while((fscanf(fichC,"%d-",&id))!=EOF){ // Numero maximo por equipos
            fscanf(fichC,"%d-",&presupuesto); // Presupuesto por defecto
            fscanf(fichC,"%d",&max_players); // Numero maximo de jugadores por equipo
            //printf(":%d:%d:%d:\n",id,presupuesto,jugadores);
            Nueva_config(lista,id,presupuesto,max_players);
        }
        fclose(fichC);
    }
}

//Funcion para introducir nueva configuracion
void Nueva_config(ListaC *lista,int id,int presupuesto,int max_players){
    //Creamos un nuevo equipo
    pConfig nuevo, ultimo;
    nuevo = (pConfig)malloc(sizeof(T_config));
    if(nuevo == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }

    nuevo->id = id;
    nuevo->presupuesto = presupuesto;
    nuevo->max_players = max_players;
    // Si la lista esta vacia
    if(ListaCVacia(*lista)){
        // Anadimos la lista a continuación de nueva configuracion
        nuevo->siguiente = *lista;
        // Ahora el comienzo de la lista es nueva configuracion
        *lista = nuevo;
    }else{
        ultimo = *lista;
        // Avanzamos hasta el último elemento
        while(ultimo->siguiente != NULL){
            ultimo = ultimo->siguiente;
        }
        // Insertamos nueva configuracion después del ultimo
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
    }
}

//Funcion que comprueba si la lista esta vacia
int ListaCVacia(ListaC lista){ return (lista == NULL); }

//Funcion para mostrar la configuracion
void Listar_config(ListaC lista){
    pConfig auxiliar;
    auxiliar = lista;
    // Si la lista esta vacia
    if(ListaCVacia(lista)){ printf("-Campo de configuracion vacio\n");
    }else{
        printf("-Configuracion:\n");
        // Avanzamos hasta el último elemento
        while(auxiliar){
            printf("Nº maximo equipos: %d\nPresupuesto defecto: %d\nNº maximo jugadores equipos: %d\n",auxiliar->id,auxiliar->presupuesto,auxiliar->max_players);
            auxiliar = auxiliar->siguiente;
        }
    }
}

//Funcion para localizar un equipo existente
void Localizar_config(ListaC *lista,int opc){
    int id,presupuesto,max_players;
    pConfig auxiliar;
    auxiliar = (pConfig)malloc(sizeof(T_config));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }
    auxiliar = *lista;
    // Si la lista esta vacia
    if(ListaCVacia(auxiliar)){
        printf("-Campos de configuracion vacios\n");
    }else{
        if(auxiliar){
            if(opc == 1){
                printf("-Total equipos: %d\n",auxiliar->id);
                printf("-Nuevo total: ");
                scanf("%d",&id);
                auxiliar->id = id;
                printf("-Numero maximo de equipos (%d) actualizado\n",auxiliar->id);
            }
            if(opc == 2){
                printf("-Presupuesto: %d\n",auxiliar->presupuesto);
                printf("-Nuevo presupuesto: ");
                scanf("%d",&presupuesto);
                auxiliar->presupuesto = presupuesto;
                printf("-Presupuesto por defecto (%d) actualizado\n",auxiliar->presupuesto);
            }
            if(opc == 3){
                printf("-Jugadores por equipo: %d\n",auxiliar->max_players);
                printf("-Nuevo total: ");
                scanf("%d",&max_players);
                auxiliar->max_players = max_players;
                printf("-Numero maximo de jugadores por equipo (%d) actualizado\n",auxiliar->max_players);
            }
        }
    }
}
