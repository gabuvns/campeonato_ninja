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
void encerra_programa(l_lista* lista, l_lista* fila1, l_lista* fila2, arvore_raiz* raiz){
    limpa_lista(lista);
    limpa_fila(fila1);
    limpa_fila(fila2);
    free_tree(raiz);
}


l_lista* etapa2(l_lista* fila2, l_elemento* meu_personagem, int hab_indisp){

}

//ira retornar uma fila somente com os campeoes caso o jogador venca, se nao retorna null
l_lista* etapa1(l_lista* fila, l_elemento* meu_personagem){
    int hab_indisp = 0;
    l_elemento* resultado[8];
    int pos_meu_personagem = -1;

    printf("1a ETAPA\n\n");

    l_elemento* ninja1 = fila->inicio;
    l_elemento* ninja2 = fila->inicio->proximo;

    for(int i = 1; i <=8; i++){
        resultado[i] = ninja_fight( ninja1,  ninja2, meu_personagem, hab_indisp);

        if(!strcmp(resultado[i]->ninja->nome, meu_personagem->ninja->nome)){
            pos_meu_personagem = i;
            printf("VITORIAAAA PORRA\n");        
        }

        if(i != 8){
                ninja1 = ninja2->proximo;
                ninja2 = ninja1->proximo;
        }
    
         
    }
    
    if(pos_meu_personagem == -1){
        printf("Derrota ;-;\n");
        return NULL;
    }

    //Tentei utilizar a funcao realloc() entretanto memoria estava sendo vazada

    fila = resultado;
    return fila;  
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
    
    l_lista* fila2 =  etapa1(fila1, meu_personagem);
    if( fila2 == NULL){
        printf("DERROTADO NO INICIO, PATETICO\n\n");
    }

    else{
        printf("lets'go etapa 2\n\n");
       l_lista* fila3 = etapa2(fila2, meu_personagem, 0);

        if(fila3 == NULL){
            printf("DERROTADO ETAPA 3\n");
        }

        else{
            printf("GOGOGO ETAPA 3 PORRAAAAAAA BATALHA FINAL\n");
        }
    }


    encerra_programa(lista, fila1, fila2, raiz);
}

int main(){

    if(menu() == 1){
        jogo();
    }

    return 0;
}