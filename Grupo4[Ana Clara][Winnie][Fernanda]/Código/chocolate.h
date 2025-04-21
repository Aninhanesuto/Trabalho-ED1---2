#ifndef __CHOCOLATE_H__
#define __CHOCOLATE_H__

/*INCLUSÃO DE BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  NOME DA ESTRUTURA: chocoNode
    VARIÁVEIS:
   char* nome = armazena uma string para o nome do chocolate;
        char* marca = armazena uma string para a marca do chocolate;
        char* tipo = armazena uma string para o tipo do chocolate;
        char* porcentagem = armazena uma string para a porcentagem de cacau do chocolate;
        char* origem = armazena uma string para a origem do chocolate;
        char* peso = armazena uma string para o peso do chocolate;
        char* ano_de_fabricacao = armazena uma string para o ano de fabricação do chocolate;
        char* validade = armazena uma string para a validade do chocolate;

*/
typedef struct Chocolate{
    char* nome;
    char* marca;
    char* tipo;
    char* porcentagem;
    char* origem;
    char* peso;
    char* ano_de_fabricacao;
    char* validade;
}chocoNode;

/*  
    NOME DA FUNÇÃO: chocoNode* alocaChoco
    DESCRIÇÃO: Função responsável por alocar uma estrutura que corresponde a um chocolate para ser inserido; a função recebe os parâmetros e realiza
               a alocação dinâmica das variáveis do tipo char*, e atribui os dados fornecidos aos campos.
    PARÂMETROS:    char* nome = armazena uma string para o nome do chocolate;
        char* marca = armazena uma string para a marca do chocolate;
        char* tipo = armazena uma string para o tipo do chocolate;
        char* porcentagem = armazena uma string para a porcentagem de cacau do chocolate;
        char* origem = armazena uma string para a origem do chocolate;
        char* peso = armazena uma string para o peso do chocolate;
        char* ano_de_fabricacao = armazena uma string para o ano de fabricação do chocolate;
        char* validade = armazena uma string para a validade do chocolate;

    RETORNO: Retorna a estrutura chocoNode com os dados fornecidos
*/
chocoNode* alocaChoco(char *nome, char* marca, char* tipo, char* porcentagem, char* origem, char* peso, char* ano_de_fabricacao, char* validade);

/*  
    NOME DA FUNÇÃO: chocoNode* leChoco;
    DESCRIÇÃO: Função responsável por ler os dados necessários da estrutura chocoNode;
    PARÂMETROS: Não possui parâmetros;
    RETORNO: Retorna a função alocaChoco após a leitura de todos os dados;
*/
chocoNode* leChoco();

/*  
    NOME DA FUNÇÃO: int comparaChoco;
    DESCRIÇÃO: Função responsável por comparar uma chave e o nome do chocolate contido na estrutura; Realiza o casting da estrutura e 
               da chave;
    PARÂMETROS: void* dado = estrutura do chocolate a ser comparada; 
                void* chave =  chave para ser comparada;
    RETORNO: Retorna o valor da comparação pela função strcmp, que compara o nome do chocolate e a chave. Retorna 0 se igual, negativo se o nome é menor que a chave, e positivo se o nome é maior que a chave (em ordem alfabética).

*/
int comparaChoco(void* dado, void* chave);

/*  
    NOME DA FUNÇÃO: void imprimeChoco;
    DESCRIÇÃO: Função responsável por imprimir todos os dados contidos na estrutura chocoNode;
    PARÂMETROS: void* dado = estrutura do chocolate a ser imprimida;
    RETORNO: Função não possui retorno.
*/
void imprimeChoco(void* dado);

/*  
    NOME DA FUNÇÃO: void freeChoco;
    DESCRIÇÃO: Função responsável por dar free nas variáveis que foram alocadas dinâmicamente na estrutura.
    PARÂMETROS: void* dado = estrutura do chocolate a ser desalocada.
    RETORNO: Função não possui retorno.
*/
void freeChoco(void *dado);

#endif 
