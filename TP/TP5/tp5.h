#ifndef TP5_H
#define TP5_H
#include <stdlib.h>
#include <stdio.h>
typedef struct element {
    int val; 
    struct element *suivant;
} element;

typedef element *liste;
int u(int n);
int v(int n);
int w(int n);
int est_triee(liste l);
liste concatener(liste l1, liste l2);
liste trier(liste l);
liste insertionenfin(liste l, int valeur);
liste insertionenfin(liste l,int valeur);
void afficherlist(liste l);
void inverse();



#endif // TP5.h