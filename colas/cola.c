#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

Cola cola_crear() {
  return slist_crear();
}

void cola_destruir(Cola cola) {
  slist_destruir(cola);
}

int cola_es_vacia(Cola cola) {
  return slist_vacia(cola);
}

char cola_inicio(Cola cola) {
  return cola.primero->dato;
}

Cola cola_encolar(Cola cola, char dato) {
  return slist_agregar_final(cola, dato);
}

Cola cola_desencolar(Cola cola) {
  SNodo* inicio = cola.primero;
  cola.primero = cola.primero->sig;
  if (cola.primero == NULL)
    cola.ultimo = NULL;
  free(inicio);
  return cola;
}

void cola_imprimir(Cola cola, FuncionVisitante visit) {
  slist_recorrer(cola, visit);
}