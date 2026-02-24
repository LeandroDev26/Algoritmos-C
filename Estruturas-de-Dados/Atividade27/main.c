#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // Necessario para INT_MIN

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Estrutura e Funcoes da Pilha ---
typedef struct PilhaNo {
    No* no_da_arvore;
    struct PilhaNo* proximo;
} PilhaNo;

typedef struct {
    PilhaNo* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

bool pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, No* no) {
    PilhaNo* novo = (PilhaNo*)malloc(sizeof(PilhaNo));
    novo->no_da_arvore = no;
    novo->proximo = p->topo;
    p->topo = novo;
}

No* desempilhar(Pilha* p) {
    if (pilhaVazia(p)) return NULL;
    PilhaNo* temp = p->topo;
    No* no_retornado = temp->no_da_arvore;
    p->topo = temp->proximo;
    free(temp);
    return no_retornado;
}

int kesimoMenor(No* raiz, int k) {
    if (raiz == NULL || k <= 0) {
        return INT_MIN; // Entrada invalida
    }

    Pilha* p = criarPilha();
    No* atual = raiz;
    int contador = 0;

    while (atual != NULL || !pilhaVazia(p)) {
        // Empilha todos os nos do caminho a esquerda
        while (atual != NULL) {
            empilhar(p, atual);
            atual = atual->esquerda;
        }

        // Desempilha um no. Este e o proximo menor elemento.
        atual = desempilhar(p);
        contador++;

        // Verifica se e o k-esimo
        if (contador == k) {
            int valor_encontrado = atual->valor;
            // Libera a pilha antes de retornar
            while(!pilhaVazia(p)) desempilhar(p);
            free(p);
            return valor_encontrado;
        }

        // Move para a subarvore direita para continuar o percurso
        atual = atual->direita;
    }

    // Se o laco terminar, k e maior que o numero de nos
    free(p);
    return INT_MIN;
}


// --- Funcoes para o Exemplo de Teste ---
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    // Percurso em-ordem da arvore: 20, 30, 40, 50, 60, 70, 80

    printf("Buscando o k-esimo menor elemento...\n");

    // Teste 1: Encontrar o 3º menor
    int k1 = 3;
    int res1 = kesimoMenor(raiz, k1);
    printf("O %d menor elemento e: %d\n", k1, res1);

    // Teste 2: Encontrar o 1º menor (o minimo)
    int k2 = 1;
    int res2 = kesimoMenor(raiz, k2);
    printf("O %d menor elemento e: %d\n", k2, res2);

    // Teste 3: Encontrar o 7º menor (o maximo)
    int k3 = 7;
    int res3 = kesimoMenor(raiz, k3);
    printf("O %d menor elemento e: %d\n", k3, res3);

    // Teste 4: Tentar encontrar um elemento que nao existe
    int k4 = 10;
    int res4 = kesimoMenor(raiz, k4);
    if (res4 == INT_MIN) {
        printf("O %d menor elemento nao foi encontrado (k e muito grande).\n", k4);
    }

    liberarArvore(raiz);
    return 0;
}
