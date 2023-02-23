double sommatoria(int k, int n){
    if(k == n){
        return 1.0/((2.0 * k + 1.0)*(2.0 * k + 1.0));
    }

    return 1.0/((2.0 * k + 1.0)*(2.0 * k + 1.0)) + sommatoria(k + 1, n);
}

int main(){

    float n;
    
    printf("Inserire numero: ");
    scanf("%f", &n);

    printf("%f \n", sommatoria(0, n));
}