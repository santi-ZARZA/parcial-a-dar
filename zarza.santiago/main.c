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
    int PrimerBandera = 0;
    int SegundaBandera = 0;

    FILE* archivo;
    ArrayList* lista_trabajadores = al_newArrayList();
    ArrayList* lista_salida;
    eTrabajador* trabajador;


    do
    {
        system("cls");
        printf("1- Cargar trabajadores\n");
        printf("2- filtrar trabajadores\n");
        printf("3- alta trabajador\n");
        printf("4- baja trabajador\n");
        printf("5- modificar empleo\n");
        printf("6- mostrar trabajadores\n");
        printf("7- listra filtrada\n");
        printf("8- Salir\n");
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
                    PrimerBandera = 1;
                }
                break;
            case '2':
                if(PrimerBandera == 1)
                {
                   if((lista_salida = filtrar(lista_trabajadores))!= NULL)
                    {
                        system("cls");
                        printf("se filtro exitosamente.\n\n");
                        mostrar(lista_salida);
                        system("pause");
                        SegundaBandera = 1;
                    }
                }

                break;
            case '3':
                if(alta(lista_trabajadores,trabajador))
                {
                    system("cls");
                    printf("carga exitosa\n");
                    system("pause");
                    PrimerBandera = 1;
                }
                else
                {
                    system("cls");
                    printf("carga Fallida\n");
                    system("pause");
                }
                break;
            case '4':
                if(baja(lista_trabajadores,trabajador) == 1)
                {
                    system("cls");
                    printf("Se a borrado con exito los datos del trabajador.\n");
                    system("pause");
                }
                break;
            case '5':
                modificar(lista_trabajadores,trabajador);
                break;
            case '6':
                if(PrimerBandera == 1)
                {
                    system("cls");
                    mostrar(lista_trabajadores);
                    system("pause");
                }
                break;
            case '7':
                if(SegundaBandera == 1)
                {
                    if(archivo_salida(lista_salida,archivo)== 1)
                    {
                        system("cls");
                        printf("se creo el archivo exitosamente.\n\n");
                        system("pause");
                    }
                }
                else
                {
                    system("cls");
                    printf("No se a filtrado a ningun trabajador\n");
                    system("pause");
                }

                break;
            case '8':
                continuacion = 0;
                break;
            default:
                printf("\n\nOpcion invalida.\n");
                system("pause");
        }

    }while(continuacion == 1);



    return 0;
}
