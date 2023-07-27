FLAGS = -Wall -Wextra -Werror -std=c99 -g

programa: main.o funciones.o analizador.o gtree.o cola.o slist.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c funciones.h analizador/analizador.h gtree/gtree.h
	$(CC) -c $< $(FLAGS)

funciones.o: funciones.c funciones.h
	$(CC) -c $< $(FLAGS)

analizador.o: analizador/analizador.c analizador/analizador.h gtree.o funciones.o cola.o slist.o
	$(CC) -c $< $(FLAGS)

gtree.o: gtree/gtree.c gtree/gtree.h
	$(CC) -c $< $(FLAGS)

slist.o: slist/slist.c slist/slist.h
	$(CC) -c $< $(FLAGS)

cola.o: colas/cola.c colas/cola.h slist.o
	$(CC) -c $< $(FLAGS)	

clean:
	rm -f *.o

test: test.c gtree/gtree_test.c gtree/gtree_test.h gtree.o analizador/analizador_test.c analizador/analizador_test.h analizador.o funciones.o slist/slist_test.c slist/slist_test.h slist.o colas/cola_test.c colas/cola_test.h cola.o
	$(CC) -o $@ $^ $(FLAGS)

.PHONY = clean