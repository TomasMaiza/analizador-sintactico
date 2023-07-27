#include "analizador_test.h"



void test_leer_diccionario() {
  Archivos* archivos = malloc(sizeof(Archivos));
  archivos->diccionario = fopen("analizador/archivos_para_test/diccionario.txt", "r");
  GTree diccionario = leer_diccionario(archivos);
  assert(diccionario->hijos[3]->dato == 'd' && diccionario->hijos[3]->estado == NO_ACEPTACION);
  assert(diccionario->hijos[3]->hijos[14]->estado == ACEPTACION);
  assert(diccionario->hijos[3]->hijos[14]->hijos[4]->estado == ACEPTACION);
  assert(diccionario->hijos[18]->estado == NO_ACEPTACION);
  gtree_destruir(diccionario);
  free(archivos);
}

void test_analizar_cadena() {
  Archivos* archivos = malloc(sizeof(Archivos));
  archivos->diccionario = fopen("analizador/archivos_para_test/diccionario.txt", "r");
  GTree diccionario = leer_diccionario(archivos);
  String cadenaLeida = "dadoexssi";
  Salida salida = analizar_cadena(cadenaLeida, diccionario);
  assert(strcmp(salida.cadenaFinal, "doe si") == 0);
  assert(cola_inicio(salida.errores) == 'd');
  assert(salida.errores.primero->sig->dato == 'a');
  assert(salida.errores.primero->sig->sig->dato == 'x');
  assert(salida.errores.ultimo->dato == 's');
  gtree_destruir(diccionario);
  free(archivos);
  free(salida.cadenaFinal);
  cola_destruir(salida.errores);
}

void test_analizador() {
  test_leer_diccionario();
  test_analizar_cadena();
}