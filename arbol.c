#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "jugador.h"
#include "listas.h"
#include "gotoxy.h"
#include "titulos.h"
#include "Maze.h"

/// (1) -FUNCIONES TECNICAAS DEL ARBOL

/// [ 1.1 ] INICIALIZACION
nodoArbol* inicArbol()
{
    return NULL;
}

/// [ 1.2 ] CREACION
nodoArbol* crearNodoArbol(Jugador nuevo)
{
    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->izq = NULL;
    aux->der = NULL;
    aux->partidasJugadas = NULL;
    aux->player = nuevo;
    return aux;
}

/// [ 1.3 ] INSERTAR
nodoArbol* insertarJugadorArbol(nodoArbol* arbol, Jugador nuevo)
{
    if(arbol == NULL)
    {
        arbol = crearNodoArbol(nuevo);

    }
    else
    {
        Jugador aux = arbol->player;
        if((strcmpi(nuevo.alias,aux.alias)) > 0) /// si la primera cadena es mayor retornara un valor positivo
        {
            arbol->der = insertarJugadorArbol(arbol->der,nuevo);
        }
        else
        {
            arbol->izq = insertarJugadorArbol(arbol->izq,nuevo);
        }
    }
    return arbol;
}

/// [ 1.4 ] MOSTRAR
void preorden(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        mostrar_jugador(arbol->player);
        hidecursor(0);
        Sleep(2000);
        system("cls");
        preorden(arbol->der);
        preorden(arbol->izq);
    }
}

/// [ 1.5.1 ] BORRAR JUGADOR
nodoArbol* borrar_jugador(nodoArbol* arbol)
{
    char nombre[50];
    printf("Jugador a borrar -> ");
    fflush(stdin);
    gets(nombre);
    int respuesta = 0;
    respuesta = comprobar_elimnado_anteriormente(nombre);
    if( respuesta == 0)
    {
        nodoArbol* nuevo = retornar_nodo_arbol(arbol,nombre); //devuelve el nodo que va a borrar en lalinea siguiente
        if (nuevo!=NULL)
        {
            cargarEnArchivoDeEliminados(nuevo->player);
            arbol=borrarNodo(arbol,nombre);
            limpiar_archivo_arbol();
            arbol_toArchivo(arbol);
            printf("\n\n---> JUGADOR ELIMINADO <---\n\n");
            system("pause");
        }
        else
        {
            printf("\n\n---> JUGADOR NO REGISTRADO <---\n\n");
            system("pause");
        }
    }
    else
    {
        printf("\n\n---> ESE JUGADOR YA FUE ELIMINADO <---\n\n");
        system("pause");
    }
    return arbol;
}

