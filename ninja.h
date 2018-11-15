#ifndef __NINJA_H_
#define __NINJA_H_

typedef struct{
    char* nome;
    char* elemento;
    int ninjutsu; //todos os atributos variam de 0 a 100
    int genjutsu;
    int taijutsu;
    int defesa;

}Ninja;

Ninja* ninja_create(char* _nome, char* _elemento, int _ninjutsu, int _genjutsu, int _taijutsu, int _defesa);
#endif