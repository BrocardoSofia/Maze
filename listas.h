#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "arbol.h"

Partida cargarUnaPartida(char nombre[], int puntaje);
NodoPuntaje* inicLista();
NodoPuntaje* crearNodoPuntaje(char nombre[], int puntaje);
NodoPuntaje* agregarAlFinal(NodoPuntaje* lista, NodoPuntaje* nuevo);
NodoPuntaje* buscarUltimoNodo(NodoPuntaje* lista);
void mostrarUnPuntaje(NodoPuntaje* lista);
void mostrarPuntajeIterativo(NodoPuntaje* lista);

#endif // LISTAS_H_INCLUDED
