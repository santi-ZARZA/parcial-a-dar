#include "ArrayList.h"
#define GENERO_ACCION 1
#define GENERO_AVENTURA 2
#define GENERO_TERROR 3
#define GENERO_DEPORTE 4
#define GENERO_LOGICA 5


typedef struct
{
    int Usuario;///     El IDENTIFICADOR NUMERICO DEL USUARIO.
    char Nick[20];///    EL NOMBRE DEL JUGADOR.
    char contrasena[30];///     LA CONTRASEÑA DEL JUGADOR.
    char E_mail[35];///     EL E-MAIL DEL JUGADOR.
}eJugador;

typedef struct
{
    int Juego;///       El IDENTIFICADOR NUMERICO DEL JUEGO.
    char Nombre[30];///     NOMBRE DEL VIDEOJUEGO.
    char Desarrolladora[20];///    EL NOMBRE DE LA DESARROLLADORA DEL VIDEOJUEGO.
    int Genero;///      TIPO DE VIDEOJUEGO.
}eGame;

typedef struct
{
    int Usuario;///     El IDENTIFICADOR NUMERICO DEL USUARIO.
    int Juego;///       El IDENTIFICADOR NUMERICO DEL JUEGO.
    int Puntaje;///     PUNTAJE DADO POR JUGADOR/ES.
}eCargados;

void new_jugador(ArrayList*);

void new_game(ArrayList*);

void mostrarTodo(ArrayList*,ArrayList*,ArrayList*);

void menu();

void Modificar(ArrayList*,ArrayList*);

void Modificar_jugador(ArrayList*);

void Modificar_juego(ArrayList*);

void Baja_Jugador(ArrayList*);

void Baja_Juego(ArrayList*);

void Bajas(ArrayList*,ArrayList*);

void Baja_Jugadores(ArrayList*);

void Baja_Juegos(ArrayList*);

void Mostrar_Juegos(ArrayList*);

int Orden_General();

int Compara_juegos(void*, void*);

void Mostrar_Jugadores(ArrayList*);

int Compara_jugadores(void*, void*);

void Cargar_juego(ArrayList*,ArrayList*,ArrayList*);

void Mostrar_Juegos_Jugadores(ArrayList*,ArrayList*,ArrayList*);

void Mostrar_Jugadores_Juegos(ArrayList*,ArrayList*,ArrayList*);

void Harcodeados(ArrayList*,ArrayList*,ArrayList*);
