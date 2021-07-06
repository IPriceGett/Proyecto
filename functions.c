#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
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
    printf(" ________  ___  ___  ________  ________  ________  _____ ______   ___  ________   ________  ________           ___       \n");
    printf(" |\\   __  \\|\\  \\|\\  \\|\\   ____\\|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\   __  \\|\\   ____\\         |\\  \\\n");
    printf("  \\\\  \\|\\ /\\ \\  \\\\\\  \\ \\  \\___|\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\___|_        \\ \\  \\\n");
    printf("   \\\\   __  \\ \\  \\\\\\  \\ \\_____  \\ \\  \\    \\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\   __  \\ \\_____  \\        \\ \\  \\\n");
    printf("    \\\\  \\|\\  \\ \\  \\\\\\  \\|____|\\  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\|____|\\  \\        \\ \\__\\\n");
    printf("     \\\\_______\\ \\_______\\____\\_\\  \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\ \\__\\____\\_\\  \\        \\|__|\n");
    printf("      \\|_______|\\|_______|\\_________\\|_______|\\|__|\\|__|\\|__|     \\|__|\\|__|\\|__| \\|__|\\|__|\\|__|\\_________\\           ___ \n");
    printf("                         \\|_________|                                                           \\|_________|          |\\__\\\n");
    printf("                                                                                                                      \\|__|\n");
    printf("1.- Jugar!\n");
    printf("2.- Instrucciones.\n");
    printf("3.- Cargar partida\n");
    printf("4.- Mostrar mejores puntajes\n");
    printf("5.- Salir\n\n");
    printf("Ingrese opcion: ");
}

void instrucciones(){
    printf("El juego 'Buscaminas' consiste en despejar un campo minado, sin dejar que estalle ninguna bomba:\n\n");
    printf("- El usuario tiene que seleccionar la casilla deseada de acuerdo con su coordenada, de la forma 'A1', \n");
    printf("  siendo 'A', la fila y '1' la columna.\n");
    printf("- Al seleccionar una casilla sin bomba, esta mostrara un numero que consiste en la cantidad de bombas que\n");
    printf("  contiene esa casilla a su alrededor.\n");
    printf("- En caso contrario, el usuario perdera el juego y se mostrara el tablero descubierto para visualizar\n");
    printf("  donde se encontraban las demas bombas.\n\n");
    getchar();
    printf("Presione ENTER para continuar.");
    getchar();
}

void mostrar_puntajes(TreeMap *puntajes){

    Usuario *iterador = firstTreeMap(puntajes);
    if (iterador == NULL){
        printf("No hay puntajes guardados.\n");
        getchar();
        printf("\nPresione ENTER para continuar.");
        getchar();
        return;
    }

    printf("- Puntajes -");
    while(iterador){
        printf("%s: %d\n", iterador->nombre_usuario, iterador->tiempo);
    }
    getchar();
    printf("\nPresione ENTER para continuar.");
    getchar();
}

