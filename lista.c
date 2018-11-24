#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#include "ninja.h"

#define CLEAR system("clear")
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


l_elemento* printa_escolha_personagem(l_lista* fila){
    CLEAR;
    int posicao = 1;
    int seu_personagem;
    if(fila->inicio == NULL){
        printf("Erro ao printar personagens, programa encerrando\n");
        return;
    }

    else{
        l_elemento* aux = fila->inicio;
      
        while(aux != NULL){
            printf("##########-.Personagem %d.-##########\n", posicao);
            print_caracteristica(aux->ninja);
            aux = aux->proximo;
            posicao++;
        }

        printf("Digite o numero do seu personagem: ");
        scanf("%d", &seu_personagem);

        while(seu_personagem < 1 || seu_personagem > 16){
            printf("Escolha uma opcao valida:");
            scanf("%d", &seu_personagem);
        }
        
        int l;
        aux = fila->inicio;

        for(l=1;l<seu_personagem;l++){
            aux = aux->proximo;
        }

        return aux;
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