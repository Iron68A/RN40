#include<stdio.h>

float moyennetableau(float tab[], int taille){
    float somme = 0;
    for(int i=0; i<taille; i++){
        somme += tab[i];
    }
    return somme/taille;
}

float variancetableau(float tab[], int taille){
    float moyenne = moyennetableau(tab, taille);
    float somme = 0;
    for(int i=0; i<taille; i++){
        somme += (tab[i]-moyenne)*(tab[i]-moyenne);
    }
    return somme/taille;
}

int main(){
    int taille = 0;
    printf("entrer la taille du tableau: ");
    scanf("%d", &taille);
    float tab[taille];
    for(int i=0; i<taille; i++){
        printf("entrer la valeur %d: ", i);
        scanf("%f", &tab[i]);
    }
    printf("la moyenne est de %f \n", moyennetableau(tab, taille));
    printf("la variance est de %f \n", variancetableau(tab, taille));
    return 0;

}