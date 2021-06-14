#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct {
    char valor;
    int coordenadas[2];
}Elemento;

List* crearTablero(char* valor, int columnas, int fila){
    int i,j;
    fila += 4;
    columnas+=11;
    List* tablero = createList(); 
    for( i=0;i<fila;i++){
        List* filas = createList();
        for( j=0;j<columnas;j++){
            Elemento* elemento = (Elemento*)calloc(1,sizeof(Elemento));
            if (i == 0 && j == 0)
                pushBack(filas," ");
            else if (i == 0 && j == 3)
                pushBack(filas,"1");
            else if (i == 0 && j == 6)
                pushBack(filas,"2");
            else if (i == 0 && j == 9)
                pushBack(filas,"3");
            else if (i == 0 && j == 12)
                pushBack(filas,"4");
            else if (i == 0 && j == 15)
                pushBack(filas,"5");
            else if (i == 0 && j == 18)
                pushBack(filas,"6");
            else if (i == 0 && j == 21)
                pushBack(filas,"7");
            else if (i == 0&& j == 24)
                pushBack(filas,"8");
            else if (i == 0&& j == 27)
                pushBack(filas,"9");
            else if (i == 0&& j == 30)
                pushBack(filas,"10");
            else if (i == 0 &&j == 32)
                pushBack(filas,"11");
            else if (i == 0 &&j == 36)
                pushBack(filas,"12");
            else if (i == 0 && j == 38)
                pushBack(filas,"13");
            else if (i == 0 && j == 42)
                pushBack(filas,"14");
            else if (i == 0 && j == 44)
                pushBack(filas,"15");
            else if (i == 0 && j == 48)
                pushBack(filas,"16");
            else if (i == 0 && j == 50)
                pushBack(filas,"17");
            else if (i == 0 && j == 54)
                pushBack(filas,"18");
            else if (i == 0 && j == 56)
                pushBack(filas,"19");
            else if (i == 0 && j == 60)
                pushBack(filas,"20");
            else if (i == 0 && j == 62)
                pushBack(filas,"21");
            else if (i == 0 && j == 66)
                pushBack(filas,"22");
            else if (i == 0 && j == 68)
                pushBack(filas,"23");
            else if (i == 0 && j == 72)
                pushBack(filas,"24");
            else if (i == 0 && j == 74)
                pushBack(filas,"25");
            else if (i == 0 && j == 78)
                pushBack(filas,"26");
            else if (i == 1 && j == 0)
                pushBack(filas,"A");
            else if (i == 2 && j == 0)
                pushBack(filas,"B");
            else if (i == 3 && j == 0)
                pushBack(filas,"C");
            else if (i == 4 && j == 0)
                pushBack(filas,"D");
            else if (i == 5 && j == 0)
                pushBack(filas,"E");
            else if (i == 6 && j == 0)
                pushBack(filas,"F");
            else if (i == 7 && j == 0)
                pushBack(filas,"G");
            else if (i == 8 && j == 0)
                pushBack(filas,"H");
            else if (i == 9 && j == 0)
                pushBack(filas,"I");
            else if (i == 10&&  j == 0)
                pushBack(filas,"J");
            else if (i == 11&&  j == 0)
                pushBack(filas,"K");
            else if (i == 12&&  j == 0)
                pushBack(filas,"L");
            else if (i == 13&&  j == 0)
                pushBack(filas,"M");
            else if (i == 14&&  j == 0)
                pushBack(filas,"N");
            else if (i == 15&&  j == 0)
                pushBack(filas,"O");
            else if (i == 16&&  j == 0)
                pushBack(filas,"P");
            else if (i == 17 && j == 0)
                pushBack(filas,"Q");
            else if (i == 18 && j == 0)
                pushBack(filas,"R");
            else if (i == 19 && j == 0)
                pushBack(filas,"S");
            else if (i == 20 && j == 0)
                pushBack(filas,"T");
            else if (i == 21 && j == 0)
                pushBack(filas,"U");
            else if (i == 22 && j == 0)
                pushBack(filas,"V");
            else if (i == 23 && j == 0)
                pushBack(filas,"W");
            else if (i == 24 && j == 0)
                pushBack(filas,"X");
            else if (i == 25 && j == 0)
                pushBack(filas,"Y");
            else if (i == 26 && j == 0)
                pushBack(filas,"Z");
            else{
                if ((j%3)!=0 || j>79)
                    pushBack(filas," ");
                else if (i>0)
                    pushBack(filas,valor);
            }
        }
        pushBack(tablero,filas);
    }
        
            
    return tablero;
}

void muestraTablero(List* tablero){
    List* fila;
    fila = firstList(tablero);
    while(fila){
        char* elem;
        elem = firstList(fila);
        while(elem){
            printf("%s ",elem);
            elem = nextList(fila);
        }
        fila = nextList(tablero);
        printf("\n");
    }
}
    