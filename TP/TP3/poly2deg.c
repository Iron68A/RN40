#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void seconddeg(float a, float b, float c,int *n, float *x1, float*x2);

int main(){
float a,b,c,x1,x2;
int n;
printf("Entrez les valeurs a,b,c \n");
scanf("%f %f %f",&a,&b,&c);
seconddeg(a,b,c,&n,&x1,&x2);
if (n==0){
    printf("Pas de solutions dans R");
}
else if (n==1){ 
    printf("La solution est %f",x1);
}
else {
    printf("Les solutions sont %f et %f",x1,x2);
}
return 0;
}

void seconddeg(float a, float b, float c,int *n, float *x1, float*x2){
    printf("la fonction est %f*x^2+%f*x+%f \n" ,a,b,c);
    float delta=(b*b)-(4*a*c);
    if (delta<0) *n=0;
    else if (delta==0) {
        *n=1;
        *x1=(-1*b)/(2*a);
    }
    else {
        *n=2;
        *x1=((-1*b)-sqrtf(delta))/(2*a);
        *x2=((-1*b)+sqrtf(delta))/(2*a);
    }

}