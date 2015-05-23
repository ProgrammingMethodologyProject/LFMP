#ifndef _USUARIOS_H_
#define _USUARIOS_H_


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
typedef T_usuario *ListaU;

//Declaraciones de funciones
void Leer_user(ListaU*);
int ListaUVacia(ListaU);
void Nuevo_user(ListaU*,int,char*,char*,char*,char*);
void Alta_user(ListaU*);
int Login_user(ListaU*);
int Comprobar_user(ListaU*,char*,char*);
void Listar_user(ListaU);
void Localizar_user(ListaU*);
void Eliminar_user(ListaU*);

#endif //_USUARIOS_H_

