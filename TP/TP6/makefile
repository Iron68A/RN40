
all : main

main : main_arbre.o arbre.o
	gcc -o main main_arbre.o arbre.o

main_arbre.o : main_arbre.c
	gcc -c main_arbre.c

arbre.o : arbre.c arbre.h
	gcc -c arbre.c arbre.h

clean :
	rm -f *.o main
