#include "ArrayList.h"
typedef struct
{
    int id;
    char nombreyapellido[50];
    char profesion[30];
    int edad;
}eTrabajador;

//typedef struct
//{
//    int Alumno;
//    int nota_1;
//    int nota_2;
//}eNotas;

int Lectuta(ArrayList*,eTrabajador*,FILE*);
ArrayList* filtrar(ArrayList*);
eTrabajador* newTrabajador();
void mostrar(ArrayList*);
//void cambiarNota(ArrayList*);
int archivo_salida(ArrayList*,FILE*);

int alta(ArrayList*,eTrabajador*);
int baja(ArrayList*,eTrabajador*);
int modificar(ArrayList*,eTrabajador*);


int posicionTrabajador(ArrayList*,int);
void setearDatos(eTrabajador*,int,char*,char*,char*,int);
eTrabajador* Mayuscula(eTrabajador*);





