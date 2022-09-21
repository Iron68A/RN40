#include<stdio.h>

//inserer un nombre dans un tableau de nombres croissants
int main(){
    int taille = 0;
    printf("entrer la taille du tableau: ");
    scanf("%d", &taille);
    int tab[taille];
    for(int i=0; i<taille; i++){
        printf("entrer la valeur %d: ", i);
        scanf("%d", &tab[i]);
    }
    int val = 0;
    printf("entrer la valeur a inserer: ");
    scanf("%d", &val);
    int i = 0;
    while(val>tab[i] && i<taille){
        i++;
    }
    for(int j=taille; j>i; j--){
        tab[j] = tab[j-1];
    }
    tab[i] = val;
    for(int i=0; i<taille+1; i++){
        printf("%d ", tab[i]);
    }
    return 0;
}

