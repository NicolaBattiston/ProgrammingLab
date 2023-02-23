#include<stdio.h>
#include <stdlib.h>

int trova_elemento(int a[], int start, int finish, int elemento){
    int trovato = 1;

    for(int i = start; i<=finish; i++){
        if(a[i] == elemento){
            trovato = 0;
        }
    }

    return trovato;
}

int n_elem_diversi(int a[], int dim){
    int nElem = 0;

    for(int i = 0; i<dim; i++){
        if(trova_elemento(a, 0, i-1, a[i]) == 1){
            nElem++;
        }
    }

    return nElem;
}

int * delete_duplicates(int array1[], int dim) {
    int nElem = n_elem_diversi(array1, dim);

    int * array2 = (int *)(malloc(sizeof(int) * nElem));

    int cont_array2 = 0;

    for(int i = 0; i<dim; i++){
        if(trova_elemento(array1, 0, i-1, array1[i]) == 1){
            array2[cont_array2] = array1[i];
            cont_array2++;
        }
    }

    return array2;
}

void main(){
    int valori[22] = {2,4,4,1,1,1,1,1,1,1,3,3,3,3,3,6,7,6,5,11,34,51};
    int * valori2 = delete_duplicates(valori, 22);

    int dim_array2 = n_elem_diversi(valori, 22);
    
    for(int i = 0; i<dim_array2; i++){
        printf("%d \n", *(valori2 + i));
    }
}