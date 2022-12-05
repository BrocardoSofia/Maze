#include "Maze.h"

int juego(int *puntajeTotal)
{
    char mapasArchi[]="mapas.bin";
    FilaNivel filita;
    int puntajeNivel;
    int finalFila=0;
    Mapa mapita;
    int nivel=0;
    int matrizMapa[40][110]={0};

    inicFila(&filita);



    //pasar archivo a fila de mapas
    archivoAfila(&filita, mapasArchi);

    define_console_size();

    do
    {
        if(filita.primero != NULL)
        {
            nivel++;
            mapita = extraerFila(&filita); //extraigo el mapa de la fila

            pasarValidosMatriz(matrizMapa,mapita.muro,mapita.validosMuro);//paso a una matriz de verificacion de movimiento

            cuentaRegresiva();//cuenta regresiva de 3 segundos

            puntajeNivel = juegaNivel(mapita, nivel, matrizMapa, *puntajeTotal);//se juega el nivel

            *puntajeTotal += puntajeNivel;//sumo el puntaje al puntaje total

            //reinicio la matrizMapa
            reiniciarMatriz(matrizMapa);
            system("cls");
        }
        else
        {
            finalFila = 1; //llego al final de los niveles
        }

    }while((puntajeNivel != 0)&&(finalFila != 1));

    GAMEOVER(*puntajeTotal);

    //devolver si gano o perdio
    return finalFila;//si es 1 gano, si es 0 no completo los mapas
}

void GAMEOVER(int puntaje)
{
    color(3);
    //imprime rectangulo
    rectanguloGrande();

    gotoxy(10,10);
    printf("      _______  _______  __   __  _______         _______  __   __  _______  ______   ");
    gotoxy(10,11);
    printf("     |       ||   _   ||  |_|  ||       |       |       ||  | |  ||       ||    _ |");
    gotoxy(10,12);
    printf("     |    ___||  |_|  ||       ||    ___|       |   _   ||  |_|  ||    ___||   | ||");
    gotoxy(10,13);
    printf("     |   | __ |       ||       ||   |___        |  | |  ||       ||   |___ |   |_||_");
    gotoxy(10,14);
    printf("     |   ||  ||       ||       ||    ___|       |  |_|  ||       ||    ___||    __  |");
    gotoxy(10,15);
    printf("     |   |_| ||   _   || ||_|| ||   |___        |       | |     | |   |___ |   |  | |");
    gotoxy(10,16);
    printf("     |_______||__| |__||_|   |_||_______|       |_______|  |___|  |_______||___|  |_|");

    gotoxy(45,25);
    printf("Puntaje final: %d", puntaje);

    hidecursor(0);
    Sleep(3000);
    system("cls");

}

void cuentaRegresiva()
{
    color(3);
    system("cls");
    //imprime rectangulo
    rectanguloGrande();

    //imprime el 3
    gotoxy(45,10);
    printf(" 333333333333333");
    gotoxy(45,11);
    printf("3:::::::::::::::33");
    gotoxy(45,12);
    printf("3::::::33333::::::3");
    gotoxy(45,13);
    printf("3333333     3:::::3");
    gotoxy(45,14);
    printf("            3:::::3");
    gotoxy(45,15);
    printf("    33333333:::::3");
    gotoxy(45,16);
    printf("    3:::::::::::3");
    gotoxy(45,17);
    printf("    33333333:::::3");
    gotoxy(45,18);
    printf("            3:::::3");
    gotoxy(45,19);
    printf("            3:::::3");
    gotoxy(45,20);
    printf("            3:::::3");
    gotoxy(45,21);
    printf("3333333     3:::::3");
    gotoxy(45,22);
    printf("3::::::33333::::::3");
    gotoxy(45,23);
    printf("3:::::::::::::::33");
    gotoxy(45,24);
    printf(" 333333333333333");
    hidecursor(0);

    Sleep(1000);
    system("cls");
    rectanguloGrande();
    //imprime el 2
    gotoxy(45,10);
    printf(" 222222222222222");
    gotoxy(45,11);
    printf("2:::::::::::::::22");
    gotoxy(45,12);
    printf("2::::::222222:::::2");
    gotoxy(45,13);
    printf("2222222     2:::::2");
    gotoxy(45,14);
    printf("            2:::::2");
    gotoxy(45,15);
    printf("            2:::::2");
    gotoxy(45,16);
    printf("         2222::::2 ");
    gotoxy(45,17);
    printf("    22222::::::22");
    gotoxy(45,18);
    printf("  22::::::::222");
    gotoxy(45,19);
    printf(" 2:::::22222 ");
    gotoxy(45,20);
    printf("2:::::2   ");
    gotoxy(45,21);
    printf("2:::::2 ");
    gotoxy(45,22);
    printf("2:::::2       222222");
    gotoxy(45,23);
    printf("2::::::2222222:::::2");
    gotoxy(45,24);
    printf("2::::::::::::::::::2");
    gotoxy(45,25);
    printf("22222222222222222222");
    hidecursor(0);

    Sleep(1000);
    system("cls");
    rectanguloGrande();
    //imprime el 1
    gotoxy(45,10);
    printf("  1111111");
    gotoxy(45,11);
    printf(" 1::::::1");
    gotoxy(45,12);
    printf("1:::::::1");
    gotoxy(45,13);
    printf("111:::::1");
    gotoxy(45,14);
    printf("   1::::1");
    gotoxy(45,15);
    printf("   1::::1");
    gotoxy(45,16);
    printf("   1::::1");
    gotoxy(45,17);
    printf("   1::::l");
    gotoxy(45,18);
    printf("   1::::l");
    gotoxy(45,19);
    printf("   1::::l ");
    gotoxy(45,20);
    printf("   1::::l ");
    gotoxy(45,21);
    printf("111::::::111");
    gotoxy(45,22);
    printf("1::::::::::1");
    gotoxy(45,23);
    printf("1::::::::::1");
    gotoxy(45,24);
    printf("111111111111");
    hidecursor(0);

    Sleep(1000);
    system("cls");
}