Elemento** crearTablero(char* valor, int columnas, int fila){
    int i,j;
    fila += 1;
    columnas+=11;
    Elemento** tablero = (Elemento**)calloc(fila,fila*sizeof(Elemento*)); 
    for( i=0;i<fila;i++){
        tablero[i] = (Elemento*)calloc(columnas,columnas*sizeof(Elemento));
        for( j=0;j<columnas;j++){
            tablero[i][j].valor = (char*)malloc(3*sizeof(char));
            strcpy(tablero[i][j].valor,"");
            if (i == 0 && j == 0)
                strcpy(tablero[i][j].valor," ");
            else if (i == 0 && j == 3)
                strcpy(tablero[i][j].valor,"1");
            else if (i == 0 && j == 6)
                strcpy(tablero[i][j].valor,"2");
            else if (i == 0 && j == 9)
                strcpy(tablero[i][j].valor,"3");
            else if (i == 0 && j == 12)
                strcpy(tablero[i][j].valor,"4");
            else if (i == 0 && j == 15)
                strcpy(tablero[i][j].valor,"5");
            else if (i == 0 && j == 18)
                strcpy(tablero[i][j].valor,"6");
            else if (i == 0 && j == 21)
                strcpy(tablero[i][j].valor,"7");
            else if (i == 0&& j == 24)
                strcpy(tablero[i][j].valor,"8");
            else if (i == 0&& j == 27)
                strcpy(tablero[i][j].valor,"9");
            else if (i == 0&& j == 30)
                strcpy(tablero[i][j].valor,"10");
            else if (i == 0 &&j == 32)
                strcpy(tablero[i][j].valor,"11");
            else if (i == 0 &&j == 35)
                strcpy(tablero[i][j].valor,"12");
            else if (i == 0 && j == 38)
                strcpy(tablero[i][j].valor,"13");
            else if (i == 0 && j == 41)
                strcpy(tablero[i][j].valor,"14");
            else if (i == 0 && j == 44)
                strcpy(tablero[i][j].valor,"15");
            else if (i == 0 && j == 47)
                strcpy(tablero[i][j].valor,"16");
            else if (i == 0 && j == 50)
                strcpy(tablero[i][j].valor,"17");
            else if (i == 0 && j == 53)
                strcpy(tablero[i][j].valor,"18");
            else if (i == 0 && j == 56)
                strcpy(tablero[i][j].valor,"19");
            else if (i == 0 && j == 59)
                strcpy(tablero[i][j].valor,"20");
            else if (i == 0 && j == 62)
                strcpy(tablero[i][j].valor,"21");
            else if (i == 0 && j == 65)
                strcpy(tablero[i][j].valor,"22");
            else if (i == 0 && j == 68)
                strcpy(tablero[i][j].valor,"23");
            else if (i == 0 && j == 71)
                strcpy(tablero[i][j].valor,"24");
            else if (i == 0 && j == 74)
                strcpy(tablero[i][j].valor,"25");
            else if (i == 0 && j == 77)
                strcpy(tablero[i][j].valor,"26");
            else if (i == 1 && j == 0)
                strcpy(tablero[i][j].valor,"A");
            else if (i == 2 && j == 0)
                strcpy(tablero[i][j].valor,"B");
            else if (i == 3 && j == 0)
                strcpy(tablero[i][j].valor,"C");
            else if (i == 4 && j == 0)
                strcpy(tablero[i][j].valor,"D");
            else if (i == 5 && j == 0)
                strcpy(tablero[i][j].valor,"E");
            else if (i == 6 && j == 0)
                strcpy(tablero[i][j].valor,"F");
            else if (i == 7 && j == 0)
                strcpy(tablero[i][j].valor,"G");
            else if (i == 8 && j == 0)
                strcpy(tablero[i][j].valor,"H");
            else if (i == 9 && j == 0)
                strcpy(tablero[i][j].valor,"I");
            else if (i == 10&&  j == 0)
                strcpy(tablero[i][j].valor,"J");
            else if (i == 11&&  j == 0)
                strcpy(tablero[i][j].valor,"K");
            else if (i == 12&&  j == 0)
                strcpy(tablero[i][j].valor,"L");
            else if (i == 13&&  j == 0)
                strcpy(tablero[i][j].valor,"M");
            else if (i == 14&&  j == 0)
                strcpy(tablero[i][j].valor,"N");
            else if (i == 15&&  j == 0)
                strcpy(tablero[i][j].valor,"O");
            else if (i == 16&&  j == 0)
                strcpy(tablero[i][j].valor,"P");
            else if (i == 17 && j == 0)
                strcpy(tablero[i][j].valor,"Q");
            else if (i == 18 && j == 0)
                strcpy(tablero[i][j].valor,"R");
            else if (i == 19 && j == 0)
                strcpy(tablero[i][j].valor,"S");
            else if (i == 20 && j == 0)
                strcpy(tablero[i][j].valor,"T");
            else if (i == 21 && j == 0)
                strcpy(tablero[i][j].valor,"U");
            else if (i == 22 && j == 0)
                strcpy(tablero[i][j].valor,"V");
            else if (i == 23 && j == 0)
                strcpy(tablero[i][j].valor,"W");
            else if (i == 24 && j == 0)
                strcpy(tablero[i][j].valor,"X");
            else if (i == 25 && j == 0)
                strcpy(tablero[i][j].valor,"Y");
            else if (i == 26 && j == 0)
                strcpy(tablero[i][j].valor,"Z");
            else{
                if ((j%3)!=0 || j>79)
                    strcpy(tablero[i][j].valor," ");
                else if (i>0)
                    strcpy(tablero[i][j].valor,valor);
            }
        }
    }
        
            
    return tablero;
}
Elemento** InsertarBombas(Elemento** tablero,int cantidadBombas, int columna, int fila){
    int m=0;
    while(m<cantidadBombas){
        srand(time(NULL));
        int i = rand() % (fila-1);
        int j = (rand() % (columna/3+3))*3;
        if(strcmp(tablero[i][j].valor,"0")==0){
            m++;
            tablero[i][j].valor="*";
        }
    }
    return tablero;
}

