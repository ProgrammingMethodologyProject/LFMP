#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>>
#include "configuracion.h"
#include "jugadores_plantillas.h"
#include "plantilla.h"


//Funcion para crear plantilla (SIN TERMINAR)
void Crear_Plantilla(T_plantilla *plantilla,int id, char *ident, char *nombre_plantilla, int presupuesto, int puntuacion)
{
    //Creamos una nueva plantilla
    plantilla nuevo, auxiliar;
    nuevo = (plantilla)malloc(sizeof(T_plantilla));
    if(nuevo == NULL){
        fprintf(stderr,"Error de asignacion de memoria");
        exit(1);
    }
    nuevo->id = id;
    strcpy(nuevo->ident,ident);
    strcpy(nuevo->nombre_plantilla,nombre_plantilla);
    strcpy(nuevo->presupuesto,presupuesto);
    strcpy(nuevo->puntuacion,puntuacion);
    nuevo->siguiente = NULL;
    // Si la plantilla esta vacia
    if(*plantilla==NULL){ // SIN TERMINAR
        nuevo->siguiente = *plantilla;
        *plantilla = nuevo;
        //printf(":%d:%s:%s:%s:%s:\n",lista->id,lista->nombre,lista->perfil,lista->user,lista->pass);
    }else{
        auxiliar = *plantilla;
        while(auxiliar->siguiente != NULL){
            auxiliar->siguiente = nuevo;
            nuevo->siguiente = auxiliar;
        }
        auxiliar->siguiente = *plantilla;
        *plantilla = nuevo;
        //printf(":%d:%s:%s:%s:%s:\n",lista->id,lista->nombre,lista->perfil,lista->user,lista->pass);
    }
    //printf(":%d:%s:%s:%s:%s:\n",nuevo->id,nuevo->nombre,nuevo->perfil,nuevo->user,nuevo->pass);
}
// Funcion que nos devuelve 1 si la lista esta vacia o 0 si no
//int lista_vacia(Lista *lista){ return (*lista == NULL ? 1:0); }


//TERMINAR
void Leer_Plantilla(T_plantilla *plantilla){

    int id,nElemN=2,nElemP=2,presupuesto,puntuacion;
    char ident[3], nombre_plantilla[30];
    nombre = (char*)calloc(nElemN,sizeof(char));
    perfil = (char*)calloc(nElemP,sizeof(char));

    FILE *fichP; fichP=fopen("Plantillas.txt","r"); //Lee el fichero
    if(!(fichP)){ //Si no existe le fichero, lo crea
        fichP=fopen("Plantillas.txt","w");
    }else{
        // Obtenemos del fichero los datos de los usuarios guardados
        while((fscanf(fichP,"%d-",&id))!=EOF){ // identificador
            int u=0,n=0,p=0;
            char c;
            printf("id=%d\n",id);
            while((c=fgetc(fichP))!='-'){
                nombre[n] = c;
                //nombre = (char*)realloc((nElemN+1),sizeof(char));
                //nElemN++;
                n++;
            }
            nombre[n]='\0';
            while((c=fgetc(fichP))!='-'){
                perfil[p] = c;
                //perfil = (char*)realloc((nElemP+1),sizeof(char));
                //nElemP++;
                p++;
            }
            perfil[p]='\0';
            fgets(user,6,fichU); // Usuario
            fgetc(fichU); // Saltamos el caracter '-'
            fgets(pass,9,fichU); // password
            //printf(":%d:%s:%s:%s:%s:\n",id,nombre,perfil,user,pass);
            Nuevo_user(lista,id,nombre,perfil,user,pass);
        }
        fclose(fichU);
    }
}

void Configurar_Plantilla(T_plantilla *plantilla)
{
    int a;

    //listar plantillas

    Listar_Plantilla();

    //participante elige plantilla del listado

    puts("Introduzca codigo plantilla");
    scanf("%d", &a);
    printf("Presupuesto: %d", plantilla->presupuesto); //se muestra el presupuesto disponible

    //menu configurar plantilla

    int a;

    puts("---- Configurar plantilla ---");
    puts("1.- Lista de jugadores en plantilla");
    puts("2.- Lista de jugadores disponibles");
    puts("3.- Añadir jugador a plantilla");
    puts("4.- Eliminar jugador de plantilla");
    puts("5.- Volver");
    scanf("%d", &a);

    switch(a)
    {
        case 1: Jugadores_Plantilla();break;
        case 2: Jugadores_Disp();break;
        case 3: Añadir_Jugador();break;
        case 4: Eliminar_Jugador();break;
        case 5: exit();break;
        default: puts("Opcion incorrecta");break;
    }
}

void Listar_Plantilla(T_plantilla *plantilla)
{
    int i;
    char str[35];

    printf("\nLista de plantillas:\n");
    for(i=0 ; i<plantilla.ident ; i++)
    {
        sprintf(str, "%02d-%s", plantilla[i].ident, plantilla[i].nombre_plantilla);
        printf("%s\n", str);
    }
    printf("\n");

}

//lista jugadores en plantilla
void Jugadores_Plantilla(T_plantilla *plantilla)
{


}

//lista jugadores disponibles
void Jugadores_Disp(T_plantilla *plantilla)
{

}

//añadir jugador a plantilla
void Añadir_Jugador(T_plantilla *plantilla, T_Futbolista *fut)
{

}

//eliminar
void Eliminar_Jugador(T_plantilla *plantilla)
{

}



void Eliminar_Plantilla(T_plantilla *plantilla)
{
    int cod,i,aux;

    Listar_Plantilla();

    puts("Introduzca codigo de la plantilla a eliminar");
    scanf("%d", &cod);
    fflush(stdin);

    for(i=0 ; i<tam ; i++){
        if(plantilla[i].ident == cod) {
            aux = 1;
            i++;
        }
        if(aux == 1)
            plantilla[i-1] = plantilla[i];
        else
            plantilla[i] = plantilla[i];
    }
    if(aux==1){
        plantilla = (T_plantilla *) realloc(plantilla, (--ident)*sizeof(T_plantilla));
    }

}

void Ranking(T_plantilla *plantilla)
{

}
