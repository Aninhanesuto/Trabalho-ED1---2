#include <stdio.h>
#include <stdlib.h>

#include "chocolate.h"
#include "vinho.h"
#include "livro.h"
#include "filme.h"
#include "produto.h"
#include "lista.h"

int PrintMenuPrin(int *ts){
  printf("           BEM VINDO A GIRLS STORE!\n");
  printf("+=================PRODUTOS==================+\n");
  printf("| [1] Chocolates                            |\n");
  printf("| [2] Vinhos                                |\n");
  printf("| [3] Livros                                |\n");
  printf("| [4] Filmes                                |\n");
  printf("| [5] Sair                                  |\n");
  printf("+===========================================+\n");
  
  int op = 0;
  
  printf("Digite uma opção: ");
  *ts = scanf("%d", &op);
  return op;
}

void mudarCorTexto() {
    #ifdef _WIN32
        system("color C"); // Vermelho claro no Windows
    #else
        printf("\033[1;31m"); // Vermelho claro no Linux/macOS (ANSI escape)
    #endif
}
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void ImprimeRelatorio(Produto *choco, Produto *vinho, Produto *livro, Produto* filme){
  printf("+=================RELATÓRIO==================+\n");
  printf("-------------Estoque de Chocolate------------\n");
  print_list(choco);
  //chamada da função de deslocamento de memória
  printf("-------------Estoque de Vinho----------------\n");
  print_list(vinho);
  //chamada da função de deslocamento de memória
  printf("-------------Estoque de Livro----------------\n");
  print_list(livro);
  //chamada da função de deslocamento de memória
  printf("-------------Estoque de Filme----------------\n");
  print_list(filme);
  //chamada da função de deslocamento de memória
  printf("+===========================================+\n");
  printf("Obrigado pela preferencia! Nos vemos na próxima ");

}

void ImprimeMenuChoco(){
  printf("+================CHOCOLATE==================+\n");
  printf("| [1] Inserir                               |\n");
  printf("| [2] Excluir                               |\n");
  printf("| [3] Buscar                                |\n");
  printf("| [4] Imprimir                              |\n");
  printf("| [5] Undo                                  |\n");
  printf("| [6] Redo                                  |\n");
  printf("| [7] Sair                                  |\n");
  printf("+===========================================+\n");
}


void ImprimeMenuFilme(){
  printf("+================FILME====================+\n");
  printf("| [1] Inserir                               |\n");
  printf("| [2] Excluir                               |\n");
  printf("| [3] Buscar                                |\n");
  printf("| [4] Imprimir                              |\n");
  printf("| [5] Undo                                  |\n");
  printf("| [6] Redo                                  |\n");
  printf("| [7] Sair                                  |\n");
  printf("+===========================================+\n");
}


void ImprimeMenuLivro(){
  printf("+================LIVRO====================+\n");
  printf("| [1] Inserir                               |\n");
  printf("| [2] Excluir                               |\n");
  printf("| [3] Buscar                                |\n");
  printf("| [4] Imprimir                              |\n");
  printf("| [5] Undo                                  |\n");
  printf("| [6] Redo                                  |\n");
  printf("| [7] Sair                                  |\n");
  printf("+===========================================+\n");
}


void ImprimeMenuVinho(){
  printf("+================VINHO======================+\n");
  printf("| [1] Inserir                               |\n");
  printf("| [2] Excluir                               |\n");
  printf("| [3] Buscar                                |\n");
  printf("| [4] Imprimir                              |\n");
  printf("| [5] Undo                                  |\n");
  printf("| [6] Redo                                  |\n");
  printf("| [7] Sair                                  |\n");
  printf("+===========================================+\n");
}

