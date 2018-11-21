#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "ninja.h"
#include "arvore.h"
#include "fila.h"
#include "hud.h"

#define CLEAR system("clear")

//encerra o programa liberando a memoria do modo correto
void encerra_programa(l_lista* lista, l_lista* fila, arvore_raiz* raiz){
    limpa_lista(lista);
    limpa_fila(fila);
    free_tree(raiz);
}

//ira retornar 1 para vitoria e 0 para derrota
void etapa1(l_lista* fila, l_elemento* meu_personagem){
    int hab_indisp = 0;
    l_elemento* resultado[8];
    int pos_meu_personagem = -1;

    printf("1a ETAPA\n\n");

    l_elemento* ninja1 = fila->inicio;
    l_elemento* ninja2 = fila->inicio->proximo;

    for(int i = 0; i < 7; i++){
        resultado[i] = ninja_fight( ninja1,  ninja2, meu_personagem, hab_indisp);
        printf("Vencedor[%d] = %s\n", i, resultado[i]->ninja->nome);
        if(!strcmp(resultado[i]->ninja->nome, meu_personagem->ninja->nome)){
            pos_meu_personagem = i;
            printf("VITORIAAAA PORRA\n");
        }
        ninja1 = ninja2->proximo;
        ninja2 = ninja1->proximo; 
    }
     
    if(pos_meu_personagem == -1){
        printf("Derrota ;-;\n");
        return;
    }

    return;
    
}

l_elemento* escolha_personagem(l_lista* fila){
    CLEAR;
    printf("Escolha seu personagem:\n");
    l_elemento* meu_personagem = printa_escolha_personagem(fila);
    return meu_personagem;
}

//filan onde n se refere a etapa
void jogo(){
    arvore_raiz* raiz = tree_create();
    l_lista* fila1 = cria_fila(raiz, 4);
    l_lista* lista = pega_ninja();

    preenche_fila(fila1, lista);

    l_elemento* meu_personagem = escolha_personagem(fila1);
    CLEAR;

    etapa1(fila1, meu_personagem);

    encerra_programa(lista, fila1, raiz);
}

int main(){

    if(menu() == 1){
        jogo();
    }

    return 0;
}