#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Funciones.h"
///#include "LecturaArchivo.h"
#include "ArrayList.h"


int main()
{
    int continuacion = 1;
    char opcion;
    int bandera = 0;

    FILE* archivo;
    ArrayList* lista_trabajadores = al_newArrayList();
    ArrayList* lista_salida;
    eTrabajador* trabajador;


    do
    {
        system("cls");
        printf("1- Cargar trabajadores\n");
        printf("2- filtrar trabajadores\n");
        printf("3- listra filtrada\n");
        printf("4- Salir\n");
        printf("\nIngrese la opcion deseada: ");
        opcion = getch();

        switch(opcion)
        {
            case '1':
                if(Lectuta(lista_trabajadores,trabajador,archivo) != -1)
                {
                    system("cls");
                    printf("\nCarga exitosa\n\n");
                    mostrar(lista_trabajadores);
                    system("pause");
                    bandera = 1;
                }
                break;
            case '2':
                if(bandera == 1)
                {
                   if((lista_salida = filtrar(lista_trabajadores))!= NULL)
                    {
                        system("cls");
                        printf("se filtro exitosamente.\n\n");
                        mostrar(lista_salida);
                        system("pause");
                    }
                }

                break;
            case '3':
                if(bandera == 1)
                {
                    if(archivo_salida(lista_salida,archivo)== 1)
                    {
                        system("cls");
                        printf("se creo el archivo exitosamente.\n\n");
                        system("pause");
                    }
                }

                break;
            case '4':
                continuacion = 0;
                break;
            default:
                printf("\n\nOpcion invalida.\n");
                system("pause");
        }

    }while(continuacion == 1);



    return 0;
}