int main(){

    Produto* chocolate = NULL;
  Pilha* chocoUndo = inicializaPilha();
  Pilha* chocoRedo = inicializaPilha();
  Pilha* auxpilhaC = inicializaPilha();
    
  Produto* vinho = NULL;
  Pilha* vinhoUndo = inicializaPilha();
  Pilha* vinhoRedo = inicializaPilha();
  Pilha* auxpilhaV = inicializaPilha();

  Produto* livro = NULL;
  Pilha* livroUndo = inicializaPilha();
  Pilha* livroRedo = inicializaPilha();
  Pilha* auxpilhaL = inicializaPilha();

  Produto* filme = NULL;
  Pilha* filmeUndo = inicializaPilha();
  Pilha* filmeRedo = inicializaPilha();
  Pilha* auxpilhaF = inicializaPilha();
  
  Produto *b = NULL;
  int op1 = 0;
  int op2;
  int ts = 0;
  char chave[50];
  

  do{

   mudarCorTexto();
      op1 = PrintMenuPrin(&ts);
      if (ts != 1) {  // Verifica se a entrada não é um número
           limparTela();
            printf("Entrada inválida! Digite um número válido.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;  // Volta para o início do loop sem executar o switch
              }
            limparTela();
    
      switch (op1) {
      case 1:
          do {
              ImprimeMenuChoco();
              printf("Digite uma opção: ");
              
              if (scanf("%d", &op2) != 1) {  // Verifica se a entrada não é um número
                  printf("Entrada inválida! Digite um número válido.\n");
                  while (getchar() != '\n'); // Limpa o buffer de entrada
                  continue;  // Volta para o início do loop sem executar o switch
              }

              limparTela();

              switch (op2) {
              case 1:
                  chocoNode* novo = leChoco();
                  chocolate = Insere(chocolate, novo, imprimeChoco, comparaChoco, freeChoco, &chocoUndo, &chocoRedo, &auxpilhaC, novo->nome);
                  limparTela();
                  printf("Chave inserida com sucesso!\n");
                  break;

              case 2:
                  getchar();
                  printf("\nInsira uma chave para ser excluída: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(chocolate, chave);
                  if (b!=NULL && b->compara(b->dado, chave)==0) {
                      printf("Produto excluído com sucesso.\n");
                      chocolate = pop(chocolate, chave, &chocoUndo, &chocoRedo, &auxpilhaC);
                  } else {
                      printf("Erro ao excluir. Produto não encontrado ou lista vazia.\n");
                  }
                  break;

              case 3:
                  getchar();
                  printf("\nInsira uma chave para ser buscada: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(chocolate, chave);
                  if(b!=NULL){
                    if(b->compara(b->dado, chave)==0) printf("PRODUTO %s ENCONTRADO!\n", chave);
                    else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  }
                  else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  break;

              case 4:
                  print_list(chocolate);
                  break;

              case 5:
                  if(chocoUndo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else chocolate = undo(chocolate, &chocoUndo, &chocoRedo);
                  break;

              case 6:
                  if(chocoRedo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else chocolate = redo(chocolate, &chocoUndo, &chocoRedo); 

                  break;

              case 7:
                  break;
              
              default:
                  printf("Digite uma opção valida\n");
                  break;
              }
          } while (op2 != 7);
          break;
      case 2:
            do{
              ImprimeMenuVinho();
              printf("Digite uma opção: ");
              
              if (scanf("%d", &op2) != 1) {  // Verifica se a entrada não é um número
                  printf("Entrada inválida! Digite um número válido.\n");
                  while (getchar() != '\n'); // Limpa o buffer de entrada
                  continue;  // Volta para o início do loop sem executar o switch
              }

              limparTela();

              switch (op2) {
              case 1:
                  VinhoNode* novo = leVinho();
                  vinho = Insere(vinho, novo, imprimeVinho, comparaVinho, freeVinho, &vinhoUndo, &vinhoRedo, &auxpilhaV, novo->nome);
                  limparTela();
                  printf("Chave inserida com sucesso!\n");
                  break;

              case 2:
                  getchar();
                  printf("\nInsira uma chave para ser excluída: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(vinho, chave);
                  if (b!=NULL && b->compara(b->dado, chave)==0) {
                      printf("Produto excluído com sucesso.\n");
                      vinho = pop(vinho, chave, &vinhoUndo, &vinhoRedo, &auxpilhaV);
                  } else {
                      printf("Erro ao excluir. Produto não encontrado ou lista vazia.\n");
                  }
                  break;

              case 3:
                  getchar();
                  printf("\nInsira uma chave para ser buscada: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(vinho, chave);
                  if(b!=NULL){
                    if(b->compara(b->dado, chave)==0) printf("PRODUTO %s ENCONTRADO!\n", chave);
                    else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  }
                  else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  break;

              case 4:
                  print_list(vinho);
                  break;

              case 5:
                  if(vinhoUndo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else vinho = undo(vinho, &vinhoUndo, &vinhoRedo);
                  break;

              case 6:
                  if(vinhoRedo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else vinho = redo(vinho, &vinhoUndo, &vinhoRedo); 

                  break;

              case 7:
                  break;
              
              default:
                  printf("Digite uma opção valida\n");
                  break;
              }
          } while (op2 != 7);
          break;

      case 3:
            do{
              ImprimeMenuLivro();
              printf("Digite uma opção: ");
              
              if (scanf("%d", &op2) != 1) {  // Verifica se a entrada não é um número
                  printf("Entrada inválida! Digite um número válido.\n");
                  while (getchar() != '\n'); // Limpa o buffer de entrada
                  continue;  // Volta para o início do loop sem executar o switch
              }

              limparTela();

              switch (op2) {
              case 1:
                  LivroNode* novo = leLivro();
                  livro = Insere(livro, novo, imprimeLivro, comparaLivro, freeLivro, &livroUndo, &livroRedo, &auxpilhaL, novo->titulo);
                  limparTela();
                  printf("Chave inserida com sucesso!\n");
                  break;

              case 2:
                  getchar();
                  printf("\nInsira uma chave para ser excluída: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(livro, chave);
                  if (b!=NULL && b->compara(b->dado, chave)==0) {
                      printf("Produto excluído com sucesso.\n");
                      livro = pop(livro, chave, &livroUndo, &livroRedo, &auxpilhaL);
                  } else {
                      printf("Erro ao excluir. Produto não encontrado ou lista vazia.\n");
                  }
                  break;

              case 3:
                  getchar();
                  printf("\nInsira uma chave para ser buscada: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(livro, chave);
                  if(b!=NULL){
                    if(b->compara(b->dado, chave)==0) printf("PRODUTO %s ENCONTRADO!\n", chave);
                    else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  }
                  else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  break;

              case 4:
                  print_list(livro);
                  break;

              case 5:
                  if(livroUndo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else livro = undo(livro, &livroUndo, &livroRedo);
                  break;

              case 6:
                  if(livroRedo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else livro = redo(livro, &livroUndo, &livroRedo); 

                  break;

              case 7:
                  break;
              
              default:
                  printf("Digite uma opção válida\n");
                  break;
              }
          } while (op2 != 7);
          break;

      case 4:
            do{
              ImprimeMenuFilme();
              printf("Digite uma opção: ");
              
              if (scanf("%d", &op2) != 1) {  // Verifica se a entrada não é um número
                  printf("Entrada inválida! Digite um número válido.\n");
                  while (getchar() != '\n'); // Limpa o buffer de entrada
                  continue;  // Volta para o início do loop sem executar o switch
              }

              limparTela();

              switch (op2) {
              case 1:
                  FilmeNode* novo = leFilme();
                  filme = Insere(filme, novo, imprimeFilme, comparaFilme, freeFilme, &filmeUndo, &filmeRedo, &auxpilhaF, novo->titulo);
                  limparTela();
                  printf("Chave inserida com sucesso!\n");
                  break;

              case 2:
                  getchar();
                  printf("\nInsira uma chave para ser excluída: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(filme, chave);
                  if (b!=NULL && b->compara(b->dado, chave)==0) {
                      printf("Produto excluído com sucesso.\n");
                      filme = pop(filme, chave, &filmeUndo, &filmeRedo, &auxpilhaF);
                  } else {
                      printf("Erro ao excluir. Produto não encontrado ou lista vazia.\n");
                  }
                  break;

              case 3:
                  getchar();
                  printf("\nInsira uma chave para ser buscada: ");
                  scanf("%[^\n]%*c", chave);
                  
                  b = busca(filme, chave);
                  if(b!=NULL){
                    if(b->compara(b->dado, chave)==0) printf("PRODUTO %s ENCONTRADO!\n", chave);
                    else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  }
                  else printf("PRODUTO %s NAO ENCONTRADO.\n", chave);
                  break;

              case 4:
                  print_list(filme);
                  break;

              case 5:
                  if(filmeUndo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else filme = undo(filme, &filmeUndo, &filmeRedo);
                  break;

              case 6:
                  if(filmeRedo==NULL) printf("Nenhuma operação para desfazer.\n");
                  else filme = redo(filme, &filmeUndo, &filmeRedo); 

                  break;

              case 7:
                  break;
              
              default:
                  printf("Digite uma opção valida\n");
                  break;
              }
          } while (op2 != 7);
          break;

      case 5:
          ImprimeRelatorio(chocolate, vinho, livro, filme);
          break;

      default:
          printf("Digite uma opção valida\n");
          break;
          
      }

  } while (op1 != 5);

  /*DESALOCAÇÕES LISTAS E PILHAS*/

    freeLista(chocolate);
    freePilha(&chocoUndo);
    freePilha(&chocoRedo);
    freePilha(&auxpilhaC);
    freeLista(vinho);
    freePilha(&vinhoUndo);
    freePilha(&vinhoRedo);
    freePilha(&auxpilhaV);
    freeLista(livro);
    freePilha(&livroUndo);
    freePilha(&livroRedo);
    freePilha(&auxpilhaL);
    freeLista(filme);
    freePilha(&filmeUndo);
    freePilha(&filmeRedo);
    freePilha(&auxpilhaF);



    return 0;
}