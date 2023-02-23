#include<stdio.h>
#include <stdlib.h>

int ricorrenza(int * p, int dim, int elemento){
    int cont_elem = 0;
    
    for(int i = 0; i < dim; i++){
        if(*(p + i) == elemento){
            cont_elem++;
        }
    }

    return cont_elem;
}

void counting_sort(int * p, int dim, int k){

    int * ricorrenze = (int *)malloc(sizeof(int) * k); 
    
    for(int i = 0; i < k; i++){
        *(ricorrenze + i) = ricorrenza(p, dim, i);
    }

    int indice = 0;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < *(ricorrenze + i); j++){
            *(p + indice) = i;
            indice++;
        }
    }
}

void main(){
    
    int dim_array;
    printf("Inserire dimensione Array: ");
    scanf("%d", &dim_array);

    int range;
    printf("Inserire il range dei valori dell' Array: ");
    scanf("%d", &range);

    int * array = (int *)malloc(sizeof(int) * dim_array); 
    
    for(int i = 0; i < dim_array; i++){
        *(array + i) = rand() % range;
    }

    for(int i = 0; i < dim_array; i++){
        printf("%d ", *(array + i));
    }

    printf("\n");
    
    counting_sort(array, dim_array, range);

    for(int i = 0; i < dim_array; i++){
        printf("%d ", *(array + i));
    }

    printf("\n");
}