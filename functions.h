#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Elemento Elemento;

typedef struct Tablero Tablero;

Elemento** crearTablero(char* valor, int columnas, int fila);

void muestraTablero(Elemento** tablero,int fila, int columna);

#endif /* FUNCTIONS_H */