

void dibujar_tituloMaZe()
{
    //11
    color(11);
    gotoxy(1,5);
    printf("MMMMMMMM               MMMMMMMM                AAA                ZZZZZZZZZZZZZZZZZZZ EEEEEEEEEEEEEEEEEEEEEE");
    gotoxy(1,6);
    printf("M:::::::M             M:::::::M               A:::A               Z:::::::::::::::::Z E::::::::::::::::::::E");
    gotoxy(1,7);
    printf("M::::::::M           M::::::::M              A:::::A              Z:::::::::::::::::Z E::::::::::::::::::::E");
    gotoxy(1,8);
    printf("M:::::::::M         M:::::::::M             A:::::::A             Z:::ZZZZZZZZ:::::Z  EE::::::EEEEEEEEE::::E");
    gotoxy(1,9);
    printf("M::::::::::M       M::::::::::M            A:::::::::A            ZZZZZ   Z:::::Z     E:::::E       EEEEEE");
    gotoxy(1,10);
    printf("M:::::::::::M     M:::::::::::M           A:::::A:::::A                  Z:::::Z      E:::::E");
    gotoxy(1,11);
    printf("M:::::::M::::M   M::::M:::::::M          A:::::A A:::::A                Z:::::Z       E::::::EEEEEEEEEE");
    gotoxy(1,12);
    printf("M::::::M M::::M M::::M M::::::M         A:::::A   A:::::A              Z:::::Z        E:::::::::::::::E");
    gotoxy(1,13);
    printf("M::::::M  M::::M::::M  M::::::M        A:::::A     A:::::A            Z:::::Z         E:::::::::::::::E");
    gotoxy(1,14);
    printf("M::::::M   M:::::::M   M::::::M       A:::::AAAAAAAAA:::::A          Z:::::Z          E::::::EEEEEEEEEE");
    gotoxy(1,15);
    printf("M::::::M    M:::::M    M::::::M      A:::::::::::::::::::::A        Z:::::Z           E:::::E");
    gotoxy(1,16);
    printf("M::::::M     MMMMM     M::::::M     A:::::AAAAAAAAAAAAA:::::A     ZZZ:::::Z     ZZZZZ E:::::E       EEEEEE");
    gotoxy(1,17);
    printf("M::::::M               M::::::M    A:::::A             A:::::A    Z::::::ZZZZZZZZ:::Z EE::::::EEEEEEEE:::::E");
    gotoxy(1,18);
    printf("M::::::M               M::::::M   A:::::A               A:::::A   Z:::::::::::::::::Z E::::::::::::::::::::E");
    gotoxy(1,19);
    printf("M::::::M               M::::::M  A:::::A                 A:::::A  Z:::::::::::::::::Z E::::::::::::::::::::E");
    gotoxy(1,20);
    printf("MMMMMMMM               MMMMMMMM AAAAAAA                   AAAAAAA ZZZZZZZZZZZZZZZZZZZ EEEEEEEEEEEEEEEEEEEEEE");
    gotoxy(50,28);
    printf("By GSM %c \n",184);

}


void dibujar_lineavertical(int datX1, int datY1, int datY2)
{
    for (int i=datY1; i<datY2; i++)    ///printea una linea vertical en distinta altura.
    {
        gotoxy(datX1,i);
        printf("\263");
    }
}

void dibujar_lineahorizontal(int datX1, int datY1, int datX2, int datY2)
{

    for(int y=datY1; y<datY2; y++)
    {
        y = y + 1;
        for(int x=datX1; x<datX2; x++)
        {
            gotoxy(x,y);
            printf("\304");
        }
    }
}

void titulo_top10()
{
    gotoxy(44,0);
    printf(" _____   ___    ___      _  __        \n");
    gotoxy(44,1);
    printf("|_   _  / _ \\  | _ \\    / |/  \\    \n");
    gotoxy(44,2);
    printf("  | |  | (_) | |  _/    | | () |      \n");
    gotoxy(44,3);
    printf("  |_|   \\___/  |_|      |_|\\__/     \n");

    gotoxy(45,7);
    printf("  JUGADOR  ");
    gotoxy(65,7);
    printf("  PUNTAJE  ");


}

void dibujarCuadro(int x1,int y1,int x2,int y2)
{
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("\304"); //linea horizontal superior
        gotoxy(i,y2);
        printf("\304"); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("\263"); //linea vertical izquierda
        gotoxy(x2,i);
        printf("\263"); //linea vertical derecha
    }


    gotoxy(x1,y1);
    printf("\332");
    gotoxy(x1,y2);
    printf("\300");
    gotoxy(x2,y1);
    printf("\277");
    gotoxy(x2,y2);
    printf("\331");
}


