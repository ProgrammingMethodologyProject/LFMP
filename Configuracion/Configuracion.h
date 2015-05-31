#ifndef _CONFIGURACION_H_
#define _CONFIGURACION_H_

//Estructuras para almacenar los datos de los Usuarios
typedef struct {
    int id;
    int presupuesto;
    int max_players;
    struct T_config *siguiente;
}T_config;

typedef T_config *pConfig;
typedef T_config *ListaC;

//Declaraciones de funciones
void Leer_config(ListaC*);
void Nueva_config(ListaC*,int,int,int);
int ListaCVacia(ListaC);
void Listar_config(ListaC*);
void Localizar_config(ListaC*,int);
int Configuracion(ListaC*,int);
#endif //_CONFIGURACION_H_
