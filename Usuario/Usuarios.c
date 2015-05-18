#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"

//Funcion que recoge todos los datos de los usuarios guardados en el fichero Usuarios.txt
void Leer_user(Lista *lista){
    int id;
    char nombre[11], perfil[14], user[6], pass[9];
    FILE *fichU;
    fichU=fopen("Usuarios.txt","r"); //Lee el fichero
    if(!(fichU)){ //Si no existe le fichero, lo crea
        fichU=fopen("Usuarios.txt","w");
    }else{
        // Obtenemos del fichero los datos de los usuarios guardados
        while((fscanf(fichU,"%d-",&id))!=EOF){ // identificador
            int u=0;
            char c[1];
            fgets(nombre,11,fichU); // nombre
            fgetc(fichU); // saltamos el caracter '-'
            fgets(perfil,14,fichU); // perfil
            hile((c[0]=fgetc(fichU))!='-'){
                user[u] = c[0];
                u++;
            }
            user[u]='\0';
            fgets(pass,9,fichU); // password
            Nuevo_user(head,id,nombre,perfil,user,pass);
        }
        fclose(fichU);
    }
}

//Funcion para añadir nuevo usuario (SIN TERMINAR)
void Nuevo_user(Lista *lista,int id, char *nombre, char *perfil, char *user, char *pass){
    //Creamos un nuevo usuario
    pusuarios nuevo;
    nuevo = (pusuarios)malloc(sizeof(T_usuario));
    if(nuevo == NULL){
        fprintf(stderr,"Error de asignacion de memoria");
        exit(1);
    }
    nuevo->id = id;
    strcpy(nuevo->nombre,nombre);
    strcpy(nuevo->perfil,perfil);
    strcpy(nuevo->user,user);
    strcpy(nuevo->pass,pass);
    // Si la lista de usuarios esta vacia
    if(lista_vacia==1){ // SIN TERMINAR
        nuevo->siguiente = *lista;
        *lista = nuevo;
    }else{}
}

// Funcion que nos devuelve 1 si la lista esta vacia o 0 si no
int lista_vacia(Lista *lista){ return (*lista == NULL ? 1:0); }

//Funcion para dar de alta un nuevo usuario (SIN TERMINAR)
void Alta_user(Lista *lista){
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
void Login_user(Lista *lista){
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
int Comprobar_user(Lista *lista, char *user, char *pass){

}
