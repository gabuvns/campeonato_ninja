#include <stdlib.h>
#include <stdio.h>
#include "ninja.h"
#include "lista.h"
#include "arvore.h"


//Funcoes relativas a criacao da arvore
//Cria no
t_node* node_create(){
    t_node* ptr = malloc(sizeof(t_node));
    int altura=0;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->ninja = NULL;
    ptr->altura = altura;
    return ptr;
}

//Cria o ponteiro  raiz que apontara para o inicio
arvore_raiz* cria_raiz(){
    arvore_raiz* raiz = (arvore_raiz*) malloc(sizeof(raiz));
    raiz->no_raiz = NULL;
    return raiz;
}

//Funcao recursiva para criar a arvore
t_node* cria_arvores (int altura){
    if(altura < 5){
        t_node*  node = node_create();
        //printf("%d\n", altura);
        altura++;

        if(node->left == NULL && altura < 5){
            node->left = cria_arvores(altura);            
        }
         
        if(node->right == NULL && altura < 5){
            node->right = cria_arvores(altura);
        }
        return node;
    }
}

//Funcao que cria a arvore e recebe de volta o ponteiro para a raiz
arvore_raiz* tree_create(){
    int altura = 0;
    arvore_raiz* raiz = cria_raiz();
    raiz->no_raiz = cria_arvores(altura);
    return raiz;
}


//Fim das funcoes relativas a criacao da arvore

//Funcoes relativas a destruicao da arvore
//libera no
void node_free(t_node* node){
    if(node != NULL){
        node_free(node->left);
        node_free(node->right);
        if(node->ninja != NULL){
            ninja_free(node->ninja);
        }
        else{
            free(node->ninja);
        }
        free(node);
    }   
}   
//Destruicao recursiva
void fullclear(t_node* raiz){
    if(raiz->left != NULL){
        fullclear(raiz->left);
    }
    free(raiz->left);

    if(raiz->right != NULL){
        fullclear(raiz->right);
    }
    free(raiz->right);
}

//Funcao principal
void free_tree(arvore_raiz* raiz){
    fullclear(raiz->no_raiz);
    free(raiz->no_raiz);
    free(raiz);
}

//Fim das funcoes relativas a destruicao da arvore