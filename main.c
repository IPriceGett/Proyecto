#include <stdio.h>
#include "list.h"
#include "functions.h"
#include "treemap.h"
#include "Map.h"

int lower_than_int(void* key1, void* key2){
    int k1 = *((int*) (key1));
    int k2 = *((int*) (key2));
    return k1<k2;
}

int main(){

    //fullscreen();
    /* Mapa ordenado que almacena los mejores puntajes */
    TreeMap *puntajes = createTreeMap(lower_than_int);
    /* Almacena las partidas guardadas */
    HashMap *partidas = createMap(50);
    /* Almacena el mapa de partidas guardadas por nombre de usuario */
    HashMap *usuarios = createMap(50);

    Tablero *tablero = inicializarTablero(tablero);
    
    int opcion;
    do{
        menu();
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
            case 1: /* Comenzar a jugar */
                secuenciaPrograma(tablero);
                break;
            case 2: /* Mostrar instrucciones */
                instrucciones();
                break;
            case 3: /* Cargar una partida desde un punto especifico */
                break;
            case 4: /* Mostrar los mejores puntajes guardados por el usuario */
                mostrar_puntajes(puntajes);
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