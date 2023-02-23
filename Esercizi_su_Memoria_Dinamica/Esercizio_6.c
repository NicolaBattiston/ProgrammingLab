#include<stdio.h>
#include <stdlib.h>

void ruota_array(int * p, int dim, int k){
    int * array = (int *)malloc(sizeof(int) * dim); 

    for(int i = 0; i< dim; i++){
        *(array + i) = *(p + i);
    }

    for(int i = 0; i < dim; i++){
        int new_pos = (dim + i + k) % dim;
        
        *(p + new_pos) = *(array + i);
    }
}

void main(){
    int dim_array;
    printf("Inserire dimensione Array: ");
    scanf("%d", &dim_array);

    int * array = (int *)malloc(sizeof(int) * dim_array); 
    
    for(int i = 0; i < dim_array; i++){
        *(array + i) = rand() % 50;
    }

    for(int i = 0; i < dim_array; i++){
        printf("%d ", *(array + i));
    }

    printf("\n");

    ruota_array(array, dim_array, - 5);    
    
    for(int i = 0; i < dim_array; i++){
        printf("%d ", *(array + i));
    }

    printf("\n");
}