#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0


//elements necessaires pour liste chainee d'entiers
typedef struct element{
    int val;
    struct element *suivant;
}element;

typedef element *listeint;

int vide(listeint l);
listeint insertionentete(listeint l, int val);
void afficherlist(listeint l);


//test si la liste est vide

int vide(listeint l){
    if (l == NULL) return 1;
    else return 0;

}

//ajout d'un element en tete de liste
listeint insertionentete(listeint l,int valeur){
    listeint p;
    p = (element *)malloc(sizeof(element));
    p -> val = valeur;
    p -> suivant = l;
    return p;
    
}

listeint insertionenfin(listeint l,int valeur){
    listeint p;
    p = (element *)malloc(sizeof(element));
    p -> val = valeur;
    p -> suivant = NULL;
    if(l == NULL){
        l=p;
    }
    else{
        listeint q;
        q = l;
        while(q -> suivant != NULL){
            q = q -> suivant;
        }
        q -> suivant = p;
    }
    return l;
}

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

//suppresion d'un element a la fin de la liste
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


void afficherlist(listeint l){
    while(l != NULL){
        printf("%d ", l->val);
        l = l->suivant;
    }
}

listeint saisie(int t){
    listeint l;
    l = NULL;
    for(int i=0;i<t;i++){
        int val;
        printf("entrez la valeur de l'element %d\n",i+1);
        scanf("%d",&val);
        l = insertionentete(l,val);
    }
    return l;
}


int main(){
    listeint l;
    l = NULL;
    printf("combien d'elements voulez vous ajouter en tete de liste ?\n");
    int n;
    scanf("%d",&n);
    l= saisie(n);
    afficherlist(l);
    testcroissant(l);
    inversion_liste(l);
    free(l);
    return 1;
}

void testcroissant(listeint l){
    listeint p;
    p = l;
    int croissant = 1;
    while(p -> suivant != NULL){
        if(p -> val > p -> suivant -> val){
            croissant = 0;
        }
        p = p -> suivant;
    }
    if(croissant == 1){
        printf("la liste est croissante\n");
    }
    else{
        printf("la liste n'est pas croissante\n");
    }
}


/*void testnbrdonne(listeint l, int n){
    listeint p;
    p= l;
    int compteur = 0;
    while( vide(p)== 0 && compteur =0){
        if(p -> val == n){
            printf("le nombre %d est dans la liste\n",n);
            compteur= 1;
        }
        p = p -> suivant;
    }
}*/

listeint trielist(listeint l){
    listeint p;
    p = l;
    int temp;
    while(p -> suivant != NULL){
        if(p -> val > p -> suivant -> val){
            temp = p -> val;
            p -> val = p -> suivant -> val;
            p -> suivant -> val = temp;
        }
        p = p -> suivant;
    }
    return l;
}

int nbr_element(listeint l){
    listeint p;
    p = l;
    int compteur = 0;
    while(p != NULL){
        compteur++;
        p = p -> suivant;
    }
    return compteur;
}

listeint inversion_liste(listeint l){
    listeint p;
    p = l;
    listeint q;
    q = NULL;
    while(p != NULL){
        q = insertionentete(q,p -> val);
        p = p -> suivant;
    }
    return q;
}

void test(int p, int v){
    if(p == 10 or v == 10){
        printf("oui\n");
    }
    else{
        printf("non\n");
    }
}