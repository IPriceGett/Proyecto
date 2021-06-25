#include <stdio.h>
#include "list.h"
#include "functions.h"

int main(){

    Elemento** tableroVisible = crearTablero(".",30,10);
    Elemento** tableroOculto = crearTablero("*",30,10);

    int opcion;
    do{
        menu();
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
            case 1: /* Comenzar a jugar */
                muestraTablero(tableroVisible,30,10);
                printf("\nIngrese casilla: ");
                break;
            case 2: /* Mostrar instrucciones */
                break;
            case 3: /* Cargar una partida desde un punto especifico */
                break;
            case 4: /* Mostrar los mejores puntajes guardados por el usuario */
                break;
            case 5: /* Salir del programa */
                break;
            default:;
                opcion = 6;
                printf("Intentelo nuevamente.");
                getchar();
                break;
        }

    }while(opcion != 5);

    return 0;
}