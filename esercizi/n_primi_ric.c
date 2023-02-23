#include <stdio.h>

int radice2(int n){
    for(int i = 0; i<n; i++){
        if(i * i >= n){
            return (i);
        }
    }
}

int n_primo_ric(int n, int div){
    
    if(n == 1){
        return 0;
    }
    
    if(n % div == 0){
        return div;
    }

    if(div % 2 == 0){
        return n_primo_ric(n, div + 1);
    }

    if(radice2(n) < div){
        return n;
    }
    
    return n_primo_ric(n, div + 2);

}

int main(){

    int n, divisore;

    printf("Inserisci il numero intero da verificare se è primo: ");
    scanf("%d", &n);

    divisore = n_primo_ric(n, 2);

    if(divisore != n){
        printf("Il numero %d non è primo\n", n);
    }else{
        printf("Il numero %d è primo\n", n);
    }
    
    return 0;
}