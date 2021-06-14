#include <stdio.h>
#include "list.h"
#include "functions.h"

int main(){
    List* tableroVisible = crearTablero(".",30,10);
    List* tableroOculto = crearTablero("*",30,10);
    muestraTablero(tableroVisible);
    int i;
    scanf("%d",i);
    return 0;
}