#include<stdio.h>

int fun(int a[], int b[], int dim){
    int somma = 0;

    for(int i = 0; i<dim; i++){
        somma = somma + (a[i]*b[i]);
    }

    return somma;
}

void main(){
    int valori1[10] = {0,1,2,3,4,5,6,7,8,9};
    int valori2[10] = {0,1,2,3,4,5,6,7,8,9};

    int somma = fun(valori1, valori2, 10);

    printf("La somma è di: %d\n",somma);
}