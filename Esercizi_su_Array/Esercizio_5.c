#include<stdio.h>

void fun(int * p, int n){
    *p = 1;
    
    for(int i = 1; i<n; i++){
        *(p + i) = *(p + i - 1) + i + 1; 
    }
}

void main(){
    int nElem = 10;
    
    int a[10];

    fun(&a, nElem);

    for(int i = 0; i<nElem; i++){
        printf("Elemento Triangolare %d è %d \n",i + 1,a[i]);
    }
}