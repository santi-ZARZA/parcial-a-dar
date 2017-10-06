#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

void setearestados(eCliente clientes [],eEquipo equipo [])
{
    int i;

        for(i=0;i<MAX_CLIENTES;i++)
        {
            clientes[i].estado = 0;
        }

        for(i=0;i<MAX_EQUIPOS;i++)
        {
            equipo[i].estado = 0;
        }
}

int lugarlibreCliente(eCliente clientes [])
{
    int i;
    int bandera=0;

    int devuelve;

        for(i=0;i<MAX_CLIENTES;i++)
        {
            if(clientes[i].estado == 0)
            {
                devuelve = i;
                bandera = 1;
                break;
            }
        }

    if(bandera == 0)
    {
        devuelve = -1;
    }

    return devuelve;
}

int buscoIDCliente(eCliente cliente [], int IDbuscar)
{
    int i;

    int bandera = 0;

    int devuelve;

        for(i=0;i<MAX_CLIENTES;i++)
        {
            if(IDbuscar == cliente[i].ID && cliente[i].estado == 1)
            {
                devuelve = i;
                bandera = 1;
                break;
            }
        }

    if(bandera == 0)
    {
        devuelve = -1;
    }

    return devuelve;
}

int lugarlibreEquipo(eEquipo equipo[])
{
    int i;
    int bandera=0;

    int devuelve;

        for(i=0;i<MAX_EQUIPOS;i++)
        {
            if(equipo[i].estado == 0)
            {
                devuelve = i;
                bandera = 1;
                break;
            }
        }

    if(bandera == 0)
    {
        devuelve = -1;
    }

    return devuelve;
}

int buscoIDEquipo(eEquipo equipo [], int busqueda)
{
    int i;

    int bandera = 0;

    int devuelve;

        for(i=0;i<MAX_EQUIPOS;i++)
        {
            if(busqueda == equipo[i].EQUIPO && equipo[i].estado == 1)
            {
                devuelve = i;
                bandera = 1;
                break;
            }
        }

    if(bandera == 0)
    {
        devuelve = -1;
    }

    return devuelve;
}

void altaCliente(eCliente cliente [],eEquipo equipo [])
{
    int posicion;


        system("cls");
        posicion = lugarlibreCliente(cliente);

    if(posicion != -1)
    {
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(cliente[posicion].nombre);

        printf("Ingrese el apellido del cliente: ");
        fflush(stdin);
        gets(cliente[posicion].apellido);

        printf("Ingrese el DNI del cliente: ");
        scanf("%d",&cliente[posicion].DNI);

        cliente[posicion].ID = (posicion+1000)+1000;

        cliente[posicion].estado = 1;


        printf("La carga fue exitosa:\n");
        printf("ID: %d\n",cliente[posicion].ID);
        printf("Nombre: %s\n",cliente[posicion].nombre);
        printf("Apellido: %s\n",cliente[posicion].apellido);
        printf("DNI: %d\n\n",cliente[posicion].DNI);
        system("pause");
    }
    else
    {
        printf("\nNo hay espacio para realizar la carga.\n\n");
        system("pause");
    }

}

