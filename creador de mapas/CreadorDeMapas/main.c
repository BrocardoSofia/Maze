#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gotoxy.h"
#include "Mapa.h"

void define_console_size();
void imprimirLimites();
void imprimirRectangulo();
void imprimeCursor(int x, int y, int anteX, int anteY);
void imprimirTitulo();
int cargaMapa(Coordenada muros[3000], int validosCoordenadas);
void imprimeSalirDeCreador();
Coordenada defineUnaCoordenada(Coordenada muros[3000], int validosCoordenadas, int entradaOsalida);
void tituloEntrada();
void tituloSalida();
void imprimirRectangulo2();
void mapaAarchivo(Mapa mapita, char nombreArchi[]);
void copiarArray(int arrayVacio[], int arrayLleno[], int validos);
void mostrarArchivo(char mapasArchi[]);

/*************************************** MAIN ******************************************************/
int main()
{
    Coordenada muros[3300];
    int validosCoordenadas = 0;
    Coordenada entrada;
    Coordenada salida;
    int tiempo;
    char cancion[30];
    int color;
    int numMapa;
    Mapa mapita;
    char mapasArchi[]="mapas.bin";

    //defino entrada con valores iniciales
    entrada.x=-1;
    entrada.y=-1;



    //mostrarArchivo(mapasArchi);

    //system("pause");
    //system("cls");

    ///carga los muros del mapa
    validosCoordenadas = cargaMapa(mapita.muro, validosCoordenadas);

    system("cls");//limpio pantalla

    ///definir entrada
    entrada = defineUnaCoordenada(mapita.muro, validosCoordenadas, 1);

    system("cls");//limpio pantalla

    ///definir salida
    gotoxy(2,36);
    printf("Coordenada de entrada: x=%d  y=%d", entrada.x, entrada.y);
    salida = defineUnaCoordenada(mapita.muro, validosCoordenadas, 2);

    system("cls");
    fflush(stdin);

    ///definir tiempo del mapa
    imprimirRectangulo2();

    gotoxy(28,12);
    printf("Tiempo del mapa(en segundos): ");
    scanf("%d", &tiempo);


    system("cls");//limpio pantalla
    fflush(stdin);
    ///nombre de cancion

    imprimirRectangulo2();

    gotoxy(28,12);
    printf("Ingresar cancion formato WAV: ");
    fflush(stdin);
    gets(cancion);

    system("cls");//limpio pantalla
    fflush(stdin);

    ///color del mapa
    imprimirRectangulo2();
    gotoxy(28,16);
    printf("Azul: ......... 1");
    gotoxy(28,17);
    printf("Verde: ........ 2");
    gotoxy(28,18);
    printf("Cyan: ......... 3");
    gotoxy(28,19);
    printf("RED: .......... 4");
    gotoxy(28,20);
    printf("Magenta: ...... 5");
    gotoxy(28,21);
    printf("Marron: ....... 6");
    gotoxy(28,22);
    printf("Gris 1: ....... 7");
    gotoxy(28,23);
    printf("Gris 2: ....... 8");
    gotoxy(28,24);
    printf("Celeste: ...... 9");
    gotoxy(28,25);
    printf("verde claro: .. 10");
    gotoxy(28,26);
    printf("Cyan claro: ... 11");
    gotoxy(28,27);
    printf("Rosa: ......... 12");
    gotoxy(28,28);
    printf("Magenta 2: .... 13");
    gotoxy(28,29);
    printf("Amarillo: ..... 14");
    gotoxy(28,30);
    printf("Blanco: ....... 15");

    gotoxy(28,12);
    printf("Ingresar el color del mapa: ");
    fflush(stdin);
    scanf("%d", &color);

    system("cls");//limpio pantalla
    fflush(stdin);

    ///numero de mapa
    imprimirRectangulo2();

    gotoxy(28,12);
    printf("Ingresar el numero de mapa: ");
    scanf("%d", &numMapa);

    ///guardar todo en 1 mapa
    mapita.tiempo = tiempo;
    //copiarArray(mapita.muro, muros, validosCoordenadas);
    mapita.validosMuro = validosCoordenadas;
    mapita.inicio = entrada;
    mapita.fin = salida;
    strcpy(mapita.cancion, cancion);
    mapita.colorMapa = color;

    ///guardar en archivo
    mapaAarchivo(mapita, mapasArchi);

    system("cls");//limpio pantalla
    printf("Mapa cargado\n");

    return 0;
}

/************************************* FUNCIONES **************************************************/

