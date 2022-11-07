#include<stdio.h>
#include<stdlib.h>

#include "liste.h"

//c = codeP
//q = quantP
//p = prixP
//ajout en tete de liste

//fonctions ajoutées pour le TP4
//fonction qui compte le nombre d'éléments de la liste
    //Itératif
int compter(List l){
    int n =0;
    while (l != NULL){
        n++;
        l = l -> next;
    } 
    return n;   
}
    //Récursif
int compter_rec(List l){
    if (l == NULL){
        return 0;
    }
    else{
        return 1 + compter_rec(l -> next);
    }
}

//Fonction nombre d'occurences d'un élément dans la liste ( avec fct rechercher )
    //Itératif
int nbr_occurences(List l, int c){
    int n = 0;
    if(l==NULL){return 0;}
    while (l != NULL){
        if (recherche(l, c) ==l){
            n++;
        }
        l = l -> next;
    }
    return n;
}
    //Récursif
int nbr_occurences_rec(List l, int c){
    if (l == NULL){return 0;}
    else{
        if (recherche(l, c) == l){
            return 1 + nbr_occurences_rec(l -> next, c);
        }
        else{
            return nbr_occurences_rec(l -> next, c);
        }
    }
}

//Effacer la liste chainée
    //Itératif
void effacer(List l){
    while (l != NULL){
        List tmp = l;
        l = l -> next;
        free(tmp);
    }
}
    //Récursif
void effacer_rec(List l){
    if (l != NULL){
        effacer_rec(l -> next);
        free(l);        
    }
}
//Fonction qui supprime tous les éléments ayant un prixP donné
    //Itératif
List supprimer_prix(List l, float p){
    while (l != NULL){
        if (l -> prixP == p){
            List tmp = l;
            free(tmp);
        }
        l = l -> next;
    }
    return l;
}
    //Récursif
List supprimer_prix_rec(List l, float p){
    if (l != NULL){
        if (l -> prixP == p){
            List tmp = l;
            free(tmp);
        }
        supprimer_prix_rec(l -> next, p);
    }
    return l;
}

//renvoyer le i eme element de la liste
    //Itératif
List ieme(List l, int i){
    if(i<0 || i>compter(l)){printf("La liste ne contient que %n éléments",compter(l));}
    int n = 0;
    while (l != NULL){
        if (n == i){
            return l;
        }
        n++;
        l = l -> next;
    }
    return NULL;
}
    //Récursif
List ieme_rec(List l, int i){
    if (i<0 || i>compter(l)){printf("La liste ne contient que %n éléments",compter(l));}
    if (l == NULL){return NULL;}
    else{
        if (i == 0){
            return l;
        }
        else{
            return ieme_rec(l -> next, i-1);
        }
    }
}



//Fonctions du TP précédent

List ajout_tete(List l, int c, int q, float p){
    List l2 = (prod *)malloc(sizeof(prod));
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
        List l2 = (prod *)malloc(sizeof(prod));
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


void afficher_list(List l){
    if (l == NULL) printf("Liste vide");
    else {
        printf("---------------------\n");
        while (l != NULL){
            printf("Code : %d, Quantite : %d, Prix : %f \n", l->codeP, l->quantP, l->prixP);
            l = l->next;
        }
        printf("---------------------\n");
    }
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
void afficher_prod(List l){
    printf("codeP = %d, quantP = %d, prixP = %f\n", l->codeP, l->quantP, l->prixP);
}

int main(){
    printf("ajout en tete de liste\n");
    List l = NULL;
    l = ajout_fin(l, 1, 2, 3.5);
    l = ajout_fin(l, 2, 3, 4.1);
    l = ajout_fin(l, 3, 4, 5.6);
    l = ajout_fin(l, 1, 2, 3.2);
    l = ajout_tete(l, 12, 42, 42.5);
    l = ajout_fin(l, 4, 6, 6.1);
    afficher_list(l);
    //supp_fin(l);
    //l = supp_tete(l);
    //afficher_list(l);
    //recherche(l, 2);
    //printf("nombre d'elements de la liste = %d\n", compter(l));
    //printf("nombre d'elements de la liste (recursif) = %d\n", compter_rec(l));
    //printf("nombre d'occurences de l'element (1,2,3.0) = %d\n", nbr_occurences(l,1));
    //printf("nombre d'occurences de l'element (1,2,3.0)(recursif) = %d\n", nbr_occurences(l,1));
    //supprimer_prix(l, 3.0);
    //supprimer_prix_rec(l, 5.0);
    List l2 = ieme(l, 2);
    afficher_prod(l2);
    effacer(l);
    afficher_list(l);
    //effacer_rec(l);

    return 0;
}
