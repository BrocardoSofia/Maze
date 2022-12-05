#ifndef INGRESAR_USUARIO_H_INCLUDED
#define INGRESAR_USUARIO_H_INCLUDED
#include "arbol.h"

typedef struct
{
    char name[50];
    char password[50];
}Usuario;

///datos de ingreso, alias y password
Usuario ingresar_usuario(Usuario ingresando);

///validar si el usuario que quiere iniciar sesion existe en el arbol.
int validar_ingreso(nodoArbol* arbol, Usuario ingresando);

#endif // INGRESAR_USUARIO_H_INCLUDED