void bajaCliente(eCliente cliente [],eEquipo equipo [])
{
    int IDbusqueda;

    int verificador;

    char seguir;

    int i;

        system("cls");
        printf("ID          CLIENTES\n\n");
        for(i=0;i<MAX_CLIENTES;i++)
        {
            if(cliente[i].estado == 1)
            {
                printf("%d",cliente[i].ID);
                printf("\t\t%s  %s\n",cliente[i].nombre,cliente[i].apellido);
            }
        }
        printf("\ningrese el ID del usuario: ");
        scanf("%d",&IDbusqueda);

        verificador = buscoIDCliente(cliente,IDbusqueda);

        if(verificador != -1)
        {
            system("cls");
            printf("ID      DNI     CLIENTE\n\n");
            printf("%d      %d      %s  %s",cliente[verificador].ID,cliente[verificador].DNI,cliente[verificador].nombre,cliente[verificador].apellido);
            printf("\n\ndesea dar de baja al cliente? (s/n): ");
            seguir = tolower(getch());

            if(seguir == 's')
            {
                for(i=0;i<MAX_EQUIPOS;i++)
                {
                    if((equipo[i].CLIENTE == cliente[verificador].ID) && equipo[i].estado == 1)
                    {
                        equipo[i].estado = 0;
                    }
                }

                cliente[verificador].estado = 0;

                printf("\nse dado de baja al cliente.\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("se a cancelado la operacion.\n\n");
                system("pause");
            }
        }
        else
        {
             system("cls");
            printf("no se a encontrado el ID de este cliente.\n\n");
            system("pause");
        }
}

void modificarCliente(eCliente cliente [])
{
    int IDbusqueda;

    int verificador;

    int opcion;

    int i;

    char auxiliar1[50];
    char auxiliar2[50];

        system("cls");
        printf("ID          CLIENTES\n\n");
        for(i=0;i<MAX_CLIENTES;i++)
        {
            if(cliente[i].estado == 1)
            {
                printf("%d",cliente[i].ID);
                printf("\t\t%s  %s\n",cliente[i].nombre,cliente[i].apellido);
            }
        }
        printf("\ningrese el ID  del usuario: ");
        scanf("%d",&IDbusqueda);

        verificador = buscoIDCliente(cliente,IDbusqueda);

        if(verificador != -1)
        {
                system("cls");

                printf("1.modificar nombre\n");
                printf("2.modificar apellido\n");
                printf("3.modificar ambos\n");
                printf("ingrese la opcion deseada: ");
                scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            system("cls");
                            printf("ingrese nuevo nombre: ");
                            fflush(stdin);
                            gets(auxiliar1);

                            strcpy(cliente[verificador].nombre,auxiliar1);
                            break;
                        case 2:
                            system("cls");
                            printf("ingrese nuevo apellido: ");
                            fflush(stdin);
                            gets(auxiliar2);

                            strcpy(cliente[verificador].apellido,auxiliar2);
                            break;
                        case 3:
                            system("cls");
                                printf("ingrese nuevo nombre: ");
                                fflush(stdin);
                                gets(auxiliar1);
                                printf("ingrese nuevo apellido: ");
                                fflush(stdin);
                                gets(auxiliar2);

                            strcpy(cliente[verificador].nombre,auxiliar1);
                            strcpy(cliente[verificador].apellido,auxiliar2);
                            break;
                        default:
                            printf("opcipn invalida.\n\n");
                            system("pause");
                    }

            }
        else
        {
             system("cls");
            printf("no se a encontrado el ID de este cliente.\n\n");
            system("pause");
        }
}

void Informar(eCliente cliente [],eEquipo equipo [])
{
    int opcion;
    int i , j;

    int verificador = 0;


    for(i=0;i<MAX_CLIENTES;i++)
    {
        for(j=0;j<MAX_EQUIPOS;j++)
        {
            if(cliente[i].estado == 1 && equipo[j].estado == 1)
            {
                verificador = 1;
                break;
            }

        }
        if(verificador == 1)
        {
            break;
        }
    }
        system("cls");

        printf("1. NOMBRE Y APELLIDO DEL ASOCIADO CON MAS ALQUILERES\n");
        printf("2. EL O LOS EQUIPO/S MAS ALQUILADO/S Y SU CANTIDAD\n");
        printf("3. EL TIEMPO PROMEDIO REAL DE ALQUILER DE LOS EQUIPOS\n");
        printf("4. TODOS LOS CLIENTES CON SUS ALQUILERES\n\n");
        printf("Ingrese la opcion deseada: ");
        scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    if(verificador != 0)
                    {
                        clienteconmasalquileres(cliente,equipo);
                    }
                    else
                    {
                        system("cls");
                        printf("no hay clientes registrados.\n\n");
                        system("pause");
                    }
                    break;
                case 2:
                    if(verificador != 0)
                    {
                        equiposmasalquilados(cliente,equipo);
                    }
                    else
                    {
                        system("cls");
                        printf("no hay clientes registrados.\n\n");
                        system("pause");
                    }
                    break;
                case 3:
                    if(verificador != 0)
                    {
                        tiempopromediorealdelosequipos(cliente,equipo);
                    }
                    else
                    {
                        system("cls");
                        printf("no hay clientes registrados.\n\n");
                        system("pause");
                    }
                    break;
                case 4:
                    if(verificador != 0)
                    {
                        todoslosclientesconalquileres(equipo,cliente);
                    }
                    else
                    {
                        system("cls");
                        printf("no hay clientes registrados.\n\n");
                        system("pause");
                    }
                    break;

            }
}

