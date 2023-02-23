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

list invertList(list a){
    list a1 = a, new_head = a, coda;

    if(a != NULL){
        if(a -> next != NULL){
            while(a -> next -> next != NULL){
                a = a -> next; 
            }
        
            new_head = a -> next;
            coda = new_head;
            a -> next = NULL;
        
            while(a1 -> next != NULL){
                
                a = a1;
                
                while(a -> next -> next != NULL){
                    a = a -> next; 
                }
            
                coda -> next = a -> next;
                coda = coda -> next;
                a -> next = NULL;
            }
        
            coda -> next = a1;
        }
    }
    return new_head;
}

void main(){
    list a = createList();

    printf("\n\nLista di partenza:\n");
    printListRic(a);
    printf("\n\n");
    
    a = invertList(a);
    
    printf("\n\nLista Finale:\n");
    printListRic(a);
}