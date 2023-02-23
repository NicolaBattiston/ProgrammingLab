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

//Ritorna l'ultimo elemento di una lista
list lastElementList(list a){
    if(a != NULL){
        while (a -> next != NULL){
            a = a -> next;
        }
    }

    return a;
}

//Ritorna l'unione delle 2 liste in base a z
list mergeList(list a, list b, int z){
    if(z > 0){
        if(a == NULL){
            return b;
        }else{
            lastElementList(a) -> next = b;
            return a;
        }
    }else{
        
        if(b == NULL){
            return a;
        }else{
            lastElementList(b) -> next = a;
            return b;
        }
    }
}

void main(){
    list a,b;
    int z;
    
    printf("Insert Elements of List A: \n");
    a = createList();
    printf("Insert Elements of List B: \n");
    b = createList();

    printf("Choose a number\n");
    printf(" > 0 for merge a with b \n");
    printf(" <= 0 for merge b with a \n");
    printf("Insert the number: ");
    scanf("%d", &z);
    
    printListRic(mergeList(a, b, z));
}