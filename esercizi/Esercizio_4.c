int min(int x, int y, int z){
    int min;
    
    if(x <= y && x <= z){
        min = x;
    }else if(y <= x && y <= z){
        min = y;
    }else{
        min = z;
    }

    return min;
}

void test(int x, int y){
    int isMin;
    
    if(x>=y){
        for(int w = 1; w < x; w++){
            printf("Il minimo tra %d, %d, %d, è: %d\n", x, y, w, min(x,y,w));
        }
    }else{
        for(int w = 1; w < y; w++){
            printf("Il minimo tra %d, %d, %d, è: %d\n", x, y, w, min(x,y,w));
        }
    }
}

void main()
{
    int n1, n2;

    printf("Inserire il primo numero:\n ");
    scanf("%d", &n1);

    printf("Inserire il primo numero:\n ");
    scanf("%d", &n2);

    test(n1, n2);

}