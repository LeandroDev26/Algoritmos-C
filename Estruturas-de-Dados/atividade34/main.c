#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Funcoes Auxiliares ---
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirEmOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

// --- Etapa 1: Extrair os nos para um array ---

int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

void obterNosEmOrdem(No* raiz, int* array, int* indice) {
    if (raiz == NULL) return;
    obterNosEmOrdem(raiz->esquerda, array, indice);
    array[*indice] = raiz->valor;
    (*indice)++;
    obterNosEmOrdem(raiz->direita, array, indice);
}

// --- Etapa 2 e 3: Construir a nova arvore a partir do array ---

No* construirArvoreBalanceada(int* array, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = inicio + (fim - inicio) / 2;
    No* raiz = criarNo(array[meio]);

    raiz->esquerda = construirArvoreBalanceada(array, inicio, meio - 1);
    raiz->direita = construirArvoreBalanceada(array, meio + 1, fim);

    return raiz;
}

// --- Funcao Principal da Questao ---
No* balancearArvore(No* raiz_original) {
    if (raiz_original == NULL) {
        return NULL;
    }

    int n = contarNos(raiz_original);
    int* nos_array = (int*)malloc(n * sizeof(int));

    int indice = 0;
    obterNosEmOrdem(raiz_original, nos_array, &indice);

    No* nova_raiz = construirArvoreBalanceada(nos_array, 0, n - 1);

    free(nos_array);
    return nova_raiz;
}

// --- Funcao de Teste ---
int main() {
    // Criando uma arvore desbalanceada (parecida com uma lista)
    No* raiz_desbalanceada = criarNo(10);
    raiz_desbalanceada->direita = criarNo(20);
    raiz_desbalanceada->direita->direita = criarNo(30);
    raiz_desbalanceada->direita->direita->direita = criarNo(40);
    raiz_desbalanceada->direita->direita->direita->direita = criarNo(50);

    printf("Arvore original (desbalanceada): ");
    imprimirEmOrdem(raiz_desbalanceada);
    printf("\n");

    // Chama a funcao para balancear a arvore
    No* raiz_balanceada = balancearArvore(raiz_desbalanceada);

    printf("Nova arvore (balanceada):      ");
    imprimirEmOrdem(raiz_balanceada);
    printf("\n\n");

    printf("Liberando memoria das arvores...\n");
    liberarArvore(raiz_desbalanceada);
    liberarArvore(raiz_balanceada);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}
