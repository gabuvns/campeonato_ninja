#include <stdlib.h>
#include <stdio.h>
#include "ninja.h"

#include "lista.h"
#include "arvore.h"
#include "fila.h"

#define CLEAR system("clear")

void boas_vindas(){
    CLEAR;
    printf("/ \\  /|/ \\/ \\  /|   / |/  _ \\  /    // \\/  __// \\ /|/__ __\\ \n");
    printf("| |\\ ||| || |\\ ||   | || / \\|  |  __\\| || |  _| |_||  / \\  \n");
    printf("| | \\||| || | \\||/\\_| || |-||  | |   | || |_//| | ||  | |  \n");
    printf("\\_/ \\ |\\_/\\_/  \\|\\____/\\_/ \\|  \\_/   \\_/\\____ \\_/ \\|  \\_/ \n");
    printf("\n\n\n\n\nAperte enter para continuar.\n");
    printf("\n\n\n\n\nCriado por: Carlos Gabriel V N Soares\n");
    getchar();
}

void show_menu(){
    CLEAR;    
    printf("(1). Iniciar exame\n");
    printf("(2). Sair\n");
    printf("Digite sua opcao: ");
}

int menu(){
    CLEAR;
    char entrada;
    show_menu();
    scanf(" %c", &entrada);
    while(entrada != '1' && entrada != '2'){
        printf("Digite uma opcao valida: ");
        scanf(" %c", &entrada);

    }

    if(entrada == '1'){
       return 1;
    }

    else{
        CLEAR;
        printf("Jogo encerrado, obrigado por jogar.\n");
        return 2;            
    }   
}

//Pinta em diferentes cores do melhor para o pior atributo, alem de mostra-los
//vetor[4], de 0 a 4, em ordem crescente
void mostrar_meupersonagem(l_elemento* personagem, int hab_indisp){

    printf("\e[39mSeu personagem:\e[33m %s\e[39m\n\n\n", personagem->ninja->nome);
    
    if(personagem->ninja->elemento[0] == 'F'){
        printf("Seu elemento: \e[91mFogo\n");
    }
    if(personagem->ninja->elemento[0] == 'V'){
        printf("Seu elemento: \e[96mVento\n");
    }
    if(personagem->ninja->elemento[0] == 'R'){
        printf("Seu elemento: \e[33mRelampago\n");
    }
    if(personagem->ninja->elemento[0] == 'A'){
        printf("Seu elemento: \e[34mAgua\n");
    }
    if(personagem->ninja->elemento[0] == 'T'){
        printf("Seu elemento: \e[32mTerra\n");
    }

    printf("\e[39m");
    printf("\e[35mNinjutsu = %d\n", personagem->ninja->ninjutsu);
    printf("\e[39m");
    printf("\e[32mGenjutsu = %d\n", personagem->ninja->genjutsu);
    printf("\e[39m");
    printf("\e[93mTaijutsu = %d\n", personagem->ninja->taijutsu);
    printf("\e[39m");
    printf("\e[94mDefesa   = %d\n", personagem->ninja->defesa);
    printf("\e[39m");
}

