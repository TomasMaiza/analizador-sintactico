#ifndef __GTREE_H__
#define __GTREE_H__
#define TAMANIO_ALFABETO 26

typedef enum {
  ACEPTACION,
  NO_ACEPTACION
} EstadoDeAceptacion;

typedef struct _GTNodo {
  char dato;
  struct _GTNodo** hijos;
  EstadoDeAceptacion estado;
} GTNodo;

typedef GTNodo* GTree;

// retorna un arbol vacío
GTree gtree_crear();

// destruye el arbol
void gtree_destruir(GTree);

// recibe un char y calcula el índice asociado al mismo
int indice_dato(char);

// inserta un elemento al gtree, devuelve la direccion del nodo donde se
//insertó el dato
GTree gtree_insertar(GTree*, char, EstadoDeAceptacion);

// busca un dato entre los hijos del nodo dado y si lo halla devuelve su raiz,
//sino devuelve NULL.
GTree gtree_buscar(GTree, char);


#endif /* __GTREE_H__ */