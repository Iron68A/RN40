#include<stdio.h>
#include<math.h>

/*
* Programme & fonctions de calcul de moyenne, variance et ecart type d'un tableau donné
*@Author: A. BARTHELME
*@Date: 03/10/2022
* @description: TP3 de RN 40 / UTBM 
*
*/
//entête des fontions : 

float moyennetableau(float tableau[], int taille);
float variance(float tableau[], int taille);
float ecarttype(float tableau[], int taille);


// programme 

float moyennetableau(float tableau[], int taille)
{
    float somme = 0;
    for (int i = 0; i < taille; i++)
    {
        somme += tableau[i];
    }
    return somme / taille;
}

float variance(float tableau[], int taille)
{
    float moyenne = moyennetableau(tableau, taille);
    float somme = 0;
    for (int i = 0; i < taille; i++)
    {
        somme += (tableau[i] - moyenne) * (tableau[i] - moyenne);
    }
    return somme / taille;
}

float ecarttype(float tableau[], int taille)
{
    return sqrt(variance(tableau, taille));
}

//MAIN 

int main(){
    //creation du tableau
    int i= 0 ;
    printf("Entrez la taille du tableau: ");
    scanf("%d", &i);
    float tableau[i];
    for (int j = 0; j < i; j++)
    {
        printf("Entrez la valeur %d: ", j);
        scanf("%f", &tableau[j]);
    }
    //Fontions appelées pour le tableau 
    printf("La moyenne du tableau est: %f \n", moyennetableau(tableau, i));
    printf("La variance du tableau est: %f \n ", variance(tableau, i));
    printf("L'ecart type du tableau est: %f \n ", ecarttype(tableau, i));
    

    return 0;
    
}





