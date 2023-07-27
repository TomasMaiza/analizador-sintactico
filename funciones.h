#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
#include <string.h>
#include <stdio.h>

typedef struct {
  FILE* diccionario, *entrada, *salida;
} Archivos;

typedef char* String;

// toma las entradas del main, abre los archivos y los almacena en la estructura
Archivos* abrir_archivos(String*);

// cierra los archivos de la estructura Archivos
void cerrar_archivos(Archivos*);

// ejecuta las funciones que permiten ejecutar el analizador sintáctico
void ejecutar_analizador(Archivos*);

#endif /* __FUNCIONES_H__ */