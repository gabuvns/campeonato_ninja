#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ninja.h"
#include "lista.h"
#include "arvore.h"

/*Funcoes relativas a criacao da arvore
Cria no*/
t_node* node_create(){
    t_node* ptr = malloc(sizeof(t_node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->ninja = NULL;
    return ptr;
}

/*Cria o ponteiro  raiz que apontara para o inicio*/
arvore_raiz* cria_raiz(){
    arvore_raiz* raiz = (arvore_raiz*) malloc(sizeof(raiz));
    raiz->no_raiz = NULL;
    return raiz;
}

/*Funcao recursiva para criar a arvore*/
t_node* cria_arvores (int altura){
    if(altura < 5){
        t_node*  node = node_create();
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

/*Funcao que cria a arvore e recebe de volta o ponteiro para a raiz*/
arvore_raiz* tree_create(){
    int altura = 0;
    arvore_raiz* raiz = cria_raiz();
    raiz->no_raiz = cria_arvores(altura);
    return raiz;
}


/*Fim das funcoes relativas a criacao da arvore*/

/*Funcoes relativas a destruicao da arvore
libera no*/
void node_free(t_node* node){
    if(node != NULL){
        node_free(node->left);
        node_free(node->right);

        /*ATENCAO, LIBERAR AQUI OU NA ARVORE*******/
        if(node->ninja != NULL){
            ninja_free(node->ninja);
        }

        free(node);
    }   
}   
/*Destruicao recursiva*/
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

/*Funcao principal*/
void free_tree(arvore_raiz* raiz){
    fullclear(raiz->no_raiz);
    free(raiz->no_raiz);
    free(raiz);
}

/*Fim das funcoes relativas a destruicao da arvore*/

/*cria uma lista com os 16 ninjas aleatoriamente*/
l_lista* pega_ninja(){
    /*abre arquivo*/
    FILE* fd;
    fd = fopen("ninjas.txt", "r");
    
    if(fd == NULL){
        printf("Erro ao abrir aqruivo, arquivo inexistente! Programa encerrado!\n");
        return;
    }

    /*vetor aleatorio*/
    int vetor[16];
    int valor_aleatorio;

    struct timespec seed;																	
    clock_gettime(CLOCK_REALTIME, &seed);												
    srand(seed.tv_nsec); 
    
    int i = 0, j, flag;

    while(i<16){
        flag  = 1; 
        valor_aleatorio = rand() % 32;

        for(j=0;j<16;j++){
            if(vetor[j] == valor_aleatorio){
                flag = 0;
            }
        }
        
        if(flag == 1){
            vetor[i] = valor_aleatorio;
            i++;    
        }
    } 

    /*coloca o ninja na lista*/
    Ninja* ninja;
    char nome[16];
    char elemento[11];
    int ninjutsu;
    int taijutsu;
    int genjutsu;
    int defesa;

    l_lista* lista = aloca_lista();

    for(i=0;i<16;i++){
        for(j=0;j<vetor[i];j++){
            fscanf(fd, "%[^,], %[^,],  %d, %d, %d, %d\n", nome, elemento, &ninjutsu, &genjutsu, &taijutsu, &defesa);
        }

        ninja = ninja_create(nome, elemento, ninjutsu, genjutsu, taijutsu, defesa);   
        insere_lista(lista, ninja);        
        rewind(fd); 
    }

    fclose(fd);
    return lista;
}

