#include<stdio.h>

int fun(int a[], int dim, int k){
    int presente = 0;
    
    for(int i = 0; i<dim - 2; i++){
        if(a[i] + a[i + 1] + a[i + 2] == k){
            presente = 1;
        }
    }

    return presente;
}

void main(){
    int valori[10] = {0,1,2,3,4,5,6,7,8,9};

    int presente = fun(valori, 10, 30);

    if(presente == 0){
        printf("Il valore specificato non esiste\n");
    }else{
        printf("Il valore specificato esiste\n");
    }
}