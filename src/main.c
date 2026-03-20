#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "produto.h"
#include "leitura_csv.h"
#include "busca.h"

#define TESTES 1000
#define REPETICOES 3

int main() {

    int quantidade;

    Produto *produtos = carregarCSV("data/dataset2.csv", &quantidade);

    FILE *teste = fopen("data/dataset2.csv", "r");

    if (teste == NULL) {
        printf("Arquivo NAO encontrado!\n");
    } else {
        printf("Arquivo encontrado!\n");
        fclose(teste);
    }

    if (!produtos) {
        return 1;
    }

    printf("Total de registros carregados: %d\n", quantidade);

    int idInicio = produtos[0].id;
    int idMeio = produtos[quantidade / 2].id;
    int idFinal = produtos[quantidade - 1].id;
    int idInexistente = -1;

    double tempoTotal = 0;

    for (int r = 0; r < REPETICOES; r++) {

        clock_t inicio = clock();

        for (int i = 0; i < TESTES; i++) {

            buscaSequencial(produtos, quantidade, idInicio);
            buscaSequencial(produtos, quantidade, idMeio);
            buscaSequencial(produtos, quantidade, idFinal);
            buscaSequencial(produtos, quantidade, idInexistente);
        }

        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Execucao %d: %f segundos\n", r + 1, tempo);

        tempoTotal += tempo;
    }

    double tempoMedioTotal = tempoTotal / REPETICOES;
    double tempoMedioBusca = tempoMedioTotal / (TESTES * 4);

    printf("\nTempo medio total: %f segundos\n", tempoMedioTotal);
    printf("Tempo medio por busca: %e segundos\n", tempoMedioBusca);

    free(produtos);

    return 0;
}