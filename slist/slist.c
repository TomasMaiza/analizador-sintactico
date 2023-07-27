#include "slist.h"
#include <stdlib.h>
#include <math.h>

SList slist_crear() {
  SList lista;
  lista.primero = NULL;
  lista.ultimo = NULL;
  return lista;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista.primero != NULL) {
    nodoAEliminar = lista.primero;
    lista.primero = lista.primero->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista.primero == NULL;
}

SList slist_agregar_final(SList lista, char dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  if (slist_vacia(lista))
    lista.primero = nuevoNodo;
  else
    lista.ultimo->sig = nuevoNodo;
  lista.ultimo = nuevoNodo;
  return lista;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista.primero; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}
