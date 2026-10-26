#include <stdio.h>
#include <string.h>

#define NUM_FILMES 4
#define NUM_DIAS 7

int main() {
    // ==========================================
    // 1. DECLARAÇÃO DE ESTRUTURAS E DADOS
    // ==========================================
    
    // Vetor de strings para armazenar os títulos dos filmes
    char filmes[NUM_FILMES][50] = {
        "O Poderoso Chefao",
        "Interestelar",
        "Matrix",
        "Vingadores: Ultimato"
    };
    
    // Vetor de strings para armazenar os dias da semana (rótulos das colunas)
    char dias[NUM_DIAS][20] = {
        "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"
    };

    // Matriz bidimensional (4x7) simulando a quantidade de ingressos vendidos (Filme x Dia)
    int vendas[NUM_FILMES][NUM_DIAS] = {
        {120, 150, 130, 160, 250, 400, 380}, // O Poderoso Chefao
        {200, 220, 210, 250, 380, 550, 520}, // Interestelar
        {180, 190, 170, 200, 300, 450, 420}, // Matrix
        {300, 320, 290, 350, 500, 700, 680}  // Vingadores: Ultimato
    };

    // Vetores e variáveis auxiliares para os cálculos e métricas
    int total_filme[NUM_FILMES] = {0};
    int total_dia[NUM_DIAS] = {0};
    float receita_filme[NUM_FILMES] = {0.0}; // Desafio Bônus: Receita financeira
    
    int maior_venda = -1;
    int index_melhor_filme = 0;
    int total_geral_ingressos = 0;
    float receita_total_geral = 0.0;

    // Preços dos ingressos (Regra de negócio do bônus)
    float preco_dia_util = 20.00;
    float preco_fim_de_semana = 30.00; // Sábado (5) e Domingo (6)

    // ==========================================
    // 2. PROCESSAMENTO COM LAÇOS ANINHADOS (FOR)
    // ==========================================
    // Percorremos a matriz linha por linha (filmes) e coluna por coluna (dias)
    for (int i = 0; i < NUM_FILMES; i++) {
        for (int j = 0; j < NUM_DIAS; j++) {
            
            // Acumula os totais quantitativos
            total_filme[i] += vendas[i][j];       
            total_dia[j] += vendas[i][j];         
            total_geral_ingressos += vendas[i][j]; 

            // Desafio Bônus: Cálculo da receita considerando preço diferenciado no fim de semana
            if (j >= 5) { // 5 = Sábado, 6 = Domingo
                receita_filme[i] += vendas[i][j] * preco_fim_de_semana;
            } else {      // Dias úteis (Segunda a Sexta)
                receita_filme[i] += vendas[i][j] * preco_dia_util;
            }
        }
        
        // Acumula na receita geral
        receita_total_geral += receita_filme[i];

        // Lógica para identificar o filme mais vendido da semana
        if (total_filme[i] > maior_venda) {
            maior_venda = total_filme[i];
            index_melhor_filme = i;
        }
    }

    // ==========================================
    // 3. EXIBIÇÃO FORMATADA DOS RESULTADOS
    // ==========================================
    printf("=================================================================================\n");
    printf("            SISTEMA DE GESTAO DE BILHETERIA E ANALISE FINANCEIRA\n");
    printf("=================================================================================\n\n");

    // Cabeçalho da Tabela de Ingressos
    printf("%-22s", "Filme");
    for (int j = 0; j < NUM_DIAS; j++) {
        printf("%-10s", dias[j]);
    }
    printf("%-10s\n", "TOTAL");
    printf("---------------------------------------------------------------------------------\n");

    // Impressão das linhas da matriz de vendas
    for (int i = 0; i < NUM_FILMES; i++) {
        printf("%-22s", filmes[i]);
        for (int j = 0; j < NUM_DIAS; j++) {
            printf("%-10d", vendas[i][j]);
        }
        printf("%-10d\n", total_filme[i]);
    }

    // Rodapé da tabela com totais diários
    printf("---------------------------------------------------------------------------------\n");
    printf("%-22s", "TOTAL DIA");
    for (int j = 0; j < NUM_DIAS; j++) {
        printf("%-10d", total_dia[j]);
    }
    printf("%-10d\n", total_geral_ingressos);
    printf("=================================================================================\n\n");

    // Exibição dos Indicadores de Destaque e do Desafio Bônus (Receita Financeira)
    printf(">>> INDICADORES DE DESEMPENHO E FINANCEIRO (DESAFIO BONUS) <<<\n");
    printf(" Filme Mais Vendido da Semana : %s (%d ingressos)\n", filmes[index_melhor_filme], maior_venda);
    printf("---------------------------------------------------------------------------------\n");
    printf(" Receita Total por Filme:\n");
    for (int i = 0; i < NUM_FILMES; i++) {
        printf(" - %-22s : R$ %.2f\n", filmes[i], receita_filme[i]);
    }
    printf("---------------------------------------------------------------------------------\n");
    printf(" FATURAMENTO TOTAL DA BILHETERIA : R$ %.2f\n", receita_total_geral);
    printf("=================================================================================\n");

    return 0;
}