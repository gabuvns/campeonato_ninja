#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "ninja.h"
#include "arvore.h"

int main(){
   
  
    l_lista* lista = pega_ninja();

  
    
    
    printa_lista(lista);
    limpa_lista(lista);


    return 0;
}