#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Funciones.h"
#include "ArrayList.h"


int funcionquefiltra(void* item)
{
    int retorno = 0;
    eTrabajador* auxiliar;

        if(item != NULL)
        {
            auxiliar = (eTrabajador*) item;

            if(auxiliar->edad > 30 && strcmp(auxiliar->profesion,"Programador")== 0)
            {
                retorno = 1;
            }
        }

    return retorno;
}

int Lectuta(ArrayList* lista,eTrabajador* trabajador, FILE* archivo)
{
    int retorno = 0;

    char identificador[2],nombresyapellidos[20],profesion[20],edad[20];

        archivo = fopen("empleados.csv","r");

        if(archivo != NULL && lista != NULL)
        {
            while(!feof(archivo))
            {
                trabajador = newTrabajador();
                if(trabajador != NULL)
                {
                    fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",identificador,nombresyapellidos,profesion,edad);

                    trabajador->id = atoi(identificador);
                    strcpy(trabajador->nombreyapellido,nombresyapellidos);
                    strcpy(trabajador->profesion,profesion);
                    trabajador->edad = atoi(edad);


                    lista->add(lista,trabajador);
                }
                else
                {
                    retorno = -1;
                }
            }
        }
        else
        {
            retorno = -1;
        }

        fclose(archivo);


    return retorno;
}

eTrabajador* newTrabajador()
{
    eTrabajador* Auxiliar;
    eTrabajador* retorno = NULL;

        Auxiliar = (eTrabajador*) malloc(sizeof(eTrabajador));
        if(Auxiliar != NULL)
        {
            retorno = Auxiliar;
        }


    return  retorno;
}

ArrayList* filtrar(ArrayList* lista)
{
    ArrayList* auxiliar = NULL;
    int i;

        if(lista != NULL)
        {
            if(al_isEmpty(lista) == 0)
            {
                auxiliar = al_filter(lista,funcionquefiltra);
            }
        }
    return auxiliar;
}

