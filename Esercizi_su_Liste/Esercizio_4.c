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

list insertElement(list a, int k){

    //creo un nodo con il nuovo elemento
    list new_element = createNewNode(k);

    //caso 1: l'elemento va inserito prima di tutta la lista
    if(a -> info > k){
        new_element -> next = a;
        
        return new_element;
    }else{
        //l'elemeno non è il più piccolo
        //controllo se la lista contiene 1 o più elementi 
        if(a -> next != NULL){
            //la lista contiene più di 1 elemento
            
            list coda = a;

            while(coda -> next -> info < k && coda -> next -> next != NULL){
                coda = coda -> next;
            }

            if(coda -> next -> info >= k){
                //caso 2: l'elemento va inserito internamente alla lista
                new_element -> next = coda -> next;
                coda -> next = new_element;
            }else{
                //caso 3: l'elemento va inserito in fondo alla lista
                coda -> next -> next = new_element;
            }
        }else{
            //la lista contiene 1 elemento
            //L'elemento non è il più piccolo -> va in fondo alla lista
            a -> next = new_element;
        }
        
        return a;
    }
}

void main(){
    list a = createList();
    
    int k;
    printf("Inserisci il nuovo elemento da inserire: ");
    scanf("%d", &k);
    
    a = insertElement(a, k);
    printListRic(a);
}