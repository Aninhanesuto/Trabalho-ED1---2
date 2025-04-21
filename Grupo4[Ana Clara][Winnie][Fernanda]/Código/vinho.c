#include "vinho.h"


#define MAX_TAM 100

VinhoNode* alocaVinho(char *nome, char* vinicola, char* tipo, char* pais, char* regiao, int ano_de_fabricacao, char* uva){
    VinhoNode* novo = (VinhoNode*)calloc(1,sizeof(VinhoNode));
    if(novo==NULL){
        printf("ERRO_DE_ALOCACAO\n");
        exit(1);
    }

    novo->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    novo->vinicola = (char*)malloc(sizeof(char) * (strlen(vinicola) + 1));
    novo->tipo = (char*)malloc(sizeof(char) * (strlen(tipo) + 1));
    novo->pais = (char*)malloc(sizeof(char) * (strlen(pais) + 1));
    novo->uva = (char*)malloc(sizeof(char) * (strlen(uva) + 1));
    novo->regiao = (char*)malloc(sizeof(char) * (strlen(regiao) + 1));
    
    novo->ano_de_fabricacao = ano_de_fabricacao;

    strcpy(novo->nome, nome);
    strcpy(novo->vinicola, vinicola);
    strcpy(novo->tipo, tipo);
    strcpy(novo->pais, pais);
    strcpy(novo->uva, uva);
    strcpy(novo->regiao, regiao);

    return novo;
}
VinhoNode* leVinho(){
    char nome[MAX_TAM];
    char vinicola[MAX_TAM];
    char tipo[MAX_TAM];
    char pais[MAX_TAM];
    char regiao[MAX_TAM];
    int ano_de_fabricacao;
    char uva[MAX_TAM];

    getchar(); // Remove qualquer '\n' residual

    printf("NOME: ");
    scanf(" %[^\n]%*c", nome);

    printf("VINÍCOLA: ");
    scanf(" %[^\n]%*c", vinicola);

    printf("TIPO: ");
    scanf(" %[^\n]%*c", tipo);

    printf("PAÍS: ");
    scanf(" %[^\n]%*c", pais);

    printf("REGIÃO: ");
    scanf(" %[^\n]%*c", regiao);

    printf("ANO DE FABRICAÇÃO: ");
    scanf("%d", &ano_de_fabricacao);
    getchar(); // Consome o '\n' deixado pelo scanf de inteiro

    printf("UVA: ");
    scanf(" %[^\n]%*c", uva);

    return alocaVinho(nome, vinicola, tipo, pais, regiao, ano_de_fabricacao, uva);
}

int comparaVinho(void* dado, void* chave) {
    VinhoNode* d = (VinhoNode*)dado;
    char* c = (char*)chave;

    return strcmp(d->nome, c);
}

void imprimeVinho(void* dado){
    VinhoNode* node = (VinhoNode*)dado;
    printf("NOME: %s\n", node->nome);
    printf("VINICOLA: %s\n", node->vinicola);
    printf("TIPO: %s\n", node->tipo);
    printf("PAIS: %s\n", node->pais);
    printf("REGIAO: %s\n", node->regiao);
    printf("ANO DE FABRICACAO: %d\n", node->ano_de_fabricacao);
    printf("UVA: %s\n", node->uva);

}

void freeVinho(void *dado){
    VinhoNode* node = (VinhoNode*)dado;
    if(node!=NULL){
        free(node->nome);
        free(node->vinicola);
        free(node->tipo);
        free(node->pais);
        free(node->regiao);
        free(node->uva);
        free(node);
    } 
}
