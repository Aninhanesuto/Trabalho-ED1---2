#ifndef __PRODUTO_H__
#define __PRODUTO_H__

/*INCLUSÃO DE BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>

/*  NOME DA ESTRUTURA: Produto
    VARIÁVEIS:
        void* dado = ponteiro para estrutura que está sendo armazenada (chocolate, vinho, livro ou filme);
        void(*print)(void* dado) = ponteiro para uma função de imprimir referente à estrutura que está sendo armazenada;
        int(*compara)(void* dado, void* chave) = ponteiro para uma função de comparar referente à uma estrutura que está sendo armazenada;
        struct produto *next = ponteiro para o próximo elemento da lista de produto;
*/
typedef struct produto{
    void *dado;
    void(*print)(void* dado);
    int(*compara)(void* dado, void* chave);
    void(*desaloca)(void* dado);
    struct produto *next;
}Produto;

Produto* inicializaProduto();

/*  
    NOME DA FUNÇÃO: Produto* alocaProduto;
    DESCRIÇÃO: Função genérica responsável por alocar um nó Produto, atribuindo aos campos os dados fornecidos nos parâmetros;
    PARÂMETROS: void* dado = ponteiro para estrutura que está sendo armazenada (chocolate, vinho, livro ou filme);
                void(*print)(void* dado) = ponteiro para uma função de imprimir referente à estrutura que está sendo armazenada;
                int(*compara)(void* dado, void* chave) = ponteiro para uma função de comparar referente à uma estrutura que está sendo armazenada;
                struct produto *next = ponteiro para o próximo elemento da lista de produto;
    RETORNO: Retorna um novo nó do tipo Produto.
*/
Produto* alocaProduto(void* dado, void(*print)(void *dado), int(*compara)(void* dado, void* chave), void(*desaloca)(void* dado));

/*  
    NOME DA FUNÇÃO: void printProduto;
    DESCRIÇÃO: Função genérica responsável por imprimir os dados contidos no campo void* dado no nó da estrutura Produto;
    PARÂMETROS: Produto* P = nó do Produto;
    RETORNO: Função sem retorno;
*/
void printProduto(Produto *P);

/*  
    NOME DA FUNÇÃO: int comparaProduto;
    DESCRIÇÃO: Função genérica responsável por comparar o campo dado com uma chave fornecida;
    PARÂMETROS: Produto* P = nó do Produto;
                void* chave =  chave para ser comparada;
    RETORNO: Retorna a comparação do dado com a chave;
*/
int comparaProduto(Produto *P, void* chave);

void freeProduto(Produto *P);

#endif 
