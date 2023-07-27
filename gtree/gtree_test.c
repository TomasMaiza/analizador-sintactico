#include "gtree_test.h"

void test_indice_dato() {
  assert(indice_dato('a') == 0);
  assert(indice_dato('o') == 14);
  assert(indice_dato('s') == 18);
  assert(indice_dato('z') == 25);
}

void test_gtree_insertar() {
  GTree tree = gtree_crear();
  GTree nuevoNodo1 = gtree_insertar(&tree, 's', NO_ACEPTACION);
  GTree nuevoNodo2 = gtree_insertar(&nuevoNodo1, 'i', ACEPTACION);
  assert(nuevoNodo1->dato == 's' && nuevoNodo1->estado == NO_ACEPTACION);
  assert(nuevoNodo2->dato == 'i' && nuevoNodo2->estado == ACEPTACION);
  gtree_destruir(tree);
}

void test_gtree_buscar() {
  GTree tree = gtree_crear();
  GTree nuevoNodo1 = gtree_insertar(&tree, 's', NO_ACEPTACION);
  GTree nuevoNodo2 = gtree_insertar(&nuevoNodo1, 'i', ACEPTACION);
  assert(gtree_buscar(tree, 's') == nuevoNodo1);
  assert(gtree_buscar(nuevoNodo1, 'i') == nuevoNodo2);
  assert(gtree_buscar(tree, 'h') == NULL);
  gtree_destruir(tree);
}

void test_gtree() {
  test_indice_dato();
  test_gtree_insertar();
  test_gtree_buscar();
}