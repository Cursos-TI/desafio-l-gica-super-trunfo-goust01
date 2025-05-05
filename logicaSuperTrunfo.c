#include <stdio.h>

typedef struct {
    char estado[50], codigo[20], cidade[50];
    int populacao;
    float area, pib;
} Carta;


float calcularDensidade(Carta c) {
    return c.populacao / c.area;
}


float calcularPibPerCapita(Carta c) {
    return c.pib / c.populacao;
}


void exibirCarta(Carta c) {
    printf("\nCidade: %s (%s)\n", c.cidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Densidade Populacional: %.2f habitantes/km²\n", calcularDensidade(c));
    printf("PIB per capita: %.2f\n", calcularPibPerCapita(c));
}


void compararCartas(Carta c1, Carta c2, char atributo) {
    printf("\nComparação de cartas (Atributo: %c):\n", atributo);

    if (atributo == 'P') {
        printf("Carta 1 - %s: %d\nCarta 2 - %s: %d\n", c1.cidade, c1.populacao, c2.cidade, c2.populacao);
        if (c1.populacao > c2.populacao) printf("Resultado: Carta 1 venceu!\n");
        else printf("Resultado: Carta 2 venceu!\n");
    } else if (atributo == 'A') { 
        printf("Carta 1 - %s: %.2f\nCarta 2 - %s: %.2f\n", c1.cidade, c1.area, c2.cidade, c2.area);
        if (c1.area > c2.area) printf("Resultado: Carta 1 venceu!\n");
        else printf("Resultado: Carta 2 venceu!\n");
    } else if (atributo == 'I') { 
        printf("Carta 1 - %s: %.2f\nCarta 2 - %s: %.2f\n", c1.cidade, c1.pib, c2.cidade, c2.pib);
        if (c1.pib > c2.pib) printf("Resultado: Carta 1 venceu!\n");
        else printf("Resultado: Carta 2 venceu!\n");
    } else if (atributo == 'D') { 
        float d1 = calcularDensidade(c1), d2 = calcularDensidade(c2);
        printf("Carta 1 - %s: %.2f\nCarta 2 - %s: %.2f\n", c1.cidade, d1, c2.cidade, d2);
        if (d1 < d2) printf("Resultado: Carta 1 venceu!\n"); 
        else printf("Resultado: Carta 2 venceu!\n");
    } else if (atributo == 'B') {
        float p1 = calcularPibPerCapita(c1), p2 = calcularPibPerCapita(c2);
        printf("Carta 1 - %s: %.2f\nCarta 2 - %s: %.2f\n", c1.cidade, p1, c2.cidade, p2);
        if (p1 > p2) printf("Resultado: Carta 1 venceu!\n");
        else printf("Resultado: Carta 2 venceu!\n");
    }
}

int main() {
    Carta carta1, carta2;

    
    printf("Digite as informações da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Cidade: ");
    scanf("%s", carta1.cidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);

   
    printf("\nDigite as informações da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Cidade: ");
    scanf("%s", carta2.cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);

   
    printf("\nInformações da Carta 1:");
    exibirCarta(carta1);

    printf("\nInformações da Carta 2:");
    exibirCarta(carta2);

  
    char atributo;
    printf("\nDigite o atributo para comparar (P = População, A = Área, I = PIB, D = Densidade, B = PIB per capita): ");
    scanf(" %c", &atributo); 
  
    compararCartas(carta1, carta2, atributo);

    return 0;
}


