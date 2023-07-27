#include <stdio.h>
#include <stdlib.h>
#include "gtree.h"

GTree gtree_crear() {
  GTNodo* raiz = malloc(sizeof(GTNodo));
  raiz->estado = NO_ACEPTACION;
  raiz->hijos = malloc(sizeof(GTNodo) * TAMANIO_ALFABETO);
  for (int i = 0; i < TAMANIO_ALFABETO; i++)
    raiz->hijos[i] = NULL;
  return raiz;
}

void gtree_destruir(GTree arbol) {
  for (int i = 0; i < TAMANIO_ALFABETO; i++) {
    GTree hijo = arbol->hijos[i];
    if (hijo != NULL)
      gtree_destruir(hijo);
  }
  free(arbol->hijos);
  free(arbol);
}

int indice_dato(char dato) {
  return (int)dato - 97;
}

GTree gtree_insertar(GTree* arbol, char dato, EstadoDeAceptacion estado) {
  int indiceDato = indice_dato(dato);
  GTNodo* nodo = (*arbol)->hijos[indiceDato];
  if (nodo == NULL) {
    nodo = gtree_crear();
    nodo->dato = dato;
    nodo->estado = estado;
    (*arbol)->hijos[indiceDato] = nodo;
  }
  return nodo;
}

GTree gtree_buscar(GTree arbol, char dato) {
  return arbol->hijos[indice_dato(dato)];
}