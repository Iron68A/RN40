#include<stdio.h>
#include<math.h>
/*CODE PRIVE
  Programmer en C
  TP 1 RN40
  Sujet dans le repo github

BARTHELME ALEXANDRE 

*/

//declaration des fonctions avant le main, car fonctions apres ( par habitude )
void addition(int n, int matrice1[n][n], int matrice2[n][n], int resultat[n][n]);
void soustraction(int n, int matrice1[n][n], int matrice2[n][n], int resultat[n][n]);
void multiparnbr(int n, int matrice[n][n], int nbr, int resultat[n][n]);
void divparnbr(int n, int matrice[n][n], int nbr, int resultat[n][n]);

int main(){
    int n,i,j;
    int selec;
    int scal;

    //choix
    printf("quel operation voulez vous faire ? \n 1: addition\n 2: soustraction\n 3: mutliplication par un nombre\n 4: division par un nombre \n ");
    scanf("%d",&selec);


    //taille
    printf("Donner la taille des matrices: ");
    scanf("%d",&n);
    int matrice1[n][n],matrice2[n][n],resultat[n][n];

    //remplissage des matrices
    printf("Donner les elements de la matrice 1:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("donner l'element %d %d: ",i,j);
            scanf("%d",&matrice1[i][j]);
        }
    }
    if (selec!=3 && selec!=4){
    printf("Donner les elements de la matrice 2:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Donner l'element %d %d: ",i,j);
            scanf("%d",&matrice2[i][j]);
        }
    }
    }

    //calcul en fct du choix
    switch (selec){
      case 1:
        addition(n,matrice1,matrice2,resultat);
        break;
      case 2:
        soustraction(n,matrice1,matrice2,resultat);
        break;
      case 3:
        printf("Donner le nombre par lequel vous voulez multiplier la matrice: ");
        scanf("%d",&scal);
        multiparnbr(n,matrice1,scal,resultat);
        break;
      case 4:
        printf("Donner le nombre par lequel vous voulez diviser la matrice: ");
        scanf("%d",&scal);
        divparnbr(n,matrice1,scal,resultat);
        break;
      default:
        printf("Un probleme est survenu, relancer le programme en suivant les instructions");
    }




    //affichage du resultat
    printf("La matrice resultat est:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",resultat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//FONCTIONS DE CALCULS


void addition(int n, int matrice1[n][n], int matrice2[n][n], int resultat[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            resultat[i][j]=matrice1[i][j]+matrice2[i][j];         
        }
    }
}

void soustraction(int n, int matrice1[n][n], int matrice2[n][n], int resultat[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            resultat[i][j]=matrice1[i][j]-matrice2[i][j];         
        }
    }
}


void multiparnbr(int n, int matrice[n][n], int nbr, int resultat[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            resultat[i][j]=matrice[i][j]*nbr;         
        }
    }
}

void divparnbr(int n, int matrice[n][n], int nbr, int resultat[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            resultat[i][j]=matrice[i][j]/nbr;         
        }
    }
}