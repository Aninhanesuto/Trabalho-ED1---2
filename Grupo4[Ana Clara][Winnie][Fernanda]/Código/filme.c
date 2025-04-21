#include "filme.h"


#define MAX_TAM 100

FilmeNode* alocaFilme(char *titulo, char* diretor, char* genero, char* distribuidor, char* PaisDeOrigem, char* duracao){
    FilmeNode* novo = (FilmeNode*)calloc(1,sizeof(FilmeNode));
    if(novo==NULL){
        printf("ERRO_DE_ALOCACAO\n");
        exit(1);
    }

    novo->titulo = (char*)malloc(sizeof(char) * (strlen(titulo) + 1));
    novo->diretor = (char*)malloc(sizeof(char) * (strlen(diretor) + 1));
    novo->genero = (char*)malloc(sizeof(char) * (strlen(genero) + 1));
    novo->distribuidor = (char*)malloc(sizeof(char) * (strlen(distribuidor) + 1));
    novo->PaisDeOrigem = (char*)malloc(sizeof(char) * (strlen(PaisDeOrigem) + 1));
    novo->duracao = (char*)malloc(sizeof(char) * (strlen(duracao) + 1));


    strcpy(novo->titulo, titulo);
    strcpy(novo->diretor, diretor);
    strcpy(novo->genero, genero);
    strcpy(novo->distribuidor, distribuidor);
    strcpy(novo->duracao, duracao);
    strcpy(novo->PaisDeOrigem, PaisDeOrigem);

    return novo;
}
FilmeNode* leFilme(){
    char titulo[MAX_TAM];
    char diretor[MAX_TAM];
    char genero[MAX_TAM];
    char distribuidor[MAX_TAM];
    char duracao[MAX_TAM]; // Corrigi a acentuação para evitar problemas
    char PaisDeOrigem[MAX_TAM];

    getchar(); // Limpa qualquer '\n' residual antes da primeira entrada

    printf("TÍTULO: ");
    scanf(" %[^\n]%*c", titulo);

    printf("DIRETOR: ");
    scanf(" %[^\n]%*c", diretor);

    printf("GÊNERO: ");
    scanf(" %[^\n]%*c", genero);

    printf("NACIONALIDADE OU ORIGEM: ");
    scanf(" %[^\n]%*c", distribuidor);

    printf("DURAÇÃO: ");
    scanf(" %[^\n]%*c", duracao); // Removi o '&'

    printf("PAÍS DE ORIGEM: ");
    scanf(" %[^\n]%*c", PaisDeOrigem);

    return alocaFilme(titulo, diretor, genero, distribuidor, PaisDeOrigem, duracao);
}

int comparaFilme(void* dado, void* chave) {
    FilmeNode* d = (FilmeNode*)dado;
    char* c = (char*)chave;

    return strcmp(d->titulo, c);
}

void imprimeFilme(void* dado){
    FilmeNode* node = (FilmeNode*)dado;
    printf("TITULO: %s\n", node->titulo);
    printf("DIRETOR: %s\n", node->diretor);
    printf("GENERO: %s\n", node->genero);
    printf("DISTRIBUIDORA: %s\n", node->distribuidor);
    printf("DURACAO: %s\n", node->duracao);
    printf("PAIS DE ORIGEM: %s\n", node->PaisDeOrigem);

}

void freeFilme(void *dado){
    FilmeNode* node = (FilmeNode*)dado;
    if(node!=NULL){
        free(node->titulo);
        free(node->diretor);
        free(node->genero);
        free(node->distribuidor);
        free(node->duracao);
        free(node->PaisDeOrigem);
        free(node);
    } 
}
