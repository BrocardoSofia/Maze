#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ingresar_usuario.h"
#include "arbol.h"
#include "jugador.h"
#include "listas.h"
#include "gotoxy.h"
#include "titulos.h"
#include <windows.h>

void menu_ingreso();
nodoArbol* iniciar_sesion();
nodoArbol* menu_jugador(nodoArbol* arbol, char alias[]);
nodoArbol* menu_admin(nodoArbol* arbol);


int main()
{
    define_console_size();
    menu_ingreso();
    system("cls");
    return 0;
}

void menu_ingreso()
{
    int opcion;
    Jugador nuevo;
    nodoArbol* arbol = inicArbol();
    arbol = archivo_toArbol(arbol); /// carga los jugadores del archivo de jugadores previos (ya registrados) hacia el arbol.
    dibujar_tituloMaZe();
    hidecursor(0);
    Sleep(3000);
    if(arbol!=NULL) /// si el arbol tiene jugadores, lee del archivo de partidas las partidas que
    {               /// le corresponde a cada jugador y se las agrega a su lista de partidas.
        arbol = leer_informacion_partida(arbol);
    }
    do
    {
        system("cls");
        imprimirLimites(3);
        dibujarCuadro(48,10,71,21);
        gotoxy(50,12);
        printf("( 0 ) Salir");
        gotoxy(50,13);
        printf("( 1 ) Iniciar Sesion");
        gotoxy(50,14);
        printf("( 2 ) Registrarse");
        gotoxy(52,17);
        printf("INGRESE OPCION");
        dibujarCuadro(54,18,63,20);
        gotoxy(59,19);
        hidecursor(1);
        scanf("%i",&opcion);
        switch(opcion)
        {
        case 1:
            arbol = iniciar_sesion(arbol); /// pasar el arbol para comprobar si existe ese usuario creado.
            break;
        case 2:
            nuevo = registrar_jugador(arbol,nuevo); /// pasar el arbol para comprobar si el alias se puede ocupar o si ya existe.
            arbol = insertarJugadorArbol(arbol,nuevo); /// inserta el nuevo jugador al arbol
            jugador_aArchivo(nuevo);///y carga ese jugador registrado al archivo de jugadores
            break;
        }
    }
    while(opcion!=0);
}


nodoArbol* iniciar_sesion(nodoArbol* arbol)
{
    system("cls");

    int respuesta = 0;/// almacena 1 si existe ese usuario y almacena 0 si no existe.
    int bloq=0; /// contador para bloquear el inicio de sesion luego de 3 intentos fallidos.
    Usuario ingresando;/// cargo los datos para ingresar;
    do
    {
        imprimirLimites(3);
        ingresando = ingresar_usuario(ingresando);
        respuesta = validar_ingreso(arbol,ingresando); /// arbol para buscar, y dato que ingresa (alias y password). retorna (1 existe) y  (0 no existe).
        if((respuesta == 1)&&(arbol!=NULL)) /// si es 1 es que el inicio de sesion fue el correcto.
        {
            arbol = menu_jugador(arbol,ingresando.name); /// le paso el arbol y el nombre del jugador, mas facil para buscar y agregar sus puntajes (por si acaso)
        }
        else if(respuesta == 100) /// si la respuesta es 100 se trata de que ingreso el administrador
        {
            system("cls");
            arbol = menu_admin(arbol);
            respuesta = 1;
        }
        else
        {
            if(bloq < 2)
            {
                system("cls");
                imprimirLimites(4);
                color(4);
                dibujarCuadro(32,9,90,11);
                gotoxy(33,10);
                hidecursor(0);
                printf("Usuario o contrasenia incorrectos, intente de nuevo");
                bloq++;
                error();
                Sleep(3000);
                hidecursor(1);
                system("cls");
            }
            else
            {
                system("cls");
                imprimirLimites(4);
                color(4);
                dibujarCuadro(32,9,80,11);
                gotoxy(33,10);
                hidecursor(0);
                printf("Por tu seguridad decidimos bloquear el ingreso");
                respuesta = 1;
                error();
                Sleep(2000);
                hidecursor(1);
                system("cls");

            }
        }
    }

    while(respuesta != 1);
    return arbol;
}


nodoArbol* menu_jugador(nodoArbol* arbol, char alias[])
{
    int opcion;
    int mayor = 0;
    nodoArbol* auxArbol;
    do
    {
        system("cls");
        imprimirLimites(3);
        dibujarCuadro(32,9,82,20);
        gotoxy(35,11);
        printf("Bienvenido [ %s ] un placer verte por aqui", alias);
        gotoxy(38,13);
        printf("( 0 ) Salir");
        gotoxy(38,14);
        printf("( 1 ) Jugar");
        gotoxy(38,15);
        printf("( 2 ) Ver top 10 mundial de partidas");
        gotoxy(38,16);
        printf("( 3 ) Ver analiticas");
        gotoxy(38,17);
        printf("( 4 ) Historial de partidas");
        gotoxy(47,21);
        printf("Ingrese una opcion");
        dibujarCuadro(53,22,59,24);
        gotoxy(56,23);
        scanf("%i",&opcion);
        switch(opcion)
        {
        case 1:
            arbol = arbol_jugar(arbol,alias); /// el juego en si
            break;
        case 2:
            system("cls");
            mostrar_top10(arbol);
            hidecursor(1);
            break;
        case 3:
            system("cls");
            auxArbol = retornar_nodo_arbol(arbol,alias); /// busca el nodoarbol segun el alias de quien ingreso al juego
            mostrar_jugador(auxArbol->player); /// muestra sus estadisticas -> partidas jugadas, ganadas,perdidas.
            break;
        case 4:
            system("cls");
            auxArbol = retornar_nodo_arbol(arbol,alias);/// busca el nodoarbol segun el alias de quien ingreso al juego
            mostrarPuntajeIterativo(auxArbol->partidasJugadas);/// muestra iterativamente sus puntajes.
            printf("\n\n\n");
            system("pause");
            break;
        }
    }
    while(opcion!=0);
    return arbol;
}

nodoArbol* menu_admin(nodoArbol* arbol)
{
    int opcion;
    do
    {
        system("cls");
        hidecursor(1);
        imprimirLimites(3);
        dibujarCuadro(32,12,82,21);
        gotoxy(35,13);
        printf("MENU ADMIN");
        gotoxy(38,15);
        printf("( 1 ) BORRAR UN JUGADOR");
        gotoxy(38,16);
        printf("( 2 ) REINCORPORAR UN JUGADOR");
        gotoxy(38,17);
        printf("( 3 ) MOSTRAR TOP 10");
        gotoxy(38,18);
        printf("( 4 ) MOSTRAR TODOS LOS JUGADORES");
        gotoxy(47,22);
        printf("Ingrese una opcion:");
        dibujarCuadro(53,23,59,25);
        gotoxy(56,24);
        scanf("%i",&opcion);
        hidecursor(0);
        switch(opcion)
        {
        case 1:
            system("cls");
            arbol = borrar_jugador(arbol);
            break;
        case 2:
            system("cls");
            arbol=reincorporarJugador(arbol);
            limpiar_archivo_arbol();
            arbol_toArchivo(arbol);
            break;
        case 3:
            system("cls");
            mostrar_top10(arbol);
            break;
        case 4:
            system("cls");
            preorden(arbol);
            break;
        }
    }
    while(opcion!=0);
    return arbol;
}
