#ifndef FUTBOLISTA_H
#define FUTBOLISTA_H

typedef struct {
    int id_futbolista;
    int id_equipo;
    int precio_jugador;
    int valoracion;
    char nombre_jugador[20];
}T_Futbolista;


void listar_equipos();
void valorar_equipos();
void salir();

#endif
