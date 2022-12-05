#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

/***
 * @author BARTHELME Alexandre
 * TP 6 - Rn 40 Arbre binaire
 * @brief Fichier arbre.c, contient les fonctions de création et d'affichage d'un arbre binaire
*/

Arbre *cree_arbre(int val){
    //arbre vide
    Arbre *a = (Arbre *)malloc(sizeof(Arbre));
    a->value = val;
    a->Agauche = NULL;
    a->Adroite = NULL;
    a->parent = NULL;
    return a;
}

Arbre *join_arbre(Arbre *gauche, Arbre *droit, int noeud){
    Arbre *a = (Arbre *)malloc(sizeof(Arbre));
    a->value = noeud;
    a->Agauche = gauche;
    a->Adroite = droit;
    return a;
}

void affiche_arbre_prefixe(Arbre *a){
    if(a != NULL){
        printf("%d ", a->value);
        affiche_arbre_prefixe(a->Agauche);
        affiche_arbre_prefixe(a->Adroite);
    }
}

void affiche_arbre_postfixe(Arbre *a){
    if(a != NULL){
        affiche_arbre_postfixe(a->Agauche);
        affiche_arbre_postfixe(a->Adroite);
        printf("%d ", a->value);
    }
}

int nombre_de_noeuds(Arbre *a) {
    if (a != NULL) {
        return 1 + nombre_de_noeuds(a->Agauche) + nombre_de_noeuds(a->Adroite);
    }
}

void vider_arbre(Arbre *a){
    if(a != NULL){
        vider_arbre(a->Agauche);
        vider_arbre(a->Adroite);
        free(a);
    }
}