void InsertarPistas(Elemento** tablero,int columna, int fila){
    for(int i=0;i<fila+1;i++){
        for(int j=0;j<columna+11;j++){
            if(strcmp(tablero[i][j].valor,"*")==0){
                for(int x=-1;x<=1;x++){
                    for(int y=-3;y<=3;y+=3){
                        if(1<=x+i && x+i<=25 && 3<=j+y && j+y<=75){
                            if(strcmp(tablero[x+i][j+y].valor,"*")!=0){
                                int aux = atoi(tablero[x+i][j+y].valor);
                                aux=aux+1;
                                char aux2[2];
                                itoa(aux,aux2,10);
                                strcpy(tablero[x+i][j+y].valor,aux2);
                            }
                        }
                    }
                }
            }
        }
    }
}

void muestraTablero(Elemento** tablero,int columna, int fila){
    columna +=11;
    fila += 1;
    for(int i = 0; i<fila;i++){
        for(int j =0;j<columna;j++){
            printf("%s ",tablero[i][j].valor);
        }
        printf("\n");
    }
}

void seedRand(){
    srand(time(NULL));
}

int numAleatorio(int min, int max){
    return min + rand() / (RAND_MAX / (max-min+1) + 1);
}

Tablero* inicializarTablero(Tablero* tablero){
    tablero = (Tablero *) calloc (1, sizeof(Tablero));
    return tablero;
}


