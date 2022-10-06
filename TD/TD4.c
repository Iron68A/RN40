#include<stdio.h>
#include<stdlib.h>


/*
//elements necessaires pour liste chainee d'entiers
typedef struct element{
    int val;
    struct element *suivant;
}element;

typedef element *listeint;

int vide(listeint l);
listeint insertionentete(listeint l, int val);


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
*/
int main(){
    int a = 3;      
    int b = 10;
    int c, *pa, *pb, *pc;
    pa = &a;                    //pa pointe sur a
    *pa = *pa * 2;          //a = 6
    pb = &b;                //pb pointe sur b
    c = 3 * (*pb - *pa);    //c = 3 * (10 - 6) = 12
    pc = pb;            //pc pointe sur b
    pa = pb;               //pa pointe sur b
    pb = pc;            //pb pointe sur b
    printf("%d %d %d %d %d %d", a, b, c, *pa, *pb, *pc);

    return 1;

}


/*

int main(){
    listeint l;
    l = NULL;
    int val = 4;
    int val2 = 5;
    int val3 = 6;
    l = insertionentete(l, val);
    l = insertionenfin(l, val2);
    l = insertionentete(l, val3);
//affichage de la liste
    while(l != NULL){
        printf("%d ", l->val);
        l = l->suivant;
    }
    free(l);

    return 1;
}
*/