#include<stdio.h>

float ccinteg(float a, float b, int n){
float h = (b-a)/n;
float sol = 0;
float i= a;
while (i<b){
 sol = sol+((1/i)+(1/(i+h)))/2*h;
 i = i+h;
 }
 return sol;
}

int main(){
 float a2,b2;
 int n2;
 printf("entrer les valeurs\n");
 scanf("%f %f %d", &a2,&b2,&n2);
 printf("res est %f ",ccinteg(a2,b2,n2));
 return (0);
}