#include<stdio.h>
#include <stdlib.h>

int scambia(int * p, int index1, int index2){
    int buffer = *(p + index1);
    *(p + index1) = *(p + index2);
    *(p + index2) = buffer;
}

int verifica_prec(int * p, int index, int pari){
    if(pari == 1){
        if(*(p + index - 1) < *(p + index)){
            scambia(p, index - 1, index);
            return 0;
        }
    }else{
        if(*(p + index - 1) > *(p + index)){
            scambia(p, index - 1, index);
            return 0;
        }
    }

    return 1;
}

void onda_order_array(int * p, int dim){
    int finito = 0;

    while(finito == 0){
        finito = 1;
        int i = 1;
        
        while(i < dim && finito == 1){
            finito = verifica_prec(p, i, i%2);
            i++;
        }
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
    
    onda_order_array(array, dim_array);

    for(int i = 0; i < dim_array; i++){
        printf("%d ", *(array + i));
    }

    printf("\n");
}