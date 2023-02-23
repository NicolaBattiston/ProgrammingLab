#include <stdio.h>

int pow2_rico(int n)
{
    if (n==1)
    {
        return 2;
    }
    else 
    { 
        return 2 * pow2_rico(n - 1);
    }
}

int somm_rico(int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
       return n+somm_rico(n-1); 
    }
}

void main()
{
    for(int n = 1; n<11; n++)
    {
        int serie=pow2_rico(n);
        serie=serie*somm_rico(n);
        printf("la serie è: %d \n", serie);
    }
}