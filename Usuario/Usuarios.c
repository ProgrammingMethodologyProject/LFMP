#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"

//Funcion que recoge todos los datos de los usuarios guardados en el fichero Usuarios.txt
void Leer_user(Lista *lista){
    int id,nElemN=2,nElemP=2;
    char *nombre, *perfil, user[6], pass[9];
    nombre = (char*)calloc(nElemN,sizeof(char));
    perfil = (char*)calloc(nElemP,sizeof(char));

    FILE *fichU; fichU=fopen("Usuarios.txt","r"); //Lee el fichero
    if(!(fichU)){ //Si no existe le fichero, lo crea
        fichU=fopen("Usuarios.txt","w");
    }else{
        // Obtenemos del fichero los datos de los usuarios guardados
        while((fscanf(fichU,"%d-",&id))!=EOF){ // identificador
            int u=0,n=0,p=0;
            char c;
            while((c=fgetc(fichU))!='-'){
                nombre[n] = c;
                //nombre = (char*)realloc((nElemN+1),sizeof(char));
                //nElemN++;
                n++;
            }
            nombre[n]='\0';
            while((c=fgetc(fichU))!='-'){
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

//Funcion para introducir nuevo usuario (SIN TERMINAR)
void Nuevo_user(Lista *lista,int id, char *nombre, char *perfil, char *user, char *pass){
    //Creamos un nuevo usuario
    pUsuarios nuevo, ultimo;
    nuevo = (pUsuarios)malloc(sizeof(T_usuario));
    if(nuevo == NULL){
        fprintf(stderr,"Error de asignacion de memoria");
        exit(1);
    }
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->perfil = perfil;
    strcpy(nuevo->user,user);
    strcpy(nuevo->pass,pass);
    // Si la lista de usuarios esta vacia
    if(ListaVacia(*lista)){
        // Anadimos la lista a continuación del nuevo usuario
        nuevo->siguiente = *lista;
        // Ahora el comienzo de la lista es nuevo usuario
        *lista = nuevo;
    }else{
        ultimo = *lista;
        // Avanzamos hasta el último elemento
        while(ultimo->siguiente != NULL){
            ultimo = ultimo->siguiente;
        }
        //Insertamos nuevo usuario después del ultimo
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
    }
}

//Funcion para dar de alta un nuevo usuario (SIN TERMINAR)
void Alta_user(Lista *lista){
    int nuevo_id, aux=1;
    char nuevo_nombre[20];
    char nuevo_perfil[13] = "participante";
    char nuevo_user[5];
    char nuevo_pass[8];
    
    pUsuarios auxiliar;
    auxiliar = *lista;
    if(auxiliar != NULL){ // Recorremos los usuarios existentes hasta el ultimo y devuelva el proximo id
        aux++;
        while(auxiliar->siguiente != NULL){ auxiliar = auxiliar->siguiente; aux++; }
    }
    
    printf("Alta usuario:\n");
    puts("Identificador: %d\n",aux);
    nuevo_id = aux;
    puts("Nombre(max 20): ");
    fflush(stdin); //Elimina basura
    gets(nuevo_nombre);
    if(strlen(nuevo_nombre)>20){
        printf("\tNombre introducido demasiado largo.\n");
        exit(0);
    }
    puts("Usuario(5 caracteres): ");
    fflush(stdin);
    gets(nuevo_user);
    puts("Password(8 caracteres): ");
    fflush(stdin);
    gets(nuevo_pass);
    Nuevo_user(lista,nuevo_id,nuevo_nombre,nuevo_perfil,nuevo_user,nuevo_pass);
    printf("\nAlta finalizada.\n");
    getch();
}

//Funcion para acceder con un usuario (SIN TERMINAR)
void Login_user(Lista *lista){
    char user[5],pass[8],p=0,letra;
    int cont=1,m=0,c;
    printf("\t+----------------------------------------\n");
    printf("\t|\t* Usuario: ");
    gets(user);
    printf("\t|\t* Pass: ");
    while(cont){
        fflush(stdin);
        letra=getch();
        if(letra=='\r'){ // Si presionamos la tecla enter
            cont=0;
            continue;
        }else if(letra=='\b'){ // Si presionamos la tecla return
            if(p>0){
                p--;
                printf("\b \b");
            }
            continue;
        }else{
            pass[p]=letra;
            p++;
        }
        putchar('*');
    }
    printf("\n\t+----------------------------------------\nChecking...\n");
    if((c=Comprobar_user(lista,&user,&pass))){
        printf("Your login was successful\n");
        getch();
        system("cls");
        return c;
    }else{
        printf("Usuario o password incorrecto.\n");
        getch();
    }
}

//Funcion que comprueba si la lista esta vacia
int ListaVacia(Lista lista){ return (lista == NULL); }

//Funcion para comprobar si el usuario existe (SIN TERMINAR)
int Comprobar_user(Lista *lista,char *user, char *pass){
    int check=0;
    char *admin = "administrador", *croni = "cronista", *parti = "participante";
    pUsuarios indice;
    indice = *lista;
    while(indice){
        if((strcmp(indice->user,user))==0){
            if((strcmp(indice->pass,pass))==0){
                if((strcmp(indice->perfil,admin))==0){ check = 1;
                }else if((strcmp(indice->perfil,croni)){ check = 2;
                }else{ check = 3; }
            }
        }
        if(indice->siguiente == NULL){
            if(check){
                return check;
            }else{
                return 0;
            }
        }else{
            indice = indice->siguiente;
        }
    }
}
