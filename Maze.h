#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gotoxy.h"
#include "ListaJuego.h"
#include "FilaMapa.h"

#define MAX 2000
#define FILAS 28


int juego(int *puntajeTotal);
int juegaNivel(Mapa mapita, int nivel, int matriz[40][110], int puntajeTotal);
void imprimirJugador(int x, int y, int anteX, int anteY);
void imprimirLimites(int colorMapa);
void imprimirTituloNivel(int nivel, int colorMapa, int puntaje);
void mapaNivel1();
void imprimirRectangulo();
void cronometro(int* tiempoTotal, int* tiempoAux, int colorMapa);
void define_console_size();
void archivoAfila(FilaNivel* filita, char archi[]);
void pasarValidosMatriz(int matriz[30][110], Coordenada mapa[], int validosMapa);
int verificaMovimiento(int matriz[40][110], int x, int y);
void imprimirSalida(Coordenada salida);
void reiniciarMatriz(int matriz[40][110]);
void rectanguloGrande();
void cuentaRegresiva();
void GAMEOVER(int puntaje);

#endif // MAZE_H_INCLUDED
