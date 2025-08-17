#include <stdio.h>

#include <string.h>

#define MAX_STRING 50

typedef struct {
    char codigo[MAX_STRING];
    char nome[MAX_STRING];
    long populacao;
    double area;
    double pib;
} Carta;

void limparBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void lerCarta(Carta *c, int indice) {
    printf("=== Cadastro da Carta %d ===\n", indice);

    // 1) Código
    printf("Código da Cidade: ");
    fflush(stdout);
    scanf("%49s", c->codigo);
    limparBuffer();

    // 2) Nome
    printf("Nome da Cidade: ");
    fflush(stdout);
    if (fgets(c->nome, MAX_STRING, stdin) == NULL) {

    }
    // Remove '\n' ao fim da string, se existir
    size_t len = strlen(c->nome);
    if (len > 0 && c->nome[len-1] == '\n') {
        c->nome[len-1] = '\0';
    }

    printf("População (número inteiro): ");
    fflush(stdout);
    scanf("%ld", &c->populacao);
    limparBuffer();

    printf("Área (km²): ");
    fflush(stdout);
    scanf("%lf", &c->area);
    limparBuffer();

    printf("PIB (bilhões USD): ");
    fflush(stdout);
    scanf("%lf", &c->pib);
    limparBuffer();

    printf("\n");
}

int escolherAtributo() {
    int opc;
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("Opção: ");
    scanf("%d", &opc);
    printf("\n");
    return opc;
}

void compararCartas (const Carta *a, const Carta *b, int attr) {
    double valA, valB;
    const char *nomeAttr;

    switch (attr) {
        case 1:
            valA = a->populacao;
            valB = b->populacao;
            nomeAttr = "População";
            break;
        
        case 2:
            valA = a->area;
            valB = b->area;
            nomeAttr = "Área";
            break;

        case 3:
            valA = a->pib;
            valB = b->pib;
            nomeAttr = "PIB";
            break;

        default:
            printf("Atributo Inválido.\n");
            return;
    }

    printf("Comparando: %s:\n", nomeAttr);
    printf("%s = %.2f vs %s = %.2f\n\n", a->nome, valA, b->nome, valB);

    if (valA > valB) {
        printf("-> A carta vencedora é: %s (%.2f > %.2f)\n", a->nome, valA, valB);
    } else if (valB > valA) {
        printf("-> A carta vencedora é: %s (%.2f > %.2f)\n", b->nome, valB, valA);
    } else {
        printf("-> Empate! Ambos tem %.2f no atributo %s.\n", valA, nomeAttr);
    }
    printf("\n");
}

int main() {
    Carta carta1, carta2;
    int atributo;
    // Leitura das duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Escolha e comparação
    atributo = escolherAtributo();
    compararCartas(&carta1, &carta2, atributo);

    return 0;
}
