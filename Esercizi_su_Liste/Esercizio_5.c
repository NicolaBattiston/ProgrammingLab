#include<stdio.h>
#include<stdlib.h>

typedef struct node list_element;
typedef list_element * list;

struct node{
  int info;
  list next;
};

//crea un nuovo nodo  
list createNewNode(int element){
    list new_element = malloc (sizeof (list_element));

    new_element -> info = element;
    new_element -> next = NULL;

    return new_element;
}

//torna una lista di elementi fino a che l'Input è != -1 
list createList(){
    list a = NULL, new_element, coda = NULL;
    int n = 0;
  
    while (n != -1){
        
        printf ("Inserisci un nuovo elemento: ");
        scanf ("%d", &n);
        
        if (n != -1){
            //Crea un nuovo nodo
            new_element = createNewNode(n);

            if(a == NULL){
                a = new_element;
            }else{
                coda -> next = new_element;
            }

            coda = new_element;
    	}
    }

  return a;
}

//Funzione Ricorsiva che stampa la lista
void printListRic(list a){
  if (a != NULL)
    {
      printf ("%d\n", a->info);
      printListRic(a->next);
    }
}

//sposto la testa della lista k volte (metodo ricorsivo)
list moveHeadListRic(list a, int k){
    if(k == 0){
        return a;
    }
    
    list buffer = a;
    a = a -> next;
    free(buffer);
    return moveHeadListRic(a, k - 1);
}

void main(){
    list a = createList();

    int k;
    printf("Inserisci l'indice della sottolista desiderata: ");
    scanf("%d", &k);
    
    a = moveHeadListRic(a, k);
    printListRic(a);
    //printListRic(moveHeadListRic(createList(), 5));
}