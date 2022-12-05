#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listas.h"
#include "arbol.h"

Partida cargarUnaPartida(char nombre[], int puntaje)
{
    Partida aux;
    strcpy(aux.jugador,nombre); //este dato me viene del arbol
    aux.activo=1;
    aux.puntaje=puntaje;

    return aux;
}

NodoPuntaje* inicLista()
{
    return NULL;
}

NodoPuntaje* crearNodoPuntaje(char nombre[], int puntaje)
{
    NodoPuntaje* nuevo=(NodoPuntaje*)malloc(sizeof(NodoPuntaje));

    Partida aux=cargarUnaPartida(nombre,puntaje);
    nuevo->puntaje=aux;
    nuevo->idPartida=rand()%100;
    nuevo->siguiente=NULL;

    return nuevo;
}

NodoPuntaje* agregarAlFinal(NodoPuntaje* lista, NodoPuntaje* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        NodoPuntaje* ultimo=buscarUltimoNodo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}

NodoPuntaje* buscarUltimoNodo(NodoPuntaje* lista)
{
    NodoPuntaje* buscado=lista;

    if(lista!=NULL)
    {
        while(buscado->siguiente!=NULL)
        {
            buscado=buscado->siguiente;
        }
    }
    return buscado;
}

void mostrarUnPuntaje(NodoPuntaje* lista)
{
    Partida aux=lista->puntaje;
    printf("\t\t----------------------\n");
    printf("\t\tNombre jugador: %s\n",aux.jugador);
    printf("\t\tPuntaje: %d\n",aux.puntaje);
    printf("\t\tid de partida: %d\n",lista->idPartida);
    printf("\t\t----------------------\n");

}

void mostrarPuntajeIterativo(NodoPuntaje* lista)
{
    NodoPuntaje* seguidora=lista;

    while(seguidora!=NULL)
    {
        mostrarUnPuntaje(seguidora);
        seguidora=seguidora->siguiente;
    }
}
