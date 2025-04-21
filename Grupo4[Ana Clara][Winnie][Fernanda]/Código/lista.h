#ifndef __LISTA_H__
#define __LISTA_H__
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "produto.h"

/*
ESTRUTURA: pilha
FUNÇÃO: Utilizaremos essa estrutura para auxiliar nas operações de undo e redo
VARIAVEIS: Produto *P = armazena uma lista
            struct pilha *next = ponteiro para o próximo nó da pilha*/
typedef struct pilha{
    Produto* P;
    struct pilha *next;
}Pilha;

/*
FUNÇÃO: Pilha* inicializaNoPilha;
DESCRIÇÃO: Inicializa um nó da pilha, recebendo um nó da pilha
PARÂMETROS: Produto *lista = lista de produtos 
RETORNO: Retorna um nó para pilha;
*/
Pilha* inicializaNoPilha(Produto *lista);

/*
FUNÇÃO: Pilha* inicializaPilha;
DESCRIÇÃO: Inicializa uma pilha
RETORNO: Retorna uma pilha;
*/
Pilha* inicializaPilha();

/*
FUNÇÃO: Pilha* inserePilha;
DESCRIÇÃO: Insere um novo nó no final da pilha
PARÂMETROS: Produto *lista = lista de produtos 
            Pilha* pilha = pilha onde será inserido o novo nó
RETORNO: Retorna a pilha modificada;
*/
Pilha* inserePilha(Produto* lista, Pilha* pilha);

/*
FUNÇÃO: Pilha* removePilha;
DESCRIÇÃO: Remove o nó contido no topo da pilha
PARÂMETROS: Pilha* pilha = pilha onde será removido o topo   
RETORNO: Retorna a pilha modificada;
*/
Pilha* removePilha(Pilha* pilha);

/*
FUNÇÃO: void limpaRedo;
DESCRIÇÃO: limpa a pilha de redo após uma alteração na lista, passando seus nós para uma pilha auxiliar
PARÂMETROS: Pilha* pilhaaux = pilha auxiliar que guardará os nós que foram removidos da pilha redo.
            Pilha **redo = pilha referente ao redo
RETORNO: Sem retorno.
*/
void limpaRedo(Pilha **pilhaaux, Pilha **redo);


/*
FUNÇÃO: Produto* undo;
DESCRIÇÃO: realiza a operação de undo.
PARÂMETROS: Produto* list = lista atual
            Pilha **undo = pilha referente ao undo
            Pilha **redo = pilha referente ao redo
RETORNO: Retorna a nova lista.
*/
Produto* undo(Produto* list, Pilha** undo, Pilha** redo);

/*
FUNÇÃO: Produto* redo;
DESCRIÇÃO: realiza a operação de redo.
PARÂMETROS: Produto* list = lista atual
            Pilha **undo = pilha referente ao undo
            Pilha **redo = pilha referente ao redo
RETORNO: Retorna a nova lista.
*/
Produto* redo(Produto* list, Pilha** undo, Pilha** redo);

/*
FUNÇÃO: Produto* Insere;
DESCRIÇÃO: Realiza a inserção ordenada na lista de forma ordenada, e também faz o compartilhamento de ponteiros.
PARÂMETROS: Produto* list = lista atual
            void* dado = nó que sera inserido na lista 
            void(*print)(void *dado) = função print referente á estrutura do nó
            int(*compara)(void* dado, void* chave) = função compara referente á estrutura do nó
            void(*desaloca)(void* dado) = função desaloca referente á estrutura do nó
            Pilha **undo = pilha referente ao undo
            Pilha **redo = pilha referente ao redo
            Pilha* pilhaaux = pilha auxiliar que guardará os nós que foram removidos da pilha redo.
            void *chave = chave que foi inserida na lista, necessária para a ordenação
RETORNO: Retorna a nova lista.
*/
Produto* Insere(Produto *list, void *dado, void(*print)(void *dado), int(*compara)(void* dado, void* chave),void(*desaloca)(void* dado), Pilha** undo, Pilha **redo, Pilha **auxpilha, void* chave);


/*
FUNÇÃO: Produto* pop;
DESCRIÇÃO: Realiza a exclusao da lista atual, e também faz o compartilhamento de ponteiros.
PARÂMETROS: Produto* list = lista atual
            void *chave = chave para ser excluida
            Pilha **undo = pilha referente ao undo
            Pilha **redo = pilha referente ao redo
            Pilha* pilhaaux = pilha auxiliar que guardará os nós que foram removidos da pilha redo.
RETORNO: Retorna a nova lista.
*/
Produto* pop(Produto *list, void* chave, Pilha** undo, Pilha** redo, Pilha **auxpilha);

/*
FUNÇÃO: Produto* busca;
DESCRIÇÃO: Realiza a busca de uma chave na lista
PARÂMETROS: Produto* list = lista atual
            void *chave = chave para ser buscada
RETORNO: Retorna o nó que corresponde a busca
*/
Produto* busca(Produto *list, void* chave);

/*
FUNÇÃO: void print_list
DESCRIÇÃO: Percorre a lista e imprime a lista chamando a função print da estrutura em questão
PARÂMETROS: Produto* list = lista atual
RETORNO: Sem retorno
*/
void print_list(Produto *list);

/*
FUNÇÃO: void freeLista
DESCRIÇÃO: Desaloca lista
PARÂMETROS: Produto* list = lista a ser desalocada
RETORNO: Sem retorno
*/
void freeLista(Produto* list);

/*
FUNÇÃO: void freePilha
DESCRIÇÃO: Desaloca pilha
PARÂMETROS: Pilha** pilha = pilha a ser desalocada
RETORNO: Sem retorno
*/
void freePilha(Pilha** pilha);

#endif 
