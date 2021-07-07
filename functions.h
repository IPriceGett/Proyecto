#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "treemap.h"

typedef struct Elemento Elemento;

typedef struct Tablero Tablero;

typedef struct Usuario Usuario;

/* Muestra el menu principal del programa, con las funcionalidades que contiene. */
void menu();

/* Esta funcion muestra las instrucciones por pantalla, en el caso que el usuario no tenga conocimientos sobre el juego. */
void instrucciones();

/*
 * Funcion que muestra los puntajes guardados por el usuario, ordenador de menor a meyor.
 * El puntaje es el tiempo que demoró en ganar una partida.
 */
void mostrar_puntajes(TreeMap *puntajes);

/*
 * Funcion que crea un tablero respecto a las columnas y filas dadas. Para crear el tablero visible y el oculto
 * se llama a esta funcion.
 */
Elemento** crearTablero(char* valor, int columnas, int fila);

/*
 * Funcion que muestra el tablero visible por pantalla y se actualiza cada vez que el usuario
 * seleccione una casilla.
 */
void muestraTablero(Elemento** tablero,int fila, int columna);

/* Se inicializa la semilla para la funcion 'srand' */
void seedRand();

/* Genera un numero aleatorio entre un rango minimo y maximo */
int numAleatorio(int min, int max);

/* Se inicializan los tableros, ya sea el visible y el oculto, con el fin de comenzar el juego. */
Tablero* inicializarTablero(Tablero* tablero);

/*
 * Funcion para comenzar el juego y lo personaliza como lo desea el usuario. Se configura
 * el tiempo para jugar, ya sea limitado o iliminado, tambien se guarda la partida
 * si lo desea el usuario y una vez ganado el juego, si se desea se guarda el puntaje.
 */
void comenzarJuego(Tablero* tablero, TreeMap *puntajes, int columnas, int filas, int bombas);

/*
 * Funcion para seleccionar la dificultad, sea esta Principiante, Intermedio, Experto,
 * Aleatorio o Personalizado.
 * */
void seleccionarDificultad(Tablero* tablero, TreeMap *puntajes);

/* Funcion para comenzar con la configuracion del juego. */
void secuenciaPrograma(Tablero* tablero, TreeMap *puntajes);

/*
 * Una vez que se presione la opcion '2' mientras el usuario esté en partida, se llama a esta
 * funcion y se guarda la partida en curso. Esto no incluye guardar el tiempo/puntaje que lleve el usuario.
 */
void guardarPartida(Tablero* tablero, int fila, int columna);

/* Fucion que carga la partida presionando la opcion '3' del menu principal. */
void cargarPartida(Tablero* tablero, TreeMap *puntajes);

/*
 * Inserta las pistas en el tablero oculto, siendo las pistas la cantidad de bombas
 * que contiene una casilla a su alrededor.
 */
void InsertarPistas(Elemento** tablero,int columna, int fila);

/* Inserta las bombas en el tablero oculto, de acuerdo con la cantidad de bombas dadas. */
Elemento** InsertarBombas(Elemento** tablero,int cantidadBombas, int columna, int fila);

#endif /* FUNCTIONS_H */