void mostrar(ArrayList* lista)
{
    int i;
    eTrabajador* aux;

    if(lista != NULL)
    {
        if(al_isEmpty(lista)== 0)
        {
            system("cls");
            printf("TRABAJADORES\n");
            printf("----------------------------------------------------\n\n");
            for(i=0;i<al_len(lista);i++)
            {
                aux = (eTrabajador*) al_get(lista,i);

                    printf("id: %d nombre y apellido : %s trabajo: %s edad: %d\n",aux->id,aux->nombreyapellido,aux->profesion,aux->edad);
                    printf("----------------------------------------------------\n");
            }

        }
        else
        {
            system("cls");
            printf("\nno hay alumnos que Mostrar.\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("\nhubo un error.\n");
        system("pause");
    }
}

void cambiarNota(ArrayList* lista)
{
//    eAlumno* auxliar;
//    int nota1,nota2;
//    int opcion;
//    char opcion2;
//    int i;
//
//        if(lista != NULL)
//        {
//             system("cls");
//            printf("ALUMNOS\n");
//            printf("----------------------------------------------------\n\n");
//            for(i=0;i<al_len(lista);i++)
//            {
//                auxliar = (eAlumno*) al_get(lista,i);
//
//                printf("[%d]--> Nombre: %s  Apellido: %s \n",i,auxliar->Nombre,auxliar->apellido);
//                printf("----------------------------------------------------\n");
//            }
//            printf("\nIngrese la Posicion de el alumno a cambiar nota\as : ");
//            scanf("%d",&opcion);
//
//            auxliar = (eAlumno*) al_pop(lista,opcion);
//
//            system("cls");
//            printf("%s      %s\n\n",auxliar->Nombre,auxliar->apellido);
//            printf("1- cambiar Nota parcial 1\n");
//            printf("2- cambiar Nota parcial 2\n");
//            printf("3- cambiar notas parciales\n");
//            opcion2 = getch();
//
//            switch(opcion2)
//            {
//                case '1':
//                    system("cls");
//                    printf("ingrese la nueva nota del alumno: ");
//                    scanf("%d",&nota1);
//
//                    auxliar->nota_1 = nota1;
//
//                    al_push(lista,opcion,auxliar);
//                    break;
//                case '2':
//                    system("cls");
//                    printf("ingrese la nueva nota del alumno: ");
//                    scanf("%d",&nota2);
//
//                    auxliar->nota_2 = nota2;
//
//                    al_push(lista,opcion,auxliar);
//                    break;
//                case '3':
//                    system("cls");
//                    printf("ingrese la 1° nueva nota del alumno: ");
//                    scanf("%d",&nota1);
//                    printf("ingrese la 2° nueva nota del alumno: ");
//                    scanf("%d",&nota2);
//
//                    auxliar->nota_1 = nota1;
//                    auxliar->nota_2 = nota2;
//
//                    al_push(lista,opcion,auxliar);
//                    break;
//                default:
//                    printf("\n\nopcion ingresada invalida\n\n");
//            }
//
//
//        }
}

int archivo_salida(ArrayList* lista,FILE* archivo)
{
    int i;
    int salida = 0;
    ///int cont = 0;

    eTrabajador* auxiliar;

        if(lista != NULL)
        {
            archivo = fopen("out.csv","w");
            if(archivo != NULL)
            {
                for(i=0;i<al_len(lista);i++)
                {
                    auxiliar = (eTrabajador*) al_get(lista,i);

                    fprintf(archivo,"%d,%s,%s,%d\n",auxiliar->id,auxiliar->nombreyapellido,auxiliar->profesion,auxiliar->edad);
                    salida = 1;
                }
            }
            fclose(archivo);

        }

    return salida;
}

int alta(ArrayList* lista,eTrabajador* trabajador)
{
    int retorno = 0;

    int auxID;
    char auxNombre[20];
    char auxApellido[20];
    char auxEmpleo[30];
    int auxEdad;


        trabajador = newTrabajador();

        if(lista != NULL && trabajador != NULL)
        {
            system("cls");
            fflush(stdin);
            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(auxNombre);
            printf("ingrese su apellido: ");
            fflush(stdin);
            gets(auxApellido);
            printf("ingrese su edad: ");
            scanf("%d",&auxEdad);
            printf("ingrese su profesion: ");
            fflush(stdin);
            gets(auxEmpleo);

                if(lista->isEmpty(lista) == 0)
                {
                    auxID = lista->len(lista)+1;
                }
                else
                {
                    if(lista->isEmpty(lista) == 1)
                    {
                        auxID = lista->isEmpty(lista)+16;
                    }
                }

            setearDatos(trabajador,auxID,auxNombre,auxApellido,auxEmpleo,auxEdad);

            lista->add(lista,trabajador);

            retorno = 1;

        }

    return retorno;
}

/*eTrabajador**/ void setearDatos(eTrabajador* trabajador,int ID,char* nombre,char* apellido,char* profesion,int edad)
{
    ///int retorno = 0;

            trabajador->id = ID;
            strcpy(trabajador->nombreyapellido,nombre);
            strcat(trabajador->nombreyapellido," ");
            strcat(trabajador->nombreyapellido,apellido);
            strcpy(trabajador->profesion,profesion);
            trabajador = Mayuscula(trabajador);
            trabajador->edad = edad;

    ///return trabajador;
}

eTrabajador* Mayuscula(eTrabajador* trabajador)
{
    ///int i;
    ///char auxiliar[30];

        ///strcpy(auxiliar,trabajador->profesion);

        if(strcmp(trabajador->profesion,"programador")== 0)
        {
            strcpy(trabajador->profesion,"Programador");
        }


    return trabajador;
}

int baja(ArrayList* lista,eTrabajador* trabajador)
{
    int retorno = -1;
    int AuxId;
    char opcion;
    int continuacion = 1;
    int comprobante = 1;

    int posicion;

        if(lista != NULL && trabajador != NULL)
        {
            do
            {
                system("cls");
                mostrar(lista);
                printf("\nIngrese el ID del trabajador a Borrar: ");
                scanf("%d",&AuxId);

                posicion = posicionTrabajador(lista,AuxId);

                if(posicion != -1)
                {
                    trabajador = (eTrabajador*) lista->get(lista,posicion);
                    do
                    {
                        system("cls");
                        printf("||ID: %d ||Nombre y Apellido: %s ||Trabajo: %s ||Edad: %d\n\n",trabajador->id,trabajador->nombreyapellido,trabajador->profesion,trabajador->edad);
                        printf("Desea continuar? (S/N)");
                        opcion = tolower(getch());

                        switch(opcion)
                        {
                            case 's':
                                if(!lista->remove(lista,lista->indexOf(lista,trabajador)))
                                {
                                    system("cls");
                                    printf("se a borrado con exito.\n");
                                    system("pause");
                                    comprobante = 0;
                                    continuacion = 0;
                                    retorno = 1;
                                }
                                else
                                {
                                    system("cls");
                                    printf("se a producido un error por lo cual no se a podido borrar el dato.\n");
                                    system("pause");
                                    comprobante = 0;
                                    continuacion = 0;
                                    retorno = 1;
                                }
                                break;
                            case 'n':
                                system("cls");
                                printf("Se a cancelado la operacion.\n");
                                system("pause");
                                comprobante = 0;
                                break;
                            default:
                                printf("\n\n La opcion ingresada es invalida Por Favor reingrese.\n\n");
                                system("pause");
                            }
                    }while(comprobante == 1);
                }
                else
                {
                    system("cls");
                    printf("El ID ingresado es invalido, Por Favor Reingrese.\n");
                    system("pause");
                }

            }while(continuacion == 1);

        }
        else
        {
            system("cls");
            printf("Se a producido un error por lo cual no se puede acceder a la opcion.\n");
            system("pause");
        }

    return retorno;
}

int posicionTrabajador(ArrayList* lista,int id)
{
    int Retorno = -1;
    eTrabajador* trabajador = NULL;
    int i;

        if(lista != NULL )
        {
                for(i=0;i<lista->len(lista);i++)
                {
                    trabajador = (eTrabajador*) lista->get(lista,i);

                        if(trabajador->id == id)
                        {
                            Retorno = i;
                            break;
                        }
                }
        }

    return Retorno;
}

int modificar(ArrayList* lista,eTrabajador* trabajador)
{
    int retorno = 0;
    char NewEmpleo[50];

    int AuxId;
    char opcion;
    int continuacion = 1;
    int comprobante = 1;

    int posicion;

        if(lista != NULL && trabajador != NULL)
        {
            do
            {
                system("cls");
                mostrar(lista);
                printf("\nIngrese el ID del trabajador a Modificar: ");
                scanf("%d",&AuxId);

                posicion = posicionTrabajador(lista,AuxId);

                if(posicion != -1)
                {
                    trabajador = (eTrabajador*) lista->get(lista,posicion);
                    do
                    {
                        system("cls");
                        printf("||ID: %d ||Nombre y Apellido: %s ||Trabajo: %s ||Edad: %d\n\n",trabajador->id,trabajador->nombreyapellido,trabajador->profesion,trabajador->edad);
                        printf("Desea continuar? (S/N)");
                        opcion = tolower(getch());

                        switch(opcion)
                        {
                            case 's':
                                system("cls");
                                printf("Ingrese el Nuevo empleo: ");
                                fflush(stdin);
                                gets(NewEmpleo);

                                strcpy(trabajador->profesion,NewEmpleo);
                                system("cls");
                                printf("carga exitosa.\n\n");
                                printf("ID: %d  Nombre y Apellido: %s  Profesion: %s  Edad: %d\n\n",trabajador->id,trabajador->nombreyapellido,trabajador->profesion,trabajador->edad);
                                system("pause");
                                comprobante = 0;
                                continuacion = 0;
                                retorno = 1;
                                break;
                            case 'n':
                                system("cls");
                                printf("Se a cancelado la operacion.\n");
                                system("pause");
                                comprobante = 0;
                                break;
                            default:
                                printf("\n\n La opcion ingresada es invalida Por Favor reingrese.\n\n");
                                system("pause");
                            }
                    }while(comprobante == 1);
                }
                else
                {
                    system("cls");
                    printf("El ID ingresado es invalido, Por Favor Reingrese.\n");
                    system("pause");
                }

            }while(continuacion == 1);

        }
        else
        {
            system("cls");
            printf("Se a producido un error por lo cual no se puede acceder a la opcion.\n");
            system("pause");
        }

    return retorno;
}
