#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "lista.h"
#include "ninja.h"
#include "arvore.h"
#include "fila.h"
#include "hud.h"

int hab_indisp;

int ehmeupersonagem(l_elemento* ninja, l_elemento* meu_personagem){
    
    if(!strcmp(ninja->ninja->nome, meu_personagem->ninja->nome)){
        return 1;
    }
    else{
        return 0;
    }
}

l_elemento* escolha_personagem(l_lista* fila){
    system("clear");
    printf("Escolha seu personagem:\n");
    

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

/*Printa os atribudos modificados*/
void print_atributos_elementais(int vantagem, Ninja* meu_personagem, int hab_indisp){
    float atributo1, atributo2, atributo3, atributo4;
    printf("Seu personagem = %s\n", meu_personagem->nome);

    if(vantagem == 2){
        if(hab_indisp != 1){
            printf("\e[35m(1)Ninjutsu = %d\n", meu_personagem->ninjutsu);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(1)Ninjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 2){
            printf("\e[32m(2)Genjutsu = %d\n", meu_personagem->genjutsu);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(2)Genjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }

        if(hab_indisp != 3){   
            printf("\e[93m(3)Taijutsu = %d\n", meu_personagem->taijutsu);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(3)Taijutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 4){
            printf("\e[94m(4)Defesa   = %d\n", meu_personagem->defesa);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(4)Defesa = Habilidade indisponivel.\n");
            printf("\e[39m");            
        }
    }
    if(vantagem == 1){
        printf("Voce possui vantagem! seus atributos estao sendo multiplicados por 1.2!\n\n");
        if(hab_indisp != 1){
            atributo1 = meu_personagem->ninjutsu*1.2;
            printf("\e[35m(1)Ninjutsu = %.1f\n", atributo1);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(1)Ninjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 2){
            atributo2 = meu_personagem->genjutsu*1.2;

            printf("\e[32m(2)Genjutsu = %.1f\n", atributo2);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(2)Genjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }

        if(hab_indisp != 3){   
            atributo3 = meu_personagem->taijutsu*1.2;
            printf("\e[93m(3)Taijutsu = %.1f\n", atributo3);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(3)Taijutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 4){
            atributo4 =  meu_personagem->defesa*1.2;
            printf("\e[94m(4)Defesa = %.1f\n", atributo4);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(4)Defesa = Habilidade indisponivel.\n");
            printf("\e[39m");            
        }
    }
    if(vantagem == 0){
        printf("Voce esta na desvantagem, seus atributos estao sendo multiplicados por 0.8!\n\n");
        if(hab_indisp != 1){
            atributo1 = meu_personagem->ninjutsu*0.8;
            printf("\e[35m(1)Ninjutsu = %.1f\n", atributo1);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(1)Ninjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 2){
            atributo2 = meu_personagem->genjutsu*0.8;

            printf("\e[32m(2)Genjutsu = %.1f\n", atributo2);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(2)Genjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }

        if(hab_indisp != 3){   
            atributo3 = meu_personagem->taijutsu*0.8;
            printf("\e[93m(3)Taijutsu = %.1f\n", atributo3);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(3)Taijutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 4){
            atributo4 =  meu_personagem->defesa*0.8;
            printf("\e[94m(4)Defesa = %.1f\n", atributo4);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(4)Defesa = Habilidade indisponivel.\n");
            printf("\e[39m");            
        }
    }
}
/*Batalha dos bots*/
Ninja* batalha_bots(Ninja* ninja_one, Ninja* ninja_two){
    srand(time(0));
    int atributo = rand() % 4 + 1;
    Ninja* vencedor;

    if(atributo == 1 ){
        if(ninja_one->ninjutsu > ninja_two->ninjutsu){
            vencedor = ninja_one;        
        }
        else {
            vencedor = ninja_two;
        }
    }

    if(atributo == 2){
        if(ninja_one->genjutsu > ninja_two->genjutsu){
            vencedor = ninja_one;        
        }
        else {
            vencedor = ninja_two;
        }
    }

    if(atributo == 3){
        if(ninja_one->taijutsu > ninja_two->taijutsu){
            vencedor = ninja_one;        
        }
        else {
            vencedor = ninja_two;
        }
    }

    if(atributo == 4){
        if(ninja_one->defesa > ninja_two->defesa){
            vencedor = ninja_one;        
        }
        else {
            vencedor = ninja_two;
        }
    }

    return vencedor;
}

/*
*Retorna 1 caso o jogador tenha vantagem e 0 caso o adversario tenha vantagem e 2 caso nada ocorra
*Fogo = 0, vento = 1, relampago = 2, terra = 3, agua = 4
*/
int elementos(Ninja* meu_personagem, Ninja* inimigo){
    int elem_meu, elem_inimigo;
    /*meu elemento*/
    if(meu_personagem->elemento[0] == 'F'){
        elem_meu = 0;
    }
    if(meu_personagem->elemento[0] == 'V'){
        elem_meu = 1;
    }
    if(meu_personagem->elemento[0] == 'R'){
        elem_meu = 2;
    }
    if(meu_personagem->elemento[0] == 'T'){
        elem_meu = 3;
    }
    if(meu_personagem->elemento[0] == 'A'){
        elem_meu = 4;
    }

    /*elemento do inimigo*/
    if(inimigo->elemento[0] == 'F'){
        elem_inimigo = 0;
    }
    if(inimigo->elemento[0] == 'V'){
        elem_inimigo = 1;
    }
    if(inimigo->elemento[0] == 'R'){
        elem_inimigo = 2;
    }
    if(inimigo->elemento[0] == 'T'){
        elem_inimigo = 3;
    }
    if(inimigo->elemento[0] == 'A'){
        elem_inimigo = 4;
    }

    /*Comparacoes*/
    if(elem_meu == 0){
        if(elem_inimigo == 1){
            return 1;
        }
        if(elem_inimigo == 4){
            return 0;
        }
    }

    if(elem_meu == 1){
        if(elem_inimigo == 2){
            return 1;
        }
        if(elem_inimigo == 0){
            return 0;
        }
    }
    if(elem_meu == 2){
        if(elem_inimigo == 3){
            return 1;
        }
        if(elem_inimigo == 1){
            return 0;
        }
    }
    if(elem_meu == 3){
        if(elem_inimigo == 4){
            return 1;
        }
        if(elem_inimigo == 2){
            return 0;
        }
    }
    if(elem_meu == 4){
        if(elem_inimigo == 0){
            return 1;
        }
        if(elem_inimigo == 3){
            return 0;
        }
    }
    
    return 2;
    
}

/*Usado no caso de jogador, retorna 1 em caso de vitoria e 0 em caso de derrota*/
int embate_atributos(Ninja* meu_personagem, Ninja* inimigo, int atributo_escolhido, int vantagem){
    int atributo_meu, atributo_inimigo;
    if(vantagem == 2){
        if(atributo_escolhido == 1){
            atributo_meu = meu_personagem->ninjutsu;
            atributo_inimigo = inimigo->ninjutsu;
        }
        else if(atributo_escolhido == 2){
            atributo_meu = meu_personagem->genjutsu;
            atributo_inimigo = inimigo->genjutsu;
        }
        else if(atributo_escolhido == 3){
            atributo_meu = meu_personagem->taijutsu;
            atributo_inimigo = inimigo->taijutsu;
        }
        else if(atributo_escolhido == 4){
            atributo_meu = meu_personagem->defesa;
            atributo_inimigo = inimigo->defesa;
        }
    }
    else if(vantagem == 1){
        if(atributo_escolhido == 1){
            atributo_meu = meu_personagem->ninjutsu*1.2;
            atributo_inimigo = inimigo->ninjutsu;
        }
        else if(atributo_escolhido == 2){
            atributo_meu = meu_personagem->genjutsu*1.2;
            atributo_inimigo = inimigo->genjutsu;
        }
        else if(atributo_escolhido == 3){
            atributo_meu = meu_personagem->taijutsu*1.2;
            atributo_inimigo = inimigo->taijutsu;
        }
        else if(atributo_escolhido == 4){
            atributo_meu = meu_personagem->defesa*1.2;
            atributo_inimigo = inimigo->defesa;
        }
    }
    else if(vantagem == 0){
        if(atributo_escolhido == 1){
            atributo_meu = meu_personagem->ninjutsu*0.8;
            atributo_inimigo = inimigo->ninjutsu;
        }
        else if(atributo_escolhido == 2){
            atributo_meu = meu_personagem->genjutsu*0.8;
            atributo_inimigo = inimigo->genjutsu;
        }
        else if(atributo_escolhido == 3){
            atributo_meu = meu_personagem->taijutsu*0.8;
            atributo_inimigo = inimigo->taijutsu;
        }
        else if(atributo_escolhido == 4){
            atributo_meu = meu_personagem->defesa*0.8;
            atributo_inimigo = inimigo->defesa;
        }
    }

    if(atributo_escolhido == 1){
        printf("%s (Ninjutsu = %d) x %s (Ninjutsu = %d)\n", meu_personagem->nome, meu_personagem->ninjutsu, inimigo->nome, inimigo->ninjutsu);
    }
    if(atributo_escolhido == 2){
        printf("%s (Genjutsu = %d) x %s (Genjutsu = %d)\n", meu_personagem->nome, meu_personagem->genjutsu, inimigo->nome, inimigo->genjutsu);
    }
    if(atributo_escolhido == 3){
        printf("%s (Taijutsu = %d) x %s (Taijutsu = %d)\n", meu_personagem->nome, meu_personagem->taijutsu, inimigo->nome, inimigo->taijutsu);
    }
    if(atributo_escolhido == 4){
        printf("%s (Defesa = %d) x %s (Defesa = %d)\n", meu_personagem->nome, meu_personagem->defesa, inimigo->nome, inimigo->defesa);
    }

    if(atributo_meu > atributo_inimigo){
        printf("Vencedor: %s\n", meu_personagem->nome);
        return 1;
    }

    else if(atributo_inimigo > atributo_meu){
        printf("Vencedor: %s\n", inimigo->nome);
        return 0;
    }
    /*Em caso de empate vai na sorte*/
    else{
        printf("EMPATE! Sera decidido na sorte!\n");
        srand(time(0));
        if(rand() % 2 == 1){
            printf("Vencedor: %s\n", meu_personagem->nome);
            return 1;
        }
        else{
            printf("Vencedor: %s\n", inimigo->nome);
            return 0;
        }
    }
}

Ninja* batalha_humana(l_lista* fila, l_elemento* meu_personagem, l_elemento* inimigo){
    int resultado;
    int atributo_escolhido = 0;

    int vantagem = elementos(meu_personagem->ninja, inimigo->ninja);

    print_atributos_elementais(vantagem, meu_personagem->ninja, hab_indisp);

    printf("\n\nNinja inimigo = %s\n\n", inimigo->ninja->nome);
    printf("\n\nEscolha seu atributo: ");
    scanf("%d", &atributo_escolhido);

    while(atributo_escolhido == hab_indisp || ((atributo_escolhido != 1) && (atributo_escolhido != 2) && (atributo_escolhido != 3) && (atributo_escolhido != 4))){
        printf("Opcao invalida, selecione um atributo disponivel: ");
        scanf("%d", &atributo_escolhido);
    }

    printf("\n");

    hab_indisp = atributo_escolhido;

    /*nesse caso ninja_one sera sempre o jogador*/
    resultado = embate_atributos(meu_personagem->ninja, inimigo->ninja, atributo_escolhido, vantagem);
    
    if(resultado == 1){
        return meu_personagem->ninja;
    }
    

    else {
        return inimigo->ninja;
    }
}

int batalha_quarta_etapa(l_lista* fila3, l_lista* fila4, l_elemento* meu_personagem){
    int vencedor = 0;
    l_elemento* auxiliar3 = fila3->inicio;
    l_elemento* auxiliar4 = fila4 ->inicio;
    system("clear");

    printf("4 ETAPA\n######ETAPA FINAL!#####\n");
    
        if(ehmeupersonagem(auxiliar3, meu_personagem)){            
            auxiliar4->ninja = batalha_humana(fila3, meu_personagem, auxiliar3->proximo);
            if(ehmeupersonagem(auxiliar4, meu_personagem)){
                vencedor = 1;
            }
        }

        else if(ehmeupersonagem(auxiliar3->proximo, meu_personagem)){
            auxiliar4->ninja = batalha_humana(fila3, meu_personagem, auxiliar3);
            if(ehmeupersonagem(auxiliar4, meu_personagem)){
                vencedor = 1;
            }
        }

        else{   
            auxiliar4->ninja = batalha_bots(auxiliar3->ninja, auxiliar3->proximo->ninja);
        }
     
    return vencedor;
}


int batalha_terceira_etapa(l_lista* fila3, l_lista* fila4, l_elemento* meu_personagem){
    int i;
    int vencedor = 0;
    l_elemento* aux;
    l_elemento* auxiliar3 = fila3->inicio;
    l_elemento* auxiliar4 = fila4 ->inicio;
    system("clear");

    printf("3 ETAPA!\n");
    
    for(i=0;i<2;i++){
        
        if(ehmeupersonagem(auxiliar3, meu_personagem)){            
            auxiliar4->ninja = batalha_humana(fila3, meu_personagem, auxiliar3->proximo);
            if(ehmeupersonagem(auxiliar4, meu_personagem)){
                vencedor = 1;
            }
        }

        else if(ehmeupersonagem(auxiliar3->proximo, meu_personagem)){
            auxiliar4->ninja = batalha_humana(fila3, meu_personagem, auxiliar3);
            if(ehmeupersonagem(auxiliar4, meu_personagem)){
                vencedor = 1;
            }
        }

        else{
            auxiliar4->ninja = batalha_bots(auxiliar3->ninja, auxiliar3->proximo->ninja);
        }
        
        aux = auxiliar3->proximo;
        auxiliar3 = aux->proximo;
        auxiliar4 = auxiliar4->proximo;  
    }
     
    return vencedor;
}

int batalha_segunda_etapa(l_lista* fila2, l_lista* fila3, l_elemento* meu_personagem){
    int i;
    int vencedor = 0;
    l_elemento* aux;
    l_elemento* auxiliar2 = fila2->inicio;
    l_elemento* auxiliar3 = fila3 ->inicio;
    system("clear");

    printf("2 ETAPA!\n");
    
    for(i=0;i<4;i++){
        
        if(ehmeupersonagem(auxiliar2, meu_personagem)){
            
            auxiliar3->ninja = batalha_humana(fila2, meu_personagem, auxiliar2->proximo);
            if(ehmeupersonagem(auxiliar3, meu_personagem)){
                vencedor = 1;
            }
        }

        else if(ehmeupersonagem(auxiliar2->proximo, meu_personagem)){
            auxiliar3->ninja = batalha_humana(fila2, meu_personagem, auxiliar2);
            if(ehmeupersonagem(auxiliar3, meu_personagem)){
                vencedor = 1;
            }

        }

        else{
            auxiliar3->ninja = batalha_bots(auxiliar2->ninja, auxiliar2->proximo->ninja);

        }
        
        aux = auxiliar2->proximo;
        auxiliar2 = aux->proximo;
        auxiliar3 = auxiliar3->proximo;  
    }
     
    return vencedor;
}

int batalha_primeira_etapa(l_lista* fila1, l_lista* fila2, l_elemento* meu_personagem){
    int i;
    int vencedor = 0;
    l_elemento* auxiliar1 = fila1->inicio;
    l_elemento* aux;
    l_elemento* auxiliar2 = fila2 ->inicio;

    printf("1 ETAPA!\n");
    
    for(i=0;i<8;i++){
        if(ehmeupersonagem(auxiliar1, meu_personagem)){
            auxiliar2->ninja = batalha_humana(fila1, meu_personagem, auxiliar1->proximo);
            if(ehmeupersonagem(auxiliar2, meu_personagem)){
                vencedor = 1;
            }
        }

        else if(ehmeupersonagem(auxiliar1->proximo, meu_personagem)){
            auxiliar2->ninja = batalha_humana(fila1, meu_personagem, auxiliar1);
            if(ehmeupersonagem(auxiliar2, meu_personagem)){
                vencedor = 1;
            }
        }

        else{
            auxiliar2->ninja = batalha_bots(auxiliar1->ninja, auxiliar1->proximo->ninja);
        }
        aux = auxiliar1->proximo;
        auxiliar1 = aux->proximo;
        auxiliar2 = auxiliar2->proximo;  
    }
    return vencedor;
}

void proxima_etapa(){
    printf("\nVoce ganhou!\n");
    printf("\n\nPressione enter para poder passar para a proxima etapa!");
    getchar();
    getchar();
}

void batalhas_ninja(l_elemento* meu_personagem, l_lista* fila1, l_lista* fila2, l_lista* fila3, l_lista* fila4, l_lista* fila5){
    int ganhei = 0;
    hab_indisp = 0;
    ganhei = batalha_primeira_etapa(fila1, fila2, meu_personagem);
    
    if(ganhei){
        proxima_etapa();        
        ganhei = batalha_segunda_etapa(fila2, fila3, meu_personagem);

        if(ganhei){
            proxima_etapa();
            ganhei = batalha_terceira_etapa(fila3, fila4, meu_personagem);

            if(ganhei){
                proxima_etapa();
                ganhei = batalha_quarta_etapa(fila4, fila5, meu_personagem);

                if(ganhei){
                    proxima_etapa();
                    system("clear");
                    printf("#########PARABENS##########\n");
                    printf("Ganhou o campeonato!!!\n\n");
                }
                else{
                    printf("\nBem...você tentou\n");
                }
            }
            else{
                printf("\nVoce perdeu, mas nao eh de todo mal\n");
            }
        }
        else{
            printf("\nVoce foi derrotado na segunda etapa, voce eh ruim mas nem tanto\n");
        }
    }
    else{
        printf("\nVoce foi derrotado na primeira rodada, patetico!\n");
    }
}

int jogo(){
    int entrada; 
    arvore_raiz* raiz = tree_create();
    l_lista* fila1 = cria_fila(raiz, 4);
    l_lista* fila2 = cria_fila(raiz, 3);
    l_lista* fila3 = cria_fila(raiz, 2);
    l_lista* fila4 = cria_fila(raiz, 1);
    l_lista* fila5 = cria_fila(raiz, 0);
    l_lista* lista = pega_ninja();

    preenche_fila(fila1, lista);
    l_elemento* meu_personagem = escolha_personagem(fila1);
    system("clear");
    batalhas_ninja(meu_personagem, fila1, fila2, fila3, fila4, fila5);
    
    limpa_fila(fila1);
    limpa_fila(fila2);
    limpa_fila(fila3);
    limpa_fila(fila4);
    limpa_fila(fila5);
    free_tree(raiz);
    limpa_lista(lista);

    printf("\n\n(1).Iniciar outra partida\n");
    printf("(2).Sair do jogo\n");
    printf("Sua opcao: ");
    scanf("%d", &entrada);
    return entrada;
}