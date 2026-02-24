#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para armazenar os dados de cada municipio
typedef struct {
    char nome[100];
    double area;
    long populacao;
} Municipio;

// Struct para o no da arvore
typedef struct No {
    Municipio dados;
    struct No* esquerda;
    struct No* direita;
} No;


// Cria um novo no da arvore
No* criarNo(Municipio dados) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->dados.nome, dados.nome);
    novoNo->dados.area = dados.area;
    novoNo->dados.populacao = dados.populacao;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

// Insere um novo municipio na ABB (ordenado pelo nome)
No* inserir(No* raiz, Municipio dados) {
    if (raiz == NULL) {
        return criarNo(dados);
    }
    // Usa strcmp para comparar os nomes
    if (strcmp(dados.nome, raiz->dados.nome) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, dados);
    } else if (strcmp(dados.nome, raiz->dados.nome) > 0) {
        raiz->direita = inserir(raiz->direita, dados);
    }
    // Nota: Chaves duplicadas (mesmo nome) sao ignoradas.
    return raiz;
}

// Libera a memoria alocada para a arvore
void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}


// (a) Contar o numero de municipios
int contarMunicipios(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarMunicipios(raiz->esquerda) + contarMunicipios(raiz->direita);
}

// (b) Mostrar municipios com mais de X habitantes
void mostrarMaioresQueX(No* raiz, long x) {
    if (raiz == NULL) return;
    mostrarMaioresQueX(raiz->esquerda, x);
    if (raiz->dados.populacao > x) {
        printf("- %s\n", raiz->dados.nome);
    }
    mostrarMaioresQueX(raiz->direita, x);
}

// (c) Mostrar a densidade demografica
void mostrarDensidade(No* raiz) {
    if (raiz == NULL) return;
    mostrarDensidade(raiz->esquerda);

    double densidade = 0.0;
    if (raiz->dados.area > 0) {
        densidade = (double)raiz->dados.populacao / raiz->dados.area;
    }
    printf("- %s: %.2f hab/km\n", raiz->dados.nome, densidade);

    mostrarDensidade(raiz->direita);
}

// (d) Mostrar o somatorio de area em porcentagem
double somarAreas(No* raiz) {
    if (raiz == NULL) return 0.0;
    return raiz->dados.area + somarAreas(raiz->esquerda) + somarAreas(raiz->direita);
}

void mostrarPercentualArea(No* raiz) {
    const double AREA_BRASIL_KM2 = 8515767.0; // Area aproximada do Brasil
    double area_total_municipios = somarAreas(raiz);
    double percentual = (area_total_municipios / AREA_BRASIL_KM2) * 100.0;

    printf("Area total dos municipios cadastrados: %.2f km\n", area_total_municipios);
    printf("Isso representa %.6f%% do territorio nacional.\n", percentual);
}

// (e) Mostrar as cidades em ordem alfabetica
void listarEmOrdemAlfabetica(No* raiz) {
    if (raiz == NULL) return;
    listarEmOrdemAlfabetica(raiz->esquerda);
    printf("- %s (Area: %.2f km, Populacao: %ld)\n",
           raiz->dados.nome, raiz->dados.area, raiz->dados.populacao);
    listarEmOrdemAlfabetica(raiz->direita);
}

// (f) Mostrar a cidade com a maior populacao
void encontrarMaiorPopRecursivo(No* no, No** maior_no) {
    if (no == NULL) return;

    if (*maior_no == NULL || no->dados.populacao > (*maior_no)->dados.populacao) {
        *maior_no = no;
    }
    encontrarMaiorPopRecursivo(no->esquerda, maior_no);
    encontrarMaiorPopRecursivo(no->direita, maior_no);
}

void mostrarMaiorPopulacao(No* raiz) {
    if (raiz == NULL) {
        printf("A arvore esta vazia.\n");
        return;
    }
    No* maior_no = NULL;
    encontrarMaiorPopRecursivo(raiz, &maior_no);
    printf("A cidade com maior populacao e: %s (%ld habitantes).\n",
           maior_no->dados.nome, maior_no->dados.populacao);
}




int main() {
    No* raiz = NULL;

    // Criando dados de exemplo
    Municipio m1 = {"Uberlandia", 4115.2, 706597};
    Municipio m2 = {"Araguari", 2730.6, 117825};
    Municipio m3 = {"Sao Paulo", 1521.1, 12396372};
    Municipio m4 = {"Monte Carmelo", 1354.0, 47689};
    Municipio m5 = {"Rio de Janeiro", 1200.3, 6775561};

    // Inserindo na arvore
    raiz = inserir(raiz, m1);
    raiz = inserir(raiz, m2);
    raiz = inserir(raiz, m3);
    raiz = inserir(raiz, m4);
    raiz = inserir(raiz, m5);

    printf("### Sistema de Gerenciamento de Municipios ###\n\n");

    // Testando as funcoes
    printf("--- (e) Lista de Municipios em Ordem Alfabetica ---\n");
    listarEmOrdemAlfabetica(raiz);

    printf("\n--- (a) Total de Municipios ---\n");
    printf("Total de municipios cadastrados: %d\n", contarMunicipios(raiz));

    printf("\n--- (b) Municipios com mais de 1.000.000 de habitantes ---\n");
    mostrarMaioresQueX(raiz, 1000000);

    printf("\n--- (c) Densidade Demografica ---\n");
    mostrarDensidade(raiz);

    printf("\n--- (d) Percentual de Area Total ---\n");
    mostrarPercentualArea(raiz);

    printf("\n--- (f) Municipio com Maior Populacao ---\n");
    mostrarMaiorPopulacao(raiz);

    printf("\n-------------------------------------------------\n");
    printf("Liberando memoria da arvore...\n");
    liberarArvore(raiz);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}
