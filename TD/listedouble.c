#include<stdio.h>
#define TRUE 1
#define FALSE 0


//liste doublement chainée

typedef struct cellule{
    int val;
    struct cellule *suiv;
    struct cellule *prec;
}cellule;
typedef cellule *liste;

int estvide(liste l){
    if(l == NULL) return 1;
    else return 0;
}

//element suivantde la liste
liste suivant(liste l){
    if(l == NULL) return NULL;
    else return l -> suiv;
}

//element precedent de la liste
liste precedent(liste l){
    if(l == NULL) return NULL;
    else return l -> prec;
}

liste insertionentete(liste l,int val){
    liste p;
    p = (cellule *)malloc(sizeof(cellule));
    p -> val = val;
    p -> suiv = l;
    p -> prec = NULL;
    if(l != NULL) l -> prec = p;
    return p;
}

liste insertionenfin(liste l,int val){
    liste p;
    p = (cellule *)malloc(sizeof(cellule));
    p -> val = val;
    p -> suiv = NULL;
    if(l == NULL){
        p -> prec = NULL;
        l = p;
    }
    else{
        liste q;
        q = l;
        while(q -> suiv != NULL){
            q = q -> suiv;
        }
        q -> suiv = p;
        p -> prec = q;
    }
    return l;
}



//important 

liste suppTete(liste l){
    cellule * temp;
    if (estvide(l)) return NULL;
    else if (l->suiv == NULL){
        free(l);
        return NULL;
    }
    else{
        temp = l->suiv;
        temp -> prec = NULL;
        free(l);
        return temp;
    } 
}

liste suppfin(liste l){
    if (estvide(l)) return NULL;
    else if (l->suiv == NULL){
        free(l);
        return NULL;
    }
    else{
        liste q;
        liste d;
        q = l;
        while(q -> suiv != NULL){
            d = q;
            q = q -> suiv;
        }
        d -> suiv = NULL;
        free(q);
        return l;
    }
}

liste suppvaleur(liste l, int v){
    liste i;
    if( estvide(l)) return l;
    else if (l->suiv ==NULL)
    {
        if(l->val == v){
            free(l);
            return l;
        }
        else return l;
    }
    else {
        i =l;
        while (i->suiv != NULL && i->val != v)
        {
            i = i->suiv;
        }
        if(i->val == v){
            if(i->prec == NULL){
                l = suppTete(l);
                return l;
            }
            else if(i->suiv == NULL){
                l = suppfin(l);
                return l;
            }
            else{
                i = i->prec;
                
                i->suiv = i->suiv->suiv;
                i->suiv->prec = i;
                free(i);
                return l;
            }
        }
    }
}

liste suppoccurence(liste l,int v){
    while(l->suiv != NULL){
        if(l->val == v && l->prec == NULL){
            suppTete(l);
        }
        else if (l->val == v && l->suiv == NULL){
            suppfin(l);
        }
        else if (l->val == v){
            suppvaleur(l,v);
        }
        else{
            l = l->suiv;
        }
    }
}