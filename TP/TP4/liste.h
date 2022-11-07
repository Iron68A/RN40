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
//TP4
int compter(List l);
int compter_rec(List l);
void effacer(List l);
void effacer_rec(List l);
int nbr_occurences(List l, int c);
int nbr_occurences_rec(List l, int c);
List supprimer_prix(List l, float p);
List supprimer_prix_rec(List l, float p);
List ieme(List l, int i);
List ieme_rec(List l, int i);
//TP3
List ajout_tete(List l, int c , int q , float p);
List ajout_fin(List l, int c , int q , float p);
List supp_tete(List l);
List supp_fin(List l);
List recherche(List l, int c) ;
void afficher_list(List l);
void afficher_prod(List l);

#endif // LISTE_H