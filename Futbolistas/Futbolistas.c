#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Futbolistas.h"

//Funcion que recoge todos los datos de los equipos guardados en el fichero Futbolistas.txt
void Leer_futbolista(ListaF *lista){
    int id_futbolista, id_equipo, precio, valoracion;
    char *nombre;
    nombre = (char*)calloc(20,sizeof(char));

    FILE *fichF; fichF=fopen("Futbolistas.txt","r"); // Lee el fichero
    if(!(fichF)){ // Si no existe le fichero, lo crea
        fichF=fopen("Futbolistas.txt","w");
    }else{
        // Obtenemos del fichero los datos de los futbolistas guardados
        while((fscanf(fichF,"%d-",&id_futbolista))!=EOF){ // identificador futbolistas
            fscanf(fichF,"%d-",&id_equipo); // identificador futbolistas
            int n=0;
            char c;
            while((c=fgetc(fichF))!='-'){ // nombre futbolistas
                nombre[n] = c;
                n++;
            }
            nombre[n]='\0';
            fscanf(fichF,"%d-",&precio); // Precio
            fscanf(fichF,"%d",&valoracion); // Valoracion
            //printf(":%d:%d:%s:%d:%d:\n",id_futbolista,id_equipo,nombre,precio,valoracion);
            Nuevo_futbolista(lista,id_futbolista,id_equipo,nombre,precio,valoracion);
        }
        fclose(fichF);
    }
}

//Funcion para introducir nuevo futbolista
void Nuevo_futbolista(ListaF *lista,int id_futbolista,int id_equipo,char *nombre,int precio,int valoracion){
    //Creamos un nuevo futbolista
    pfutbolista nuevo, ultimo;
    nuevo = (pfutbolista)malloc(sizeof(T_futbolista));
    if(nuevo == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }

    nuevo->id_futbolista = id_futbolista;
    nuevo->id_equipo = id_equipo;
    strcpy(nuevo->nombre,nombre);
    nuevo->precio = precio;
    nuevo->valoracion = valoracion;
    // Si la lista de futbolistas esta vacia
    if(ListaFVacia(*lista)){
        nuevo->siguiente = *lista; // Anadimos la lista a continuación del nuevo futbolista
        *lista = nuevo; // Ahora el comienzo de la lista es nuevo futbolista
    }else{
        ultimo = *lista;
        // Avanzamos hasta el último elemento
        while(ultimo->siguiente){ ultimo = ultimo->siguiente; }
        // Insertamos nuevo futbolista después del ultimo
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
    }
}

//Funcion para dar de alta un nuevo futbolista
void Alta_futbolista(ListaF *lista, int nuevo_id_equipo){
    int nuevo_id_futbolista,nuevo_precio,nuevo_valoracion,aux=1;
    char nuevo_nombre[20];

    pfutbolista auxiliar;
    auxiliar = (pfutbolista)malloc(sizeof(T_futbolista));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }

    auxiliar = *lista;
    if(auxiliar != NULL){ // Para calcular el siguiente identificador
        aux++;
        while(auxiliar->siguiente != NULL){ auxiliar = auxiliar->siguiente; aux++; }
    }
    printf("\t-Alta futbolista:\n");
    printf("-Identificador futbolista: %d\n",aux);
    nuevo_id_futbolista = aux;
    printf("-Identificador equipo: %d\n",nuevo_id_equipo);

    puts("-Nombre(max 20):");
    fflush(stdin);
    gets(nuevo_nombre);
    if(strlen(nuevo_nombre)>20){ printf("\tNombre introducido demasiado largo.\n"); exit(0); }

    printf("-Precio: ");
    scanf("%d",&nuevo_precio);
    nuevo_valoracion = 0;

    Nuevo_futbolista(lista,nuevo_id_futbolista,nuevo_id_equipo,nuevo_nombre,nuevo_precio,nuevo_valoracion);
    printf("\nAlta finalizada.\n");
}

//Funcion que comprueba si la lista esta vacia
int ListaFVacia(ListaF lista){ return (lista == NULL); }

//Funcion para listar los futbolista existentes
void Listar_futbolista(ListaF *lista){
    pfutbolista auxiliar;
    auxiliar = *lista;
    // Si la lista de futbolista esta vacia
    if(ListaFVacia(*lista)){ printf("-Lista de futbolistas vacia\n");
    }else{
        printf("-Lista de futbolistas:\n");
        // Avanzamos hasta el último elemento
        while(auxiliar){
            if(auxiliar->id_futbolista <10){
                if(auxiliar->id_equipo <10){
                    printf("0%d-0%d-%s-%d-%d\n",auxiliar->id_futbolista,auxiliar->id_equipo,auxiliar->nombre,auxiliar->precio,auxiliar->valoracion);
                }else{
                    printf("0%d-%d-%s-%d-%d\n",auxiliar->id_futbolista,auxiliar->id_equipo,auxiliar->nombre,auxiliar->precio,auxiliar->valoracion);
                }
            }else{
                if(auxiliar->id_equipo <10){
                    printf("%d-0%d-%s-%d-%d\n",auxiliar->id_futbolista,auxiliar->id_equipo,auxiliar->nombre,auxiliar->precio,auxiliar->valoracion);
                }else{
                    printf("%d-%d-%s-%d-%d\n",auxiliar->id_futbolista,auxiliar->id_equipo,auxiliar->nombre,auxiliar->precio,auxiliar->valoracion);
                }
            }
            auxiliar = auxiliar->siguiente;
        }
    }
}

