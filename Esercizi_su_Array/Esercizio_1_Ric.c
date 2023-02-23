#include<stdio.h>

int fun(int a[], int dim){
    if(dim == 0){
        return a[0];
    }

    return a[dim - 1] + fun(a, dim - 1);
}

void main(){
    int valori[10] = {0,1,2,3,4,5,6,7,8,9};

    int somma = fun(valori, 10);

    printf("La somma è di: %d\n",somma);
}