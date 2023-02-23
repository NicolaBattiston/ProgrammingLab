#include <stdio.h>

void main()
{
    int n;
    int nElem = 0;
    float somma;

    while(n != 0)
    {
        printf("Inserisci un numero intero da tastiera: ");
        scanf("%d", &n);
        somma = somma + n;
        nElem++;
    }
    nElem--;
    printf("La media è: %f \n", somma/nElem);
}