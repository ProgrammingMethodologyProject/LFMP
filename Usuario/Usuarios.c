#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"

//Funcion que recoge todos los datos de los usuarios guardados en el fichero Usuarios.txt
void Leer_user(T_usuario *head){
    int id;
    char nombre[20]="";
    char perfil[13]="";
    char user[5];
    char pass[8];
    FILE *fichU;
    char c;
    fichU=fopen("Usuarios.txt","r"); //Lee el fichero
    if(!(fichU)){ //Si no existe le fichero, lo crea
        printf("Creando archivo Usuarios.txt\n");
        printf("...\n");
        fichU=fopen("Usuarios.txt","w");
        if(fichU){
            printf("Usuarios.txt creado satisfactoriamente\n");
            system("pause");
            system("cls");
        }else{
            printf("Hubo un error, we need to fix it, shut down this programme please\n");
        }
    }else{
        while(fscanf(fichU,"%d-",&id)!=EOF){ //Obtenemos del fichero los datos de los usuarios guardados
            int n=0, p=0;
            while((c=fgetc(fichU))!='-'){
                nombre[n] = c;
                n++;
            }
            while((c=fgetc(fichU))!='-'){
                perfil[p] = c;
                p++;
            }
            fgets(user,6,fichU);
            getc(fichU);
            fgets(pass,9,fichU);
            Nuevo_user(head,id,nombre,perfil,user,pass);
            head
        }
    }
    fclose(fichU);
}

//Funcion para añadir nuevo usuario
void Nuevo_user(T_usuario *head,int id, char nombre, char perfil, char user, char pass){
    //Creamos un nuevo usuario
    nodo nuevo;
    nuevo = (nodo)malloc(sizeof(T_usuario));
    nuevo->id = id;
    strcpy(nuevo->nombre,nombre);
    strcpy(nuevo->perfil,perfil);
    strcpy(nuevo->user,user);
    strcpy(nuevo->pass,pass);
}

void Login_user(T_usuario *lista){
    char user[5],pass[8],p=0,letra;
    int cont,m=0;
    printf("\t+----------------------------------------\n");
    printf("\t|\t* Usuario: ");
    gets(user);
    printf("\t|\t* Pass: ");
    for(cont=0;cont<10;cont++){
        fflush(stdin);
        letra=getch();
        if(letra=='\r'){ // Si presionamos la tecla enter
            cont=100;
            continue;
        }else if(letra=='\b'){ // Si presionamos la tecla return
            cont=cont-2;
            printf("\b \b");
            continue;
        }else{
            pass[p]=letra;
            p++;
        }
        putchar('*');
    }
    printf("\n\t+----------------------------------------\nChecking...\n");
    //Comprobar_user(lista,user,pass);
    printf("Your login was successful\n"); system("pause");
}
