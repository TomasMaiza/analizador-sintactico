#include <stdio.h>
#include <stdlib.h>
#include "analizador/analizador.h"
#include "funciones.h"
#include <string.h>

Archivos* abrir_archivos(char** argv) {
  Archivos* archivos = malloc(sizeof(Archivos));
  archivos->diccionario = fopen(argv[1], "r");
  archivos->entrada = fopen(argv[2], "r");
  archivos->salida = fopen(argv[3], "w");
  return archivos;
}

void cerrar_archivos(Archivos* archivos) {
  fclose(archivos->entrada);
  fclose(archivos->salida);
  free(archivos);
}

void ejecutar_analizador(Archivos* archivos) {
  GTree diccionario = leer_diccionario(archivos);
  leer_entrada(archivos, diccionario);
  cerrar_archivos(archivos);
  gtree_destruir(diccionario);
}