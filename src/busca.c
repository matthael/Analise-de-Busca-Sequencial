#include "busca.h"

int buscaSequencial(Produto *vetor, int tamanho, int id) {

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].id == id) {
            return i;
        }
    }

    return -1;
}