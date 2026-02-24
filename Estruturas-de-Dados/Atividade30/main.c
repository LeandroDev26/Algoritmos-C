#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


bool existeValorNegativo_iterativo(No* raiz) {
    if (raiz == NULL) {
        return false;
    }

    Pilha* p = criarPilha();
    empilhar(p, raiz);

    while (!pilhaVazia(p)) {
        No* atual = desempilhar(p);

        // Verifica a condicao: o valor do no e negativo?
        if (atual->valor < 0) {
            // Limpa a pilha antes de retornar para evitar vazamento de memoria
            while(!pilhaVazia(p)) desempilhar(p);
            free(p);
            return true;
        }

        // Empilha os filhos para continuar a busca
        if (atual->direita != NULL) {
            empilhar(p, atual->direita);
        }
        if (atual->esquerda != NULL) {
            empilhar(p, atual->esquerda);
        }
    }

    free(p);
    return false;
}


No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}


int main() {
    // --- Teste 1: Arvore COM valor negativo ---
    No* raiz1 = criarNo(15);
    raiz1->esquerda = criarNo(100);
    raiz1->direita = criarNo(-5);
    raiz1->esquerda->esquerda = criarNo(2);
    raiz1->esquerda->direita = criarNo(25);

    printf("Verificando Arvore 1...\n");
    bool achou1 = existeValorNegativo_iterativo(raiz1);
    printf("Existe valor negativo na Arvore 1? %s\n\n", achou1 ? "Sim" : "Nao");

    // --- Teste 2: Arvore SEM valor negativo ---
    No* raiz2 = criarNo(15);
    raiz2->esquerda = criarNo(100);
    raiz2->direita = criarNo(5);

    printf("Verificando Arvore 2...\n");
    bool achou2 = existeValorNegativo_iterativo(raiz2);
    printf("Existe valor negativo na Arvore 2? %s\n", achou2 ? "Sim" : "Nao");

    liberarArvore(raiz1);
    liberarArvore(raiz2);

    return 0;
}
