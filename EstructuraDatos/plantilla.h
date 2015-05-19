#ifndef PLANTILLA_H
#define PLANTILLA_H

typedef struct {
    int id;
    int ident[3];
    char nombre_plantilla[30];
    int valor_config; //presupuesto
    int puntuacion = 0;
}T_plantilla;

T_plantilla *plantilla;

#endif