void error()
{
    gotoxy(3,15);
    printf("EEEEEEEEEEEEEEEEEEEEEE RRRRRRRRRRRRRRRRR   RRRRRRRRRRRRRRRRR       OOOOOOOOO      RRRRRRRRRRRRRRRR   ");
    gotoxy(3,16);
    printf("E::::::::::::::::::::E R::::::::::::::::R  R::::::::::::::::R    OO:::::::::OO    R::::::::::::::::R  ");
    gotoxy(3,17);
    printf("E::::::::::::::::::::E R::::::RRRRRR:::::R R::::::RRRRRR:::::R OO:::::::::::::OO  R::::::RRRRRR:::::R ");
    gotoxy(3,18);
    printf("EE::::::EEEEEEEEE::::E RR:::::R     R:::::RRR:::::R     R:::::RO:::::::OOO:::::::ORR:::::R     R:::::R");
    gotoxy(3,19);
    printf("  E:::::E       EEEEEE  R::::R     R:::::R  R::::R     R:::::R O::::::O   O::::::O R::::R     R:::::R");
    gotoxy(3,20);
    printf("  E:::::E               R::::R     R:::::R  R::::R     R:::::R O:::::O     O:::::O R::::R     R:::::R");
    gotoxy(3,21);
    printf(  "  E::::::EEEEEEEEEE     R::::RRRRRR:::::R   R::::RRRRRR:::::R  O:::::O     O:::::O R::::RRRRRR:::::R ");
    gotoxy(3,22);
    printf("  E:::::::::::::::E     R:::::::::::::RR    R:::::::::::::RR   O:::::O     O:::::O R:::::::::::::RR  ");
    gotoxy(3,23);
    printf("  E:::::::::::::::E     R::::RRRRRR:::::R   R::::RRRRRR:::::R  O:::::O     O:::::O R::::RRRRRR:::::R  ");
    gotoxy(3,24);
    printf("  E::::::EEEEEEEEEE     R::::R     R:::::R  R::::R     R:::::R O:::::O     O:::::O R::::R     R:::::R");
    gotoxy(3,25);
    printf("  E:::::E               R::::R     R:::::R  R::::R     R:::::R O:::::O     O:::::O R::::R     R:::::R");
    gotoxy(3,26);
    printf("  E:::::E       EEEEEE  R::::R     R:::::R  R::::R     R:::::R O::::::O   O::::::O R::::R     R:::::R");
    gotoxy(3,27);
    printf("EE::::::EEEEEEEE:::::E RR:::::R     R:::::RRR:::::R     R:::::RO:::::::OOO:::::::ORR:::::R     R:::::R");
    gotoxy(3,28);
    printf("E::::::::::::::::::::E R::::::R     R:::::RR::::::R     R:::::ROO:::::::::::::OO  R::::::R     R:::::R");
    gotoxy(3,29);
    printf("E::::::::::::::::::::E R::::::R     R:::::RR::::::R     R:::::R  OO:::::::::OO    R::::::R     R:::::R");
    gotoxy(3,30);
    printf("EEEEEEEEEEEEEEEEEEEEEE RRRRRRRR     RRRRRRRRRRRRRRR     RRRRRRR    OOOOOOOOO      RRRRRRRR     RRRRRRR");
}



void titulo_analiticas()
{
    imprimirLimites(12);
    gotoxy(14,7);
    printf(" _______  __    _  _______  ___      ___   _______  ___   _______  _______  _______ ");
    gotoxy(14,8);
    printf("|   _   ||  |  | ||   _   ||   |    |   | |       ||   | |       ||   _   ||       |");
    gotoxy(14,9);
    printf("|  |_|  ||   |_| ||  |_|  ||   |    |   | |_     _||   | |       ||  |_|  ||  _____|");
    gotoxy(14,10);
    printf("|       ||       ||       ||   |    |   |   |   |  |   | |       ||       || |_____ ");
    gotoxy(14,11);
    printf("|       ||  _    ||       ||   |___ |   |   |   |  |   | |      _||       ||_____  |");
    gotoxy(14,12);
    printf("|   _   || | |   ||   _   ||       ||   |   |   |  |   | |     |_ |   _   | _____| |");
    gotoxy(14,13);
    printf("|__| |__||_|  |__||__| |__||_______||___|   |___|  |___| |_______||__| |__||_______|");
}
