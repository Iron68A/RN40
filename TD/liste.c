#include<stdio.h>

//definition d'une liste
typedef struct element{
    int val;
    struct element *suivant;

}element;

typedef element *listeint;

listeint supprimerentete(listeint l);
listeint supprimerfindeliste(listeint l);

//suppresion d'un element au début de la liste
listeint supprimerentete(listeint l){ 
    if (l == NULL) return l;
    else {
    listeint p;
    p = l;
    l = l -> suivant;
    free(p);
    return l;
    }
}

listeint supprimerfindeliste(listeint l){
    if (l == NULL) return l;
    else {
        listeint p;
        p = l;
        while (p -> suivant != NULL){
            p = p -> suivant;
        }
        free(p);
        return l;
    }
}








