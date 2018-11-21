#ifndef __LISTA_H_
#define __LISTA_H_

typedef struct{
    char* nome;
    char* elemento;
    //todos os atributos variam de 0 a 100
    int ninjutsu; 
    int genjutsu;
    int taijutsu;
    int defesa;

}Ninja;

typedef struct elemento{
  struct elemento* proximo;
  struct elemento* anterior;
  Ninja* ninja;

}l_elemento;

typedef struct{
  l_elemento* inicio;
  l_elemento* ultimo;
  int quantidade;

}l_lista;

l_elemento* aloca_elemento();
l_lista* aloca_lista();
void insere_lista(l_lista* lista, Ninja* ninja);
void printa_lista(l_lista* lista);
void limpa_lista(l_lista* lista);
l_elemento* printa_escolha_personagem(l_lista* fila);

#endif