/// [ 1.5.2 ] BORRAR NODO JUGADOR
nodoArbol* borrarNodo(nodoArbol* arbol, char nombre[])
{
    if(arbol != NULL)
    {
        if((strcmpi(arbol->player.alias,nombre)) == 0)
        {
            if(arbol->izq != NULL)
            {
                nodoArbol* masDer = NodoMasDerecha(arbol->izq);
                arbol->player = masDer->player;
                arbol->partidasJugadas = masDer->partidasJugadas;
                arbol->izq = borrarNodo(arbol->izq, masDer->player.alias);
            }
            else if(arbol->der != NULL)
            {
                nodoArbol* masIzq = NodoMasIzquierda(arbol->der);
                arbol->player = masIzq->player;
                arbol->partidasJugadas = masIzq->partidasJugadas;
                arbol->der = borrarNodo(arbol->der, masIzq->player.alias);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
        else
        {
            if((strcmpi(nombre,arbol->player.alias)) > 0)
            {
                arbol->der = borrarNodo(arbol->der, nombre);
            }
            else
            {
                arbol->izq = borrarNodo(arbol->izq, nombre);
            }
        }
    }
    return arbol;
}

/// [ 1.5.3 ]
nodoArbol* NodoMasDerecha(nodoArbol* arbol)
{
    if(arbol->der != NULL)
    {
        arbol=NodoMasDerecha(arbol->der);
    }
    return arbol;
}

/// [ 1.5.4 ]
nodoArbol* NodoMasIzquierda(nodoArbol* arbol)
{
    if(arbol->izq != NULL)
    {
        arbol=NodoMasIzquierda(arbol->izq);
    }
    return arbol;
}

/// [ 1.6 ] BUSQUEDA
nodoArbol* retornar_nodo_arbol(nodoArbol* arbol, char alias[])
{
    nodoArbol* rta = NULL;
    if(arbol!= NULL)
    {
        Jugador aux = arbol->player;
        if(strcmpi(alias,aux.alias)==0)
        {
            rta = arbol;
        }
        else
        {
            rta = retornar_nodo_arbol(arbol->der,alias);
            if(rta == NULL)
            {
                rta = retornar_nodo_arbol(arbol->izq,alias);
            }
        }
    }
    return rta;
}


/// (2) - JUEGO Y FUNCIONES NECESARIAS

/// [ 2.1 ]
nodoArbol* arbol_jugar(nodoArbol* arbol, char alias[])
{
    int puntaje = 0;
    int resultado_partida = juego(&puntaje);
    fflush(stdin);
    nodoArbol* auxiliar1 = retornar_nodo_arbol(arbol,alias);
    if(auxiliar1!=NULL) ///significa que existe
    {
        auxiliar1 = actualizar_estadisticas(auxiliar1,resultado_partida);
        NodoPuntaje* aux = crearNodoPuntaje(alias,puntaje);
        auxiliar1->partidasJugadas = agregarAlFinal(auxiliar1->partidasJugadas,aux);
        ///PASO DEL NODO PUNTAJE A UN ESTRUCTURA PARTIDA AUX PARA ESCRIBIR EN EL ARCHIVO.
        Partida puntajeAux = aux->puntaje;
        int id = aux->idPartida;
        ///DECLARO LA ESTRUCTURA REGISTRO PARTIDAS Y LE ASIGNO LA INFO DE LA PARTIDA ASI SE CARGA EN EL ARCHIVO
        registro_partida partidaAux;

        partidaAux.idPartida = id;
        partidaAux.puntaje = puntajeAux.puntaje;
        partidaAux.activo = puntajeAux.activo;
        strcpy(partidaAux.jugador,puntajeAux.jugador);
        partida_aArchivo(partidaAux);
    }

    limpiar_archivo_arbol();
    arbol_toArchivo(arbol);

    return arbol;
}

/// [ 2.2 ]
nodoArbol* actualizar_estadisticas(nodoArbol* arbol, int resultado)
{
    Jugador aux = arbol->player;
    if(resultado == 1)
    {
        aux.partidasGanadas =  aux.partidasGanadas + 1;
    }
    else
    {
        aux.partidasPerdidas = aux.partidasPerdidas + 1;
    }
    aux.partidasJugadas = aux.partidasJugadas + 1;
    arbol->player = aux;
    return arbol;
}


/// (3) - FUNCIONES QUE MANEJAN ARCHIVOS

/// [ 3.1 ] PARTIDA
void partida_aArchivo(registro_partida p)
{
    FILE* fp;
    fp = fopen("registro_partidas.dat","ab");
    if(fp != NULL)
    {
        fwrite(&p,sizeof(registro_partida),1,fp);
    }
    fclose(fp);
}

NodoPuntaje* crearNodoPuntajeRearmado(Partida aux,int id)
{
    NodoPuntaje* nuevo=(NodoPuntaje*)malloc(sizeof(NodoPuntaje));

    nuevo->puntaje=aux;
    nuevo->idPartida=id;
    nuevo->siguiente=NULL;

    return nuevo;
}
/// [ 3.1.2 ] CARGA LAS PARTIDAS DESDE EL ARCHIVO HACIA TODO EL ARBOL
nodoArbol* leer_informacion_partida(nodoArbol* arbol) /// aca mientras leeo creo el nodo puntaje y lo asigno a al nodo arbol.
{
    nodoArbol* auxArbol = NULL;
    NodoPuntaje* auxNPuntaje = NULL;
    Partida auxPartida;
    registro_partida dato;

    FILE* fp;
    fp = fopen("registro_partidas.dat","rb");
    if((fp != NULL)&&(arbol!=NULL))
    {
        while((fread(&dato,sizeof(registro_partida),1,fp)) > 0 )
        {
            auxArbol = retornar_nodo_arbol(arbol,dato.jugador);
            if(auxArbol!=NULL)
            {
                //AuxPartida almacena temporalmente [activo - puntaje - alias ]
                auxPartida.activo = dato.activo;
                auxPartida.puntaje = dato.puntaje;
                strcpy(auxPartida.jugador,dato.jugador);
                ///crear NodoPuntaje y pasarle la info de AuxPartida
                auxNPuntaje = crearNodoPuntajeRearmado(auxPartida,dato.idPartida);
                auxArbol->partidasJugadas = agregarAlFinal (auxArbol->partidasJugadas,auxNPuntaje);
            }
        }
    }
    fclose(fp);
    return arbol;
}
/// [ 3.1.2 ] CARGA LA PARTIDA DE UN SOL9O JUGADOR HACIA EL NODO ARBOL DE ESE JUGADOR (ESTO LO HACEMOS PARA CUANDO LO REINCORPORA)
nodoArbol* leer_informacion_partida_del_reincorporado(nodoArbol* arbol, char nombre[])
{
    nodoArbol* auxArbol = NULL;
    NodoPuntaje* auxNPuntaje = NULL;
    Partida auxPartida;
    registro_partida dato;

    FILE* fp;
    fp = fopen("registro_partidas.dat","rb");
    if((fp != NULL)&&(arbol!=NULL))
    {
        while((fread(&dato,sizeof(registro_partida),1,fp)) > 0 )
        {
            if((strcmpi(dato.jugador,nombre))==0)
            {
                auxArbol = retornar_nodo_arbol(arbol,dato.jugador);
                if(auxArbol!=NULL)
                {
                    //AuxPartida almacena temporalmente [activo - puntaje - alias ]
                    auxPartida.activo = dato.activo;
                    auxPartida.puntaje = dato.puntaje;
                    strcpy(auxPartida.jugador,dato.jugador);
                    ///crear NodoPuntaje y pasarle la info de AuxPartida
                    auxNPuntaje = crearNodoPuntajeRearmado(auxPartida,dato.idPartida);
                    auxArbol->partidasJugadas = agregarAlFinal (auxArbol->partidasJugadas,auxNPuntaje);
                }
            }
        }
    }
    fclose(fp);
    return arbol;
}

/// [ 3.2 ] LIMPIAR ARCHVO -> "registro_jugadores.dat"
void limpiar_archivo_arbol()
{
    FILE* fp;
    fp = fopen("registro_jugadores.dat","wb");
    if(fp != NULL)
    {
        fflush(fp);
    }
    fclose(fp);
}

/// [ 3.3 ] PASA LOS JUGADORES DEL ARCHVIO ->"registro_jugadores.dat" -> HACIA EL ARBOL
nodoArbol* archivo_toArbol(nodoArbol* arbol)
{
    Jugador player;
    FILE* fp;
    fp = fopen("registro_jugadores.dat","rb");
    if(fp != NULL)
    {
        while((fread(&player,sizeof(Jugador),1,fp)) > 0 )
        {
            arbol = insertarJugadorArbol(arbol,player);
        }
        fclose(fp);
    }
    return arbol;
}

/// [ 3.3.1 ] ARBOL DE JUGADORES -> "registro_jugadores.dat" (CARGA SOLO LA ESTRUCTURA JUGADOR EN EL ARCHIVO)
void arbol_toArchivo(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        jugador_aArchivo(arbol->player);
        arbol_toArchivo(arbol->der);
        arbol_toArchivo(arbol->izq);
    }
}

/// [ 3.3.2 ] JUGADOR -> "registro_jugadores.dat"
void jugador_aArchivo(Jugador nuevo)
{
    FILE* fp;
    fp = fopen("registro_jugadores.dat","ab");
    if(fp != NULL)
    {
        fwrite(&nuevo,sizeof(Jugador),1,fp);
    }
    fclose(fp);
}

/// [ 3.4 ] JUGADORES ELMINADOS -> "jugadores_eliminados.dat" (CARGA SOLO LA ESTRUCUTURA JUGADOR EN EL ARCHIVO)
void cargarEnArchivoDeEliminados(Jugador eliminado)
{
    FILE* fp;
    fp = fopen("jugadores_eliminados.dat","a+b");
    if(fp != NULL)
    {
        fwrite(&eliminado,sizeof(Jugador),1,fp);
    }
    fclose(fp);
}

/// [ 3.5 ] REINCORPORAR JUGADOR -> "jugadores_eliminados.dat" -> Arbol
nodoArbol* reincorporarJugador(nodoArbol* arbol)
{
    char nombre[50];
    printf(" ALIAS DEL JUGADOR A REINCORPORAR -> ");
    fflush(stdin);
    gets(nombre);
    Jugador aux;
    int cont = 0;
    int rta = 0;
    FILE* fp=fopen("jugadores_eliminados.dat","rb");
    FILE* fp2=fopen("jugadores_eliminados_aux.dat","a+b");

    rta = buscar_nombre_arbol(arbol,nombre);
    if(rta == 1)
    {
        printf("\n\n---> EL JUGADOR EXISTE, TODAVIA NO FUE ELIMINADO <---\n\n");
        system("pause");
    }
    else if(fp!=NULL)
    {
        while(fread(&aux,sizeof(Jugador),1,fp)>0)
        {
            if(strcmpi(aux.alias,nombre)==0)
            {
                printf("\n\n---> JUGADOR REINCORPORADO <---\n\n");
                system("pause");
                arbol = insertarJugadorArbol(arbol,aux);
                arbol = leer_informacion_partida_del_reincorporado(arbol,aux.alias);
            }
            else
            {
                 fwrite(&aux,sizeof(Jugador),1,fp2);
            }
        }
        rta = buscar_nombre_arbol(arbol,nombre);
        if( rta == 0)
        {
            printf("\n\n--->JUGADOR INEXISTENTE, NUNCA FUE REGISTRADO NI ELIMINADO <---\n");
            system("pause");
        }
    }
    else
    {
        printf("\n\n---> NO HAY JUGADORES ELIMINADOS <---\n\n");
        system("pause");
    }
    fclose(fp2);
    fclose(fp);

    limpiar_archivo_eliminados();

    fp2=fopen("jugadores_eliminados_aux.dat","rb");
    fp=fopen("jugadores_eliminados.dat","a+b");
    if(fp2!=NULL && fp!=NULL)
    {
        while(fread(&aux,sizeof(Jugador),1,fp2)>0) //paso la data que esta en el 2 al 1
        {
            fwrite(&aux,sizeof(Jugador),1,fp);
        }
        fclose(fp);
        fclose(fp2);
    }

    limpiar_archivo_eliminados_aux();

    return arbol;
}

/// [ 3.5.1 ] LIMPIAR ARCHIVO -> "jugadores_eliminados.dat"

void limpiar_archivo_eliminados()
{
    FILE* fp;
    fp = fopen("jugadores_eliminados.dat","wb");
    if(fp != NULL)
    {
        fflush(fp);
    }
    fclose(fp);
}

/// [ 3.5.2 ] LIMPIAR ARCHIVO -> "jugadores_eliminados_aux.dat"
void limpiar_archivo_eliminados_aux()
{
    FILE* fp;
    fp = fopen("jugadores_eliminados_aux.dat","wb");
    if(fp != NULL)
    {
        fflush(fp);
    }
    fclose(fp);
}

int comprobar_elimnado_anteriormente(char nombre [])
{
    int rta = 0;
    Jugador aux;
    FILE* fp;
    fp = fopen("jugadores_eliminados.dat","rb");
    if(fp != NULL)
    {
        while((fread(&aux,sizeof(Jugador),1,fp)>0)&&(rta == 0))
        {
            if((strcmpi(aux.alias,nombre)) == 0)
            {
                rta = 1;
            }
        }
    }
    fclose(fp);
    return rta;
}

