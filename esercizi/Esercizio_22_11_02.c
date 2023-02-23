#include <stdio.h>

int pot(int base, int potenza){
    if(potenza == 1){
        return (base);
    }
    
    return (base * pot(base, potenza - 1));
}

int pot_ite(int base, int potenza){
    int prodotto = 1;
    
    for(int i = 1; i<=potenza; i++){
        prodotto = prodotto * base;    
    }
}

int sommatoria(int i, int n, int k){
    if(i == n){
        return (i * pot(k, i + 1))/pot(3, i);
    }

    return ((i * pot(k, i + 1))/pot(3, i) + sommatoria(i + 1, n, k));
}

void main(){
    int i, n, k;

    printf("Inserire l'inizio della somatoria (i): ");
    scanf("%d", &i);

    printf("Inserire la fine della somatoria (n): ");
    scanf("%d", &n);

    printf("Inserire la costante nel calcolo della somatoria (k): ");
    scanf("%d", &k);

    printf("%d \n", sommatoria(i,n,k));
}