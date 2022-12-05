#include "ListaJuego.h"

NodoNivel* inicNodo()
{
    return NULL;
}

NodoNivel* crearNodoMapa(Mapa mapita)
{
    NodoNivel* aux = (NodoNivel*) malloc(sizeof(NodoNivel));//reservo espacio de memoria para el nodo

    aux->nivel = mapita;//guardo los datos del mapa en el nodo
    aux->siguiente = NULL;//inicializo siguiente en NULL


    return aux;
}
