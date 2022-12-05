#ifndef LISTAJUEGO_H_INCLUDED
#define LISTAJUEGO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"

typedef struct NodoNivel
{
    Mapa nivel;
    struct NodoNivel * siguiente;

}NodoNivel;

NodoNivel* inicNodo();
NodoNivel* crearNodoMapa(Mapa mapita);

#endif // LISTAJUEGO_H_INCLUDED
