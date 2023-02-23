#include<stdio.h>

int fun(int a[], int dim){
    int somma = 0;
    for(int i = 0; i<dim; i++){
        if(a[i] % 2 == 0){
            somma = somma + a[i];
        }
    }

    return somma;
}

void main(){
    int valori[10] = {0,1,2,3,4,5,6,7,8,9};

    int somma = fun(valori, 10);

    printf("La somma è di: %d\n",somma);
}