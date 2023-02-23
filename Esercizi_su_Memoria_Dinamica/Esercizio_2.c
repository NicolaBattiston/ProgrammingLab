#include<stdio.h>

int n_maggiori(int * p, int dim, int elemento){
    int n_elem = 0;
    
    for(int i = 0; i < dim; i++){
        if(*(p + i) > elemento){
            n_elem++;
        }
    }

    return n_elem;
}

int scambia(int * p, int index1, int index2){
    int buffer = *(p + index1);
    *(p + index1) = *(p + index2);
    *(p + index2) = buffer;
}

void riordina_array(int * p, int dim, int numero){
    
    int n_elem_maggiori = n_maggiori(p, dim, numero);
    
    int posizione = dim - n_elem_maggiori - 1;
    
    for(int i = 0; i <= posizione; i++){
        if(*(p + i) > numero){
            int index2 = posizione + 1;
            while(index2 < dim){
                if(*(p + index2) <= numero){
                    scambia(p, i, index2);
                }
                index2++;
            }
        }
    }
}

void main(){
    int n_elem_array = 34;
    
    int valori[34] = {5,86,31,9,45,17,82,63,55,4,20,99,1,74,66,12,3,28,39,51,7,26,46,31,2,7,15,73,67,11,24,69,31,74};

    riordina_array(valori, n_elem_array, 15);

    for(int i = 0; i < n_elem_array; i++){
        printf("%d ", *(valori + i));
    }

    printf("\n");
}