#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "analizador/analizador.h"

int main(int argc, char** argv) {
  if (argc != 4)
    return 1;
  Archivos* archivos = abrir_archivos(argv);
  ejecutar_analizador(archivos);
  return 0;
}