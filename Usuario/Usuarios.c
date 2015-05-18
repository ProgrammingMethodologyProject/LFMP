#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"

//Funcion que recoge todos los datos de los usuarios guardados en el fichero Usuarios.txt
void Leer_user(T_usuario *head){
    int id;
    char nombre[20], perfil[13], user[5], pass[8];
    FILE *fichU;
    fichU=fopen("Usuarios.txt","r"); //Lee el fichero
    if(!(fichU)){ //Si no existe le fichero, lo crea
        printf("Creando archivo Usuarios.txt\n...\n");
        fichU=fopen("Usuarios.txt","w");
        if(fichU){
            printf("Usuarios.txt creado satisfactoriamente\n");
            system("pause");
            system("cls");
        }else{printf("Hubo un error, we need to fix it, shut down this programme please\n");}
    }else{
        while(!feof(fichU)){ //Obtenemos del fichero los datos de los usuarios guardados
            fscanf(fichU,"%d-",&id); // identificador
            //printf(":%d",id);
            fgets(nombre,11,fichU); // nombre
            //printf(":%s",nombre);
            fgetc(fichU); // saltamos el caracter '-'
            fgets(perfil,14,fichU); // perfil
            //printf(":%s",perfil);
            fgetc(fichU); // saltamos el caracter '-'
            fgets(user,6,fichU); // user
            //printf(":%s",user);
            fgetc(fichU); // saltamos el caracter '-'
            fgets(pass,9,fichU); // password
            //printf(":%s:\n",pass);
            //printf(":%d:%s:%s:%s:%s\n",id,nombre,perfil,user,pass);
            Nuevo_user(head,id,nombre,perfil,user,pass);
        }
    }
    fclose(fichU);
}

//Funcion para añadir nuevo usuario (SIN TERMINAR)
void Nuevo_user(T_usuario *lista,int id, char *nombre, char *perfil, char *user, char *pass){
    //Creamos un nuevo usuario
    pusuarios nuevo;
    nuevo = (pusuarios)malloc(sizeof(T_usuario));
    nuevo->id = id;
    strcpy(nuevo->nombre,nombre);
    strcpy(nuevo->perfil,perfil);
    strcpy(nuevo->user,user);
    strcpy(nuevo->pass,pass);
    if(lista==NULL){
//        nuevo->siguiente = *lista;
//        *lista = nuevo;
    }else{}
}

//Funcion para dar de alta un nuevo usuario (SIN TERMINAR)
void Alta_user(T_usuario *lista){
    int nuevo_id;
    char nuevo_nombre[20];
    char nuevo_perfil[13];
    char nuevo_user[5];
    char nuevo_pass[8];
    printf("Alta usuario:\n");
    puts("Identificador: ");
    fflush(stdin); //Elimina basura
    scanf("%d",&nuevo_id);
    if(nuevo_id>99){
        printf("\tIdentificador introducido demasiado grande.\n");
        exit(0);
    }
    puts("Nombre(max 20): ");
    fflush(stdin); //Elimina basura
    gets(nuevo_nombre);
    puts("Perfil(administrador,cronista,participante): ");
    fflush(stdin);
    gets(nuevo_perfil);
    puts("Usuario(5 caracteres): ");
    fflush(stdin);
    gets(nuevo_user);
    puts("Password(8 caracteres): ");
    fflush(stdin);
    gets(nuevo_pass);
    Nuevo_user(lista,nuevo_id,nuevo_nombre,nuevo_perfil,nuevo_user,nuevo_pass);
    printf("\nAlta finalizada.\n");
}

//Funcion para acceder con un usuario (SIN TERMINAR)
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

//Funcion para comprobar si el usuario existe (SIN TERMINAR)
int Comprobar_user(T_usuario *lista, char *user, char *pass){

}
