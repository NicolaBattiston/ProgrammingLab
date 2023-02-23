#include<stdio.h>

void fun(int a[], int * b, int dim){
    int cont_j = 0;
    
    for(int i = 0; i<dim; i++){
        int verificato = 1;
        for(int j = 0; j<dim; j++){
            if(i != j){
                if(!(a[i] % a[j] != 0)){
                    verificato = 0;
                }
            }
        }
        if(verificato == 1){
            *(b + cont_j) = a[i];
            cont_j++;
        }
    }
}

void main(){
    int dimensione = 10;
    
    int valori1[] = {10,4,5,3,2,6,8,71,84,9};
    int valori2[] = {0,0,0,0,0,0,0,0,0,0};
    
    fun(valori1, &valori2, dimensione);

    for(int i = 0; i<dimensione; i++){
        printf("%d ", valori2[i]);
    }

    printf("\n");
}