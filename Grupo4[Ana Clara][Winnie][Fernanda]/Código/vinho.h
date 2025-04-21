#ifndef __VINHO_H__
#define __VINHO_H__

/*INCLUSÃO DE BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  NOME DA ESTRUTURA: VinhoNode
    VARIÁVEIS:
        char* nome = armazena uma string para o nome do Vinho;
        char* vinicola = armazena uma string para a vinicola do Vinho;
        char* tipo = armazena uma string para o tipo do Vinho;
        char* pais = armazena uma string para o pais do Vinho;
        char* regiao = armazena uma string a regiao do Vinho;
        int ano_de_fabricacao = inteiro referente ao ano de fabricação do Vinho;
        char* uva = armazena uma string para a uva do Vinho;
*/
typedef struct Vinho{
    char* nome;
    char* vinicola;
    char* tipo;
    char* pais;
    char* regiao;
    int ano_de_fabricacao;
    char* uva;
}VinhoNode;

/*  
    NOME DA FUNÇÃO: VinhoNode* alocaVinho
    DESCRIÇÃO: Função responsável por alocar uma estrutura que corresponde a um Vinho para ser inserido; a função recebe os parâmetros e realiza
               a alocação dinâmica das variáveis do tipo char*, e atribui os dados fornecidos aos campos.
    PARÂMETROS: char* nome = armazena uma string para o nome do Vinho;
                char* vinicola = armazena uma string para a vinicola do Vinho;
                char* tipo = armazena uma string para o tipo do Vinho;
                char* pais = armazena uma string para o pais do Vinho;
                char* regiao = armazena uma string a regiao do Vinho;
                int ano_de_fabricacao = inteiro referente ao ano de fabricação do Vinho;
                char* uva = armazena uma string para a uva do Vinho;
    RETORNO: Retorna a estrutura VinhoNode com os dados fornecidos
*/
VinhoNode* alocaVinho(char *nome, char* vinicola, char* tipo, char* pais, char* regiao, int ano_de_fabricacao, char* uva);

/*  
    NOME DA FUNÇÃO: VinhoNode* leVinho;
    DESCRIÇÃO: Função responsável por ler os dados necessários da estrutura VinhoNode;
    PARÂMETROS: Não possui parâmetros;
    RETORNO: Retorna a vinho após a leitura de todos os dados;
*/
VinhoNode* leVinho();

/*  
    NOME DA FUNÇÃO: int comparaVinho;
    DESCRIÇÃO: Função responsável por comparar uma chave e o nome do Vinho contido na estrutura; Realiza o casting da estrutura e 
               da chave;
    PARÂMETROS: void* dado = estrutura do Vinho a ser comparada; 
                void* chave =  chave para ser comparada;
    RETORNO: Retorna o valor da comparação pela função strcmp, que compara o nome do chocolate e a chave. Retorna 0 se igual, um valor negativo se o nome é menor que a chave, e um valor positivo se o nome é maior que a chave (em ordem alfabética).

*/
int comparaVinho(void* dado, void* chave);

/*  
    NOME DA FUNÇÃO: void imprimeVinho;
    DESCRIÇÃO: Função responsável por imprimir todos os dados contidos na estrutura VinhoNode;
    PARÂMETROS: void* dado = estrutura do Vinho a ser imprimida;
    RETORNO: Função não possui retorno.
*/
void imprimeVinho(void* dado);

/*  
    NOME DA FUNÇÃO: void freeVinho;
    DESCRIÇÃO: Função responsável por dar free nas variáveis que foram alocadas dinâmicamente na estrutura.
    PARÂMETROS: void* dado = estrutura do vinho a ser desalocada.
    RETORNO: Função não possui retorno.
*/

void freeVinho(void *dado);

#endif 