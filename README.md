# Análise de Busca Sequencial

## Objetivo

Este projeto foi desenvolvido como parte do **Projeto Integrador I** no **Instituto de Educação Superior de Brasília (IESB)**. O objetivo é analisar o desempenho e a eficiência de algoritmos de busca sequencial aplicados a um conjunto de dados de alta volumetria.

## 📝 Descrição do Projeto

O sistema realiza a carga de um dataset e executa testes de busca em diferentes posições do vetor (Início, Meio e Fim). A análise foca em métricas de tempo de execução para demonstrar a relação entre a posição do dado e o custo computacional.

## 📊 Resultados Obtidos

Com base nos testes realizados em um dataset de **200.003 registros**, os resultados médios foram:

| Bloco de Busca | Média de Tempo (s) |
| :--- | :--- |
| **Início** (Pos. 0-4999) | 0,0243 s |
| **Meio** (Pos. 100000-104999) | 1,7580 s |
| **Final** (Pos. 190000-194999) | 3,4690 s |

* **Tempo Médio por Busca:** ~0,000583 segundos.
* **Tempo Total Médio das Execuções:** ~5,25 segundos.

## 🛠️ Tecnologias e Ferramentas

- **Linguagem:** C
- **Compilador:** GCC (Padrão C11)
- **Ambiente:** VS Code / Terminal Linux
- **Dataset:** Disponibilizado pelo Prof. José Reginaldo de Sousa Mendes Júnior.

## 🚀 Como Executar

   ```bash
make
make run