#include <stdio.h>
#include <string.h>

// Definição de uma estrutura para representar uma carta
typedef struct {
    char estado[50];
    char codigo[20];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(Carta carta) {
    return carta.populacao / carta.area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(Carta carta) {
    return carta.pib / carta.populacao;
}

// Função para comparar duas cartas com base em um atributo específico
void compararCartas(Carta carta1, Carta carta2, char atributo) {
    printf("Comparação de cartas (Atributo: %s):\n", atributo);

    // Compara com base no atributo escolhido
    if (atributo == 'P') { // Comparando População
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
    }
    else if (atributo == 'A') { // Comparando Área
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
    }
    else if (atributo == 'I') { // Comparando PIB
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
    }
    else if (atributo == 'D') { // Comparando Densidade Populacional
        float densidade1 = calcularDensidadePopulacional(carta1);
        float densidade2 = calcularDensidadePopulacional(carta2);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, densidade1);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, densidade2);
        if (densidade1 < densidade2) { // Menor densidade vence
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
    }
    else if (atributo == 'B') { // Comparando PIB per capita
        float pibPerCapita1 = calcularPibPerCapita(carta1);
        float pibPerCapita2 = calcularPibPerCapita(carta2);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, pibPerCapita1);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, pibPerCapita2);
        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
    }
}

int main() {
    // Definindo duas cartas com dados de exemplo
    Carta carta1 = {"São Paulo", "SP001", "São Paulo", 12300000, 1500.5, 500000, 200};
    Carta carta2 = {"Rio de Janeiro", "RJ002", "Rio de Janeiro", 6000000, 1200.3, 300000, 150};

    // Escolher o atributo para comparação: 'P' para População, 'A' para Área, 'I' para PIB, 'D' para Densidade Populacional, 'B' para PIB per capita
    char atributo = 'P'; // Atributo escolhido para comparação (pode ser alterado conforme necessário)

    // Chama a função para comparar as cartas
    compararCartas(carta1, carta2, atributo);

    return 0;
}

