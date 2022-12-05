#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "top.h"
#include "gotoxy.h"
#include "titulos.h"

nodoTOP* inic_lista()
{
    return NULL;
}

nodoTOP* crear_nodo_top(registro_partida nuevo)
{
    nodoTOP* aux = (nodoTOP*)malloc(sizeof(nodoTOP));
    aux->dato = nuevo;
    aux->siguiente = NULL;
    return aux;
}

nodoTOP* agrega_principio_top(nodoTOP* lista, nodoTOP* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodoTOP* agegar_orden_top(nodoTOP* lista, nodoTOP* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;

    }
    else if(lista->dato.puntaje <= nuevo->dato.puntaje)
    {
        lista = agrega_principio_top(lista,nuevo);
    }
    else
    {
        nodoTOP* seguidora = lista;
        nodoTOP* anterior = lista;

        while((seguidora != NULL)&&(seguidora->dato.puntaje >= nuevo->dato.puntaje))
        {
            anterior = seguidora;
            seguidora = seguidora->siguiente;
        }
        anterior->siguiente = nuevo;
        nuevo->siguiente = seguidora;
    }
    return lista;
}

nodoTOP* archivoPartidas_toLista(nodoTOP* lista)
{
    registro_partida aux;
    nodoTOP* nuevo;
    FILE* fp = fopen("registro_partidas.dat","rb");
    if(fp != NULL)
    {
        while((fread(&aux,sizeof(registro_partida),1,fp)) > 0)
        {
            nuevo = crear_nodo_top(aux);
            lista = agegar_orden_top(lista,nuevo);

        }
        fclose(fp);
    }
    return lista;
}

int lista_toArreglo(nodoTOP* lista, registro_partida arreglo [10])
{
    int i=0;
    nodoTOP* seguidora = lista;
    while((seguidora != NULL)&&(i<10))
    {
        registro_partida auxi = seguidora->dato;
        arreglo[i] = auxi;
        seguidora = seguidora->siguiente;
        i++;
    }
    return i;
}

void mostrar_top10(arbol)
{
    registro_partida arreglo [10];
    int rta;
    int x = 41;
    int y = 9;
    nodoTOP* lista = inic_lista();
    lista = archivoPartidas_toLista(lista);
    int validos = lista_toArreglo(lista,arreglo);
    system("cls");
    color(2);
    gotoxy(0,0);
    titulo_top10();
    dibujarCuadro(40,6,80,28);
    dibujar_lineahorizontal(41,5,80,27);
    dibujar_lineavertical(60,7,28);
    gotoxy(65,29);
    printf("INACTIVO -> [0]");

    for(int i = 0; i<validos; i++)
    {
        rta = buscar_nombre_arbol(arbol,arreglo[i].jugador);
        if(rta == 0)
        {
            arreglo[i].activo = 0;
        }
        mostrar_una_partida(arreglo[i],i+1,x,y);
        y = y + 2;
    }

    gotoxy(0,0);
    system("pause");
    hidecursor(1);
    color(3);
}

void mostrar_una_partida(registro_partida aux,int pos,int x, int y)
{
    gotoxy(x,y);
    if(aux.activo == 0)
    {
        printf("%i%c %s [%i]",pos,167,aux.jugador,aux.activo);
        x = x + 20;
        gotoxy(x,y);
        printf("%i", aux.puntaje);
        hidecursor(0);

    }
    else
    {
        printf("%i%c %s",pos,167,aux.jugador);
        x = x + 20;
        gotoxy(x,y);
        printf("%i", aux.puntaje);
        hidecursor(0);

    }
}