void NuevoAlquiler(eEquipo equipo[], eCliente cliente[])
{
    int IDbusqueda;

    int verificador;

    int posicion;

     int opcion;

        system("cls");

        printf("Ingrese el ID del cliente: ");
        scanf("%d",&IDbusqueda);

            verificador = buscoIDCliente(cliente,IDbusqueda);

        if(verificador != -1)
        {
            system("cls");

            posicion = lugarlibreEquipo(equipo);

            if(posicion != -1)
            {
                printf("1. MESCLADORA\n2. AMOLADORA\n3. TALADRO\n");
                printf("ingrese cual de los siguientes desea alquilar: ");
                scanf("%d", &opcion);
                    switch(opcion)
                    {
                        case 1:
                            equipo[posicion].EQUIPO = EQUIPO_MESCLADORA;
                            break;
                        case 2:
                            equipo[posicion].EQUIPO = EQUIPO_AMOLADORA;
                            break;
                        case 3:
                            equipo[posicion].EQUIPO = EQUIPO_TALADRO;
                            break;
                    }
                printf("ingrese el tiempo estimado de alquiler: ");
                scanf("%f",&equipo[posicion].tiempoestimado);

                strcpy(equipo[posicion].operador,cliente[verificador].nombre);

                equipo[posicion].CLIENTE = IDbusqueda;

                equipo[posicion].estado = ALQUILADO;

                    printf("\nEl Alquiler fue exitoso:\n");
                    printf("Cliente: %s\n",cliente[verificador].nombre);
                    switch(equipo[posicion].EQUIPO)
                    {
                        case 1:
                            printf("Equipo: MESCLADORA\n");
                            break;
                        case 2:
                            printf("Equipo: AMOLADORA\n");
                            break;
                        case 3:
                            printf("Equipo: TALADRO\n");
                            break;
                    }
                    system("pause");

            }
            else
            {
                system("cls");
                printf("no hay mas equipos que alquilar.\n\n");
                system("pause");
            }

        }
        else
        {
            system("cls");
            printf("el ID ingresado no corresponde a niingun usuario registrado.\n\n");
            system("pause");
        }
}

void jarcodeo(eCliente cliente [],eEquipo equipo [])
{
    int ID[3]={1000,1500,3000};
    int DNI[3]={4193384,1933844,3843344};
    char nombre[3][50]={"juan","carlos","maria"};
    char apellido[3][50]={"lopez","garcia","luisa"};
    int estado[3]={1,1,1};

    int CLIENTE[3]={1000,1500,3000};
    int EQUIPO[3]={1,2,3};
    float tiempoestimado[3]={12.20,13.35,23};
    char operador[3][50]={"juan","carlos","maria"};
    int estados[3]={ALQUILADO,ALQUILADO,ALQUILADO};

    int i, j;

        for(i=0;i<3;i++)
        {
            cliente[i].ID = ID[i];
            cliente[i].DNI = DNI[i];
            strcpy(cliente[i].nombre,nombre[i]);
            strcpy(cliente[i].apellido,apellido[i]);
            cliente[i].estado = estado[i];
        }
        for(j=0;j<3;j++)
        {
            equipo[j].CLIENTE = CLIENTE[j];
            equipo[j].EQUIPO = EQUIPO[j];
            equipo[j].tiempoestimado = tiempoestimado[j];
            strcpy(equipo[j].operador,operador[j]);
            equipo[j].estado = estados[j];
        }
}

void todoslosclientesconalquileres(eEquipo equipo [],eCliente cliente [])
{
    int i, j;

                        system("cls");
                        printf("ID\t\tNOMBRE Y APELLIDO\t\tEQUIPO\n\n");
                        for(i=0;i<MAX_CLIENTES;i++)
                        {
                            if(cliente[i].estado == 1)
                            {
                                printf("%d              %s %s",cliente[i].ID,cliente[i].nombre,cliente[i].apellido);

                                    for(j=0;j<MAX_EQUIPOS;j++)
                                    {
                                        if(cliente[i].ID == equipo[j].CLIENTE && equipo[j].estado == 1)
                                        {
                                            switch(equipo[j].EQUIPO)
                                            {
                                                case 1:
                                                    printf("\t\tMESCLADORA\n");
                                                    break;
                                                case 2:
                                                    printf("\t\tAMOLADORA\n");
                                                    break;
                                                case 3:
                                                    printf("\t\tTALADRO\n");
                                                    break;
                                            }
                                        }
                                    }
                                    printf("\n");
                            }
                        }
                        printf("\n\n");
                        system("pause");
}

