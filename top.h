#ifndef TOP_H_INCLUDED
#define TOP_H_INCLUDED
#include "arbol.h"
typedef struct
{
    registro_partida dato;
    struct nodoTOP* siguiente;
}nodoTOP;

nodoTOP* inic_lista();
nodoTOP* crear_nodo_top(registro_partida nuevo);
nodoTOP* agrega_principio_top(nodoTOP* lista, nodoTOP* nuevo);
nodoTOP* agegar_orden_top(nodoTOP* lista, nodoTOP* nuevo);
nodoTOP* archivoPartidas_toLista(nodoTOP* lista);
int lista_toArreglo(nodoTOP* lista, registro_partida arreglo [10]);
void mostrar_top10();
void mostrar_una_partida(registro_partida aux, int pos, int x, int );
void mostrar_listaTOP(nodoTOP* lista);


#endif // TOP_H_INCLUDED


