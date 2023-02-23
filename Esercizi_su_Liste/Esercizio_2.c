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
            new_element = createNewNode(n); //Crea un nuovo nodo

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

//torna il numero di elementi contenuti nella lista
int nElementsInList(list a){
    int n_elements = 0;
    
    while(a != NULL){
        a = a->next;
        n_elements++;    
    }

    return n_elements;
}

//Funzione Ricorsiva che stampa la lista
void printListRic(list a){
  if (a != NULL)
    {
      printf ("%d\n", a->info);
      printListRic(a->next);
    }
}

void main(){
    list a = createList();
    printf("%d \n", nElementsInList(a));
}