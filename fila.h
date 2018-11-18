#ifndef __FILA_H_
#define __FILA_H_

#include <stdlib.h>
#include <stdio.h>
#include "ninja.h"
#include "lista.h"
#include "arvore.h"

l_lista* cria_fila(arvore_raiz* raiz, int altura_desejada);
void insere_fila(l_lista* fila, t_node* node);
void limpa_fila(l_lista* fila);

#endif