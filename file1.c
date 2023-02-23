#include<stdio.h>
#include <stdlib.h>

double media(int * p, int dim){
    if(dim == 1){
        return *p;
    }

    double m_prec = media(&(*(p + 1)), dim - 1);
    return m_prec + (*(p) - m_prec)/dim;
}

void main(){
    int a[10] = {1, 4, 3, 7, 6, 34, 56, 75, 24, 10};
    printf("%f\n", media(a, 10));
}