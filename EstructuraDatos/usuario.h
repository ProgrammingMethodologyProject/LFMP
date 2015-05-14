#ifndef _USUARIO_H_
#define _USUARIO_H_

//Estructuras para almacenar los datos de los Usuarios
typedef struct {
    int id;
    char nombre_plantilla[30];
    char perfil_user[20];
    char user[5];
    char pass[8];
    struct T_usuario *siguiente;
}T_usuario;

typedef T_usuario *ListaUser;

//Declaraciones de funciones
void Leer_user(ListaUser*);

#endif //_USUARIO_H_
