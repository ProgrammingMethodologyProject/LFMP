//Navegador para los menús
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(cont){
    int N=0, M, seguir;
    char dir[1]; //Vector donde guardaremos los dos caracteres de cada tecla de direccion
    M = navegador(N,cont);
    while(seguir){
        dir[0]=getch();
        if(dir[0]=='\r'){ //Al pulsar intro nos devuelve '\r'
            return N+1;
        }else{
            dir[1]=getch();
        }
        if(dir[1]=='H'){ //Al pulsar la tecla de la direccion hacia abajo nos devuelve 'H' como segundo caracter
            system("cls");
            N--;
            if(N<0){ N=M; }
            navegador(N,cont);
        }else if(dir[1]=='P'){ //Al pulsar la tecla de la direccion hacia arriba nos devuelve 'P' como segundo caracter
            system("cls");
            N++;
            if(N>M){ N=0; }
            navegador(N,cont);
        }
    }
}

int navegador(int n, int cont){
    if(cont==0){
        char a=' ',b=' ',c=' ';
        if(n==0){a='*';}
        if(n==1){b='*';}
        if(n==2){c='*';}
        printf("\n\t+------------> MENU PRINCIPAL <-----------+\n");
        printf("\t|\t%c 1 REGISTRO\t\t\t|\n",a);
        printf("\t|\t%c 2 ACCESO AL SISTEMA\t\t|\n",b);
        printf("\t|\t%c 3 SALIR\t\t\t|\n",c);
        printf("\t+---------------------------------------+\n");
        return 2;
    }else if(cont==1){
        char a=' ',b=' ',c=' ',d=' ';
        if(n==0){a='*';}
        if(n==1){b='*';}
        if(n==2){c='*';}
        if(n==3){d='*';}
        printf("\n\t+---------> MENU ADMINSTRADOR <---------+\n");
        printf("\t|\t%c 1 EQUIPOS\t\t\t|\n",a);
        printf("\t|\t%c 2 USUARIOS\t\t\t|\n",b);
        printf("\t|\t%c 3 CONFIGURACION\t\t|\n",c);
        printf("\t|\t%c 4 SALIR\t\t\t|\n",d);
        printf("\t+---------------------------------------+\n");
        return 3;
    }else if(cont==2){
        char a=' ',b=' ',c=' ';
        if(n==0){a='*';}
        if(n==1){b='*';}
        if(n==2){c='*';}
        printf("\n\t+-----------> MENU CRONISTA <-----------+\n");
        printf("\t|\t%c 1 LISTAR EQUIPOS\t\t|\n",a);
        printf("\t|\t%c 2 VALORAR EQUIPOS\t\t|\n",b);
        printf("\t|\t%c 3 SALIR\t\t\t|\n",c);
        printf("\t+---------------------------------------+\n");
        return 2;
    }else if(cont==3){
        char a=' ',b=' ',c=' ',d=' ',e=' ',f=' ';
        if(n==0){a='*';}
        if(n==1){b='*';}
        if(n==2){c='*';}
        if(n==3){d='*';}
        if(n==4){e='*';}
        if(n==5){f='*';}
        printf("\n\t+---------> MENU PARTICIPANTE <---------+\n");
        printf("\t|\t%c 1 CREAR PLANTILLA\t\t|\n",a);
        printf("\t|\t%c 2 CONFIGURAR PLANTILLA\t|\n",b);
        printf("\t|\t%c 3 LISTAR PLANTILLA\t\t|\n",c);
        printf("\t|\t%c 4 ELIMINAR PLANTILLA\t\t|\n",d);
        printf("\t|\t%c 5 RANKING\t\t\t|\n",e);
        printf("\t|\t%c 6 SALIR\t\t\t|\n",f);
        printf("\t+---------------------------------------+\n");
        return 5;
    }
}
