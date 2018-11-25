#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "ninja.h"
#include "lista.h"
#include "hud.h"

/**
 * @brief Aloca na memoria as informacoes de um ninja
 * 
 * @param _nome 
 * @param _elemento 
 * @param _ninjutsu 
 * @param _genjutsu 
 * @param _taijutsu 
 * @param _defesa 
 * @return Ninja* 
 */
Ninja* ninja_create(char* _nome, char* _elemento, int _ninjutsu, int _genjutsu, int _taijutsu, int _defesa){

    Ninja* ptr = malloc(sizeof(Ninja));
    
    ptr->nome = malloc(sizeof(char) * strlen(_nome));
    strcpy(ptr->nome, _nome);
    ptr->elemento = malloc(sizeof(char) * strlen(_elemento));
    strcpy(ptr->elemento, _elemento);

    ptr->ninjutsu = _ninjutsu;
    ptr->genjutsu = _genjutsu;
    ptr->taijutsu = _taijutsu;
    ptr->defesa = _defesa; 
    return ptr;
}

Ninja* ninja_create_vazio(){

    Ninja* ptr = malloc(sizeof(Ninja));
    
    ptr->nome = malloc(sizeof(char) * 15);
    
    ptr->elemento = malloc(sizeof(char) * 10);
    

    return ptr;
}

/**
 * @brief Libera o espco alocado de um ninja
 * 
 * @param ninja 
 */
void ninja_free(Ninja* ninja){
        free(ninja->nome);
        free(ninja->elemento);
        free(ninja);

}

