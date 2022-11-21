#include <stdio.h>
#include <stdlib.h>
#include "tp5.h"
#define TRUE 1
#define FALSE 0



//exo 3
//redifinition de la structure liste

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


//Compter les elements d'une liste, voir TD
//Tester de manière récursive si une liste est triée par ordre croissant:

int est_triee(liste l){
    if(l==NULL){
        return TRUE;
    }
    else if(l->suivant==NULL){
        return TRUE;
    }
    else if(l->val>l->suivant->val){
        return FALSE;
    }
    else{
        return est_triee(l->suivant);
    }
} 

//concatener deux listes de manière récursive
liste concatener(liste l1, liste l2){
    liste l3;
    if(l1==NULL){
        return l2;
    }
    else if(l2==NULL){
        return l1;
    }
    else{
        l3=l1;
        l3->suivant=concatener(l1->suivant,l2);
        return l3;
    }

}

//trie une liste par ordre croissant de manière récursive d'une liste donnée
liste trier(liste l){
    liste l1,l2,l3;
    if(l==NULL){
        return l;
    }
    else if(l->val>l->suivant->val){

}


//exercice 1 de recursivité de suite d'entiers natuels
//u0 =1, v0=2, w0 =3;
//un+1 = 2un + 3vn +wn
//vn+1 = un+vn+2wn
//wn+1 = un +4vn +wn

int u(int n){
    if(n==0){
        return 1;
    }
    else{
        return 2*u(n-1)+3*v(n-1)+w(n-1);
    }
}

int v(int n){
    if(n==0){
        return 2;
    }
    else{
        return u(n-1)+v(n-1)+2*w(n-1);
    }
}

int w(int n){
    if(n==0){
        return 3;
    }
    else{
        return u(n-1)+4*v(n-1)+w(n-1);
    }
}


void inverse(void)
{
    char c;
    if((c = getchar()) != '.'){ inverse(); }
    putchar(c);
    return;
}

int main(){
    int n = 1;
    int r= u(n);
    printf("%d \n",r);
    
    liste l1 = NULL;
    l1 = insertionentete(l1,1);
    l1 = insertionentete(l1,2);
    l1 = insertionentete(l1,3);
    afficherlist(l1);
    trier(l1);
    afficherlist(l1);

    
    //printf("phrase : ");
    //inverse();
}



