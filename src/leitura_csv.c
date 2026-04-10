#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura_csv.h"

Produto* carregarCSV(const char* nomeArquivo, int* quantidade) {

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    int capacidade = 100;
    *quantidade = 0;

    Produto *vetor = malloc(capacidade * sizeof(Produto));

    if (!vetor) {
        printf("Erro de alocacao de memoria.\n");
        fclose(arquivo);
        return NULL;
    }

    char linha[256];

    // Pula o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo)) {

        Produto p;
        char categoria[100];

        // Caso categoria venha entre aspas
        if (sscanf(linha, "%d,%50[^,],\"%99[^\"]\",%f",
                   &p.id, p.nome, categoria, &p.valor) == 4) {

            strcpy(p.categoria, categoria);
        }

        // Caso categoria venha sem aspas
        else if (sscanf(linha, "%d,%50[^,],%30[^,],%f",
                        &p.id, p.nome, p.categoria, &p.valor) == 4) {
        }

        // Linha inválida
        else {
            continue;
        }

        // Realocação dinâmica
        if (*quantidade >= capacidade) {
            capacidade *= 2;

            Produto *temp = realloc(vetor, capacidade * sizeof(Produto));

            if (!temp) {
                printf("Erro ao realocar memoria.\n");
                free(vetor);
                fclose(arquivo);
                return NULL;
            }

            vetor = temp;
        }

        vetor[*quantidade] = p;
        (*quantidade)++;

        // Exibe progresso a cada 1000 registros
        if ((*quantidade % 1000) == 0) {
            printf("\rRegistros carregados: %d", *quantidade);
            fflush(stdout);
        }
    }

    // Quebra linha ao finalizar
    printf("\nLeitura concluida com sucesso!\n");

    fclose(arquivo);

    return vetor;
}