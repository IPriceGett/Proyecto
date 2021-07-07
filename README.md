# Proyecto
Desafio aplicacion de escritorio como proyecto. Aplicacion basada en el juego "buscaminas"

## Notas para el usuario
* Para compilar y ejecutar :
      ```
      gcc main.c functions.c treemap.c map.c -o Proyecto
      ./Proyecto
      ```
* Importar/Exportar : El archivo .csv (para importar) debe estar en la carpeta donde se compila el programa. Para exportar, se crea, o modifica si ya hay uno, en esa misma carpeta.
* Maxima cantidad de filas que puede ingresar el usuario = 26
* Maxima cantidad de columnas que puede ingresar el usuario = 26
* La cantidad de minas no puede ser superior a: filas * columas * 0.15625

## Detalles del programa

Cosas que el programa puede hacer perfectamente y lo que no puede.

| Funciones | ¿Es posible? 
|------------------------------------|-------
| Jugar con dificultad personalizada | ✔
| Jugar con tiempo      |✔
| Puntajes              |✔
| Guardar la partida    |✔
| Cargar la partida     |✔❌
| Jugar con el ratón    |❌ 
| Usar banderas         |❌
| Expansión de casillas |❌

### Detalles

Guardar partida crea un archivo para que asi las partidas no se pierdan al salir del programa, pero cuando cargamos partida en dificultades distintas a la primera(8x8) estas no se leen correctamente.
Las banderas no fueron implementadas para el juego, además de la expansión de las casillas cuando el jugador elige una casilla vacia.


## Aspectos positivos y a mejorar por el grupo

| Nombre | Aspectos positivos | Aspectos a mejorar          
|------------------|-------|-----------------------
| Ignacio Price    | Gran conocimiento en estructuras y punteros | Mejorar legibilidad - Mayor orden en el código
| Matias Burgos    | Buenos comentarios aportando al equipo | Es terco con sus decisiones
| Nicolás Barraza  | Aporta el equipo con comentarios | Trabajar más para ayudar al equipo
| Benjamín Herrera | Alto pensamiento analitico - Ayuda al equipo a solucionar errores | Contar más con el equipo
| Eyleen Sánchez   | Orden en el código | Mayor comunicación

## Puntos de premio/castigo

| Nombre | Puntos
|-----------------|-------
| Nicolás Barraza | 0
| Benjamín Herrera| 0 
| Ignacio Price   | 0 
| Matias Burgos   | 0 
| Eyleen Sánchez  | 0
