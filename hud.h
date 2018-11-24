#ifndef __HUD_H_
#define __HUD_H_

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void mostrar_meu_personagem(Ninja* personagem);
int menu();
void derrota();
void vitoria(int etapa);
void vitoria_torneio();
void print_caracteristica(Ninja* ninja);
 
#endif