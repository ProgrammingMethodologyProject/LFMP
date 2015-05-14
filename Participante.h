#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

typedef struct {
    int identificador;
    char nombre_plantilla[30];
    char perfil_usuario[20];
    char usuario[5];
    char contraseña[8];
}T_Participante;

MENU PARTICIPANTE
1.- Crear Plantilla
2.- Configurar Plantilla
3.- Listar Plantillas
4.- Eliminar Plantilla
5.- Ranking
6.- Salir del programa

void crear_plamtilla();
void configurar_plantilla();
void listar_plantilla();
void eliminar_plantilla();
void ranking();
void salir();

#endif
