#include "slist_test.h"

void test_slist_crear() {
  SList lista = slist_crear();
  assert(lista.primero == NULL);
  assert(lista.ultimo == NULL);
}

void test_slist_vacia() {
  SList lista = slist_crear();
  assert(slist_vacia(lista));
  lista.primero = malloc(sizeof(SNodo));
  lista.primero->dato = 'a';
  lista.primero->sig = NULL;
  assert(!slist_vacia(lista));
  slist_destruir(lista);
}

void test_slist_agregar_final() {
  SList lista = slist_crear();
  lista = slist_agregar_final(lista, 'a');
  assert(lista.primero->dato == 'a' && lista.ultimo->dato == 'a');
  lista = slist_agregar_final(lista, 'b');
  assert(lista.primero->dato == 'a' && lista.ultimo->dato == 'b');
  lista = slist_agregar_final(lista, 'c');
  assert(lista.primero->dato == 'a' && lista.ultimo->dato == 'c');
  assert(lista.ultimo->sig == NULL);
  slist_destruir(lista);
}

void test_slist() {
  test_slist_crear();
  test_slist_vacia();
  test_slist_agregar_final();
}