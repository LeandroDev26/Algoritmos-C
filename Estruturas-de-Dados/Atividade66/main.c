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

int tamanhoIterativo(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    Pilha* p = criarPilha();
    empilhar(p, raiz);
    int contador = 0;

    while (!pilhaVazia(p)) {
        No* atual = desempilhar(p);
        contador++; // Conta o no que foi processado

        // Empilha os filhos para visita futura
        if (atual->direita != NULL) {
            empilhar(p, atual->direita);
        }
        if (atual->esquerda != NULL) {
            empilhar(p, atual->esquerda);
        }
    }

    free(p);
    return contador;
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

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->esquerda->esquerda->esquerda = criarNo(1);

    printf("Calculando o tamanho da arvore...\n");

    int tamanho = tamanhoIterativo(raiz);

    printf("O tamanho da arvore (numero de nos) e: %d\n", tamanho);

    liberarArvore(raiz);
    return 0;
}