void comenzarJuego(Tablero* tablero, int columnas, int filas, int bombas){
    char resp;
    char minsec[50];
    int min=0, sec=0;
    char *token;
    char coord[50];
    int flag=1;
    int opcion;
    char* aux;
    time_t t, t2;
    struct tm *local, *local2;
    int contador;
    contador = filas*(columnas/3+3)*-1 + bombas;
    printf("Desea jugar con tiempo? (S/N): ");
    scanf(" %c", &resp);
    if(resp=='S' || resp=='s'){
        printf("Cuanto tiempo maximo desea emplear? (minutos,segundos): ");
        scanf("%s", minsec);

        token = strtok(minsec, ",");
        min = atoi(token);
        token = strtok(NULL, ",");
        sec = atoi(token);

        t = time(NULL);
        local = localtime(&t);

        printf("\nDispondras de %i minutos y %i segundos a partir desde ahora (%i:%i:%i)\n",min,sec,local->tm_hour,local->tm_min,local->tm_sec);
    }else{
        printf("\nTienes todo el tiempo del mundo para jugar, no te apures!\n");
    }
    printf("\n\t\tBuena suerte! :D\n\n");
    getchar();
    printf("Presione ENTER para comenzar a jugar");
    getchar();

    do{
        system("cls");
        muestraTablero(tablero->visible,columnas,filas);
        printf("\n- OPCIONES -\n");
        printf("1.- Desbloquear una casilla || 2.- Guardar la partida || 3.-Salir al menu principal\n");
        scanf(" %i", &opcion);

        switch(opcion){
            case 1: /* Despejar casilla */
                printf("Ingrese la coordenada de la casilla (letra,numero): ");
                getchar();
                char coordenada[4];
                fgets(coordenada,4,stdin);
                char letra[2];
                int x;
                aux = strtok(coordenada,",");
                strcpy(letra,aux);
                    if (strcmp(letra,"A")==0 || strcmp(letra,"a")==0)
                        x  = 1;
                    else if (strcmp(letra,"B")==0 || strcmp(letra,"b")==0)
                        x  = 2;
                    else if (strcmp(letra,"C")==0 || strcmp(letra,"c")==0)
                        x  = 3;
                    else if (strcmp(letra,"D")==0 || strcmp(letra,"d")==0)
                        x  = 4;
                    else if (strcmp(letra,"E")==0 || strcmp(letra,"e")==0)
                        x  = 5;
                    else if (strcmp(letra,"F")==0 || strcmp(letra,"f")==0)
                        x  = 6;
                    else if (strcmp(letra,"G")==0 || strcmp(letra,"g")==0)
                        x  = 7;
                    else if (strcmp(letra,"H")==0 || strcmp(letra,"h")==0)
                        x  = 8;
                    else if (strcmp(letra,"I")==0 || strcmp(letra,"i")==0)
                        x  = 9;
                    else if (strcmp(letra,"J")==0 || strcmp(letra,"j")==0)
                        x  = 10;
                    else if (strcmp(letra,"K")==0 || strcmp(letra,"k")==0)
                        x  = 11;
                    else if (strcmp(letra,"L")==0 || strcmp(letra,"l")==0)
                        x  = 12;
                    else if (strcmp(letra,"M")==0 || strcmp(letra,"m")==0)
                        x  = 13;
                    else if (strcmp(letra,"N")==0 || strcmp(letra,"n")==0)
                        x  = 14;
                    else if (strcmp(letra,"O")==0 || strcmp(letra,"o")==0)
                        x  = 15;
                    else if (strcmp(letra,"P")==0 || strcmp(letra,"p")==0)
                        x  = 16;
                    else if (strcmp(letra,"Q")==0 || strcmp(letra,"q")==0)
                        x  = 17;
                    else if (strcmp(letra,"R")==0 || strcmp(letra,"r")==0)
                        x  = 18;
                    else if (strcmp(letra,"S")==0 || strcmp(letra,"s")==0)
                        x  = 19;
                    else if (strcmp(letra,"T")==0 || strcmp(letra,"t")==0)
                        x  = 20;
                    else if (strcmp(letra,"U")==0 || strcmp(letra,"u")==0)
                        x  = 21;
                    else if (strcmp(letra,"V")==0 || strcmp(letra,"v")==0)
                        x  = 22;
                    else if (strcmp(letra,"W")==0 || strcmp(letra,"w")==0)
                        x  = 23;
                    else if (strcmp(letra,"X")==0 || strcmp(letra,"x")==0)
                        x  = 24;
                    else if (strcmp(letra,"Y")==0 || strcmp(letra,"y")==0)
                        x  = 25;
                    else if (strcmp(letra,"Z")==0 || strcmp(letra,"z")==0)
                        x  = 26;
                    int y;
                    aux = strtok(NULL,",");
                    y = atoi(aux)*3;
                    if(strcmp(tablero->oculto[x][y].valor,"*")==0) printf("perdiste");
                    if(strcmp(tablero->oculto[x][y].valor," ")!=0)
                        strcpy(tablero->visible[x][y].valor,tablero->oculto[x][y].valor);
                    contador+=1;
                    if(contador == 0) printf("ganaste");
                break;
            case 2: /* Funcion guardarPartida */
                break;
            case 3: /* Salir al menu */
                break;
            default:;
                opcion = 4;
                printf("Por favor, ingrese una opcion valida.\n");
                getchar();
                printf("Presione ENTER para continuar.\n");
                getchar();
                break;
        }
    }while(opcion!=3);

    /*Sleep(10000);
    t2 = time(NULL);
    local2 = localtime(&t2);

    printf("\n %i:%i:%i \n", local2->tm_hour, local2->tm_min, local2->tm_sec);

    double tiempoEmpleado = (difftime(t2,t))/60;

    printf("\n\tHan pasado %.0lf minutos! \n",tiempoEmpleado);*/
}

