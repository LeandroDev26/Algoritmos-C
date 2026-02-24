#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

bool ehABB_iterativo(No* raiz) {
    if (raiz == NULL) {
        return true; // Uma arvore vazia e considerada uma ABB
    }

    Pilha* p = criarPilha();
    No* atual = raiz;
    No* no_anterior = NULL;

    while (atual != NULL || !pilhaVazia(p)) {
        // Percorre o caminho mais a esquerda, empilhando os nos
        while (atual != NULL) {
            empilhar(p, atual);
            atual = atual->esquerda;
        }

        // Visita o no (desempilha)
        atual = desempilhar(p);

        // AQUI ESTA A VERIFICACAO PRINCIPAL
        // Se o no anterior existe e seu valor e maior ou igual ao do no atual,
        // a ordem foi quebrada, entao nao e uma ABB.
        if (no_anterior != NULL && atual->valor <= no_anterior->valor) {
            // Limpa o resto da pilha para evitar vazamento de memoria
            while(!pilhaVazia(p)) desempilhar(p);
            free(p);
            return false;
        }

        // Atualiza o no anterior para a proxima comparacao
        no_anterior = atual;

        // Move para a subarvore direita
        atual = atual->direita;
    }

    // Se o laco terminar, a ordem foi mantida em toda a arvore
    free(p);
    return true;
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
    // --- Teste 1: Arvore que E uma ABB VALIDA ---
    No* raiz_valida = criarNo(20);
    raiz_valida->esquerda = criarNo(10);
    raiz_valida->direita = criarNo(30);

    // --- Teste 2: Arvore que NAO E uma ABB ---

    No* raiz_invalida = criarNo(20);
    raiz_invalida->esquerda = criarNo(10);
    raiz_invalida->esquerda->direita = criarNo(25);

    printf("Verificando as arvores de forma nao-recursiva...\n\n");

    bool res1 = ehABB_iterativo(raiz_valida);
    printf("A primeira arvore e uma ABB? %s\n", res1 ? "Sim" : "Nao");

    bool res2 = ehABB_iterativo(raiz_invalida);
    printf("A segunda arvore e uma ABB? %s\n", res2 ? "Sim" : "Nao");

    liberarArvore(raiz_valida);
    liberarArvore(raiz_invalida);

    return 0;
}
