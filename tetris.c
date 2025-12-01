#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5   


// STRUCT DA PEÇA

typedef struct {
    char nome;   // Tipo da peça ('I', 'O', 'T', 'L')
    int id;     
} Peca;

// Fila circular
Peca fila[TAM_FILA];
int inicio = 0, fim = 0, quantidade = 0;

// Contador para IDs automáticos
int contadorID = 0;


// FUNÇÃO PARA GERAR UMA NOVA PEÇA AUTOMATICAMENTE

Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;

    nova.nome = tipos[rand() % 4]; // Escolhe tipo aleatório
    nova.id = contadorID++;        // Gera ID único

    return nova;
}

// ENQUEUE - INSERIR PEÇA NO FINAL DA FILA

void inserirPeca() {
    if (quantidade == TAM_FILA) {
        printf("\nA fila está cheia! Não é possível inserir nova peça.\n");
        return;
    }

    fila[fim] = gerarPeca();
    fim = (fim + 1) % TAM_FILA;
    quantidade++;

    printf("\nPeça inserida com sucesso!\n");
}

// DEQUEUE - REMOVER PEÇA DO INÍCIO DA FILA

void jogarPeca() {
    if (quantidade == 0) {
        printf("\nA fila está vazia! Não há peça para jogar.\n");
        return;
    }

    Peca jogada = fila[inicio];
    inicio = (inicio + 1) % TAM_FILA;
    quantidade--;

    printf("\nPeça jogada: [%c %d]\n", jogada.nome, jogada.id);
}


// EXIBIR FILA COMPLETA

void exibirFila() {
    printf("\n=== Fila de Peças ===\n");

    if (quantidade == 0) {
        printf("(fila vazia)\n");
        return;
    }

    int i = inicio;

    for (int c = 0; c < quantidade; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM_FILA;
    }

    printf("\n");
}

// PROGRAMA PRINCIPAL

int main() {
    srand(time(NULL));  // Semente de aleatoriedade

    int opcao;

    // INICIALIZAR A FILA COM 5 PEÇAS
    for (int i = 0; i < TAM_FILA; i++) {
        inserirPeca();
    }

    do {
        exibirFila();

        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogarPeca();
                break;
            case 2:
                inserirPeca();
                break;
            case 0:
                printf("\nSaindo do jogo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