void rectanguloGrande()
{
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<110; j++)
        {
            if((i==0)||(j==0)||(j==1)||(i==39)||(j==109)||(j==108))
            {
                printf("%c",219);
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

void reiniciarMatriz(int matriz[40][110])
{
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<110; j++)
        {
            matriz[i][j]=0;
        }
    }

}

//funcion de control
void mostrarMatriz(int matriz[40][110])
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<110; j++)
        {
            printf("%d", matriz[i][j]);
            if(j == 109)
            {
                printf("\n");
            }
        }
    }
}

void pasarValidosMatriz(int matriz[40][110], Coordenada mapa[], int validosMapa)
{
    int mX;
    int mY;
    for(int i=0; i<validosMapa; i++)
    {
        mX = mapa[i].x;
        mY = mapa[i].y;
        matriz[mY][mX]=-1;//hay un muro
    }
}

int verificaMovimiento(int matriz[40][110], int x, int y)
{
    int rta=0;
    if((matriz[y][x] == -1)||(matriz[y][x+1] == -1)||(matriz[y+1][x] == -1)||(matriz[y+1][x+1] == -1))
    {
        rta=-1;//no se puede mover ahi
    }

    return rta;
}

///devuelve el puntaje, si perdio el puntaje es 0
int juegaNivel(Mapa mapita, int nivel, int matriz[40][110], int puntajeTotal)
{
    int x=2;
    int y=7;
    int anteX=x;
    int anteY=y;
    char c=0;
    int tiempo = 0;
    int tiempoAux = mapita.tiempo;
    int puntaje;
    int llego=0;

    hidecursor(0);//oculta el cursor
    //printf("%d validos\n", mapita.validosMuro);
    //system("pause");

    imprimirTituloNivel(nivel, mapita.colorMapa, puntajeTotal);
    imprimirLimites(mapita.colorMapa);//imprime el mapa una vez
    mostrarMapa(mapita.muro, mapita.validosMuro, mapita.colorMapa);
    imprimirSalida(mapita.fin);
    ///imprimir mapa --------------------------------------------------------------------------------
    imprimirJugador(x,y, anteX,anteY);

    ///el loop tiene que ser hasta que se acaba el tiempo (devuelve 0) o llegue al destino
    do
    {
        //c=verificarMovimiento(c,x,y);//verifica que el jugador se mueva en una posicion valida, sino devuelve 00
        hidecursor(0);


        if(GetAsyncKeyState(0X26)||GetAsyncKeyState(87))//Flecha ↑ o letra 'w'
        {
            if((y>7)&&(verificaMovimiento(matriz,x,y-1)!=-1))
            {
                y--;
                imprimirJugador(x,y,anteX,anteY);
                anteY=y;
                llego=verificaSalida(mapita.fin,x,y);
            }
        }
        if(GetAsyncKeyState(0X25)||GetAsyncKeyState(65))//Flecha ← o letra 'a'
        {
            if((x>2)&&(verificaMovimiento(matriz,x-2,y)!=-1))
            {
                x-=2;
                imprimirJugador(x,y,anteX,anteY);
                anteX=x;
                llego=verificaSalida(mapita.fin,x,y);
            }
        }
        if(GetAsyncKeyState(0X27)||GetAsyncKeyState(68))//Flecha → o letra 'd'
        {
            if((x<106)&&(verificaMovimiento(matriz,x+2,y)!=-1))
            {
                x+=2;
                imprimirJugador(x,y,anteX,anteY);
                anteX=x;
                llego=verificaSalida(mapita.fin,x,y);
            }
        }
        if(GetAsyncKeyState(0X28)||GetAsyncKeyState(83))//Flecha ↓ o letra 's'
        {
            if((y<33)&&(verificaMovimiento(matriz,x,y+1)!=-1))
            {
                y++;
                imprimirJugador(x,y,anteX,anteY);
                anteY=y;
                llego=verificaSalida(mapita.fin,x,y);
            }
        }
        Sleep(150);//frena el programa para dar sensación de movimiento

        cronometro(&tiempo, &tiempoAux, mapita.colorMapa);//Disminuye el cronometro al cabo de 1 segundo aprox

        }while((tiempoAux != 0)&&(llego == 0));

        puntaje = tiempoAux;

    return puntaje;
}

