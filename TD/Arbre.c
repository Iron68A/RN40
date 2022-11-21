#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
/**
 * Arbre binaire de recherche = arbre binaire "trié", la valeur de tout noeud est supérieure à celle de son fils gauche et inférieure à celle de son fils droit
 * Exemple : 
 *              30
 *            /  \
 *         40    20
 *       / \   /  \
 *    45  35 25  10
 * 
 * Exo : Ecrire un algorithme qui permet de créer un arbre binaire de recherche à partir d'une liste d'entiers
 * Entrée : Une liste d'entiers
 * Sortie : Un arbre binaire de recherche
 * 
 * Algo :
 * creer_arbre(liste):
 * Si liste est vide
 * alors retourner arbre vide
 * Sinon
 * retourner creer_arbre(liste[1..n/2]) // liste des éléments de 1 à n/2
 * ajouter liste[n/2+1] en racine de l'arbre
 * ajouter creer_arbre(liste[n/2+2..n]) en fils droit de l'arbre
 * 
 * 
 * Exo : ecrire l'algo recursif qui insère un entier dans un arbre binaire de recherche 
 * Entrée : Un arbre binaire de recherche et un entier
 * Sortie : Un arbre binaire de recherche
 * Algo : 
 * inserer(arbre, entier):
 * Si arbre est vide
 * alors retourner arbre contenant l'entier
 * Sinon
 * Si entier < racine de l'arbre
 * alors retourner inserer(fils gauche de l'arbre, entier)
 * Sinon
 * retourner inserer(fils droit de l'arbre, entier)
 * 
*/




typedef struct noeud {
    int val;
    struct noeud *gauche;
    struct noeud *droite;
} noeud;

typedef noeud *arbre;

typedef struct element {
    int val; 
    struct element *suivant;
} element;

typedef element *liste;

arbre enraciner(int val, arbre a1, arbre a2);
int videa(arbre a);
arbre fils_gauche(arbre a);
arbre fils_droit(arbre a);
int nbrnoeuds(arbre a);
liste inversel(liste l);

int videl(liste l);
liste insertionentete(liste l, int val);
void afficherlist(liste l);
liste insertionenfin(liste l, int val);


//ARBRE 
arbre enraciner(int val, arbre a1, arbre a2) {
    arbre temp = malloc(sizeof(noeud));
    temp->val = val;
    temp->gauche = a2;
    temp->droite = a1;
    return temp;
}
arbre fils_gauche(arbre a) {
    if (a == NULL) {
        return NULL;
    }
    return a->gauche;
}

arbre fils_droit(arbre a) {
    if (a == NULL) {
        return NULL;
    }
    return a->droite;
}

int videa(arbre a) {
    if (a == NULL) {
        return 1;
    }
    return 0;
}
//ALGO
/** Algorithme le nombre de noeud d'un arbre binaire
 * Entrées: un arbre binaire a
 * Sortie: un entier n
 * Algo:
 * int nombre(arbe a):
 * si a est vide alors nombre = 0
 * sinon nombre(a) = 1+ nombre(fils_gauche(a)) + nombre(fils_droit(a)) 
 * */

int nbrnoeud(arbre a) {
    if (videa(a)) {
        return 0;
    }
    return 1 + nbrnoeud(fils_gauche(a)) + nbrnoeud(fils_droit(a));
}

//LISTE
int videl(liste l){
    if (l == NULL) return 1;
    else return 0;

}

liste insertionentete(liste l,int valeur){
    liste p;
    p = (element *)malloc(sizeof(element));
    p -> val = valeur;
    p -> suivant = l;
    return p;
    
}

liste insertionenfin(liste l,int valeur){
    liste p;
    p = (element *)malloc(sizeof(element));
    p -> val = valeur;
    p -> suivant = NULL;
    if(l == NULL){
        l=p;
    }
    else{
        liste q;
        q = l;
        while(q -> suivant != NULL){
            q = q -> suivant;
        }
        q -> suivant = p;
    }
    return l;
}
void afficherlist(liste l){
    liste p;
    p = l;
    while(p != NULL){
        printf("%d ",p -> val);
        p = p -> suivant;
    }
    printf("\n");
}


/**
 * Ex1 : ecrire un programme récurssif qui construit la liste inverse d'une liste donnée
 * Entrées: une liste L
 * Sortie: une liste L'
 * Algo:
 * liste inverse(liste L):
 * si L est vide alors inverse = vide
 * sinon L' = ajouter en tete(inverse(suivant(L)),tete(L))
*/

liste inversel(liste l){
    if(videl(l)){
        return l;
    }
    else{
        return insertionenfin(inversel(l->suivant),l->val);
    }
} 

/**
* Ex2 : Ecrire le programme récursif qui teste l'appartenance d'un element à un arbe d'entiers
* Entrées: un arbre a et un entier x
* Sortie: un booleen b
* Algo:
* booleen appartient(arbre a, int x):
* si a est vide alors appartient = faux
* si racine(a) = x alors appartient = vrai
* sinon appartient = appartient(fils_gauche(a),x) ou appartient(fils_droit(a),x)
*/

int appartient(arbre a, int x){
    if(videa(a)){
        return FALSE;
    }
    if(a->val == x){
        return TRUE;
    }
    else{
        return appartient(fils_gauche(a),x) || appartient(fils_droit(a),x);
    }
}



/**
 * Ex3 : Ecrire le programme récursif qui teste l'égalité de deux arbres données
 * Entrées: deux arbres a1 et a2
 * Sortie: un booleen b
 * Algo:
 * booleen egalite(arbre a1, arbre a2):
 * si a1 est vide et a2 est vide alors egalite = vrai
 * sinon si a1 est vide et a2 n'est pas vide ou a1 n'est pas vide et a2 est vide alors egalite = faux
 * sinon egalite = egalite(fils_gauche(a1),fils_gauche(a2)) et egalite(fils_droit(a1),fils_droit(a2))
 * */

int egalite(arbre a1, arbre a2){
    if(videa(a1) && videa(a2)){
        return TRUE;
    }
    else if(videa(a1) && !videa(a2) || !videa(a1) && videa(a2)){
        return FALSE;
    }
    else{
        return egalite(fils_gauche(a1),fils_gauche(a2)) && egalite(fils_droit(a1),fils_droit(a2));
    }
}




int main(){
    liste l = NULL;
    l = insertionenfin(l,1);
    l = insertionenfin(l,2);
    l = insertionenfin(l,3);
    afficherlist(l);
    liste l1;
    l1 = inversel(l);
    afficherlist(l1);
    return 0;
}