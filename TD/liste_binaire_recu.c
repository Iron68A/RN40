//ALGO Récursif
/**
 * Entrée :  Un nombre entier n
 * Sortie : la liste contenant la représentation binaire de n
 * 
 * Algo:
 * listebinaire(n):
 * Si n=0
 *   alors retourner liste vide 
 * Si n=1 
 *  alors retourner liste contenant 1
 * Sinon
 *   retourner listebinaire(n/2)            // Valeur entière de la division
 *   ajouter n%2 en tete de la liste
 *  
 * 
 * 
 *  
*/






//code

#include <stdio.h>

int listebinaire(int n);
int main()
{
    int n;
    printf("Entrer un nombre entier: ");
    scanf("%d", &n);
    listebinaire(n);
    return 0;
}

int listebinaire(int n)
{
    if (n == 0)
        return 0;
    else
    {
        listebinaire(n / 2);
        printf("%d", n % 2);
    }
}
