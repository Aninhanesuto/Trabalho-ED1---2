#ifndef __LIVRO_H__
#define __LIVRO_H__

/*INCLUSÃO DE BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  NOME DA ESTRUTURA: LivroNode
    VARIÁVEIS:
        char* titulo = armazena uma string para o titulo do Livro;
        char* autor = armazena uma string para o autor do Livro;
        char* editora = armazena uma string para a editora do Livro;
        char* DataDePublicacao = armazena uma string para a data de publicacao do Livro;
        char* idioma = armazena uma string para o idioma do Livro;
        int NumDePag = inteiro referente ao numero de paginas do Livro;
*/
typedef struct Livro{
    char* titulo;
    char* autor;
    char* editora;
    char* DataDePublicacao;
    char* idioma;
    int NumDePag;
}LivroNode;

/*  
    NOME DA FUNÇÃO: LivroNode alocaLivro
    DESCRIÇÃO: Função responsável por alocar uma estrutura que corresponde a um Livro para ser inserido; a função recebe os parâmetros e realiza
               a alocação dinâmica das variáveis do tipo char*, e atribui os dados fornecidos aos campos.
    PARÂMETROS: char* titulo = armazena uma string para o titulo do Livro;
                char* autor = armazena uma string para o autor do Livro;
                char* editora = armazena uma string para a editora do Livro;
                char* DataDePublicacao = armazena uma string para a data de publicacao do Livro;
                char* idioma = armazena uma string para o idioma do Livro;
                int NumDePag = inteiro referente ao numero de paginas do Livro;
    RETORNO: Retorna a estrutura chocoNode com os dados fornecidos
*/
LivroNode* alocaLivro(char *titulo, char* autor, char* editora, char* DataDePublicacao, int NumDePag, char* idioma);


/*  
    NOME DA FUNÇÃO: LivroNode* leLivro ;
    DESCRIÇÃO: Função responsável por ler os dados necessários da estrutura LivroNode;
    PARÂMETROS: Não possui parâmetros;
    RETORNO: Retorna a um livro após a leitura de todos os dados;
*/
LivroNode* leLivro();

/*  
    NOME DA FUNÇÃO: int comparaLivro;
    DESCRIÇÃO: Função responsável por comparar uma chave e o nome do Livro contido na estrutura; Realiza o casting da estrutura e 
               da chave;
    PARÂMETROS: void* dado = estrutura do Livro a ser comparada; 
                void* chave =  chave para ser comparada;
    RETORNO: Retorna o valor da comparação pela função strcmp, que compara o nome do chocolate e a chave. Retorna 0 se igual, um valor negativo se o nome é menor que a chave, e um valor positivo se o nome é maior que a chave (em ordem alfabética).

*/
int comparaLivro(void* dado, void* chave);

/*  
    NOME DA FUNÇÃO: void imprimeLivro;
    DESCRIÇÃO: Função responsável por imprimir todos os dados contidos na estrutura LivroNode;
    PARÂMETROS: void* dado = estrutura do Livro a ser imprimida;
    RETORNO: Função não possui retorno.
*/
void imprimeLivro(void* dado);

/*  
    NOME DA FUNÇÃO: void freeLivro;
    DESCRIÇÃO: Função responsável por dar free nas variáveis que foram alocadas dinâmicamente na estrutura.
    PARÂMETROS: void* dado = estrutura do filme a ser desalocada.
    RETORNO: Função não possui retorno.
*/
void freeLivro(void *dado);

#endif 