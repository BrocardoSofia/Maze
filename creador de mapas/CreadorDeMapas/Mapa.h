#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gotoxy.h"

#define MAX 3300

typedef struct Coordenada
{
    int x;
    int y;
}Coordenada;

typedef struct Mapa
{
    int tiempo; //tiempo de cada nivel
    Coordenada muro [MAX];//contiene las coordenadas de cada muro
    int validosMuro;
    Coordenada inicio;
    Coordenada fin;
    char cancion[30];
    int colorMapa;
}Mapa;

void mostrarMapa(Coordenada muro[], int validosMuro, int color);

#endif // MAPA_H_INCLUDED
