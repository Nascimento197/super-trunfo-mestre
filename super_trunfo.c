#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para calcular densidade demográfica
float densidadeDemografica(Carta c) {
    return (float)c.populacao / c.area;
}

// Exibe o menu de atributos disponíveis
void exibirMenu(int ignorar) {
    printf("\nEscolha um atributo:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Pontos Turísticos\n");
    if (ignorar != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função que retorna o valor do atributo escolhido
float obterAtributo(Carta c, int escolha) {
    switch (escolha) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return densidadeDemografica(c);
        default: return -1; // inválido
    }
}

// Função para imprimir o nome do atributo
const char* nomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

int main() {
    // Cartas pré-cadastradas (pode expandir depois)
    Carta c1 = {"Brasil", 214000000, 8515767, 22000, 30};
    Carta c2 = {"Argentina", 46000000, 2780400, 600, 15};

    printf("Comparando cartas: %s vs %s\n", c1.nome, c2.nome);

    int escolha1, escolha2;
    
    // Escolha do 1º atributo
    exibirMenu(0);
    scanf("%d", &escolha1);

    // Escolha do 2º atributo (não pode repetir o 1º)
    do {
        exibirMenu(escolha1);
        scanf("%d", &escolha2);
        if (escolha2 == escolha1) {
            printf("Você já escolheu esse atributo. Escolha outro.\n");
        }
    } while (escolha2 == escolha1);

    // Obter valores dos atributos
    float valor1_c1 = obterAtributo(c1, escolha1);
    float valor1_c2 = obterAtributo(c2, escolha1);
    float valor2_c1 = obterAtributo(c1, escolha2);
    float valor2_c2 = obterAtributo(c2, escolha2);

    // Comparação do atributo 1
    int resultado1;
    if (escolha1 == 5) { // Densidade demográfica (menor vence)
        resultado1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0);
    } else {
        resultado1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0);
    }

    // Comparação do atributo 2
    int resultado2;
    if (escolha2 == 5) {
        resultado2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0);
    } else {
        resultado2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0);
    }

    // Soma total dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    int vencedor = (soma_c1 > soma_c2) ? 1 : (soma_c1 < soma_c2 ? 2 : 0);

    // Exibir resultados
    printf("\n===== RESULTADO =====\n");
    printf("%s - %s: %.2f | %s: %.2f | Soma = %.2f\n", c1.nome, nomeAtributo(escolha1), valor1_c1, nomeAtributo(escolha2), valor2_c1, soma_c1);
    printf("%s - %s: %.2f | %s: %.2f | Soma = %.2f\n", c2.nome, nomeAtributo(escolha1), valor1_c2, nomeAtributo(escolha2), valor2_c2, soma_c2);

    if (vencedor == 1) {
        printf("Vencedor: %s\n", c1.nome);
    } else if (vencedor == 2) {
        printf("Vencedor: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
