#include <stdio.h>

int pot(int n){
    if(n == 0){
        return 1;
    }

    return 2 * pot(n - 1);
}

int produttoria(int a, int b){
    int produttoria = 1;

    for(int i = a; i <= (b/2); i++){
        produttoria *= pot(i)/a;
    }

    return produttoria - b;
}

int main(){

    int a, b, x;
    
    printf("Inserire numero iniziale: ");
    scanf("%d", &a);
    
    printf("Inserire numero finale: ");
    scanf("%d", &b);

    printf("%d", produttoria(a, b));
}