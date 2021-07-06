#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "list.h"
#include "treemap.h"

typedef struct Elemento Elemento;

typedef struct Tablero Tablero;

typedef struct Usuario Usuario;

void menu();

void instrucciones();

void mostrar_puntajes(TreeMap *puntajes);

Elemento** crearTablero(char* valor, int columnas, int fila);

void muestraTablero(Elemento** tablero,int fila, int columna);

void seedRand();

int numAleatorio(int min, int max);

Tablero* inicializarTablero(Tablero* tablero);

void comenzarJuego(Tablero* tablero, int columnas, int filas, int bombas);

void seleccionarDificultad(Tablero* tablero);

void secuenciaPrograma(Tablero* tablero);

void guardarPartida(Tablero* tablero, int fila, int columna);

void cargarPartida(Tablero* tablero);

void InsertarPistas(Elemento** tablero,int columna, int fila);

Elemento** InsertarBombas(Elemento** tablero,int cantidadBombas, int columna, int fila);

#endif /* FUNCTIONS_H */