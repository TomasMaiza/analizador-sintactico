#ifndef __ANALIZADOR_H__
#define __ANALIZADOR_H__
#include "../gtree/gtree.h"
#include "../funciones.h"
#include "../colas/cola.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define ESPACIO_CADENA 255

typedef struct {
  String cadenaFinal;
  int indiceCadena;
  Cola errores;
} Salida;

typedef struct {
  String cadenaLeida;
  int indice;
} LecturaDePalabra;

// lee el diccionario y lo almacena en un GTree, el cual retorna
GTree leer_diccionario(Archivos*);

// lee e inserta una palabra en el GTree
void insertar_palabra(GTree*, FILE*);

// toma el archivo de entrada y el diccionario y lee linea por linea el archivo
void leer_entrada(Archivos*, GTree);

// lee una frase del archivo de entrada y la almacena para luego analizarla
void leer_cadena(Archivos*, GTree);

// toma una cadena de la entrada y el diccionario. Retorna la cadena final
//luego de analizarla y una cola que almacena los errores hallados
Salida analizar_cadena(String, GTree);

// crea una estructura salida inicializada
Salida inicializar_salida();

// escribe la salida y los errores de una línea de la entrada
void escribir_salida(FILE*, Salida);

#endif /* __ANALIZADOR_H__ */