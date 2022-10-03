#include<stdio.h>
#include<math.h>

//entête des fontions :

void recherchetab(float tableau[], int taille, float valeur);
void dichotab(float tableau[], int taille, float valeur);

// programme

void recherchetab(float tableau[], int taille, float valeur)
{
    for (int i = 0; i < taille; i++)
    {
        if (tableau[i] == valeur)
        {
            printf("La valeur %f est dans le tableau à la position %d \n", valeur, i);
            printf("PS : Les indices commencent a 0 \n");
        }
    }
}

void dichotab(float tableau[],int taille, float valeur){
//trier le tableau
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (tableau[i] < tableau[j])
            {
                float temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
    printf("Le tableau trie est: ");
    for (int i = 0; i < taille; i++)
    {
        printf("%f ", tableau[i]);
    }
    
//trouver milieu puis valeur 
    int milieu = taille/2;
    printf("miliue = %d et contenu = %f \n", milieu, tableau[milieu]);
    if (tableau[milieu] == valeur)
    {
        printf("La valeur %f est dans le tableau à la position %d \n", valeur, milieu);
        
    }
    else if (tableau[milieu] > valeur)
    {
        for (int i = 0; i < milieu; i++)
        {
            if (tableau[i] == valeur)
            {
                printf("La valeur %f est dans le tableau à la position %d \n", valeur, i);
                
            }
        }
    }
    else if (tableau[milieu] < valeur)
    {
        for (int i = milieu; i < taille; i++)
        {
            if (tableau[i] == valeur)
            {
                printf("La valeur %f est dans le tableau a la position %d \n", valeur, i);
                
            }
        }
    }
    else printf("La valeur %f n'est pas dans le tableau \n", valeur);


}




//Main 
int main(){
    int i =0;
    printf("Entrez la taille du tableau puis son contenu :");
    scanf("%d", &i);
    float tableau[i];
    for (int j = 0; j < i; j++)
    {
        printf("Entrez la valeur %d: ", j);
        scanf("%f", &tableau[j]);
    }
    float valeur;
    printf("Entrez maintenant la valeur a rechercher : ");
    scanf("%f", &valeur);
    printf("valeur chercher par methode de comparaison : \n");
   recherchetab(tableau, i, valeur);
    printf("valeur chercher par methode de dichotomie : \n");
    dichotab(tableau, i, valeur);
    return 0;

}