void mostrarArchivo(char mapasArchi[])
{
    FILE * buffer;
    buffer = fopen(mapasArchi, "rb");
    Mapa aux;

    if(buffer != NULL)
    {
        while(fread(&aux, sizeof(Mapa), 1, buffer)>0)
        {
            printf("Mapa: \n");
            printf("%d segundos\n", aux.tiempo);
            printf("%d validos\n", aux.validosMuro);
            printf("%s cancion\n\n", aux.cancion);
            mostrarMapa(aux.muro,aux.validosMuro,aux.colorMapa);
            system("pause");
            system("cls");
        }
    }

    fclose(buffer);
}

void copiarArray(int arrayVacio[], int arrayLleno[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        arrayVacio[i]=arrayLleno[i];
    }
}

void mapaAarchivo(Mapa mapita, char nombreArchi[])
{
    FILE * buffer;

    buffer = fopen(nombreArchi, "ab");

    if(buffer != NULL)
    {
        fwrite(&mapita, sizeof(Mapa), 1, buffer);
    }

    fclose(buffer);
}

void imprimirRectangulo2()
{
    int x=10;

    color(3);
    gotoxy(25,x);

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<50; j++)
        {
            if((i==1)||(i==5)||(j==0)||(j==1)||(j==48)||(j==49))
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }

            if(j==49)
            {
                gotoxy(25,x++);
            }
        }
    }
}

Coordenada defineUnaCoordenada(Coordenada muros[3000], int validosCoordenadas, int entradaOsalida)
{
    Coordenada entrada;
    int x=2;
    int y=7;
    int anteX=x;
    int anteY=y;
    int i=0;//cuando sea 1 significa que ya definio la entrada o la salida

    ///muestro mapa
    define_console_size();
    imprimirLimites();//imprime el mapa una vez
    imprimirRectangulo();
    mostrarMapa(muros,validosCoordenadas,3);

    if(entradaOsalida == 1)
    {
        tituloEntrada();
    }
    else
    {
        tituloSalida();
    }

    imprimeCursor(x,y,anteX,anteY);

    do
    {
        hidecursor(0);

        if(GetAsyncKeyState(0X26)||GetAsyncKeyState(87))//Flecha ↑ o letra 'w'
        {
            if(y>7)
            {
                y--;
                imprimeCursor(x,y,anteX,anteY);
                anteY=y;
            }
        }
        if(GetAsyncKeyState(0X25)||GetAsyncKeyState(65))//Flecha ← o letra 'a'
        {
            if(x>2)
            {
                x-=2;
                imprimeCursor(x,y,anteX,anteY);
                anteX=x;
            }
        }
        if(GetAsyncKeyState(0X27)||GetAsyncKeyState(68))//Flecha → o letra 'd'
        {
            if(x<107)
            {
                x+=2;
                imprimeCursor(x,y,anteX,anteY);
                anteX=x;
            }
        }
        if(GetAsyncKeyState(0X28)||GetAsyncKeyState(83))//Flecha ↓ o letra 's'
        {
            if(y<34)
            {
                y++;
                imprimeCursor(x,y,anteX,anteY);
                anteY=y;
            }
        }
        //Si apreto enter
        if(GetAsyncKeyState(13))
        {
            //marco esa coordenada como entrada
            entrada.x = x;
            entrada.y = y;
            i=1;
        }

        Sleep(150);//frena el programa por milisegundos

    }
    while(i!=1);

    return entrada;
}



void tituloEntrada()
{
    gotoxy(10,1);
    printf("  ___  ___ ___ ___ _  _ ___ ___ _  _ ___   ___      ___ _  _ _____ ___    _   ___   _");
    gotoxy(10,2);
    printf(" |   \\| __| __|_ _| \\| |_ _| __| \\| |   \\ / _ \\    | __| \\| |_   _| _ \\  /_\\ |   \\ /_\\");
    gotoxy(10,3);
    printf(" | |) | _|| _| | || .` || || _|| .` | |) | (_) |   | _|| .` | | | |   / / _ \\| |) / _ \\");
    gotoxy(10,4);
    printf(" |___/|___|_| |___|_|\\_|___|___|_|\\_|___/ \\___/    |___|_|\\_| |_| |_|_\\/_/ \\_\\___/_/ \\_\\");
}

void tituloSalida()
{
    gotoxy(10,1);
    printf("  ___  ___ ___ ___ _  _ ___ ___ _  _ ___   ___      ___   _   _    ___ ___   _");
    gotoxy(10,2);
    printf(" |   \\| __| __|_ _| \\| |_ _| __| \\| |   \\ / _ \\    / __| /_\\ | |  |_ _|   \\ /_\\ ");
    gotoxy(10,3);
    printf(" | |) | _|| _| | || .` || || _|| .` | |) | (_) |   \\__ \\/ _ \\| |__ | || |) / _ \\");
    gotoxy(10,4);
    printf(" |___/|___|_| |___|_|\\_|___|___|_|\\_|___/ \\___/    |___/_/ \\_\\____|___|___/_/ \\_\\");
}

