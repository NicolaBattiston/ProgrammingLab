#include <stdio.h>

double succ(double a_n){
    double ris = (a_n + 1)/2;
    
    print("%f", ris);

    return ris;
}

int main(){
    int n;

    print("Inserire il numero della successione: ");
    scanf("%d", &n);
    
    double a_n = 0;

    for(int i = 0; i<n; i++){
        a_n = succ(a_n);
        print("%d", a_n);
    }

    return 0;
}