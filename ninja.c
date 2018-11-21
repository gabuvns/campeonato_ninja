#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "ninja.h"
#include "lista.h"
#include "hud.h"



Ninja* ninja_create(char* _nome, char* _elemento, int _ninjutsu, int _genjutsu, int _taijutsu, int _defesa){

    Ninja* ptr = malloc(sizeof(Ninja));
    
    ptr->nome = malloc(sizeof(char) * strlen(_nome));
    strcpy(ptr->nome, _nome);
    ptr->elemento = malloc(sizeof(char) * strlen(_elemento));
    strcpy(ptr->elemento, _elemento);

    ptr->ninjutsu = _ninjutsu;
    ptr->genjutsu = _genjutsu;
    ptr->taijutsu = _taijutsu;
    ptr->defesa = _defesa; 
    return ptr;
}

Ninja* ninja_create_vazio(){

    Ninja* ptr = malloc(sizeof(Ninja));
    
    ptr->nome = malloc(sizeof(char) * 15);
    
    ptr->elemento = malloc(sizeof(char) * 10);
    

    return ptr;
}

void ninja_free(Ninja* ninja){
        free(ninja->nome);
        free(ninja->elemento);
        free(ninja);

}

void print_atributos_elementais(int vantagem, l_elemento* meu_personagem, int hab_indisp){
    float atributo1, atributo2, atributo3, atributo4;
    
    if(vantagem == 2){
        if(hab_indisp != 1){
            printf("\e[35m(1)Ninjutsu = %d\n", meu_personagem->ninja->ninjutsu);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(1)Ninjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 2){
            printf("\e[32m(2)Genjutsu = %d\n", meu_personagem->ninja->genjutsu);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(2)Genjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }

        if(hab_indisp != 3){   
            printf("\e[93m(3)Taijutsu = %d\n", meu_personagem->ninja->taijutsu);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(3)Taijutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 4){
            printf("\e[94m(4)Defesa = %d\n", meu_personagem->ninja->defesa);
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
            atributo1 = meu_personagem->ninja->ninjutsu*1.2;
            printf("\e[35m(1)Ninjutsu = %.1f\n", atributo1);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(1)Ninjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 2){
            atributo2 = meu_personagem->ninja->genjutsu*1.2;

            printf("\e[32m(2)Genjutsu = %.1f\n", atributo2);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(2)Genjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }

        if(hab_indisp != 3){   
            atributo3 = meu_personagem->ninja->taijutsu*1.2;
            printf("\e[93m(3)Taijutsu = %.1f\n", atributo3);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(3)Taijutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 4){
            atributo4 =  meu_personagem->ninja->defesa*1.2;
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
            atributo1 = meu_personagem->ninja->ninjutsu*0.8;
            printf("\e[35m(1)Ninjutsu = %.1f\n", atributo1);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(1)Ninjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 2){
            atributo2 = meu_personagem->ninja->genjutsu*0.8;

            printf("\e[32m(2)Genjutsu = %.1f\n", atributo2);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(2)Genjutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }

        if(hab_indisp != 3){   
            atributo3 = meu_personagem->ninja->taijutsu*0.8;
            printf("\e[93m(3)Taijutsu = %.1f\n", atributo3);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(3)Taijutsu = Habilidade indisponivel.\n");
            printf("\e[39m");
        }
        
        if(hab_indisp != 4){
            atributo4 =  meu_personagem->ninja->defesa*0.8;
            printf("\e[94m(4)Defesa = %.1f\n", atributo4);
            printf("\e[39m");
        }
        else{
            printf("\e[91m(4)Defesa = Habilidade indisponivel.\n");
            printf("\e[39m");            
        }
    }
}

