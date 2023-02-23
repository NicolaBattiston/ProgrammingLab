#include<stdio.h>

int find_index(int * p, int dim){

    int index_ok = 0;
    int index = 0;
    
    while(index < dim && index_ok == 0){

        int index_ok = 1;
        int j = 0;
        
        while(j < dim && index_ok == 1){
            
            if(j <= index){
                if(*(p + j) > index){
                    index_ok = 0;
                    if(index == 11){
                        printf("%d", *(p + j));
                    }
                }
            }else{
                if(*(p + j) <= index){
                    index_ok = 0;
                    if(index == 11){
                        printf("%d", *(p + j));
                    }
                }
            }

            j++;
        }
        if(index_ok == 0){
            index++;
        }else{
            return index;
        }
    }
    
    return -1;
}

void main(){
    int n_elem_array = 18;
    
    int valori[18] = {1,2,4,0,2,4,2,1,4,11,0,11,65,61,31,54,78,90};

    int index = find_index(valori, n_elem_array);

    if(index == -1){
        printf("Non Esiste l'elemento richiesto");
    }else{
        printf("L'elemento richiesto è in posizione: %d", index);
    }

    printf("\n");
}