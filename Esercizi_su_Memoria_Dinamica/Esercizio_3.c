#include<stdio.h>
#include <stdlib.h>

int * somma_array(int * p, int * q, int dim_p, int dim_q){

    int * r = (int *)malloc(sizeof(int) * (dim_p + dim_q));

    int index_q = 0;
    int index_r = 0;
    
    for(int index_p = 0; index_p < dim_p; index_p++){
        while(*(p + index_p) > *(q + index_q)){
            *(r + index_r) = *(q + index_q);
            index_r++;
            index_q++;
        }

        *(r + index_r) = *(p + index_p);
        index_r++;
    }

    while(index_q < dim_q){
        *(r + index_r) = *(q + index_q);
        index_r++;
        index_q++;
    }
    
    return r;
}

void main(){

    int dim_val1 = 10, dim_val2 = 10;  
    
    int valori1[10] = {0,2,4,6,8,10,12,14,16,18};
    int valori2[10] = {0,1,2,3,4,5,6,7,8,10};

    int * somma = somma_array(valori1, valori2, dim_val1, dim_val2);

    for(int i = 0; i < dim_val1 + dim_val2; i++){
        printf("%d ", *(somma + i));
    }

    printf("\n");
}