#include "cola_test.h"

void test_cola_inicio() {
  Cola cola = cola_crear();
  cola.primero = malloc(sizeof(SNodo));
  cola.primero->dato = 'a';
  cola.primero->sig = NULL;
  cola.ultimo = cola.primero;
  assert(cola_inicio(cola) == 'a');
  cola_destruir(cola);
}

void test_cola_desencolar() {
  Cola cola = cola_crear();
  cola = cola_encolar(cola, 'a');
  cola = cola_encolar(cola, 'b');
  cola = cola_encolar(cola, 'c');
  cola = cola_desencolar(cola);
  assert(cola_inicio(cola) == 'b');
  cola = cola_desencolar(cola);
  assert(cola_inicio(cola) == 'c');
  cola = cola_desencolar(cola);
  assert(cola.primero == NULL && cola.ultimo == NULL);
  cola_destruir(cola);
}

void test_cola() {
  test_cola_inicio();
  test_cola_desencolar();
}