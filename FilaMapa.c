#include "FilaMapa.h"

void inicFila(FilaNivel * filita)
{
    filita->primero = inicNodo();
    filita->ultimo = inicNodo();
}

void agregarFinalFila(FilaNivel* filita, NodoNivel* mapita)
{

    if(filita->primero == NULL)
    {
        //si filita todavia no tiene datos mapita es el primero y el ultimo
        filita->primero = mapita;
    }
    else
    {
        //tengo que buscar el ultimo
        NodoNivel* ulti= filita->ultimo;//obtengo el ultimo elemento de la fila
        ulti->siguiente = mapita;//enlazo el anterior ultimo con el nuevo ultimo
    }

    filita->ultimo = mapita;//agrego la mapita al final - actualizo el nuevo ultimo

}

Mapa extraerFila(FilaNivel* filita)
{
    Mapa mapita;
    NodoNivel* aBorrar;

    if(filita->primero != NULL)
    {
        aBorrar = filita->primero;

        mapita = aBorrar->nivel;

        filita->primero = aBorrar->siguiente;//actualizo el nuevo primero

        if(filita->primero != NULL)
        {
            //si es diferente de null tengo que modficar el enlaze al anterior
            NodoNivel* aux = filita->primero;

        }
        else
        {
            //si filita primero es null significa que el nodo a borrar es el primero y el ultimo
            filita->ultimo = NULL;
        }
        free(aBorrar);//libero el espacio de memoria del anterior primero

    }

    return mapita;
}
