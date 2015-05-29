#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Usuarios.h"

//Funcion que recoge todos los datos de los usuarios guardados en el fichero Usuarios.txt
void Leer_user(ListaU *lista){
    int id;
    char *nombre, *perfil, user[6], pass[9], *admin = "administrador", *croni = "cronista", *parti = "participante";
    nombre = (char*)calloc(20,sizeof(char));
    
    FILE *fichU; fichU=fopen("Usuarios.txt","r"); //Lee el fichero
    if(!(fichU)){ //Si no existe le fichero, lo crea
        fichU=fopen("Usuarios.txt","w");
    }else{
        // Obtenemos del fichero los datos de los usuarios guardados
        while((fscanf(fichU,"%d-",&id))!=EOF){ // identificador
            int n=0;
            char c;
            while((c=fgetc(fichU))!='-'){
                nombre[n] = c;
                n++;
            }
            nombre[n]='\0';
            c=fgetc(fichU);
            if(c=='a'){
                perfil = admin;
                while((c=fgetc(fichU))!='-'){}
            }
            if(c=='c'){
                perfil = croni;
                while((c=fgetc(fichU))!='-'){}
            }
            if(c=='p'){
                perfil = parti;
                while((c=fgetc(fichU))!='-'){}
            }
            fgets(user,6,fichU); // Usuario
            fgetc(fichU); // Saltamos el caracter '-'
            fgets(pass,9,fichU); // password
            
            Nuevo_user(lista,id,nombre,perfil,user,pass);
        }
        fclose(fichU);
    }
}

//Funcion para introducir nuevo usuario
void Nuevo_user(ListaU *lista,int id, char *nombre, char *perfil, char *user, char *pass){
    //Creamos un nuevo usuario
    pUsuarios nuevo, ultimo;
    nuevo = (pUsuarios)malloc(sizeof(T_usuario));
    if(nuevo == NULL){
        fprintf(stderr,"Error de asignacion de memoria");
        exit(1);
    }
    
    nuevo->id = id;
    strcpy(nuevo->nombre,nombre);
    nuevo->perfil = perfil;
    strcpy(nuevo->user,user);
    strcpy(nuevo->pass,pass);
    // Si la lista de usuarios esta vacia
    if(ListaUVacia(*lista)){
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

//Funcion para dar de alta un nuevo usuario
void Alta_user(ListaU *lista){
    int nuevo_id, aux=1;
    char nuevo_nombre[20];
    char *nuevo_perfil = "participante";
    char nuevo_user[6];
    char nuevo_pass[9];
    
    pUsuarios auxiliar;
    auxiliar = (pUsuarios)malloc(sizeof(T_usuario));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }
    
    auxiliar = *lista;
    if(auxiliar != NULL){ // Recorremos los usuarios existentes hasta el ultimo y devuelva el proximo id
        aux++;
        while(auxiliar->siguiente != NULL){ auxiliar = auxiliar->siguiente; aux++; }
    }
    
    printf("-Alta usuario:\n");
    printf("-Identificador: %d\n",aux);
    nuevo_id = aux;
    puts("-Nombre(max 20): ");
    fflush(stdin); //Elimina basura
    gets(nuevo_nombre);
    if(strlen(nuevo_nombre)>20){
        printf("\tNombre introducido demasiado largo.\n");
        exit(0);
    }
    puts("-Usuario(5 caracteres): ");
    fflush(stdin);
    gets(nuevo_user);
    puts("-Password(8 caracteres): ");
    fflush(stdin);
    gets(nuevo_pass);
    Nuevo_user(lista,nuevo_id,nuevo_nombre,nuevo_perfil,nuevo_user,nuevo_pass);
    printf("\nAlta finalizada.\n");
}

//Funcion para acceder con un usuario
void Login_user(ListaU *lista){
    char user[6],pass[9],p=0,letra;
    int cont=1,c;
    
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
    pass[p]='\0';
    printf("\n\t+----------------------------------------\nChecking...\n");
    if((c=Comprobar_user(lista,&user,&pass))){
        printf("Your login was successful\n");
        getch(); system("cls");
        return c;
    }else{
        printf("Usuario o password incorrecto.\n");
        return 0;
    }
}

//Funcion que comprueba si la lista esta vacia
int ListaUVacia(ListaU lista){ return (lista == NULL); }

//Funcion para comprobar si el usuario existe
int Comprobar_user(ListaU *lista,char *user, char *pass){
    int check=0;
    char *admin = "administrador", *croni = "cronista";
    
    pUsuarios indice;
    indice = (pUsuarios)malloc(sizeof(T_usuario));
    if(indice  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }
    
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
        }else{ indice = indice->siguiente; }
    }
}

