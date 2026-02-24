#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Estrutura do no da arvore
typedef struct No
{
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Funcao para criar um novo no
No* criarNo(int valor)
{
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL)
    {
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

// Funcao para inserir um valor na arvore
No* inserir(No* raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    if (valor < raiz->valor)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Funcao para buscar um valor na arvore
No* buscar(No* raiz, int valor)
{
    printf("Buscou\n");
    if (raiz == NULL || raiz->valor == valor)
    {
        return raiz;
    }

    if (valor < raiz->valor)
    {
        return buscar(raiz->esquerda, valor);
    }
    else
    {
        return buscar(raiz->direita, valor);
    }
}

void imprimirArvore(No* raiz)
{
    if (raiz == NULL) return;
    printf("%d,", raiz->valor);
    imprimirArvore(raiz->esquerda);
    printf("");
    imprimirArvore(raiz->direita);
    printf("");
}


// Funcao para percorrer a arvore em ordem (esquerda, raiz, direita)
void emOrdem(No* raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
//Questão 2
//Função que conta numeros de nos
int contaNos(No* raiz)
{
    if(raiz == NULL)

        return 0;


    return 1 + contaNos(raiz->esquerda)+ contaNos(raiz->direita);
}

// Questão 3
//função para contar nos não folhas
int contarNosNaoFolhas(No* raiz)
{
    if (raiz == NULL)
    {

        return 0;

    }

    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return 0;
    }
    return 1 + contarNosNaoFolhas(raiz->esquerda) + contarNosNaoFolhas(raiz->direita);

}

//Questão 4
int contarNosFolhas(No* raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return 1;
    }

    return contarNosFolhas(raiz->esquerda) + contarNosFolhas(raiz->direita);
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//Questão 5
int contarAltura(No* raiz )
{

    if (raiz == NULL)
    {

        return -1;
    }
    int altura_esquerda = contarAltura(raiz->esquerda);
    int altura_direita = contarAltura(raiz->direita);

    return 1 + max(altura_esquerda, altura_direita);

}

//Questão 6
No* buscarNumeroImpar(No* raiz)
{

    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->valor % 2 != 0)
    {
        return raiz;
    }

    No* encontrado_na_esquerda = buscarNumeroImpar(raiz->esquerda);

    if (encontrado_na_esquerda != NULL)
    {
        return encontrado_na_esquerda;
    }

    return buscarNumeroImpar(raiz->direita);
}

//Questão 7
int acharMaiorNumero(No* raiz)
{

    int maior_valor = raiz->valor;


    if (raiz->esquerda != NULL)
    {
        int maior_esquerda = acharMaiorNumero(raiz->esquerda);
        // Comparamos com nosso candidato atual.
        if (maior_esquerda > maior_valor)
        {
            maior_valor = maior_esquerda;
        }
    }

    // Fazemos o mesmo para a subárvore direita.
    if (raiz->direita != NULL)
    {
        int maior_direita = acharMaiorNumero(raiz->direita);
        if (maior_direita > maior_valor)
        {
            maior_valor = maior_direita;
        }
    }

    return maior_valor;
}



No* encontrarExtremaDireita(No* no)
{
    if (no == NULL || no->direita == NULL)
    {
        return no;
    }
    return encontrarExtremaDireita(no->direita);
}

void liberarArvore(No* raiz);

//Questão 8
No* excluirNosPares(No* raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    // Travessia Pós-Ordem
    raiz->esquerda = excluirNosPares(raiz->esquerda);
    raiz->direita = excluirNosPares(raiz->direita);

    // Agora, verifica o nó atual usando 'valor'
    if (raiz->valor % 2 == 0)
    {
        No* nova_raiz_subarvore;

        if (raiz->esquerda == NULL)
        {
            nova_raiz_subarvore = raiz->direita;
        }
        else
        {
            nova_raiz_subarvore = raiz->esquerda;
            No* no_extrema_direita = encontrarExtremaDireita(raiz->esquerda);
            no_extrema_direita->direita = raiz->direita;
        }

        free(raiz);
        return nova_raiz_subarvore;
    }

    // Se for ímpar, mantém o nó
    return raiz;
}


//Questão 9

No* encontrarMinimo(No* no) {
    No* atual = no;
    while (atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* excluirNo(No* raiz, int valor_para_excluir) {
    if (raiz == NULL) {
        return raiz;
    }

    // Navega até o nó a ser excluído
    if (valor_para_excluir < raiz->valor) {
        raiz->esquerda = excluirNo(raiz->esquerda, valor_para_excluir);
    } else if (valor_para_excluir > raiz->valor) {
        raiz->direita = excluirNo(raiz->direita, valor_para_excluir);
    } else { // Encontrou o nó a ser excluído (raiz->valor == valor_para_excluir)
        // Caso 1 e 2: Nó com 0 ou 1 filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: Nó com 2 filhos
        No* sucessor = encontrarMinimo(raiz->direita);
        raiz->valor = sucessor->valor;
        raiz->direita = excluirNo(raiz->direita, sucessor->valor);
    }
    return raiz;
}

No* excluirParesBST(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    // Pós-ordem: primeiro conserta as subárvores
    raiz->esquerda = excluirParesBST(raiz->esquerda);
    raiz->direita = excluirParesBST(raiz->direita);

    // Agora, verifica o nó atual
    if (raiz->valor % 2 == 0) {
        // Se o nó atual é par, usa a função de exclusão de BST para removê-lo
        return excluirNo(raiz, raiz->valor);
    }

    // Se for ímpar, mantém o nó
    return raiz;
}
    //Questão 10
    bool ehValida(No* no, int min, int max) {
    // 1. Uma árvore vazia é uma BST válida.
    if (no == NULL) {
        return true;
    }

    // 2. Se o valor do nó está fora do intervalo, a árvore é inválida.
    // (Esta implementação não permite valores duplicados)
    if (no->valor <= min || no->valor >= max) {
        return false;
    }

    // 3. Verifica as subárvores, atualizando os limites do intervalo.
    return ehValida(no->esquerda, min, no->valor) &&
           ehValida(no->direita, no->valor, max);
}

bool ehArvoreDeBusca(No* raiz) {
    // Inicia a verificação recursiva com o intervalo máximo possível.
    return ehValida(raiz, INT_MIN, INT_MAX);
}

// Funcao para liberar memoria da arvore
void liberarArvore(No* raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}


int main()
{
    No* raiz = NULL;

    // Inserindo elementos
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 15);
    inserir(raiz, 20);
    inserir(raiz, 100);
    inserir(raiz, 60);
    inserir(raiz, 80);

    contaNos(raiz);
    // Exibindo em ordem
    printf("Percurso em ordem: ");
    emOrdem(raiz);
    printf("\n");


    //questão 02
    int totalNos = contaNos(raiz);
    printf ("Numero de nos na arvore %d\n",totalNos);

    // questão 03
    int totalNosNaoFolhas = contarNosNaoFolhas(raiz);
    printf ("Numero de nos nao folhas na arvore %d\n",totalNosNaoFolhas);

    //questão 04
    int totalNosFolhas = contarNosFolhas(raiz);
    printf ("Numero de nos folhas na arvore %d\n",totalNosFolhas);

    //questão 05
    int alturaArvore = contarAltura(raiz);
    printf ("A altura da arvore eh %d\n",alturaArvore);

    //questão 06
    printf("Buscando por um numero impar...\n");
    No* no_encontrado = buscarNumeroImpar(raiz);

    if (no_encontrado != NULL)
    {
        printf(" SUCESSO! Numero impar encontrado: %d\n", no_encontrado->valor);
    }
    else
    {
        printf(" FALHA! Nenhum numero ímpar existe na arvore.\n");
    }

    //Questao 07

    printf("Buscando o MAIOR numero \n");

    if (raiz == NULL)
    {
        printf("A arvore esta vazia.\n");
    }
    else
    {

        int maior = acharMaiorNumero(raiz);
        printf(" O maior numero na arvore eh: %d\n", maior);
    }

//Questão 08

    printf("Arvore original: ");
    imprimirArvore(raiz);
    printf("\n\n");

    // Chama a função de exclusão
    raiz = excluirNosPares(raiz);

    printf("Arvore apos excluir nos pares: ");
    imprimirArvore(raiz);
    printf("\n\n");

    //Questão 09
    inserir(raiz, 50);
    inserir(raiz, 10);
    inserir(raiz, 20);
    inserir(raiz, 9);

    printf("Arvore original (em ordem): ");
    emOrdem(raiz);
    printf("\n");

    // Chama a função de exclusão
    raiz = excluirParesBST(raiz);

    printf("Arvore apos excluir nos pares (em ordem): ");
    emOrdem(raiz);
    printf("\n");


    //Questão 10
     // --- Teste 1: Árvore VÁLIDA ---
    No* raiz_valida = criarNo(20);
    raiz_valida->esquerda = criarNo(10);
    raiz_valida->direita = criarNo(30);
    raiz_valida->esquerda->direita = criarNo(15);
    raiz_valida->direita->esquerda = criarNo(25);

    // --- Teste 2: Árvore INVÁLIDA ---
    No* raiz_invalida = criarNo(20);
    raiz_invalida->esquerda = criarNo(10);
    raiz_invalida->esquerda->direita = criarNo(25); // Viola a regra!

    printf("Verificando as arvores...\n\n");

    bool resultado1 = ehArvoreDeBusca(raiz_valida);
    printf("A primeira arvore e uma BST? %s\n", resultado1 ? "Sim " : "Nao ");

    bool resultado2 = ehArvoreDeBusca(raiz_invalida);
    printf("A segunda arvore e uma BST? %s\n", resultado2 ? "Sim " : "Nao ");


    // Liberando a memória
    liberarArvore(raiz_valida);
    liberarArvore(raiz_invalida);

    liberarArvore(raiz);
    return 0;
















    // Buscando elemento
    int chave = 90;
    No* encontrado = buscar(raiz, chave);
    if (encontrado != NULL)
    {
        printf("Valor %d encontrado na arvore.\n", chave);
    }
    else
    {
        printf("Valor %d nao encontrado.\n", chave);
    }

    // Liberar memoria
    liberarArvore(raiz);

    return 0;
}
