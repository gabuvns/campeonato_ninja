#include <stdlib.h>
#include <stdio.h>
#include "ninja.h"
#include "lista.h"
#include "arvore.h"
#include "fila.h"

/*Insere elementos na fila*/
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


/*Criamos uma fila onde cada elemento aponta para um no da arvore
coloca todos os elementos de um determinado nivel em fila*/
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


/*Percursao em largura
Consideramos o no raiz como nivel 0 e seus dois filhos como nivel 1 e assim por diante*/
l_lista* cria_fila(arvore_raiz* raiz, int altura_desejada){
    int altura_atual = 0;
    l_lista* fila = aloca_lista();
    if(altura_desejada == 0){
        insere_fila(fila, no_raiz);
    }
    else{
        cria_fila_nivel(fila, raiz->no_raiz, altura_desejada, altura_atual);
    }
    
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
            
            free(morra);
        }

    }

    free(fila);
    printf("Fila esvaziada!\n");
}

/*Preenche a fila na qual os elementos apontam para a árvore com ninjas da lista aleatoria*/
void preenche_fila(l_lista* fila, l_lista* lista){
    l_elemento* auxiliar_fila = fila->inicio;
    l_elemento* auxiliar_lista = lista->inicio;

    while(auxiliar_lista!= NULL){
        auxiliar_fila->ninja = auxiliar_lista->ninja;
        auxiliar_lista = auxiliar_lista->proximo;
        auxiliar_fila = auxiliar_fila->proximo;
    }

}