//Funcion para listar los usuarios existentes
void Listar_user(ListaU *lista){
    pUsuarios auxiliar;
    auxiliar = *lista;
    // Si la lista de usuarios esta vacia
    if(ListaUVacia(lista)){
        printf("-Lista de usuarios vacia\n");
    }else{
        printf("-Lista de usuarios:\n");
        // Avanzamos hasta el último elemento
        while(auxiliar){
            if(auxiliar->id <10){
                printf("0%d-%s-%s-%s-%s\n",auxiliar->id,auxiliar->nombre,auxiliar->perfil,auxiliar->user,auxiliar->pass);
            }else{
                printf("%d-%s-%s-%s-%s\n",auxiliar->id,auxiliar->nombre,auxiliar->perfil,auxiliar->user,auxiliar->pass);
            }
            auxiliar = auxiliar->siguiente;
        }
    }
}

//Funcion para localizar un usuario existentes
void Localizar_user(ListaU *lista){
    int id,op;
    char *admin = "administrador", *croni = "cronista", *parti = "participante";
    pUsuarios auxiliar;
    auxiliar = (pUsuarios)malloc(sizeof(T_usuario));
    if(auxiliar  == NULL){ fprintf(stderr,"Error de asignacion de memoria"); exit(1); }
    
    auxiliar = *lista;
    // Si la lista de usuarios esta vacia
    if(ListaUVacia(auxiliar)){
        printf("-Lista de usuarios vacia\n");
    }else{
        printf("-Numero identificador del usuario que quieres modificar: ");
        fflush(stdin); // Elimina basura
        scanf("%d",&id);
        // Avanzamos hasta el último elemento
        while(auxiliar && auxiliar->id != id){ auxiliar = auxiliar->siguiente; }
        if(auxiliar){
            printf("%d-%s-%s-%s-%s\n",auxiliar->id,auxiliar->nombre,auxiliar->perfil,auxiliar->user,auxiliar->pass);
            fflush(stdin);
            printf("-Modificar nombre?(1 si/2 no): ");
            scanf("%d",&op);
            if(op == 1){
                fflush(stdin);
                printf("-Nombre(max 20): ");
                gets(auxiliar->nombre);
            }
            printf("-Modificar perfil?(1 si/2 no): ");
            scanf("%d",&op);
            if(op == 1){
                printf("-Perfil (1 administrador/2 cronista/3 participante): ");
                fflush(stdin);
                scanf("%d",&op);
                if(op == 1){ auxiliar->perfil = admin; }
                if(op == 2){ auxiliar->perfil = croni; }
                if(op == 3){ auxiliar->perfil = parti; }
            }
            printf("-Modificar usuario?(1 si/2 no): ");
            scanf("%d",&op);
            if(op == 1){
                printf("-Usuario(5 caracteres): ");
                fflush(stdin);
                gets(auxiliar->user);
            }
            printf("-Modificar password?(1 si/2 no): ");
            scanf("%d",&op);
            if(op == 1){
                printf("-Password(8 caracteres): ");
                fflush(stdin);
                gets(auxiliar->pass);
            }
            printf("-Usuario modificado:\n");
            printf("%d-%s-%s-%s-%s\n",auxiliar->id,auxiliar->nombre,auxiliar->perfil,auxiliar->user,auxiliar->pass);
        }
    }
}

void Eliminar_user(ListaU *lista){
    int id;
    
    pUsuarios anterior, auxiliar;
    auxiliar = *lista;
    anterior = NULL;
    
    printf("-Eliminar usuario:\n-Introduce identificador del usuario: ");
    scanf("%d",&id);
    while(auxiliar && auxiliar->id < id){
        anterior = auxiliar;
        auxiliar = auxiliar->siguiente;
    }
    if(!auxiliar || auxiliar->id != id){
        printf("-Usuario no existe\n");
    }else{
        // Eliminamos el usuario
        if(!anterior){
            // 1er elemento
            *lista = auxiliar->siguiente;
            anterior = *lista; // Para colocar los ID
        }else{
            anterior->siguiente = auxiliar->siguiente;
            anterior = anterior->siguiente; // Para colocar los ID
        }
        while(anterior){ //Reorganiza los Id correctamente
            anterior->id = id;
            anterior = anterior->siguiente;
            id++;
        }
        free(auxiliar);
        printf("-Usuario eliminado.");
    }
}

//Funcion que actualiza el fichero Equipos.txt
void Update_user(ListaU *lista){
    pUsuarios usuarios = *lista;
    FILE *fichU;

    fichU=fopen("Usuarios.txt","w");
    while(usuarios){
        if(!(usuarios->siguiente)){
            if(usuarios->id <10){
                    fprintf(fichU,"0%d-%s-%s-%s-%s",usuarios->id,usuarios->nombre,usuarios->perfil,usuarios->user,usuarios->pass);
                }else{
                    fprintf(fichU,"%d-%s-%s-%s-%s",usuarios->id,usuarios->nombre,usuarios->perfil,usuarios->user,usuarios->pass);
                }
            usuarios = usuarios->siguiente;
        }else{
            if(usuarios->id <10){
                    fprintf(fichU,"0%d-%s-%s-%s-%s\n",usuarios->id,usuarios->nombre,usuarios->perfil,usuarios->user,usuarios->pass);
                }else{
                    fprintf(fichU,"%d-%s-%s-%s-%s\n",usuarios->id,usuarios->nombre,usuarios->perfil,usuarios->user,usuarios->pass);
                }
            usuarios = usuarios->siguiente;
        }
    }
}
