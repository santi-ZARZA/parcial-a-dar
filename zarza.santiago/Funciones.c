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


                    al_add(lista,trabajador);
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
            printf("ALUMNOS\n");
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
