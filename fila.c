#include <stdlib.h>
#include <stdio.h>
#include "ninja.h"
#include "lista.h"
#include "arvore.h"
#include "fila.h"

//Insere elementos na fila
void insere_fila(l_lista* fila, t_node* node){
  if(fila->inicio == NULL){
    fila->inicio = aloca_elemento();
    fila->inicio->proximo = NULL;
    fila->inicio->anterior = NULL;
    fila->ultimo = fila->inicio;
  }

  else{    
    l_elemento* aux;
    l_elemento* anterior;
    aux = fila->inicio;

    while(aux->proximo != NULL){
      anterior = aux;
      aux = aux->proximo;
    }

    anterior = aux;
    aux->proximo = aloca_elemento();
    aux = aux->proximo;
    aux->proximo = NULL;
    aux->anterior = anterior;
    fila->ultimo = aux;
  }

    fila->quantidade++;
}


//Criamos uma fila onde cada elemento aponta para um no na arvore, a fila ja eh criada
//coloca todos os elementos de um determinado nivel em fila
void cria_fila_nivel(l_lista* fila, t_node* node, int altura_desejada, int altura_atual){
    if(altura_atual < altura_desejada){
        altura_atual++;
        cria_fila_nivel(fila, node->left, altura_desejada, altura_atual);
        cria_fila_nivel(fila, node->right, altura_desejada, altura_atual);
    }

    else{
        insere_fila(fila, node);
    }
}

//Consideramos o no raiz como nivel 0 e seus dois filhos como nivel 1 e assim por diante
l_lista* cria_fila(arvore_raiz* raiz, int altura_desejada){
    int altura_atual = 0;
    l_lista* fila = aloca_lista();
    cria_fila_nivel(fila, raiz->no_raiz, altura_desejada, altura_atual);
    
    return fila;
}

void limpa_fila(l_lista* fila){
    if(fila->quantidade == 0){
        printf("A fila ja esta vazia!\n");
        return;
    }

    else{

        l_elemento* morra;
        l_elemento* auxiliar = fila->inicio;
        int i;

        for(i=0;i<fila->quantidade;i++){
            morra = auxiliar;
            auxiliar = auxiliar->proximo;
            
            if(morra->ninja != NULL){
                free(morra->ninja->nome);
                free(morra->ninja->elemento);
                free(morra->ninja);        
            }
            
            free(morra);
        }

    }

    free(fila);
    printf("Fila esvaziada!\n");
}
