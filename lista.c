#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "ninja.h"

l_elemento* aloca_elemento(){
  l_elemento* ptr = malloc(sizeof(l_elemento));
  ptr->anterior = NULL;
  ptr->proximo = NULL;
  return ptr;
}

l_lista* aloca_lista(){
  l_lista* ptr = malloc(sizeof(l_lista));
  ptr->inicio = NULL;
  ptr->ultimo = NULL;
  ptr->quantidade = 0;
  return ptr;
}

void insere_lista(l_lista* lista, Ninja* ninja){

  if(lista->inicio == NULL){
    lista->inicio = aloca_elemento();
    lista->inicio->ninja = ninja;
    lista->inicio->proximo = NULL;
    lista->inicio->anterior = NULL;
    lista->ultimo = lista->inicio;
  }

  else{    
    l_elemento* aux;
    l_elemento* anterior;
    aux = lista->inicio;

    while(aux->proximo != NULL){
      anterior = aux;
      aux = aux->proximo;
    }

    anterior = aux;
    aux->proximo = aloca_elemento();
    aux = aux->proximo;
    aux->ninja= ninja;
    aux->proximo = NULL;
    aux->anterior = anterior;
    lista->ultimo = aux;
  }

    lista->quantidade++;
}

void printa_lista(l_lista* lista){
  if(lista->inicio == NULL){
      printf("Erro ao printar a lista, lista vazia!\n");
      return;
  }

  else{

      l_elemento* aux = lista->inicio;
      while(aux != NULL){
          printf("Nome do ninja = %s\n", aux->ninja->nome);
          aux = aux->proximo;
      }
  }
}

void limpa_lista(l_lista* lista){
    if(lista->quantidade == 0){
        printf("A lista ja esta vazia!\n");
        return;
    }

    else{

        l_elemento* morra;
        l_elemento* auxiliar = lista->inicio;
        int i;

        for(i=0;i<lista->quantidade;i++){
            morra = auxiliar;
            auxiliar = auxiliar->proximo;
            
            free(morra->ninja->nome);
            free(morra->ninja->elemento);
            free(morra->ninja);
            free(morra);
        }

    }

    free(lista);
    printf("Lista esvaziada!\n");
}