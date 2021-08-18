#include <stdio.h>
#include <stdlib.h>
#include "Pat.h"

int main(){
    
    TipoPatNo *Arvore = NULL;
    Arvore = Insere("gabriel", &Arvore);
    Arvore = Insere("Erike", &Arvore);
    ImprimePalavras(Arvore);
    return 0;
}