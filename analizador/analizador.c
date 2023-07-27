#include <stdio.h>
#include <stdlib.h>
#include "analizador.h"

GTree leer_diccionario(Archivos* archivos) {
  GTree diccionario = gtree_crear();
  while (!feof(archivos->diccionario))
    insertar_palabra(&diccionario, archivos->diccionario);
  fclose(archivos->diccionario);
  return diccionario;
}

void insertar_palabra(GTree* diccionario, FILE* archivoDiccionario) {
  int saltoDeLineaEncontrado = 0;
  GTree arbol = *diccionario;
  while(!saltoDeLineaEncontrado) {
    char caracter = getc(archivoDiccionario);
    if (caracter == '\n') { // si encuentra un \n
      saltoDeLineaEncontrado++; // significa que finalizó la lectura de la palabra
      arbol->estado = ACEPTACION; // entonces el último estado es de aceptación
    }
    else if (caracter == EOF)
      saltoDeLineaEncontrado++;
    else {
      char letra = tolower(caracter);
      arbol = gtree_insertar(&arbol, letra, NO_ACEPTACION);
    }
  }
}

void leer_entrada(Archivos* archivos, GTree diccionario) {
  while (!feof(archivos->entrada))
    leer_cadena(archivos, diccionario);
}

void leer_cadena(Archivos* archivos, GTree diccionario) {
  char cadenaLeida[ESPACIO_CADENA], caracter = fgetc(archivos->entrada);
  int i = 0;
  while(caracter != '\n' && caracter != EOF) {
    cadenaLeida[i] = tolower(caracter);
    i++;
    caracter = fgetc(archivos->entrada);
  }
  cadenaLeida[i] = '\0';
  if (cadenaLeida[0] != '\0') {
    Salida salida = analizar_cadena(cadenaLeida, diccionario);
    escribir_salida(archivos->salida, salida);
    free(salida.cadenaFinal);
    free(salida.errores);
  }
}

Salida analizar_cadena(String cadenaLeida, GTree diccionario) {
  Salida salida = inicializar_salida();
  int indice = 0, indiceInicioPalabra = 0, indiceAceptacion = -1;
  int largoCadena = strlen(cadenaLeida), indiceCadenaAnterior = 0;
  int indiceAceptacionEnCadena = -1;
  GTree arbol = diccionario;
  while(indiceInicioPalabra != largoCadena) {
    char caracterLeido = cadenaLeida[indice];
    arbol = gtree_buscar(arbol, caracterLeido);
    if (arbol != NULL) { // se encontró el caracter en la rama del árbol
      salida.cadenaFinal[salida.indiceCadena] = caracterLeido;
      salida.indiceCadena++;
      if (arbol->estado == ACEPTACION) {
        indiceAceptacion = indice; // índice del final de cadena más largo
        indiceAceptacionEnCadena = salida.indiceCadena; // indica hasta dónde
        // llega la palabra válida más larga en la cadena espaciada
      }
      indice++;
    }
    else { // no se encontró el caracter en el árbol
      if (indiceAceptacion != -1) { // se encontró una cadena válida previamente
        indiceInicioPalabra = indiceAceptacion + 1;
        salida.cadenaFinal[indiceAceptacionEnCadena] = ' ';
        salida.indiceCadena = indiceAceptacionEnCadena + 1;
        indiceCadenaAnterior = salida.indiceCadena;
        indiceAceptacion = -1;
      }
      else { // el caracter inicial es un error
        salida.errores[salida.indiceErrores] = cadenaLeida[indiceInicioPalabra];
        salida.indiceErrores++;
        indiceInicioPalabra++;
        salida.indiceCadena = indiceCadenaAnterior;
      }
      indice = indiceInicioPalabra;
      arbol = diccionario;
      indiceAceptacionEnCadena = -1;
    }
  }
  if (salida.indiceCadena != 0)
    salida.cadenaFinal[salida.indiceCadena - 1] = '\0';
  salida.errores[salida.indiceErrores] = '\0';
  salida.cadenaFinal = realloc(salida.cadenaFinal, sizeof(char) * (salida.indiceCadena));
  salida.errores = realloc(salida.errores, sizeof(char) * (salida.indiceErrores + 1));
  return salida;
}

Salida inicializar_salida() {
  Salida salida;
  salida.cadenaFinal = malloc(sizeof(char) * ESPACIO_CADENA);
  salida.errores = malloc(sizeof(char) * ESPACIO_CADENA);
  salida.indiceCadena = 0;
  salida.indiceErrores = 0;
  return salida;
}

void escribir_salida(FILE* archivoDeSalida, Salida salida) {
  int cantidadDeErrores = salida.indiceErrores;
  if (salida.indiceCadena != 0)
    fprintf(archivoDeSalida, "%s ", salida.cadenaFinal);
  if (cantidadDeErrores > 0) {
    fprintf(archivoDeSalida, " - Errores: ");
    fprintf(archivoDeSalida, "%c", salida.errores[0]);
    for (int i = 1; i < cantidadDeErrores; i++)
      fprintf(archivoDeSalida, ", %c", salida.errores[i]);
  }
  else
    fprintf(archivoDeSalida, " - sin errores encontrados");
  fputs("\n", archivoDeSalida);
}