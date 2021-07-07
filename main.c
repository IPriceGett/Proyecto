#include <stdio.h>
#include "functions.h"
#include "treemap.h"
#include "Map.h"

double lower_than_double(void* key1, void* key2){
    double k1 = *((double*) (key1));
    double k2 = *((double*) (key2));
    return k1<k2;
}

int main(){

    seedRand();
    /* Mapa ordenado que almacena los mejores puntajes */
    TreeMap *puntajes = createTreeMap(lower_than_double);
    Tablero *tablero = inicializarTablero(tablero);
    
    int opcion;
    do{
        menu();
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
            case 1: /* Comenzar a jugar */
                secuenciaPrograma(tablero, puntajes);
                break;
            case 2: /* Mostrar instrucciones */
                instrucciones();
                break;
            case 3: /* Cargar una partida desde un punto especifico */
                cargarPartida(tablero, puntajes);
                break;
            case 4: /* Mostrar los mejores puntajes guardados por el usuario */
                mostrar_puntajes(puntajes);
                break;
            case 5: /* Salir del programa */
                break;
            default:;
                opcion = 6;
                printf("Por favor, ingrese una opcion valida.\n");
                getchar();
                printf("\nPresione ENTER para continuar.\n");
                getchar();
                break;
        }

    }while(opcion != 5);

    return 0;
}