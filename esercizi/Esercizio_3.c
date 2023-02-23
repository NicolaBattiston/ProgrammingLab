void main()
{
    int n, k, coeff_Binomiale = 1;

    printf("Inserire il numero n: ");
    scanf("%d", &n);

    printf("Inserire il numero k: ");
    scanf("%d", &k);

    for(int i = n; i>k; i--){
        coeff_Binomiale = coeff_Binomiale * i;
    }

    for(int i = n-k; i>1; i--){
        coeff_Binomiale = coeff_Binomiale / i;
    }

    printf("%d \n", coeff_Binomiale);
}