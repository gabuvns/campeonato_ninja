#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "ninja.h"
#include "arvore.h"
#include "fila.h"
#include "hud.h"
#include "jogo.h"

int main(){
    int entrada;
    entrada = menu();
    
    while(entrada == 1){
        entrada = jogo();
    }

    system("clear");
    printf("\n\n########################\n");
    printf("\n\n###Obrigado por jogar###\n");
    printf("\n\n########################\n");
    return 0;
}