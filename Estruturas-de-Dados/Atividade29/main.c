#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

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

bool existeValor_iterativo(No* raiz, int x) {
    if (raiz == NULL) {
        return false;
    }

    Pilha* p = criarPilha();
    empilhar(p, raiz);

    while (!pilhaVazia(p)) {
        No* atual = desempilhar(p);

        // Verifica se o no atual contem o valor
        if (atual->valor == x) {
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

    // Se o laco terminar, o valor nao foi encontrado
    free(p);
    return false;
}


// --- Funcoes para o Exemplo de Teste ---
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
    // Montando uma arvore NAO ordenada de exemplo
    No* raiz = criarNo(15);
    raiz->esquerda = criarNo(100);
    raiz->direita = criarNo(-5);
    raiz->esquerda->esquerda = criarNo(2);
    raiz->esquerda->direita = criarNo(25);

    printf("Verificando a existencia de valores na arvore...\n");

    // Teste 1: Buscar um valor que existe
    int valor1 = 25;
    bool achou1 = existeValor_iterativo(raiz, valor1);
    printf("O valor %d existe na arvore? %s\n", valor1, achou1 ? "Sim" : "Nao");

    // Teste 2: Buscar um valor que NAO existe
    int valor2 = 99;
    bool achou2 = existeValor_iterativo(raiz, valor2);
    printf("O valor %d existe na arvore? %s\n", valor2, achou2 ? "Sim" : "Nao");

    liberarArvore(raiz);
    return 0;
}
