#ifndef __NINJA_H_
#define __NINJA_H_
#include "lista.h"

void ninja_free(Ninja* ninja);
Ninja* ninja_create(char* _nome, char* _elemento, int _ninjutsu, int _genjutsu, int _taijutsu, int _defesa);
Ninja* ninja_create_vazio();



#endif