int verificaSalida(Coordenada salida, int x, int y)
{
    int rta=0;

    if(((salida.x==x)&&(salida.y==y))||((salida.x==x+1)&&(salida.y==y))||((salida.x==x)&&(salida.y==y+1))||((salida.x==x+1)&&(salida.y==y+1)))
    {
        rta = 1;//encontro la salida
    }

    return rta;
}

void imprimirSalida(Coordenada salida)
{
    color(15);
    gotoxy(salida.x,salida.y);
    printf("%c%c",219,219);

}

void cronometro(int* tiempoTotal, int* tiempoAux, int colorMapa)
{
    (*tiempoTotal) = (*tiempoTotal)+150;

    if((*tiempoTotal)==1050) //Al cabo de un segundo aprox
    {
        if((*tiempoAux)>0)//Si todavia hay tiempo
        {
            (*tiempoAux)--;//Disminuye el tiempo restante en uno
            gotoxy(85,3);//Lo posiciona en pantalla
            color(colorMapa);
            printf("Tiempo restante: %.2d",(*tiempoAux));//Lo muestra (solo dos digitos)
            }
        (*tiempoTotal)=0;//Setea la variable auxiliar nuevamnte
    }
}

void imprimirJugador(int x, int y, int anteX, int anteY)
{
    color(8);//color del jugador

    //me posiciono en la posicion 'actual' del jugador y lo 'borro'
    gotoxy(anteX,anteY);
    printf("  \n");
    gotoxy(anteX,anteY+1);
    printf("  \n");

    //mover el jugador a la nueva posicion
    gotoxy(x,y);
    printf("%c%c\n", 219, 219);
    gotoxy(x,y+1);
    printf("%c%c\n", 217,192);

}

void imprimirLimites(int colorMapa)
{
    gotoxy(0,6);
    color(colorMapa);
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


void imprimirTituloNivel(int nivel, int colorMapa, int puntaje)
{
    color(colorMapa);
    imprimirRectangulo();

    gotoxy(50,3);
    printf("Puntaje: %d", puntaje);

    switch(nivel)
    {
        case 1:
            gotoxy(2,1);
            printf("  _  _  _            _    _ \n");
            gotoxy(2,2);
            printf(" | \\| |(_)__ __ ___ | |  / |\n");
            gotoxy(2,3);
            printf(" | .` || |\\ V // -_)| |  | |\n");
            gotoxy(2,4);
            printf(" |_|\\_||_| \\_/ \\___||_|  |_|\n");
            break;

        case 2:
            gotoxy(2,1);
            printf("  _  _  _            _    ___ \n");
            gotoxy(2,2);
            printf(" | \\| |(_)__ __ ___ | |  |_  ) \n");
            gotoxy(2,3);
            printf(" | .` || |\\ V // -_)| |   / /\n");
            gotoxy(2,4);
            printf(" |_|\\_||_| \\_/ \\___||_|  /___|\n");
            break;
    }

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


void archivoAfila(FilaNivel* filita, char archi[])
{
    FILE* buffer;
    Mapa mapita;
    NodoNivel* aux;
    buffer = fopen(archi, "rb");//abro el archivo en modo lectura

    if(buffer != NULL)
    {
        while(fread(&mapita,sizeof(Mapa),1,buffer)>0)
        {
            //voy creando nodos y agregandolos a la lista
            aux = crearNodoMapa(mapita);
            agregarFinalFila(filita,aux);
        }
    }

    fclose(buffer);//cierro el archivo
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

/**
void mapaNivel1()
{
    Coordenada muro[MAX]; //cant de filas en el mapa --- tal vez hacer arreglo dinamico
    switch(num)
    {
        case 1:
            for(int i=0; i<FILAS; i++)
            {
                //agrego en la posicion de la fila los ejes Y
            }
            break;
    }
}
**/
