#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "ninja.h"
#include "arvore.h"
#include "fila.h"

int main(){
   
    arvore_raiz* raiz = tree_create();
    l_lista* fila = cria_fila(raiz, 4);
    
    
    printf("Numero de itens = %d\n", fila->quantidade);
    limpa_fila(fila);
    free_tree(raiz);

    return 0;
}