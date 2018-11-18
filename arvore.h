#ifndef __ARVORE_H_
#define __ARVORE_H_

#include "ninja.h"
#include "lista.h"

typedef struct node{
    Ninja* ninja;
    struct node* left;
    struct node* right;

}t_node;

typedef struct{
    t_node* no_raiz;
    int tamanho;
}arvore_raiz;

void free_tree(arvore_raiz* raiz);
arvore_raiz* tree_create();
l_lista* pega_ninja();
/*void preenche_arvore(l_lista* lista,arvore_raiz* raiz);
void visita_nivel(t_node* raiz, int altura);*/

#endif