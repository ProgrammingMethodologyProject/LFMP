#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int identificador;
    char nombre_plantilla[30];
    char perfil_usuario[20];
    char usuario[5];
    char contraseña[8];
}T_usuario;

#endif
