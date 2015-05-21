#ifndef _USUARIO_H_
#define _USUARIO_H_


//Estructuras para almacenar los datos de los Usuarios
typedef struct {
    int id;
    char *nombre;
    char *perfil;
    char user[6];
    char pass[9];
    struct T_usuario *siguiente;
}T_usuario;

typedef T_usuario *pUsuarios;
typedef T_usuario *Lista;

//Declaraciones de funciones
void Leer_user(Lista*);
int ListaVacia(Lista);
void Nuevo_user(Lista*,int,char*,char*,char*,char*);
void Alta_user(Lista*);
int Login_user(Lista*);
int Comprobar_user(Lista*,char*,char*);
void mostrar_user(Lista*);

#endif //_USUARIO_H_

