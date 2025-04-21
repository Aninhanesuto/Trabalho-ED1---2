#include "produto.h"

Produto* inicializaProduto(){
    Produto* ProdutoNode = (Produto*)calloc(1,sizeof(Produto));
    if(ProdutoNode==NULL){
        printf("ERRO_DE_ALOCACAO!");
        exit(1);
    }

    return ProdutoNode;
}

Produto* alocaProduto(void* dado, void(*print)(void *dado), int(*compara)(void* dado, void* chave), void(*desaloca)(void* dado)){
    Produto* ProdutoNode = (Produto*)calloc(1,sizeof(Produto));
    if(ProdutoNode==NULL){
        printf("ERRO_DE_ALOCACAO!");
        exit(1);
    }
    ProdutoNode->dado = dado;
    ProdutoNode->compara = compara;
    ProdutoNode->print = print;
    ProdutoNode->desaloca = desaloca;

    return ProdutoNode;
}

void printProduto(Produto *P){
    P->print(P->dado);
}

int comparaProduto(Produto *P, void* chave){
    return P->compara(P->dado, chave);
}

void freeProduto(Produto *P){
    if(P!=NULL){
        P->desaloca(P->dado);
        free(P);
    }
}
