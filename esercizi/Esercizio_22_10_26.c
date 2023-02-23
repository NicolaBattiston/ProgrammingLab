#include <stdio.h>

int somm1(int i){
    if(i == 1){
        return 1;
    }
    return i + (somm1(i - 1));
}

int somm2(int a, int b){
    int sommatoria = 0;
    
    for(int i = a; i<=b; i++){
        sommatoria += somm1(i);
    }

    return sommatoria;
}

int sommVeloce(int a, int b){
    int sommatoria = (b - a + 1) * somm1(a);

    for(int i = b - a; i > 0; i--){
        a++;
        sommatoria += i * a;
    }

    return sommatoria;
}

int main(){

    int a,b;
    
    printf("Inserire numero iniziale: ");
    scanf("%d", &a);
    
    printf("Inserire numero finale: ");
    scanf("%d", &b);

    for(int i = 0; i<100; i++){
        somm2(a, b);
    }
    
    printf("Risultato: %d \n", somm2(a, b));

    for(int i = 0; i<1000000000 i++){
        sommVeloce(a, b);
    }
    
    printf("Risultato: %d \n", sommVeloce(a, b));
    
}