#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Elemento Elemento;

typedef struct Tablero Tablero;

void menu();

Elemento** crearTablero(char* valor, int columnas, int fila);

void muestraTablero(Elemento** tablero,int fila, int columna);

Tablero* inicializarTablero(Tablero* tablero);

void seleccionarDificultad(Tablero* tablero);

#endif /* FUNCTIONS_H */