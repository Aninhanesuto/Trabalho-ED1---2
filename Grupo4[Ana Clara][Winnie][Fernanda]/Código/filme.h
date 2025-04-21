#ifndef __FILME_H__
#define __FILME_H__

/*INCLUSÃO DE BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  NOME DA ESTRUTURA: FilmeNode
    VARIÁVEIS:
        char* titulo = armazena uma string para o titulo do Filme;
        char* diretor = armazena uma string para o diretor do Filme;
        char* genero = armazena uma string para o genero do Filme;
        char* distribuidor = armazena uma string para o distribuidor do Filme
        char* PaisDeOrigem = armazena uma string para o pais de origem do Filme;
        char* duracao  = armazena uma string para o pais de origem do Filme;
*/
typedef struct Filme{
    char* titulo;
    char* diretor;
    char* genero;
    char* distribuidor;
    char* PaisDeOrigem;
    char* duracao;
}FilmeNode;

/*  
    NOME DA FUNÇÃO: FilmeNode alocaFilme
    DESCRIÇÃO: Função responsável por alocar uma estrutura que corresponde a um filme para ser inserido; a função recebe os parâmetros e realiza
               a alocação dinâmica das variáveis do tipo char*, e atribui os dados fornecidos aos campos.
    PARÂMETROS: char* titulo = armazena uma string para o titulo do Filme;
                char* diretor = armazena uma string para o diretor do Filme;
                char* genero = armazena uma string para o genero do Filme;
                char* distribuidor = armazena uma string para o distribuidor do Filme
                char* PaisDeOrigem = armazena uma string para o pais de origem do Filme;
                char* duracao  = armazena uma string para o pais de origem do Filme;
    RETORNO: Retorna a estrutura chocoNode com os dados fornecidos
*/
FilmeNode* alocaFilme(char *titulo, char* diretor, char* genero, char* distribuidor, char* PaisDeOrigem, char* duracao);

/*  
    NOME DA FUNÇÃO: FilmeNode* leFilme ;
    DESCRIÇÃO: Função responsável por ler os dados necessários da estrutura FilmeNode;
    PARÂMETROS: Não possui parâmetros;
    RETORNO: Retorna um filme após a leitura de todos os dados;
*/
FilmeNode* leFilme();

/*  
    NOME DA FUNÇÃO: int comparaFilme;
    DESCRIÇÃO: Função responsável por comparar uma chave e o nome do Filme contido na estrutura; Realiza o casting da estrutura e 
               da chave;
    PARÂMETROS: void* dado = estrutura do Filme a ser comparada; 
                void* chave =  chave para ser comparada;
    RETORNO: Retorna o valor da comparação pela função strcmp, que compara o nome do chocolate e a chave. Retorna 0 se igual, negativo se o nome é menor que a chave, e positivo se o nome é maior que a chave (em ordem alfabética).

*/
int comparaFilme(void* dado, void* chave);

/*  
    NOME DA FUNÇÃO: void imprimeFilme;
    DESCRIÇÃO: Função responsável por imprimir todos os dados contidos na estrutura FilmeNode;
    PARÂMETROS: void* dado = estrutura do Filme a ser imprimida;
    RETORNO: Função não possui retorno.
*/
void imprimeFilme(void* dado);

/*  
    NOME DA FUNÇÃO: void freeFilme;
    DESCRIÇÃO: Função responsável por dar free nas variáveis que foram alocadas dinâmicamente na estrutura.
    PARÂMETROS: void* dado = estrutura do file a ser desalocada.
    RETORNO: Função não possui retorno.
*/
void freeFilme(void *dado);

#endif 