#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//Calculer la valeur d’un polynome pour un X donne. Le polynome sera represente par une serie de monomes, c’est-a-dire des couples (coefficient, degre) stockes dans un taleau.

typedef struct {
  float coeff;
  int degre;
} monome;

float valeur_polynome(int n, monome polynome[n], float x) {
  float somme = 0;
  for (int i = 0; i < n; i++) {
    somme += polynome[i].coeff * pow(x, polynome[i].degre);
  }
  return somme;
}


//somme de deux polynomes
monome somme(monome pol1[n],monome pol2[m]){
    monome pol3[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(pol1[i].degre==pol2[j].degre){
        pol3[k].degre=pol1[i].degre;
        pol3[k].coeff=pol1[i].coeff+pol2[j].coeff;
        i++;
        j++;
        k++;
        }
        else if(pol1[i].degre>pol2[j].degre){
        pol3[k].degre=pol1[i].degre;
        pol3[k].coeff=pol1[i].coeff;
        i++;
        k++;
        }
        else{
        pol3[k].degre=pol2[j].degre;
        pol3[k].coeff=pol2[j].coeff;
        j++;
        k++;
        }
    }
    while(i<n){
        pol3[k].degre=pol1[i].degre;
        pol3[k].coeff=pol1[i].coeff;
        i++;
        k++;
    }
    while(j<m){
        pol3[k].degre=pol2[j].degre;
        pol3[k].coeff=pol2[j].coeff;
        j++;
        k++;
    }
    return pol3;

}

