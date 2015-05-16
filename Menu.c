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
    }
}
