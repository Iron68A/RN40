#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

/***
 * @author BARTHELME Alexandre
 * TP 6 - Rn 40 Arbre binaire
 * @file main_arbre.c
 * @brief Main du fichier arbre.c
*/

int main(){
    Arbre *a = join_arbre(cree_arbre(2),cree_arbre(1),4);
    Arbre *b = join_arbre(cree_arbre(0),NULL,3);
    Arbre *c = join_arbre(b,a,5);
    affiche_arbre_prefixe(c);
    vider_arbre(c);
    return 0;
}