void seleccionarDificultad(Tablero* tablero){

    int dif;

    printf("- Dificultades -\n");
    printf("1.- Principiante (8x8 , 10 minas)\n");
    printf("2.- Intermedio (16x16 , 40 minas)\n");
    printf("3.- Experto (16x26 , 65 minas)\n");
    printf("4.- Aleatorio\n");
    printf("5.- Personalizado\n\n");
    printf("Por favor, ingrese la dificultad en la que desea jugar: ");
    scanf("%i", &dif);

    char colfilmin[50];
    char *token;
    int col, fil, min, randFila, randColu, randMinas, maxRandMinas;

    system("cls");
    switch(dif){
        case 1:
            tablero->visible = crearTablero(".", 15, 8);
            tablero->oculto = crearTablero("0", 24, 8);
            printf("Generando partida...");
            tablero->oculto=InsertarBombas(tablero->oculto,10,15,8);
            InsertarPistas(tablero->oculto,15,8);
            system("cls");
            muestraTablero(tablero->visible, 15, 8);
            comenzarJuego(tablero,15,8,10);
            break;
        case 2:
            tablero->visible = crearTablero(".", 39, 16);
            tablero->oculto = crearTablero("0", 48, 16);
            printf("Generando partida...");
            tablero->oculto=InsertarBombas(tablero->oculto,40,39,16);
            InsertarPistas(tablero->oculto,39,16);
            system("cls");
            muestraTablero(tablero->visible, 39, 16);
            comenzarJuego(tablero,39,16,40);
            break;
        case 3:
            tablero->visible = crearTablero(".", 39, 26);
            tablero->oculto = crearTablero("0", 48, 26);
            printf("Generando partida...");
            tablero->oculto=InsertarBombas(tablero->oculto,65,47,26);
            InsertarPistas(tablero->oculto,39,26);
            system("cls");
            muestraTablero(tablero->visible, 39, 26);
            comenzarJuego(tablero,39,26,65);
            break;
        case 4: /* Generar un tablero aleatorio */
            randFila = numAleatorio(3,26);
            randColu = numAleatorio(3,26);
            maxRandMinas = randFila * randColu * 25.625 / 100;
            randMinas = numAleatorio(1,maxRandMinas);
            tablero->visible = crearTablero(".",(randColu-3)*3,randFila);
            tablero->oculto = crearTablero("0",randColu*3,randFila);
            printf("Generando partida...");
            tablero->oculto=InsertarBombas(tablero->oculto,randMinas,(randColu-3)*3,randFila);
            InsertarPistas(tablero->oculto,randColu*3,randFila);
            system("cls");
            muestraTablero(tablero->visible,(randColu-3)*3,randFila);
            comenzarJuego(tablero,(randColu-3)*3,randFila,randMinas);
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

            tablero->visible = crearTablero(".", (col-3)*3, fil);
            tablero->oculto = crearTablero("0", col*3, fil);
            printf("Generando partida...");
            tablero->oculto=InsertarBombas(tablero->oculto,min,(col-3)*3,fil);
            InsertarPistas(tablero->oculto,(col-3)*3,fil);
            system("cls");
            muestraTablero(tablero->visible, (col-3)*3, fil);
            comenzarJuego(tablero,(col-3)*3,fil,min);
            break;
        default:;
            dif = 6;
            printf("Intentelo nuevamente.");
            getchar();
            break;
    }
}

void secuenciaPrograma(Tablero* tablero){
    seleccionarDificultad(tablero);
}