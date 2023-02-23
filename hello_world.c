#include <stdio.h>

void main()
{
    int fattore_1;
    int fattore_2;
    int prodotto, prodotto_1;

    for (int i = 2; i < 102; i++) {
        fattore_1 = i;
        fattore_2 = 1564738457;
        prodotto = 0;
        prodotto_1 = fattore_1 * fattore_2;
        
        while (fattore_1 != 0) {
            if (fattore_1 % i != 0) {
                prodotto = prodotto + fattore_2;
            }
        fattore_1 = fattore_1 / i;    
        fattore_2 = fattore_2 * i;
        }

        //controllo se per qualche numero non vale la regola
        if(prodotto_1 != prodotto){
            printf("Non vale per il numero: %d", i);
        }else{
            if((i - 2) % 10 == 0){
                printf("OK ");
                printf("\n");
            }else{
                printf("OK ");    
            }
        }
    }
    printf("\n");
}