int cargaMapa(Coordenada muros[3000], int validosCoordenadas)
{
    int x=2;
    int y=7;
    int anteX=x;
    int anteY=y;
    char c=0;

    hidecursor(0);//oculta el cursor

    define_console_size();
    imprimirLimites();//imprime el mapa una vez
    imprimirRectangulo();
    imprimirTitulo();
    imprimeSalirDeCreador();
    imprimeCursor(x,y,anteX,anteY);


    ///el loop tiene que ser hasta que se acaba el tiempo (devuelve 0) o llegue al destino
    do
    {
        hidecursor(0);


        if(GetAsyncKeyState(0X26)||GetAsyncKeyState(87))//Flecha ↑ o letra 'w'
        {
            if(y>7)
            {
                y--;
                imprimeCursor(x,y,anteX,anteY);
                anteY=y;
            }
        }
        if(GetAsyncKeyState(0X25)||GetAsyncKeyState(65))//Flecha ← o letra 'a'
        {
            if(x>2)
            {
                x-=2;
                imprimeCursor(x,y,anteX,anteY);
                anteX=x;
            }
        }
        if(GetAsyncKeyState(0X27)||GetAsyncKeyState(68))//Flecha → o letra 'd'
        {
            if(x<107)
            {
                x+=2;
                imprimeCursor(x,y,anteX,anteY);
                anteX=x;
            }
        }
        if(GetAsyncKeyState(0X28)||GetAsyncKeyState(83))//Flecha ↓ o letra 's'
        {
            if(y<34)
            {
                y++;
                imprimeCursor(x,y,anteX,anteY);
                anteY=y;
            }
        }
        //Si apreto enter
        if(GetAsyncKeyState(13))
        {
            //posiciono dos muros en el arreglo de muros y en la matriz de verificacion
            muros[validosCoordenadas].x = x;
            muros[validosCoordenadas].y = y;
            validosCoordenadas++;//incremento el validos coordenadas
            //como en X se mueve de 2 en 2 pongo 2 muros
            x+=1;
            muros[validosCoordenadas].x = x;
            muros[validosCoordenadas].y = y;
            validosCoordenadas++;//incremento el validos coordenadas
            x+=1;

            //posiciono el cursor
            imprimeCursor(x,y,anteX,anteY);
            anteX=x;
            //imprimo el mapa
            mostrarMapa(muros,validosCoordenadas,3);
        }

        if(GetAsyncKeyState(27))
        {
            c=27;
        }

        Sleep(150);//frena el programa por milisegundos

    }
    while(c!=27);

    return validosCoordenadas;
}

void imprimeSalirDeCreador()
{
    gotoxy(2,36);
    printf("ESC para terminar mapa");
}

void imprimirRectangulo()
{
    gotoxy(0,0);
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<110; j++)
        {
            if((i==0)||(j==0)||(j==1)||(j==109)||(j==108))
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }

            if(j==109)
            {
                printf("\n");
            }
        }
    }
}



void imprimirLimites()
{
    gotoxy(0,6);
    color(3);
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<110; j++)
        {
            if((i==0)||(j==0)||(j==1)||(i==29)||(j==109)||(j==108))
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }

            if(j==109)
            {
                printf("\n");
            }

        }
    }
}



void define_console_size()
{
    HANDLE wHnd; // Handle to write to the console.
    HANDLE rHnd; // Handle to read from the console.

    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Maze!");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 110, 40};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    /*Esta funcion fue sacada de internet y funciona!!!
      no se comprende del todo el funcionamientos pero
      al parecer da las dimensiones que buscabamos
    */
}

void imprimeCursor(int x, int y, int anteX, int anteY)
{
    color(4);//color del jugador

    //me posiciono en la posicion 'actual' del cursor y lo 'borro'
    gotoxy(anteX,anteY);
    printf("  \n");

    //mover el cursor a la nueva posicion
    gotoxy(x,y);
    printf("%c",207);
}

void imprimirTitulo()
{
    gotoxy(20,1);
    printf("   ___ ___ ___   _   _  _ ___   ___      __  __   _   ___  _  ");
    gotoxy(20,2);
    printf("  / __| _ \\ __| /_\\ | \\| |   \\ / _ \\    |  \\/  | /_\\ | _ \\/_\\  ");
    gotoxy(20,3);
    printf(" | (__|   / _| / _ \\| .` | |) | (_) |   | |\\/| |/ _ \\|  _/ _ \\ ");
    gotoxy(20,4);
    printf("  \\___|_|_\\___/_/ \\_\\_|\\_|___/ \\___/    |_|  |_/_/ \\_\\_|/_/ \\_\\ ");

}
