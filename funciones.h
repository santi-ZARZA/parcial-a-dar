#define MAX_CLIENTES 10
#define MAX_EQUIPOS 30
#define EQUIPO_MESCLADORA 1
#define EQUIPO_AMOLADORA 2
#define EQUIPO_TALADRO 3
#define ALQUILADO 1
#define FINALIZADO 0



typedef struct
{
    int ID;
    int DNI;
    char nombre[50];
    char apellido[50];
    int contador;
    int estado;

}eCliente;

typedef struct
{
    int CLIENTE;
    int EQUIPO;
    float tiempoestimado;
    float tiempodevuelto;
    char operador[50];
    int estado;

}eEquipo;

void setearestados(eCliente [],eEquipo []);

int lugarlibreUsuario(eCliente []);

int buscoIDCliente(eCliente [], int);

int buscoIDEquipo(eEquipo [], int);



void altaCliente(eCliente [],eEquipo []);

void bajaCliente(eCliente [],eEquipo []);

void modificarCliente(eCliente []);

void findelalquiler(eCliente [],eEquipo []);

void Informar(eCliente [],eEquipo []);

void NuevoAlquiler(eEquipo [], eCliente []);

void jarcodeo(eCliente [],eEquipo []);

void todoslosclientesconalquileres(eEquipo [],eCliente []);

void clienteconmasalquileres(eCliente [],eEquipo []);

void equiposmasalquilados(eCliente [],eEquipo []);

void tiempopromediorealdelosequipos(eCliente [],eEquipo []);
