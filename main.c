#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int main()
{

    eCliente clientes[MAX_CLIENTES];
    eEquipo equipos[MAX_EQUIPOS];
    int opcion;

    char seguir = 's';

    setearestados(clientes,equipos);
    jarcodeo(clientes,equipos);

    do
    {
        system("cls");
        printf("1. ALTA DE CLIENTE\n");
        printf("2. MODIFICAR DATOS DE CLIENTE\n");
        printf("3. BAJA DE CLIENTE\n");
        printf("4. NUEVO ALQUILER\n");
        printf("5. FIN ALQUILER\n");;
        printf("6. INFORMAR\n");
        printf("7. SALIR\n\n");
        printf("Ingrese una opcion:  ");
        scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    altaCliente(clientes,equipos);
                    break;
                case 2:
                    modificarCliente(clientes);
                    break;
                case 3:
                    bajaCliente(clientes,equipos);
                    break;
                case 4:
                    NuevoAlquiler(equipos,clientes);
                    break;
                case 5:
                    findelalquiler(clientes,equipos);
                    break;
                case 6:
                    Informar(clientes,equipos);
                    break;
                case 7:
                    seguir = 'n';
                    break;


            }
    }while(seguir == 's');


    return 0;
}
