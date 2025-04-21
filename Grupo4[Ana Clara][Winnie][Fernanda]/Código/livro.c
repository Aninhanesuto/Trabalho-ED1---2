#include "livro.h"


#define MAX_TAM 100

LivroNode* alocaLivro(char *titulo, char* autor, char* editora, char* DataDePublicacao, int NumDePag, char* idioma){
    LivroNode* novo = (LivroNode*)calloc(1,sizeof(LivroNode));
    if(novo==NULL){
        printf("ERRO_DE_ALOCACAO\n");
        exit(1);
    }

    novo->titulo = (char*)malloc(sizeof(char) * (strlen(titulo) + 1));
    novo->autor = (char*)malloc(sizeof(char) * (strlen(autor) + 1));
    novo->editora = (char*)malloc(sizeof(char) * (strlen(editora) + 1));
    novo->DataDePublicacao = (char*)malloc(sizeof(char) * (strlen(DataDePublicacao) + 1));
    novo->idioma = (char*)malloc(sizeof(char) * (strlen(idioma) + 1));

    novo->NumDePag = NumDePag;

    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    strcpy(novo->editora, editora);
    strcpy(novo->DataDePublicacao, DataDePublicacao);
    strcpy(novo->idioma, idioma);

    return novo;
}

LivroNode* leLivro(){
    char titulo[MAX_TAM];
    char autor[MAX_TAM];
    char editora[MAX_TAM];
    char dataDePublicacao[MAX_TAM]; // Evitei acentos para evitar erros
    int numDePag;
    char idioma[MAX_TAM];

    getchar(); // Remove qualquer '\n' residual

    printf("TÍTULO: ");
    scanf(" %[^\n]%*c", titulo);

    printf("AUTOR: ");
    scanf(" %[^\n]%*c", autor);

    printf("EDITORA: ");
    scanf(" %[^\n]%*c", editora);

    printf("DATA DE PUBLICAÇÃO: ");
    scanf(" %[^\n]%*c", dataDePublicacao);

    printf("NÚMERO DE PÁGINAS: ");
    scanf("%d", &numDePag);
    getchar(); // Consome o '\n' deixado pelo scanf de inteiro

    printf("IDIOMA: ");
    scanf(" %[^\n]%*c", idioma);

    return alocaLivro(titulo, autor, editora, dataDePublicacao, numDePag, idioma);
}

int comparaLivro(void* dado, void* chave) {
    LivroNode* d = (LivroNode*)dado;
    char* c = (char*)chave;

    return strcmp(d->titulo, c);
}

void imprimeLivro(void* dado){
    LivroNode* node = (LivroNode*)dado;
    printf("titulo: %s\n", node->titulo);
    printf("autor: %s\n", node->autor);
    printf("EDITORA: %s\n", node->editora);
    printf("DATA DE PUBLICACAO: %s\n", node->DataDePublicacao);
    printf("NUMERO DE PAGINAS: %d\n", node->NumDePag);
    printf("IDIOMA: %s\n", node->idioma);

}

void freeLivro(void *dado){
    LivroNode* node = (LivroNode*)dado;
    if(node!=NULL){
        free(node->titulo);
        free(node->autor);
        free(node->editora);
        free(node->DataDePublicacao);
        free(node->idioma);
        free(node);
    } 
}
