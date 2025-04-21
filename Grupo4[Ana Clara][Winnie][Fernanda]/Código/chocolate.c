#include "chocolate.h"


#define MAX_TAM 100


chocoNode* alocaChoco(char *nome, char* marca, char* tipo, char* porcentagem, char* origem, char* peso, char* ano_de_fabricacao, char* validade){
    chocoNode* novo = (chocoNode*)calloc(1,sizeof(chocoNode));
    if(novo==NULL){
        printf("ERRO_DE_ALOCACAO\n");
        exit(1);
    }

    novo->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    novo->marca = (char*)malloc(sizeof(char) * (strlen(marca) + 1));
    novo->tipo = (char*)malloc(sizeof(char) * (strlen(tipo) + 1));
    novo->origem = (char*)malloc(sizeof(char) * (strlen(origem) + 1));
    novo->validade = (char*)malloc(sizeof(char) * (strlen(validade) + 1));

    novo->porcentagem = (char*)malloc(sizeof(char) * (strlen(porcentagem) + 1));
    novo->peso = (char*)malloc(sizeof(char) * (strlen(peso) + 1));
    novo->ano_de_fabricacao = (char*)malloc(sizeof(char) * (strlen(ano_de_fabricacao) + 1));

    strcpy(novo->nome, nome);
    strcpy(novo->marca, marca);
    strcpy(novo->tipo, tipo);
    strcpy(novo->origem, origem);
    strcpy(novo->validade, validade);
    strcpy(novo->porcentagem, porcentagem);
    strcpy(novo->peso, peso);
    strcpy(novo->ano_de_fabricacao, ano_de_fabricacao);

    return novo;
}

chocoNode* leChoco(){
    char nome[MAX_TAM];
    char marca[MAX_TAM];
    char tipo[MAX_TAM];
    char porcentagem[MAX_TAM];
    char origem[MAX_TAM];
    char peso[MAX_TAM];
    char ano_de_fabricacao[MAX_TAM];
    char validade[MAX_TAM];

    getchar(); // Limpa qualquer '\n' no buffer antes da primeira entrada

    printf("NOME: ");
    scanf(" %[^\n]%*c", nome);
    printf("\nMARCA: ");
    scanf(" %[^\n]%*c", marca);
    printf("\nTIPO DE CHOCOLATE: ");
    scanf(" %[^\n]%*c", tipo);
    
    if(strcmp(tipo, "amargo") == 0){
        printf("\nPORCENTAGEM DE CACAU: ");
        scanf(" %[^\n]%*c", porcentagem);
        
    }
    
    else strcpy(porcentagem, "-");
    
    

    printf("\nNACIONALIDADE OU ORIGEM: ");
    scanf(" %[^\n]%*c", origem);

    printf("\nPESO: ");
    scanf(" %[^\n]%*c", peso);
    //getchar(); // Limpa o '\n' deixado pelo scanf de número

    printf("\nANO DE FABRICACAO: ");
    scanf(" %[^\n]%*c", ano_de_fabricacao);
    //getchar(); // Limpa o '\n' deixado pelo scanf de número

    printf("\nVALIDADE: ");
    scanf(" %[^\n]%*c", validade);

    return alocaChoco(nome, marca, tipo, porcentagem, origem, peso, ano_de_fabricacao, validade);
}

int comparaChoco(void* dado, void* chave) {
    chocoNode* d = (chocoNode*)dado;
    char* c = (char*)chave;

    return strcmp(d->nome, c);
}

void imprimeChoco(void* dado){
    chocoNode* node = (chocoNode*)dado;
    printf("NOME: %s\n", node->nome);
    printf("MARCA: %s\n", node->marca);
    printf("TIPO DE CHOCOLATE: %s\n", node->tipo);
    printf("PORCENTAGEM DE CACAU: %s%%\n", node->porcentagem);
    printf("NACIONALIDADE OU ORIGEM: %s\n", node->origem);
    printf("PESO: %sg\n", node->peso);
    printf("ANO DE FABRICACAO: %s\n", node->ano_de_fabricacao);
    printf("VALIDADE: %s\n", node->validade);

}

void freeChoco(void *dado){
    chocoNode* node = (chocoNode*)dado;
    if(node!=NULL){
        free(node->nome);
        free(node->marca);
        free(node->tipo);
        free(node->porcentagem);
        free(node->peso);
        free(node->ano_de_fabricacao);
        free(node->origem);
        free(node->validade);
        free(node);
    } 
}
