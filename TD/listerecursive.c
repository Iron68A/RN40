#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0


//algorithme recursif pour compter les elements d'une liste
//cas trivial : liste vide
/*
entre : liste l
sortie : entier n, le nombre d'elements de la liste
int compter(liste l)
Si est_vide(l) alors
    n <- 0
Sinon
    n <- 1 + compter(reste(l))
*/

int compter (liste l)
{
    if (est_vide(l))
        return 0;
    else
        return 1 + compter(reste(l));
}
//algorithme recursif pour tester si un element appartient a une liste

/*
entre : liste l, element e
sortie : booleen b, vrai si e appartient a l, faux sinon
int appartient(liste l, element e)
Si est_vide(l) alors
    b <- faux
Sinon
    Si tete(l) = e alors
        b <- vrai
    Sinon
        appartient(l,e) <- appartient(reste(l), e)
*/

int appartient (liste l, element e)
{
    if (est_vide(l))
        return 0;
    else
        if (tete(l) == e)
            return 1;
        else
            return appartient(reste(l), e);
}
//algo recursif pour tester si une liste est triee par odre croissant

/*
entre : liste l
sortie : booleen b, vrai si l est triee par ordre croissant, faux sinon
int est_triee(liste l)
Si est_vide(l) ou reste(l)=1 alors
    b <- vrai
Sinon
    si valeur(l) > valeur(reste(l)) alors
        b <- faux
    Sinon
        est_triee(l) <- est_triee(reste(l))
*/

//algo recursif pour concatener deux listes
/*
entre : liste l1, liste l2
sortie : liste l3, la concatenation de l1 et l2
liste concatener(liste l1, liste l2)
Si est_vide(l1) alors
    l3 <- l2
si est_vide(l2) alors
    l3 <- l1
sinon 
    l3 <- inserer(tete(l1), concatener(reste(l1), l2))
*/
typedef struct {
  float coeff;
  int degre;
} monome;
/* Calcul poly recursive
    entre : liste l de monomes, float x 
    sortie : float y, la valeur du polynome pour x
    float calcul_poly(liste l, float x)
    Si est_vide(l) alors
        y <- 0
    Sinon
        ploynome(l,x) = coef(val(l)) * pw(x, degre(val(l))) + calcul_poly(reste(l), x)
*/

//algorithme récursif pour trier une liste par ordre croissant
/*
entre : liste l
sortie : liste l1 triee par ordre croissant
liste trier(liste l)
Si est_vide(l) ou reste(l) = 1 alors
    l <- l
Sinon
    Si valeur(l) > valeur(reste(l)) alors
        l1 <- inserer(valeur(reste(l)), inserer(valeur(l)), trier(reste(reste(l))))
    Sinon
        l <- inserer(valeur(l), trier(reste(l)))
*/

*/