#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "ninja.h"

int main(){
    l_lista* lista = aloca_lista();

    Ninja* ninja = ninja_create("Naruto", "vento", 20, 30, 40, 50);
    insere_lista(lista, ninja);
    ninja = ninja_create("Sasuke", "fogo", 20, 30, 40, 50);
    insere_lista(lista, ninja);
    ninja = ninja_create("Papaleguas", "raio", 65, 70, 49, 7);
    insere_lista(lista, ninja);
    
    printf("tamanho lista = %d\n", lista->quantidade);
    printa_lista(lista);
    limpa_lista(lista);

    return 0;
}