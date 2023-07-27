#ifndef __COLA_H__
#define __COLA_H__

#include "../slist/slist.h"

typedef SList Cola;

// crea una cola
Cola cola_crear();

// destruye una cola
void cola_destruir(Cola);

// determina si una cola es vacía
int cola_es_vacia(Cola);

// retorna el dato almacenado en el primer elemento de la cola
char cola_inicio(Cola);

// agrega un elemento al final de la cola
Cola cola_encolar(Cola, char);

// elimina el primer elemento de la cola
Cola cola_desencolar(Cola);

// imprime los elementos de una cola
void cola_imprimir(Cola, FuncionVisitante);

#endif /* __COLA_H__ */