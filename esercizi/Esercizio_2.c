void main()
{
    /*
    int n, k, sommatoria;

    printf("Inserire il numero n: ");
    scanf("%d", &n);

    printf("Inserire il numero k: ");
    scanf("%d", &k);
*/
    int sommatoria, sommatoria2;

    for(int n = 1; n<100; n++){
        for(int k = 1; k<100; k++){    

            sommatoria = 0;
            for(int i = 1; i<=n; i++){
                int potenza = 1;
                
                for(int j = 0; j<i; j++){
                    potenza = potenza * k;                            
                }
        
                sommatoria = sommatoria + potenza; 
            }

            sommatoria2 = k;
            for(int i = 1; i<n; i++){
                sommatoria2 = (sommatoria2 + 1) * k;
            }
            
            if(sommatoria != sommatoria2){
                printf("Errore!");
            }
        }
    }

    printf("ok \n");
}