#define LISTE_H
#ifdef LISTE_H
#include <stdlib.h>
#include <stdio.h>
// Declaration de la liste pour produit
typedef struct prod {
    int codeP;
    int quantP;
    float prixP;
    struct prod *next;
} prod;
typedef prod *List;
List ajout_tete(List l, int c , int q , float p);
List ajout_fin(List l, int c , int q , float p);
List supp_tete(List l);
List supp_fin(List l);
List recherche(List l, int c) ;
void afficher_list(List l);

#endif // LISTE_H