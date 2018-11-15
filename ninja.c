#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ninja.h"

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