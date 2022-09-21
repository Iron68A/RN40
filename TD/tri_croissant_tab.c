#include<stdio.h>
//fonction qui trie un tableau de par ordre croissant
int tri_croissant_tab(int tab[], int taille){
    int i, j, temp;
    for(i=0; i<taille; i++){
        for(j=i+1; j<taille; j++){
            if(tab[i]>tab[j]){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    printf("le tablrau trie est: ");
    for(i=0; i<taille; i++){
        printf("%d ", tab[i]);
    }
}

int main()
{
    printf("Taille du tableau: ");
    int taille;
    scanf("%d", &taille);
    int tab[taille];
    for(int i=0; i<taille; i++){
        printf("Entrer la valeur %d: ", i+1);
        scanf("%d", &tab[i]);
    }
    tri_croissant_tab(tab, taille);
    return 0;
}
