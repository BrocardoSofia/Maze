#include "Mapa.h"

/**
Imprime en pantalla las coordenadas del mapa
**/
void mostrarMapa(Coordenada muro[], int validosMuro, int colorMapa)
{
    color(colorMapa);

    for(int i=0; i<validosMuro; i++)
    {
        gotoxy(muro[i].x, muro[i].y);
        printf("%c", 219);
    }
}

