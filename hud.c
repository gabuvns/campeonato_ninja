#include <stdlib.h>
#include <stdio.h>
#include "ninja.h"
#include "time.h"
#include "lista.h"


#define CLEAR system("clear")

void vitoria(int etapa){
    printf(" \e[43m\e[34m");
    printf("\n\n*****VITORIA*****\n");        
    printf("*****VITORIA*****\n");        
    printf("*****VITORIA*****\n");        
    printf("*****VITORIA*****\n");        
    printf("*****VITORIA*****\n");        
    printf("*****VITORIA*****\n\n\n");   
    printf(" \e[49m\e[39m");
    printf("Aperte enter para avancar para a proxima etapa!\n\n\n\n");
    getchar();
    getchar();    
    system("clear");
    printf("ETAPA %d\n\n", etapa);
}
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

/*Pinta em diferentes cores do melhor para o pior atributo, alem de mostra-los
vetor[4], de 0 a 4, em ordem crescente*/
void mostrar_meu_personagem(Ninja* personagem){

    printf("\e[39mSeu personagem:\e[33m %s\e[39m\n\n\n", personagem->nome);
    
    if(personagem->elemento[0] == 'F'){
        printf("Seu elemento: \e[91mFogo\n");
    }
    if(personagem->elemento[0] == 'V'){
        printf("Seu elemento: \e[96mVento\n");
    }
    if(personagem->elemento[0] == 'R'){
        printf("Seu elemento: \e[33mRelampago\n");
    }
    if(personagem->elemento[0] == 'A'){
        printf("Seu elemento: \e[34mAgua\n");
    }
    if(personagem->elemento[0] == 'T'){
        printf("Seu elemento: \e[32mTerra\n");
    }

    printf("\e[39m");
    printf("\e[35m(1). Ninjutsu = %d\n", personagem->ninjutsu);
    printf("\e[39m");
    printf("\e[32m(2). Genjutsu = %d\n", personagem->genjutsu);
    printf("\e[39m");
    printf("\e[93m(3). Taijutsu = %d\n", personagem->taijutsu);
    printf("\e[39m");
    printf("\e[94m(4). Defesa   = %d\n", personagem->defesa);
    printf("\e[39m");
}


void vitoria_torneio(){
    printf("\n\n\n\nTORNEIOOOO\nVENCIDOOOOOO\nPORRA");
}
void derrota(){
    printf("\n\n\nPERDEUPLAYBOY\n\n");
}

void print_caracteristica(Ninja* ninja){
    struct timespec seed;																	
    clock_gettime(CLOCK_REALTIME, &seed);												
    srand(seed.tv_nsec); 
    
    int elemento = rand() % 4;

    if(elemento == 0){
        printf("\e[92m  Ninjutsu = %d\n\e[91mGenjutsu = ??\nTaijutsu = ??\nDefesa =   ??\n\e[39m", ninja->ninjutsu);
    }
    else if(elemento == 1){
        printf("\e[91mNinjutsu = ??\n\e[92mGenjutsu = %d\n\e[91mTaijutsu = ??\nDefesa =   ??\n\e[39m", ninja->genjutsu);
    }
    else if(elemento == 2){
        printf("\e[91mNinjutsu = ??\nGenjutsu = ??\n\e[92mTaijutsu = %d\n\e[91mDefesa =   ??\n\e[39m", ninja->taijutsu);
    }
    else if(elemento == 3){
        printf("\e[91mNinjutsu = ??\nGenjutsu = ??\nTaijutsu = ??\n\e[92mDefesa =   %d\n\e[39m", ninja->defesa);
    }
    printf("\n");
    
}
