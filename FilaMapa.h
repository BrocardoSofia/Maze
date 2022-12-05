#ifndef FILAJUEGO_H_INCLUDED
#define FILAJUEGO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"
#include "ListaJuego.h"

typedef struct FilaNivel
{
    struct NodoNivel * primero;
    struct NodoNivel * ultimo;
}FilaNivel;

void inicFila(FilaNivel * filita);
void agregarFinalFila(FilaNivel* filita, NodoNivel* mapita);
Mapa extraerFila(FilaNivel* filita);

#endif // FILAJUEGO_H_INCLUDED
