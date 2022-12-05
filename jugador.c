#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "jugador.h"
#include "gotoxy.h"
#include "titulos.h"

Jugador registrar_jugador(nodoArbol* arbol, Jugador player)
{
    int disponible;
    char caracter;
    int i = 0;
    do
    {
        system("cls");
        imprimirLimites(3);
        dibujarCuadro(46,12,70,14);
        gotoxy(47,13);
        printf("INGRESE ALIAS");
        dibujarCuadro(47,14,69,16);
        gotoxy(49,15);
        fflush(stdin);
        gets(player.alias);
        disponible = validar_nombre(arbol,player.alias); /// si devuelve 0, es que se puede utilizar
        if(disponible != 0)
        {
            system("cls");
            imprimirLimites(4);
            color(4);
            dibujarCuadro(33,11,80,13);
            gotoxy(34,12);
            hidecursor(0);
            printf("  ALIAS YA UTILIZADO... INTENTE CON OTRO ");
            gotoxy(0,20);
            Sleep(2000);
            hidecursor(1);
        }

    }while(disponible != 0);

    dibujarCuadro(46,16,70,18);
    gotoxy(47,17);
    printf("INGRESE PASSWORD");
    dibujarCuadro(47,18,69,20);
    gotoxy(49,19);
    fflush(stdin);
    while(caracter = getch())///el bucle se rompe cuando se toca enter(su codico ASCII es 13)
    {
        if(caracter == 13)
        {
            player.password[i]= '\0'; ///guardo el caracter nulo, me indica el final de una cadena
            break;
        }
        else if (caracter == 8)///el ASCII de la tecla borrar es 8
        {
            if(i>0) ///para que no me borre de mas
            {
                i--;///muevo el indice hacia atras
                printf("\b \b");///me mueve el cursor hacia la izquierda
            }
        }
        else
        {
            printf("*");///por cada caracter que ingreso me imprime un *
            player.password [i]=caracter;
            i++;///para que el siguiente caracter se ingrese en la posicion siguiente
        }
    }

    player.partidasJugadas = 0;
    player.partidasGanadas = 0;
    player.partidasPerdidas = 0;

    return player;
}

int validar_nombre(nodoArbol* arbol, char alias[])
{
    int rta=0;
    if(arbol != NULL) ///En caso que el arbol sea null, no entra al if porque no hay nada para buscar y retorno 0 que significa que no hay un nombre igual y se puede utilizar
    {
        rta = buscar_nombre_arbol(arbol,alias);
    }
    return rta;
}

int buscar_nombre_arbol(nodoArbol* arbol, char alias[])
{
    int rta = 0; /// valor predeterminado 0 es igual a que no encontro un nombre igual
    if(arbol!= NULL)
    {
        if((strcmpi(alias,arbol->player.alias))==0)
        {
            rta = 1;
        }
        else
        {
            rta = buscar_nombre_arbol(arbol->der,alias);
            if(rta != 1)
            {
                rta = buscar_nombre_arbol(arbol->izq,alias);
            }
        }
    }
    return rta;
}

void mostrar_jugador(Jugador player)
{
    color(11);
    titulo_analiticas();
    gotoxy(49,17);
    printf("JUGADOR [ %s ]",player.alias);
    dibujarCuadro(48,19,74,25);
    dibujar_lineahorizontal(49,18,74,25);
    dibujar_lineavertical(69,20,25);
    gotoxy(49,20);
    printf(" PARTIDAS JUGADAS");
    gotoxy(49,22);
    printf(" PARTIDAS GANADAS");
    gotoxy(49,24);
    printf(" PARTIDAS PERDIDAS");
    gotoxy(70,20);
    printf("%i\n", player.partidasJugadas);
    gotoxy(70,22);
    printf("%i\n", player.partidasGanadas);
    gotoxy(70,24);
    printf("%i\n", player.partidasPerdidas);
    hidecursor(0);
    Sleep(3000);
    hidecursor(1);

}
