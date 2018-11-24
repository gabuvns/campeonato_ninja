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
    if(menu() == 1){
        jogo();
    }

    return 0;
}