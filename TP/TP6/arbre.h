#ifndef ARBRE_H
#define ARBRE_H

typedef struct Arbre {
    int value;
    struct Arbre *Agauche;
    struct Arbre *Adroite;
    struct Arbre *parent;
} Arbre;

Arbre *cree_arbre(int x);
Arbre *join_arbre(Arbre *gauche, Arbre *droit, int noeud);
void vider_arbre(Arbre *ar); 
void affiche_arbre_prefixe(Arbre *ar);
void affiche_arbre_postfixe(Arbre *ar);
int nombre_de_noeuds (Arbre *ar);

#endif // ARBRE_H