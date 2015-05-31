#ifndef _EQUIPOS_H_
#define _EQUIPOS_H_


//Estructuras para almacenar los datos de los Equipos
typedef struct {
    int id;
    char nombre[20];
    struct T_equipo *siguiente;
}T_equipo;

typedef T_equipo *pEquipos;
typedef T_equipo *ListaE;

//Declaraciones de funciones
void Leer_equipo(ListaE*);
void Nuevo_equipo(ListaE*,int,char*);
int ListaEVacia(ListaE);
void Alta_equipo(ListaE*);
void Listar_equipo(ListaE*);
void Localizar_equipo(ListaE*);
void Eliminar_equipo(ListaE*);
void Update_equipos(ListaE*);
int TotalEquipos(ListaE*);

#endif //_EQUIPOS_H_
