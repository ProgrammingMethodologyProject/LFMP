#ifndef _FUTBOLISTAS_H_
#define _FUTBOLISTAS_H_


//Estructuras para almacenar los datos de los futbolistas
typedef struct {
    int id_futbolista;
    int id_equipo;
    char nombre[20];
    int precio;
    int valoracion;
    struct T_futbolista *siguiente;
}T_futbolista;

typedef T_futbolista *pfutbolista;
typedef T_futbolista *ListaF;

//Declaraciones de funciones
void Leer_futbolista(ListaF*);
void Nuevo_futbolista(ListaF*,int,int,char*,int,int);
int ListaFVacia(ListaF);
void Alta_futbolista(ListaF*,int);
void Listar_futbolista(ListaF*);
void Localizar_futbolista(ListaF*);
void Eliminar_futbolista(ListaF*);
void Update_futbolista(ListaF*);
int TotalJugadores(ListaF*,int);

#endif //_FUTBOLISTAS_H_
