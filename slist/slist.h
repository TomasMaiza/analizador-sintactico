#ifndef __SLIST_H__
#define __SLIST_H__
#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  char dato;
  struct _SNodo *sig;
} SNodo;

typedef struct {
  SNodo *primero, *ultimo;
} SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList, char);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

#endif /* __SLIST_H__ */

