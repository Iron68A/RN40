#include<stdio.h>
#include<stdlib.h>

#include "liste.h"

//c = codeP
//q = quantP
//p = prixP
//ajout en tete de liste




List ajout_tete(List l, int c, int q, float p){
    List l2 = (prod * )malloc(sizeof(prod));
    l2->codeP = c;
    l2->quantP = q;
    l2->prixP = p;
    l2->next = l;
    return l2;
}

//ajout en fin de liste
List ajout_fin(List l, int c, int q,float p){
    if (l == NULL){
        ajout_tete(l, c, q, p);
    }
    else{
        List l2 = (prod * )malloc(sizeof(prod));
        l2->codeP = c;
        l2->quantP = q;
        l2->prixP = p;
        l2->next = NULL;
        List l3 = l;
        while (l3->next != NULL){
            l3 = l3->next;
        }
        l3->next = l2;
        return l;
    }
}

//suppression premier element de liste
List supp_tete(List l){
    if (l == NULL) return l;
    else {
        List l2 = l;
        l = l->next;
        free(l2);
        return l;
    }
}

//suppression dernier de liste
List supp_fin(List l){
    if (l == NULL) return l;
    else {
        List l2 = l;
        List l3 = l;
        while (l2->next != NULL){
            l3 = l2;
            l2 = l2->next;
            l3->next = NULL;
        }
        free(l2);
        return l;
    }
}



//affichage de la liste
/*void afficher_list(List l){
    while(l != NULL){
        printf("codeP = %d, quantP = %d, prixP = %f\n", l->codeP, l->quantP, l->prixP);
        l = l->next;
    }
}*/

void afficher_list(List l){
    printf(" Code  | Quantite | Prix\n");
    printf("-------------------------\n");
    while(l != NULL){
        printf("  %d |   %d |   %f\n", l->codeP, l->quantP, l->prixP);
        l = l->next;
    }
    printf("-------------------------\n");
}

//recherche d'un produit via son code
List recherche(List l, int c){
    while (l != NULL){
        if (l->codeP == c){
            return l;
            printf("produit trouve\n");
            printf("codeP = %d, quantP = %d, prixP = %f\n", l->codeP, l->quantP, l->prixP);
        }
        l = l->next;
    }
    return NULL;
}

int main(){
    printf("ajout en tete de liste\n");
    List l = NULL;
    l = ajout_fin(l, 1, 2, 3.0);
    l = ajout_fin(l, 2, 3, 4.0);
    l = ajout_fin(l, 3, 4, 5.0);
    l = ajout_tete(l, 12, 42, 42.0);
    l = ajout_fin(l, 4, 6, 6.0);
    afficher_list(l);
    //supp_fin(l);
    l = supp_tete(l);
    afficher_list(l);
    recherche(l, 2);
    return 0;
}
