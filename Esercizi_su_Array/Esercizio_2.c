#include<stdio.h>

int fun(int a[], int dim){
    int verificato = 1;
    for(int i = 0; i<dim; i++){
        for(int j = i + 1; j<dim; j++){
            if(a[i] == a[j]){
                verificato = 0;
            }
        }
    }

    return verificato;
}


void main(){
    int valori[10] = {0,1,2,3,4,5,6,7,8,9};

    int verificato = fun(valori, 10);

    if(verificato == 0){
        printf("Sono presenti duplicati\n");
    }else{
        printf("Non sono presenti duplicati\n");
    }
}