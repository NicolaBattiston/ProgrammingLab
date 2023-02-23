#include<stdio.h>

int fun_somma(int a[], int dim){
    int somma = 0;

    for(int i = 0; i<dim; i++){
        somma = somma + a[i];
    }

    return somma;
}

int fun(int a[], int b[], int dim_a, int dim_b){
    int somma = fun_somma(a, dim_a);

    int verificato = 0;
    
    for(int i = 0; i<dim_b; i++){
        if(b[i] == somma){
            verificato = 1;
        }
    }

    return verificato;
}

void main(){
    int valori1[10] = {0,1,2,3,4,5,6,7,8,9};
    int valori2[10] = {0,1,2,3,4,5,4};

    int verificato = fun(valori1, valori2, 10, 7);

    if(verificato == 0){
        printf("Non esiste la somma del primo array nel secondo\n");
    }else{
        printf("Esiste la somma del primo array nel secondo\n");
    }
}