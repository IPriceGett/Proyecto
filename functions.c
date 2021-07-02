#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "treemap.h"
#include "Map.h"

typedef struct {
    char* valor;
    int coordenadas[2];
    int seleccionado;
}Elemento;

typedef struct {
    Elemento** visible;
    Elemento** oculto;
}Tablero;

typedef struct {
    char *nombre_usuario;
    int tiempo;
}Usuario;

void menu(){
    printf("\n- Menu -\n");
    printf("1.- Jugar!\n");
    printf("2.- Instrucciones.\n");
    printf("3.- Cargar partida\n");
    printf("4.- Mostrar mejores puntajes\n");
    printf("5.- Salir\n\n");
    printf("Ingrese opcion: ");
}

void instrucciones(){
    printf("El juego 'Buscaminas' consiste en despejar un campo minado, sin dejar que estalle ninguna bomba:\n");
    printf("- El usuario tiene que seleccionar la casilla deseada de acuerdo con su coordenada, de la forma 'A1', \n");
    printf("siendo 'A', la fila y '1' la columna.\n");
    printf("- Al seleccionar una casilla sin bomba, esta mostrara un numero que consiste en la cantidad de bombas que\n");
    printf("contiene esa casilla a su alrededor.\n");
    printf("- En caso contrario, el usuario perdera el juego y se mostrara el tablero descubierto para visualizar\n");
    printf("donde se encontraban las demas bombas.\n");
}

void mostrar_puntajes(TreeMap *puntajes){

    Usuario *iterador = firstTreeMap(puntajes);
    if (iterador == NULL){
        printf("No hay puntajes guardados.\n");
        return;
    }

    printf("- Puntajes -");
    while(iterador){
        printf("%s: %d\n", iterador->nombre_usuario, iterador->tiempo);
    }

}

Elemento** crearTablero(char* valor, int columnas, int fila){
    int i,j;
    fila += 4;
    columnas+=11;
    Elemento** tablero = (Elemento**)calloc(fila,fila*sizeof(Elemento*)); 
    for( i=0;i<fila;i++){
        tablero[i] = (Elemento*)calloc(columnas,columnas*sizeof(Elemento));
        for( j=0;j<columnas;j++){
            if (i == 0 && j == 0)
                tablero[i][j].valor=" ";
            else if (i == 0 && j == 3)
                tablero[i][j].valor="1";
            else if (i == 0 && j == 6)
                tablero[i][j].valor="2";
            else if (i == 0 && j == 9)
                tablero[i][j].valor="3";
            else if (i == 0 && j == 12)
                tablero[i][j].valor="4";
            else if (i == 0 && j == 15)
                tablero[i][j].valor="5";
            else if (i == 0 && j == 18)
                tablero[i][j].valor="6";
            else if (i == 0 && j == 21)
                tablero[i][j].valor="7";
            else if (i == 0&& j == 24)
                tablero[i][j].valor="8";
            else if (i == 0&& j == 27)
                tablero[i][j].valor="9";
            else if (i == 0&& j == 30)
                tablero[i][j].valor="10";
            else if (i == 0 &&j == 32)
                tablero[i][j].valor="11";
            else if (i == 0 &&j == 36)
                tablero[i][j].valor="12";
            else if (i == 0 && j == 38)
                tablero[i][j].valor="13";
            else if (i == 0 && j == 42)
                tablero[i][j].valor="14";
            else if (i == 0 && j == 44)
                tablero[i][j].valor="15";
            else if (i == 0 && j == 48)
                tablero[i][j].valor="16";
            else if (i == 0 && j == 50)
                tablero[i][j].valor="17";
            else if (i == 0 && j == 54)
                tablero[i][j].valor="18";
            else if (i == 0 && j == 56)
                tablero[i][j].valor="19";
            else if (i == 0 && j == 60)
                tablero[i][j].valor="20";
            else if (i == 0 && j == 62)
                tablero[i][j].valor="21";
            else if (i == 0 && j == 66)
                tablero[i][j].valor="22";
            else if (i == 0 && j == 68)
                tablero[i][j].valor="23";
            else if (i == 0 && j == 72)
                tablero[i][j].valor="24";
            else if (i == 0 && j == 74)
                tablero[i][j].valor="25";
            else if (i == 0 && j == 78)
                tablero[i][j].valor="26";
            else if (i == 1 && j == 0)
                tablero[i][j].valor="A";
            else if (i == 2 && j == 0)
                tablero[i][j].valor="B";
            else if (i == 3 && j == 0)
                tablero[i][j].valor="C";
            else if (i == 4 && j == 0)
                tablero[i][j].valor="D";
            else if (i == 5 && j == 0)
                tablero[i][j].valor="E";
            else if (i == 6 && j == 0)
                tablero[i][j].valor="F";
            else if (i == 7 && j == 0)
                tablero[i][j].valor="G";
            else if (i == 8 && j == 0)
                tablero[i][j].valor="H";
            else if (i == 9 && j == 0)
                tablero[i][j].valor="I";
            else if (i == 10&&  j == 0)
                tablero[i][j].valor="J";
            else if (i == 11&&  j == 0)
                tablero[i][j].valor="K";
            else if (i == 12&&  j == 0)
                tablero[i][j].valor="L";
            else if (i == 13&&  j == 0)
                tablero[i][j].valor="M";
            else if (i == 14&&  j == 0)
                tablero[i][j].valor="N";
            else if (i == 15&&  j == 0)
                tablero[i][j].valor="O";
            else if (i == 16&&  j == 0)
                tablero[i][j].valor="P";
            else if (i == 17 && j == 0)
                tablero[i][j].valor="Q";
            else if (i == 18 && j == 0)
                tablero[i][j].valor="R";
            else if (i == 19 && j == 0)
                tablero[i][j].valor="S";
            else if (i == 20 && j == 0)
                tablero[i][j].valor="T";
            else if (i == 21 && j == 0)
                tablero[i][j].valor="U";
            else if (i == 22 && j == 0)
                tablero[i][j].valor="V";
            else if (i == 23 && j == 0)
                tablero[i][j].valor="W";
            else if (i == 24 && j == 0)
                tablero[i][j].valor="X";
            else if (i == 25 && j == 0)
                tablero[i][j].valor="Y";
            else if (i == 26 && j == 0)
                tablero[i][j].valor="Z";
            else{
                if ((j%3)!=0 || j>79)
                    tablero[i][j].valor=" ";
                else if (i>0)
                    tablero[i][j].valor=valor;
            }
        }
    }
        
            
    return tablero;
}