void findelalquiler(eCliente cliente [],eEquipo equipo [])
{
    int i;

    int IDbusqueda;
    int IDbusqueda2;

    int verificador;
    int verificador2;



        system("cls");
        printf("ID      CLIENTES\n\n");
        for(i=0;i<MAX_CLIENTES;i++)
        {
            if(cliente[i].estado == 1)
            {
                printf("%d\t\t%s %s\n",cliente[i].ID,cliente[i].nombre,cliente[i].apellido);
            }
        }
        printf("\nIngrese el ID del cliente: ");
        scanf("%d",&IDbusqueda);

            verificador = buscoIDCliente(cliente,IDbusqueda);

        if(verificador != -1)
        {
            system("cls");
            printf("ID        CLIENTE\n");
            printf("%d\t\t%s %s\n",cliente[verificador].ID,cliente[verificador].nombre,cliente[verificador].apellido);
            printf("----------------------------------\n");
            printf("EQUIPOS\n\n");
            for(i=0;i<MAX_EQUIPOS;i++)
            {
                if((cliente[verificador].ID == equipo[i].CLIENTE) && equipo[i].estado == 1)
                {
                    switch(equipo[i].EQUIPO)
                    {
                        case 1:
                            printf("MESCLADORA\n");
                          break;
                        case 2:
                            printf("AMOLADORA\n");
                          break;
                        case 3:
                            printf("TALADRO\n");
                          break;
                    }
                }
            }
            printf("\n1. MESCLADORA\n2. AMOLADORA\n3. TALADRO\nIngrese el equipo a devolver: ");
            scanf("%d",&IDbusqueda2);

                verificador2 = buscoIDEquipo(equipo,IDbusqueda2);

            if(verificador2 != -1)
            {
                printf("\nIngrese el tiempo que tuvo el equipo: ");
                scanf("%f",&equipo[verificador2].tiempodevuelto);

                equipo[verificador2].estado = FINALIZADO;

                system("cls");
                printf("El alquiler del equipo a finalizado.\nGracias por alquilar el producto.\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("la opcion ingresada es incorrecta.\n\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("El ID no coincide con el de ningun usuario.\n\n");
            system("pause");
        }
}

void clienteconmasalquileres(eCliente cliente [],eEquipo equipo [])
{
   int i, j;

   int maximo;

   int bandera = 0;

   for(i=0;i<MAX_CLIENTES;i++)
   {
       cliente[i].contador = 0;
        if(cliente[i].estado == 1)
        {
            for(j=0;j<MAX_EQUIPOS;j++)
            {
                if((cliente[i].ID == equipo[j].CLIENTE) && equipo[j].estado == 1)
                {
                    cliente[i].contador++;
                }
            }
        }

        if(bandera == 0)
        {
            maximo = cliente[i].contador;
            bandera = 1;
        }
        else
        {
            if(maximo < cliente[i].contador)
            {
                maximo = cliente[i].contador;
            }
        }
   }


   system("cls");
   printf("El o los clientes con mas equipos alquilados (%d) son:\n\n",maximo);
   for(i=0;i<MAX_CLIENTES;i++)
   {
       if(maximo == cliente[i].contador)
       {
           printf("%s  %s\n\n",cliente[i].nombre,cliente[i].apellido);
       }
   }

   system("pause");

}

void equiposmasalquilados(eCliente cliente [],eEquipo equipo [])
{
   int i, j;

   int contadores[3]={0,0,0};
   char equipos[3][50]= {"MESCLADORA","AMOLADORA","TALADRO"};

   int bandera = 0;

   int maximo;

       for(j=0;j<MAX_EQUIPOS;j++)
        {
            if(equipo[j].estado == 1)
            {
                if(equipo[j].EQUIPO == EQUIPO_MESCLADORA)
                {
                    contadores[0]++;
                }
                else if(equipo[j].EQUIPO == EQUIPO_AMOLADORA)
                {
                    contadores[1]++;
                }
                else
                {
                    contadores[2]++;
                }
            }
        }

        for(i=0;i<3;i++)
        {
            if(bandera == 0)
            {
                bandera = 1;
                maximo = contadores[0];
            }
            else
            {
                if(maximo < contadores[i])
                {
                    maximo = contadores[i];
                }
            }
        }



   system("cls");
   printf("El o los equipos mas alquilados (%d) son:\n\n",maximo);
   for(i=0;i<3;i++)
   {
       if(maximo == contadores[i])
       {
           printf("%s\n",equipos[i]);
       }
   }

   printf("\n\n");
   system("pause");
}

void tiempopromediorealdelosequipos(eCliente cliente [],eEquipo equipo [])
{
    int i;

    float contadores[3]={0,0,0};
    float contador[3]={0,0,0};
    char equipos[3][50]= {"MESCLADORA","AMOLADORA","TALADRO"};
    float resultado[3]={0,0,0};

        for(i=0;i<MAX_EQUIPOS;i++)
        {
            if(equipo[i].estado == FINALIZADO)
            {
                if(equipo[i].EQUIPO == EQUIPO_MESCLADORA)
                {
                    contadores[0] += equipo[i].tiempodevuelto;
                    contador[0]++;
                }
                else if(equipo[i].EQUIPO == EQUIPO_AMOLADORA)
                {
                    contadores[1] += equipo[i].tiempodevuelto;
                    contador[1]++;
                }
                else if(equipo[i].EQUIPO == EQUIPO_TALADRO)
                {
                    contadores[2] += equipo[i].tiempodevuelto;
                    contador[2]++;
                }
            }
        }


        system("cls");


            printf("EL promedio general de alquiler de los equipos es el siguiente:\n\n");
            for(i=0;i<3;i++)
            {
                if(contadores[i] != 0 && contador[i] != 0)
                {
                    resultado[i]= contadores[i]/contador[i];

                    printf("%s          -->%.2f<--\n\n",equipos[i],resultado[i]);
                }
            }

    system("pause");
}