//Funcion para localizar un futbolista existente
void Localizar_futbolista(ListaF *lista){
    int id_futbolista, id_equipo, precio, valoracion, op;
    char nombre[20];

    pfutbolista auxiliar;
    auxiliar = (pfutbolista)malloc(sizeof(T_futbolista));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }

    auxiliar = *lista;
    // Si la lista de futbolistas esta vacia
    if(ListaFVacia(auxiliar)){
        printf("-Lista de futbolistas vacia\n");
    }else{
        printf("-Numero identificador del futbolista que quieres modificar: ");
        fflush(stdin); // Elimina basura
        scanf("%d",&id_futbolista);
        // Avanzamos hasta el último elemento
        while(auxiliar && auxiliar->id_futbolista != id_futbolista){ auxiliar = auxiliar->siguiente; }
        if(auxiliar){
            printf("%d-%d-%s-%d-%d\n",auxiliar->id_futbolista,auxiliar->id_equipo,auxiliar->nombre,auxiliar->precio,auxiliar->valoracion);
            printf("-Modificar equipo?(1 si/2 no): "); // ID Equipo
            scanf("%d",&op);
            if(op == 1){
                printf("-Equipo(max 2 digitos): ");
                scanf("%d",&id_equipo);
                auxiliar->id_equipo;
            }
            fflush(stdin); // Nombre futbolista
            printf("-Modificar nombre?(1 si/2 no): ");
            scanf("%d",&op);
            if(op == 1){
                printf("-Nombre(max 20): ");
                fflush(stdin);
                gets(nombre);
                strcpy(auxiliar->nombre,nombre);
            }
            printf("-Modificar precio?(1 si/2 no): "); // Precio en millones
            scanf("%d",&op);
            if(op == 1){
                printf("-Precio: ");
                scanf("%d",&precio);
                auxiliar->precio;
            }
            printf("-Modificar valoracion?(1 si/2 no): "); // Valoracion
            scanf("%d",&op);
            if(op == 1){
                printf("-Valoracion(0-10): ");
                do{
                    scanf("%d",&valoracion);
                }while(valoracion > 10 || valoracion < 0);
                auxiliar->valoracion;
            }
            printf("-Futbolista modificado:\n");
            printf("%d-%d-%s-%d-%d\n",auxiliar->id_futbolista,auxiliar->id_equipo,auxiliar->nombre,auxiliar->precio,auxiliar->valoracion);
        }
    }
}

//Funcion para eliminar un futbolista de la lista
void Eliminar_futbolista(ListaF *lista){
    int id_futbolista;
    pfutbolista anterior, auxiliar;
    auxiliar = *lista;
    anterior = NULL;

    printf("-Eliminar futbolista:\n-Introduce identificador del futbolista: ");
    scanf("%d",&id_futbolista);
    while(auxiliar && auxiliar->id_futbolista < id_futbolista){ anterior = auxiliar; auxiliar = auxiliar->siguiente; }
    if(!auxiliar || auxiliar->id_futbolista != id_futbolista){ printf("-Futbolista no existe\n");
    }else{
        // Eliminamos el futbolista
        if(!anterior){ // 1er elemento
            *lista = auxiliar->siguiente;
            anterior = *lista; // Para colocar los ID
        }else{
            anterior->siguiente = auxiliar->siguiente;
            anterior = anterior->siguiente; // Para colocar los ID
        }
        while(anterior){ //Reorganiza los Id correctamente
            anterior->id_futbolista = id_futbolista;
            anterior = anterior->siguiente;
            id_futbolista++;
        }
        free(auxiliar);
        printf("-Futbolista eliminado");
    }
}

//Funcion que actualiza el fichero Futbolistas.txt
void Update_futbolista(ListaF *lista){
    pfutbolista futbolistas = *lista;

    FILE *fichF;
    fichF=fopen("Futbolistas.txt","w");
    while(futbolistas){
        if(!(futbolistas->siguiente)){
            if(futbolistas->id_futbolista <10){
                if(futbolistas->id_equipo <10){
                    fprintf(fichF,"0%d-0%d-%s-%d-%d",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }else{
                    fprintf(fichF,"0%d-%d-%s-%d-%d",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }
            }else{
                if(futbolistas->id_equipo <10){
                    fprintf(fichF,"%d-0%d-%s-%d-%d",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }else{
                    fprintf(fichF,"%d-%d-%s-%d-%d",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }
            }
            futbolistas = futbolistas->siguiente;
        }else{
            if(futbolistas->id_futbolista <10){
                if(futbolistas->id_equipo <10){
                    fprintf(fichF,"0%d-0%d-%s-%d-%d\n",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }else{
                    fprintf(fichF,"0%d-%d-%s-%d-%d\n",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }
            }else{
                if(futbolistas->id_equipo <10){
                    fprintf(fichF,"%d-0%d-%s-%d-%d\n",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }else{
                    fprintf(fichF,"%d-%d-%s-%d-%d\n",futbolistas->id_futbolista,futbolistas->id_equipo,futbolistas->nombre,futbolistas->precio,futbolistas->valoracion);
                }
            }
            futbolistas = futbolistas->siguiente;
        }
    }
    fclose(fichF);
}

int TotalJugadores(ListaF *lista, int id_equipo){
    int aux=0;

    pfutbolista auxiliar;
    auxiliar = (pfutbolista)malloc(sizeof(T_futbolista));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }

    auxiliar = *lista;
    if(auxiliar){ // Para calcular el siguiente identificador
        if(auxiliar->id_equipo == id_equipo){ aux++; }
        while(auxiliar->siguiente){
                auxiliar = auxiliar->siguiente;
                if(auxiliar->id_equipo == id_equipo){ aux++; }
        }
    }
    return aux;
}