void muestraTablero(Elemento** tablero,int columna, int fila){
    for(int i = 0; i<fila;i++){
        for(int j =0;j<columna;j++){
            printf("%s ",tablero[i][j].valor);
        }
        printf("\n");
    }
}

Tablero* inicializarTablero(Tablero* tablero){
    tablero = (Tablero *) calloc (1, sizeof(Tablero));
    return tablero;
}

void seleccionarDificultad(Tablero* tablero){

    int dif;

    printf("- Dificultades -\n");
    printf("1.- Principiante (8x8 , 10 minas)\n");
    printf("2.- Intermedio (16x16 , 40 minas)\n");
    printf("3.- Experto (16x26 , 99 minas)\n");
    printf("4.- Aleatorio\n");
    printf("5.- Personalizado\n\n");
    printf("Por favor, ingrese la dificultad en la que desea jugar: ");
    scanf("%i", &dif);

    char colfilmin[50];
    char *token;
    int col, fil, min;

    switch(dif){
        case 1:
            tablero->visible = crearTablero(".", 27, 9);
            tablero->oculto = crearTablero("*", 27, 9);
            muestraTablero(tablero->visible, 27, 9);
            break;
        case 2:
            tablero->visible = crearTablero(".", 51, 17);
            tablero->oculto = crearTablero("*", 51, 17);
            muestraTablero(tablero->visible, 51, 17);
            break;
        case 3:
            tablero->visible = crearTablero(".", 51, 27);
            tablero->oculto = crearTablero("*", 51, 27);
            muestraTablero(tablero->visible, 51, 27);
            break;
        case 4: /* Generar un tablero aleatorio */
            break;
        case 5: /* Hay que definir un máximo de columnas, filas y minas. Dejarlo escrito para el usuario */
            printf("Ingrese columnas, filas y minas, respectivamente (c,f,m): ");
            scanf("%s", colfilmin);

            token = strtok(colfilmin, ",");
            col = atoi(token);
            token = strtok(NULL, ",");
            fil = atoi(token);
            token = strtok(NULL, ",");
            min = atoi(token);

            tablero->visible = crearTablero(".", ((col+1)*3), (fil+1));
            tablero->oculto = crearTablero("*", ((col+1)*3), (fil+1));
            muestraTablero(tablero->visible, ((col+1)*3), (fil+1));
            break;
        default:;
            dif = 6;
            printf("Intentelo nuevamente.");
            getchar();
            break;
    }
}