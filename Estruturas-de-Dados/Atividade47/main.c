#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;


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

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirEmOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

No* copiarArvore(No* raiz_original) {
    // 1. Caso base: se o no original e nulo, a copia tambem e.
    if (raiz_original == NULL) {
        return NULL;
    }

    // 2. Cria um novo no com o mesmo valor do no original.
    No* no_copiado = criarNo(raiz_original->valor);

    // 3. Chama recursivamente para copiar as subarvores.
    no_copiado->esquerda = copiarArvore(raiz_original->esquerda);
    no_copiado->direita = copiarArvore(raiz_original->direita);

    // 4. Retorna o no recem-criado e ja conectado as suas subarvores copiadas.
    return no_copiado;
}




int main() {

    No* arvore_original = criarNo(10);
    arvore_original->esquerda = criarNo(5);
    arvore_original->direita = criarNo(20);

    printf("Iniciando o programa de copia de arvore...\n\n");


    No* arvore_copia = copiarArvore(arvore_original);

    printf("Arvore Original (percurso em-ordem): ");
    imprimirEmOrdem(arvore_original);
    printf("\n");

    printf("Arvore Copiada (percurso em-ordem):  ");
    imprimirEmOrdem(arvore_copia);
    printf("\n\n");

    printf("As arvores sao independentes. Liberando a memoria de ambas...\n");

    liberarArvore(arvore_original);
    liberarArvore(arvore_copia);

    printf("Memoria liberada com sucesso.\n");

    return 0;
}
