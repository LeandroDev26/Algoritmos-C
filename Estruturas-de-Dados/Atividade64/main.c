#include <stdio.h>
#include <stdlib.h>

// --- Estruturas de Dados ---
typedef struct NoArvore {
    int valor;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;


typedef struct NoLista {
    int valor;
    struct NoLista* proximo;
} NoLista;


NoArvore* criarNoArvore(int valor) {
    NoArvore* novoNo = (NoArvore*)malloc(sizeof(NoArvore));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(NoArvore* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

void liberarLista(NoLista* cabeca) {
    NoLista* atual = cabeca;
    while (atual != NULL) {
        NoLista* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void imprimirLista(NoLista* cabeca) {
    NoLista* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


void criarListaRecursivo(NoArvore* no_arvore, NoLista** cabeca_lista) {
    // Caso base
    if (no_arvore == NULL) {
        return;
    }

    // 1. Percorre a subarvore direita primeiro
    criarListaRecursivo(no_arvore->direita, cabeca_lista);

    // 2. Processa o no atual: cria e insere no inicio da lista
    NoLista* novo_no_lista = (NoLista*)malloc(sizeof(NoLista));
    novo_no_lista->valor = no_arvore->valor;
    novo_no_lista->proximo = *cabeca_lista;
    *cabeca_lista = novo_no_lista;

    // 3. Percorre a subarvore esquerda
    criarListaRecursivo(no_arvore->esquerda, cabeca_lista);
}


NoLista* arvoreParaLista(NoArvore* raiz) {
    NoLista* cabeca = NULL;
    criarListaRecursivo(raiz, &cabeca);
    return cabeca;
}


// --- Funcao Principal para Teste ---
int main() {
    // Montando uma arvore de exemplo
    NoArvore* raiz = criarNoArvore(10);
    raiz->esquerda = criarNoArvore(5);
    raiz->direita = criarNoArvore(20);
    raiz->esquerda->esquerda = criarNoArvore(3);
    raiz->esquerda->direita = criarNoArvore(7);

    printf("Criando lista ligada a partir da arvore...\n");

    NoLista* lista_resultante = arvoreParaLista(raiz);

    printf("Percurso em-ordem da arvore: 3 5 7 10 20\n");
    printf("Lista ligada resultante:   ");
    imprimirLista(lista_resultante);

    // Liberando a memoria das duas estruturas
    liberarArvore(raiz);
    liberarLista(lista_resultante);

    return 0;
}
