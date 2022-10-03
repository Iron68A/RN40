#include<stdio.h>

//Programme qui calcule le nombre d'occurence d'un entier dans une liste chainée d'entiers

int nboccurence(liste l, int e);

typedef struct element{
    int val;
    struct element *suivant;
}element;

typedef element *liste;

int nboccurence(liste l, int e){
    int nb = 0;
    while (l != NULL){
        if (l -> val == e) nb++;
        l = l -> suivant;
    }
    return nb;
}