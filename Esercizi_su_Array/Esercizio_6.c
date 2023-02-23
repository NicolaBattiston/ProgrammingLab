#include<stdio.h>

int fun_count_min(int a[], int dim, int k){
    int count = 0;

    for(int i = 0; i<dim; i++){
        if(a[i] <= k){
            count++;
        }
    }

    return count;
}

int fun(int a[], int dim, int k){
    int elemento;

    for(int i = 0; i<dim; i++){
        if(fun_count_min(a, dim, a[i]) == k){
            elemento = a[i];
        }
    }

    return elemento;
}

void main(){
    int valori[10] = {1,3,2,4,6,8,63,72,89,9};
    
    int elemento = fun(valori, 10, 5);

    printf("elemento è: %d\n", elemento);
}