#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char seguir = 's';
    char opcion;

    do
    {
        system("cls");
        printf("**---------------------------------------------------------------------------**");
        printf("\n                             MENU DE VIDEOJUEGOS             \n");
        printf("**---------------------------------------------------------------------------**");
        printf("\n\n                       Presione [Enter] para Ingresar                \n\n");
        fflush(stdin);
        opcion = getch();

        switch(opcion)
        {
            case 13:
                menu();
                break;
            default:
                while(opcion != 13)
                {
                    system("cls");
                    printf("\n\nLa opcion ingresada es invalida.\nReingrese Enter");
                    fflush(stdin);
                    opcion = getch();
                }
        }

    }while(seguir == 's');

    return 0;
}
