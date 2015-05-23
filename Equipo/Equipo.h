#ifndef _EQUIPOS_H_
#define _EQUIPOS_H_


//Estructuras para almacenar los datos de los Usuarios
typedef struct {
    int id;
    char *nombre;
    struct T_equipo *siguiente;
}T_equipo;

typedef T_equipo *pEquipos;
typedef T_equipo *ListaE;

//Declaraciones de funciones
void Leer_equipo(ListaE*);
void Nuevo_equipo(ListaE*,int,char*);
int ListaEVacia(ListaE);
void Listar_equipo(ListaE);

#endif //_EQUIPOS_H_
