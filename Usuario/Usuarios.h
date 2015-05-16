#ifndef _USUARIO_H_
#define _USUARIO_H_


//Estructuras para almacenar los datos de los Usuarios
typedef struct {
    int id;
    char nombre[20];
    char perfil[13];
    char user[5];
    char pass[8];
    struct T_usuario *siguiente;
}T_usuario;

typedef T_usuario *head;
typedef T_usuario *nodo;

//Declaraciones de funciones
void Leer_user(T_usuario*);
void Nuevo_user(T_usuario*,int,char,char,char,char);

#endif //_USUARIO_H_
