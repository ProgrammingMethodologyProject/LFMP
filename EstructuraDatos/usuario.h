#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int identificador;
    char nombre[20];
    char *perfil;
    char usuario[5];
    char password[8];
}T_Usuario;

#endif
