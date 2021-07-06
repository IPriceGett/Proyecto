#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "list.h"
#include "treemap.h"

typedef struct Elemento Elemento;

typedef struct Tablero Tablero;

typedef struct Usuario Usuario;

void fullscreen();

void menu();

void instrucciones();

void mostrar_puntajes(TreeMap *puntajes);

Elemento** crearTablero(char* valor, int columnas, int fila);

void muestraTablero(Elemento** tablero,int fila, int columna);

void seedRand();

int numAleatorio(int min, int max);

Tablero* inicializarTablero(Tablero* tablero);

void ponerMina(Tablero** tablero, int columna, int fila);

void posMinas(Tablero** tablero, int cantMinas, int cantColumnas, int cantFilas);

void comenzarJuego(Tablero* tablero);

void seleccionarDificultad(Tablero* tablero);

void secuenciaPrograma(Tablero* tablero);

void guardarPartida(Tablero* tablero, int fila, int columna);

#endif /* FUNCTIONS_H */