#include <stdio.h>
#include "list.h"
#include "functions.h"

int main(){
    Elemento** tableroVisible = crearTablero(".",30,10);
    Elemento** tableroOculto = crearTablero("*",30,10);
    muestraTablero(tableroVisible,30,10);
    int i;
    scanf("%d",i);
    return 0;
}