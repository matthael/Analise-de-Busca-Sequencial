#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "leitura_csv.h"
#include "busca.h"

#define TESTES 1000
#define REPETICOES 3

int main() {

    int quantidade = 0;

    Produto *produtos = carregarCSV("data/dataset2.csv", &quantidade);

    if (produtos == NULL) {
        return 1;
    }

    printf("Arquivo encontrado!\n");
    printf("Total de registros carregados: %d\n", quantidade);

    double tempoTotalExecucoes = 0;

    for (int r = 0; r < REPETICOES; r++) {

        printf("\n================ EXECUCAO %d de %d ================\n",
               r + 1, REPETICOES);

        double tempoInicio = 0;
        double tempoMeio = 0;
        double tempoFinal = 0;

        // ===== INÍCIO =====
        printf("\n[INICIO]\n");
        printf("Intervalo 1: posicoes 0 a 999 | IDs %d a %d\n",
               produtos[0].id, produtos[999].id);
        printf("Intervalo 2: posicoes 2000 a 2999 | IDs %d a %d\n",
               produtos[2000].id, produtos[2999].id);
        printf("Intervalo 3: posicoes 4000 a 4999 | IDs %d a %d\n",
               produtos[4000].id, produtos[4999].id);

        clock_t inicioBloco = clock();

        for (int i = 0; i < TESTES; i++) {
            buscaSequencial(produtos, quantidade, produtos[i].id);
            buscaSequencial(produtos, quantidade, produtos[2000 + i].id);
            buscaSequencial(produtos, quantidade, produtos[4000 + i].id);
        }

        clock_t fimBloco = clock();
        tempoInicio = (double)(fimBloco - inicioBloco) / CLOCKS_PER_SEC;

        printf("Tempo do bloco [INICIO]: %f segundos\n", tempoInicio);

        // ===== MEIO =====
        printf("\n[MEIO]\n");
        printf("Intervalo 1: posicoes 100000 a 100999 | IDs %d a %d\n",
               produtos[100000].id, produtos[100999].id);
        printf("Intervalo 2: posicoes 102000 a 102999 | IDs %d a %d\n",
               produtos[102000].id, produtos[102999].id);
        printf("Intervalo 3: posicoes 104000 a 104999 | IDs %d a %d\n",
               produtos[104000].id, produtos[104999].id);

        inicioBloco = clock();

        for (int i = 0; i < TESTES; i++) {
            buscaSequencial(produtos, quantidade, produtos[100000 + i].id);
            buscaSequencial(produtos, quantidade, produtos[102000 + i].id);
            buscaSequencial(produtos, quantidade, produtos[104000 + i].id);
        }

        fimBloco = clock();
        tempoMeio = (double)(fimBloco - inicioBloco) / CLOCKS_PER_SEC;

        printf("Tempo do bloco [MEIO]: %f segundos\n", tempoMeio);

        // ===== FINAL =====
        printf("\n[FINAL]\n");
        printf("Intervalo 1: posicoes 190000 a 190999 | IDs %d a %d\n",
               produtos[190000].id, produtos[190999].id);
        printf("Intervalo 2: posicoes 192000 a 192999 | IDs %d a %d\n",
               produtos[192000].id, produtos[192999].id);
        printf("Intervalo 3: posicoes 194000 a 194999 | IDs %d a %d\n",
               produtos[194000].id, produtos[194999].id);

        inicioBloco = clock();

        for (int i = 0; i < TESTES; i++) {
            buscaSequencial(produtos, quantidade, produtos[190000 + i].id);
            buscaSequencial(produtos, quantidade, produtos[192000 + i].id);
            buscaSequencial(produtos, quantidade, produtos[194000 + i].id);
        }

        fimBloco = clock();
        tempoFinal = (double)(fimBloco - inicioBloco) / CLOCKS_PER_SEC;

        printf("Tempo do bloco [FINAL]: %f segundos\n", tempoFinal);

        double tempoExecucao = tempoInicio + tempoMeio + tempoFinal;

        printf("\nTempo total da execucao %d: %f segundos\n",
               r + 1, tempoExecucao);

        tempoTotalExecucoes += tempoExecucao;
    }

    double tempoMedio = tempoTotalExecucoes / REPETICOES;
    double tempoPorBusca = tempoMedio / (TESTES * 9);

    printf("\n================ RESULTADOS FINAIS ================\n");
    printf("Tempo medio total: %f segundos\n", tempoMedio);
    printf("Tempo medio por busca: %e segundos\n", tempoPorBusca);

    free(produtos);

    return 0;
}