//Retorna 1 caso o jogador tenha vantagem e 0 caso o adversario tenha vantagem e 2 caso nada ocorra
//Fogo = 0, vento = 1, relampago = 2, terra = 3, agua = 4
int elementos(l_elemento* inimigo, l_elemento* meu_personagem){
    int elem_meu, elem_inimigo;
    //meu elemento
    if(meu_personagem->ninja->elemento[0] == 'F'){
        elem_meu = 0;
    }
    if(meu_personagem->ninja->elemento[0] == 'V'){
        elem_meu = 1;
    }
    if(meu_personagem->ninja->elemento[0] == 'R'){
        elem_meu = 2;
    }
    if(meu_personagem->ninja->elemento[0] == 'T'){
        elem_meu = 3;
    }
    if(meu_personagem->ninja->elemento[0] == 'A'){
        elem_meu = 4;
    }

    //elemento do inimigo
    if(inimigo->ninja->elemento[0] == 'F'){
        elem_inimigo = 0;
    }
    if(inimigo->ninja->elemento[0] == 'V'){
        elem_inimigo = 1;
    }
    if(inimigo->ninja->elemento[0] == 'R'){
        elem_inimigo = 2;
    }
    if(inimigo->ninja->elemento[0] == 'T'){
        elem_inimigo = 3;
    }
    if(inimigo->ninja->elemento[0] == 'A'){
        elem_inimigo = 4;
    }

    //Comparacoes
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
//retorna 1 se o player ganhe e 0 caso perca
int embate_atributos(l_elemento* meu_personagem, l_elemento* inimigo, int atributo_escolhido, int vantagem){
    int atributo_meu, atributo_inimigo;
    if(vantagem == 2){
        if(atributo_escolhido == 1){
            atributo_meu = meu_personagem->ninja->ninjutsu;
            atributo_inimigo = inimigo->ninja->ninjutsu;
        }
        else if(atributo_escolhido == 2){
            atributo_meu = meu_personagem->ninja->genjutsu;
            atributo_inimigo = inimigo->ninja->genjutsu;
        }
        else if(atributo_escolhido == 3){
            atributo_meu = meu_personagem->ninja->taijutsu;
            atributo_inimigo = inimigo->ninja->taijutsu;
        }
        else if(atributo_escolhido == 4){
            atributo_meu = meu_personagem->ninja->defesa;
            atributo_inimigo = inimigo->ninja->defesa;
        }
    }
    else if(vantagem == 1){
        if(atributo_escolhido == 1){
            atributo_meu = meu_personagem->ninja->ninjutsu*1.2;
            atributo_inimigo = inimigo->ninja->ninjutsu;
        }
        else if(atributo_escolhido == 2){
            atributo_meu = meu_personagem->ninja->genjutsu*1.2;
            atributo_inimigo = inimigo->ninja->genjutsu;
        }
        else if(atributo_escolhido == 3){
            atributo_meu = meu_personagem->ninja->taijutsu*1.2;
            atributo_inimigo = inimigo->ninja->taijutsu;
        }
        else if(atributo_escolhido == 4){
            atributo_meu = meu_personagem->ninja->defesa*1.2;
            atributo_inimigo = inimigo->ninja->defesa;
        }
    }
    else if(vantagem == 0){
        if(atributo_escolhido == 1){
            atributo_meu = meu_personagem->ninja->ninjutsu*0.8;
            atributo_inimigo = inimigo->ninja->ninjutsu;
        }
        else if(atributo_escolhido == 2){
            atributo_meu = meu_personagem->ninja->genjutsu*0.8;
            atributo_inimigo = inimigo->ninja->genjutsu;
        }
        else if(atributo_escolhido == 3){
            atributo_meu = meu_personagem->ninja->taijutsu*0.8;
            atributo_inimigo = inimigo->ninja->taijutsu;
        }
        else if(atributo_escolhido == 4){
            atributo_meu = meu_personagem->ninja->defesa*0.8;
            atributo_inimigo = inimigo->ninja->defesa;
        }
    }


    if(atributo_meu > atributo_inimigo){
        return 1;
    }

    else if(atributo_inimigo > atributo_meu){
        return 0;
    }
    //Em caso de empate vai na sorte
    else{
        srand(time(0));
        return rand() % 2;
    }
}

//retorna 1 em caso de vitoria e 0 em caso de derrota
l_elemento* ninja_fight(l_elemento* ninja1, l_elemento* ninja2, l_elemento* meu_personagem, int hab_indisp){
    int ehjogador;
    int atributo_escolhido;
    int vantagem;
    int resultado;

    //ehjogador eh o ninja1
    if(strcmp(ninja1->ninja->nome, meu_personagem->ninja->nome) == 0){
        ehjogador = 1;
    }
    //ehjogador eh o ninja2 -> vira o ninja1, deste modo o ninja2 sempre sera inimigo
    else if(strcmp(ninja2->ninja->nome, meu_personagem->ninja->nome) == 0){
        ninja2 = ninja1;
        ninja1 = meu_personagem;
        ehjogador = 1;
    } 
    else{
        ehjogador = 0;
    }

    if(ehjogador == 1){
        vantagem = elementos( ninja2, meu_personagem);
       printf("\e[39mSeu personagem:\e[33m %s\e[39m\n\n\n", meu_personagem->ninja->nome);
        print_atributos_elementais(vantagem, meu_personagem, hab_indisp);
        printf("\n\nSeu adversario =  \e[41m\e[93m%s\n\e[39m\e[49m", ninja2->ninja->nome);
        printf("\nEscolha um atributo = ");
        scanf("%d", &atributo_escolhido);
        resultado = embate_atributos(meu_personagem, ninja2, atributo_escolhido, vantagem);
        if(resultado == 1){
            return meu_personagem;
        }
        else{
            return ninja2;
        }
    }
    else{
        //batalhabot
        return ninja1;
    }


}



