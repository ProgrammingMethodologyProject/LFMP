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
    //nuevo->siguiente = NULL;
    // Si la lista de usuarios esta vacia
    if(ListaVacia(*lista)){
        // Anadimos la lista a continuación del nuevo usuario
        nuevo->siguiente = *lista;
        // Ahora el comienzo de la lista es nuevo usuario
        *lista = nuevo;
        //printf(":%d:%s:%s:%s:%s:\n",lista->id,lista->nombre,lista->perfil,lista->user,lista->pass);
    }else{
        ultimo = *lista;
        // Avanzamos hasta el último elemento
        while(ultimo->siguiente){
            ultimo = ultimo->siguiente;
        }
        //Insertamos nuevo usuario después del ultimo
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
    }
    //printf(":%d:%s:%s:%s:%s:\n",nuevo->id,nuevo->nombre,nuevo->perfil,nuevo->user,nuevo->pass);
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
    int cont,m=0,c;
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
    if((c=Comprobar_user(lista,&user,&pass))){
        printf("Your login was successful\n");
        menu(c);
    }else{
        printf("Usuario o password incorrecto.\n");
    }
 getch();
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
        if(strcmp(indice->user,user)){
            if(strcmp(indice->pass,pass)){
                if( strcmp(indice->perfil,admin)){ check = 1;
                }else if(strcmp(indice->perfil,croni)){ check = 2;
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
