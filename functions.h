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

Tablero* inicializarTablero(Tablero* tablero);

void seleccionarDificultad(Tablero* tablero);

void comenzarJuego(Tablero* tablero);

void secuenciaPrograma(Tablero* tablero);

#endif /* FUNCTIONS_H */