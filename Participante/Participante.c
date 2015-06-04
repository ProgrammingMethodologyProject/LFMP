#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>>
#include "configuracion.h"
#include "jugadores_plantillas.h"
#include "plantilla.h"
#include "usuarios.h"


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

//año pasado
void Jugadores_Disp(T_plantilla *plantilla)
{
    stock = (T_plantilla *) calloc(0, sizeof(T_plantilla));
	FILE *fichP;
	int idx = 0;
    char cadena[15];
	if((file = fopen("plantilla.txt" , "r")) == NULL){
		printf("ERROR: No existe el archivo 'plantilla.txt'\n");
	}else{
        char ident[3] , c_art[6], c_alm[3], cant[7];
        while(fgets(str, 20, file) != NULL){
            T_Stock a;
            if(sscanf(str, "%[^-]-%s", c_art, cadena ) == 2)
            {
                if(sscanf(cadena, "%[^-]-%s", c_alm, cant ) == 2)
                {
                    a.c_articulo = atoi(c_art);
                    a.c_almacen = atoi(c_alm);
                    a.cantidad = atoi(cant);
                }
            }
            else
                printf("Error de lectura\n");
            stock = (T_Stock *) realloc(stock, (idx+1)*sizeof(T_Almacen));
            stock[idx] = a;
            idx++;
        }
        fclose(file);
        tam = idx;
    }

}

//añadir jugador a plantilla
void Añadir_Jugador(T_plantilla *plantilla, T_Futbolista *fut)
{
    int cod;
    char des[20];
    do{
        printf("\nIntroduzca el codigo del jugador:  \n");
        scanf("%d", &cod);
        fflush(stdin);
    }while(Jugadores_Disp(cod) || cod < 0 || cod > 99999);
    fut = (T_Futbolista *) realloc(fut, (tam+1)*sizeof(T_Futbolista));
    fut[tam].identificador = cod;
    tam++;

}

//eliminar
void Eliminar_Jugador(T_Futbolista *fut)
{
    int cod, i, aux;

    printf("\nIntroduzca el identificador del jugador:  \n");
    scanf("%d", &cod);
    fflush(stdin);

    for(i=0 ; i<tam ; i++){
        if(fut[i].identificador == cod) {
            aux = 1;
            i++;
        }
        if(aux == 1)
            fut[i-1] = fut[i];
        else
            fut[i] = fut[i];
    }
    if(aux == 1)
    {
        fut = (T_Futbolista *) realloc(fut, (--tam)*sizeof(T_Futbolista));
        borrar_stock(cod,0);
    }

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
    int i,j, caux;
    char daux[10];
    for(i=1 ; i<=tam ; i++){
        for(j=0 ; j<=tam-2 ; j++){  //tam = tamaño maximo de la plantilla
            if(plantilla[j].codigo > plantilla[j+1].codigo){
                caux = plantilla[j].codigo;
                strcpy(daux, plantilla[j].descripcion);

                plantilla[j].codigo = plantilla[j+1].codigo;
                strcpy(plantilla[j].descripcion, plantilla[j+1].descripcion);

                plantilla[j+1].codigo = caux;
                strcpy(plantilla[j+1].descripcion, daux);
            }
        }
    }

}
