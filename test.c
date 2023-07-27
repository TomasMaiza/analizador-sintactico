#include "analizador/analizador.h"
#include <assert.h>
#include "gtree/gtree.h"
#include "gtree/gtree_test.h"
#include "analizador/analizador_test.h"
#include "slist/slist_test.h"
#include "colas/cola_test.h"

void test_programa() {
  Archivos* archivos = malloc(sizeof(Archivos));
  archivos->diccionario = fopen("archivos_prueba/diccionario.txt", "r");
  archivos->entrada = fopen("archivos_prueba/entrada.txt", "r");
  archivos->salida = fopen("archivos_prueba/salida.txt", "w");
  ejecutar_analizador(archivos);
  FILE* salida = fopen("archivos_prueba/salida.txt", "r");
  char buff[255];

  fscanf(salida, "%[^-]", buff);
  assert(strcmp(buff, "nos quepas aqueo mesa lees to  ") == 0);
  fscanf(salida, "%[^\n]", buff);
  assert(strcmp(buff, "- Errores: e") == 0);
  fgetc(salida);

  fscanf(salida, "%[^-]", buff);
  assert(strcmp(buff, "hola buenos dias  ") == 0);
  fscanf(salida, "%[^\n]", buff);
  assert(strcmp(buff, "- Errores: e") == 0);
  fgetc(salida);

  fscanf(salida, "%[^-]", buff);
  assert(strcmp(buff, "hola buenos dias  ") == 0);
  fscanf(salida, "%[^\n]", buff);
  assert(strcmp(buff, "- sin errores encontrados") == 0);
  fgetc(salida);

  fscanf(salida, "%[^-]", buff);
  assert(strcmp(buff, " ") == 0);
  fscanf(salida, "%[^\n]", buff);
  assert(strcmp(buff, "- Errores: x, e, e, e") == 0);
  fgetc(salida);

  fclose(salida);
}

int main() {
  test_gtree();
  test_slist();
  test_cola();
  test_analizador();
  test_programa();
  return 0;
}