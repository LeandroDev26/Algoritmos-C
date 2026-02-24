#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Funcoes Auxiliares ---

// Funcao para criar um novo no
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

// Funcao para liberar a memoria da arvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

// Funcao para percorrer e imprimir a arvore em ordem
void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}


No* inserirIterativo(No* raiz, int valor) {
    No* novoNo = criarNo(valor);
    if (novoNo == NULL) {
        printf("Falha ao alocar memoria!\n");
        return raiz;
    }

    // Caso 1: A arvore esta vazia
    if (raiz == NULL) {
        return novoNo;
    }

    No* atual = raiz;
    No* pai = NULL;

    // Encontra a posicao correta para inserir
    while (atual != NULL) {
        pai = atual;
        if (valor < atual->valor) {
            atual = atual->esquerda;
        } else if (valor > atual->valor) {
            atual = atual->direita;
        } else {
            // Valor ja existe, nao faz nada. Libera o no que nao sera usado.
            printf("(Valor %d ja existe, insercao ignorada)\n", valor);
            free(novoNo);
            return raiz;
        }
    }

    // Anexa o novo no ao pai encontrado
    if (valor < pai->valor) {
        pai->esquerda = novoNo;
    } else {
        pai->direita = novoNo;
    }

    return raiz;
}

No* buscarIterativo(No* raiz, int valor) {
    No* atual = raiz;
    while (atual != NULL) {
        // Se encontrou o valor, retorna o no
        if (valor == atual->valor) {
            return atual;
        }

        // Navega para a esquerda ou direita
        if (valor < atual->valor) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    // Se o laco terminar, o valor nao foi encontrado
    return NULL;
}


// --- Funcao Principal para Testes ---

int main() {
    No* raiz = NULL;

    printf("--- Testando Insercao Nao Recursiva ---\n");
    raiz = inserirIterativo(raiz, 50);
    raiz = inserirIterativo(raiz, 30);
    raiz = inserirIterativo(raiz, 70);
    raiz = inserirIterativo(raiz, 20);
    raiz = inserirIterativo(raiz, 40);
    raiz = inserirIterativo(raiz, 60);
    raiz = inserirIterativo(raiz, 80);

    printf("Arvore construida com sucesso. Percurso em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n\n");

    printf("--- Testando Busca Nao Recursiva ---\n");

    // Teste 1: Buscar um valor que existe
    int valor_existente = 40;
    printf("Buscando pelo valor %d...\n", valor_existente);
    No* encontrado = buscarIterativo(raiz, valor_existente);
    if (encontrado != NULL) {
        printf("Status: SUCESSO! Valor %d encontrado na arvore.\n", encontrado->valor);
    } else {
        printf("Status: FALHA! Valor %d nao encontrado.\n", valor_existente);
    }

    printf("\n");

    // Teste 2: Buscar um valor que NAO existe
    int valor_inexistente = 99;
    printf("Buscando pelo valor %d...\n", valor_inexistente);
    encontrado = buscarIterativo(raiz, valor_inexistente);
    if (encontrado != NULL) {
        printf("Status: SUCESSO! Valor %d encontrado na arvore.\n", encontrado->valor);
    } else {
        printf("Status: FALHA! Valor %d nao encontrado.\n", valor_inexistente);
    }

    // Liberar a memoria alocada
    liberarArvore(raiz);
    printf("\nMemoria da arvore liberada.\n");

    return 0;
}
