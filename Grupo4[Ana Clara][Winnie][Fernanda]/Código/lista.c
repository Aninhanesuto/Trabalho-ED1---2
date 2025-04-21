#include "lista.h"

/*INICIALIZAÇÕES*/
Pilha* inicializaNoPilha(Produto *lista){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->next=pilha;
    pilha->P = lista;
    return pilha;
}

Pilha* inicializaPilha(){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->next= pilha;
    pilha->P = NULL;
    return pilha;
}

/*OPERAÇÕES COM PILHAS.*/

//NA FUNÇÃO INSEREPILHA, ESTAMOS TRABALHANDO COM UMA LISTA CIRCULAR SIMPLES ENCADEADA, PARA AUXILIAR NA MANIPULAÇÃO
Pilha* inserePilha(Produto* lista, Pilha* pilha){
    Pilha* newpilha=inicializaNoPilha(lista);
    if(pilha == NULL){
        pilha=newpilha;
        pilha->next=newpilha;
    }
    else{
        newpilha->next = pilha->next;
        pilha->next = newpilha;
        pilha=newpilha;
    }
    
    return pilha;
}

Pilha* removePilha(Pilha* pilha){
    Pilha* auxpilha = pilha->next;
    
    if (pilha == NULL) return NULL;
    if(auxpilha==pilha){
        free(auxpilha);
        return NULL;
    }
    Pilha* predpilha = auxpilha;
    while(predpilha->next!=pilha) predpilha = predpilha->next;
    predpilha->next=auxpilha;
    free(pilha);
    
    return predpilha;
}

/*OPERAÇÕES COM UNDO E REDO*/

void limpaRedo(Pilha **pilhaaux, Pilha **redo){
    if((*redo)==NULL) return;
    if((*pilhaaux) == NULL){
        *pilhaaux = (*redo);
        *redo = NULL;
    }
    else{
        Pilha* Predo = (*redo)->next;
        Pilha* Paux = (*pilhaaux)->next; 
        (*redo)->next = Paux;
        (*pilhaaux)->next = Predo;
        *redo=NULL;
    }
    
}

//AO FAZER UNDO, PEGAMOS O ULTIMO ELEMENTO DA PILHA DE UNDO E INSERIMOS EM REDO, LOGO APÓS APAGAMOS O TOPO DA PILHA DE UNDO;
Produto* undo(Produto* list, Pilha** undo, Pilha** redo){
    if (*undo == NULL) return list; 
    Produto* new = (*undo)->P;
    *redo = inserePilha(list, (*redo));
    *undo = removePilha(*undo);
    return new;
}

//AO FAZER REDO, É INSERIDO NA PILHA DE UNDO A ULTIMA VERSÃO DA LISTA, E É REMOVIDO DE REDO O SEU TOPO.
Produto* redo(Produto* list, Pilha** undo, Pilha** redo){
    if (*redo == NULL) return list; 
    Produto* new = (*redo)->P;
    *undo = inserePilha(list, *undo);
    *redo = removePilha(*redo);
    return new;
} 

/*OPERAÇÕES COM AS LISTAS - INSERÇÃO, EXCLUSÃO, BUSCA E IMPRIME */

Produto* Insere(Produto *list, void *dado, void(*print)(void *dado), int(*compara)(void* dado, void* chave),void(*desaloca)(void* dado), Pilha** undo, Pilha **redo, Pilha **auxpilha, void* chave){
    Produto *node = alocaProduto(dado, print, compara, desaloca);
    Produto* old = list;
    Produto* new = NULL; 
    Produto *aux = list;
    Produto *pred = NULL;
    Produto *new_aux = NULL;

    limpaRedo(auxpilha, redo);
    

    if(list == NULL){
        new = node; 
        *undo = inserePilha(NULL, (*undo));
        return new;
    }
    else{
        *undo = inserePilha(old, (*undo));
        while (aux) {
            Produto *copia = alocaProduto(aux->dado, aux->print, aux->compara, aux->desaloca);

            if (new == NULL) {
                new = copia; 
                new_aux = new;
            } else {
                new_aux->next = copia; 
                new_aux = new_aux->next;
            } 
            if (aux->compara(aux->dado, chave) < 0) {
                pred = copia; 
            } else {
                break; 
            }
    
            aux = aux->next; 
        }
        if (pred == NULL) {
            
            node->next = new;
            new = node; 
        } else {
           
            node->next = pred->next;
            pred->next = node;
        }
        
        return new;
      
    }
}

Produto* pop(Produto *list, void* chave, Pilha** undo, Pilha** redo, Pilha **auxpilha){
    Produto *auxnode = NULL;
    Produto *prednode = NULL;
    Produto* old = list;
    Produto* new = NULL;
    Produto* auxnew = NULL;
    auxnode = list;
  
    Produto* node = NULL;

    limpaRedo(auxpilha, redo);

    *undo = inserePilha(old, (*undo));
    if (list == NULL){
        return NULL;
    }
    else{
        while(auxnode!=NULL && (auxnode->compara(auxnode->dado, chave) != 0)){
            prednode = auxnode;
            if(prednode!=NULL){
                node = alocaProduto(auxnode->dado, auxnode->print, auxnode->compara, auxnode->desaloca);
                if(new ==NULL){
                    new = node;
                    auxnew=new;
                } 
                else{
                    while(auxnew->next!=NULL) auxnew=auxnew->next;
                    auxnew->next=node;
                } 
            }
            auxnode = auxnode->next;
        }
        if(prednode==NULL) new = auxnode->next;
        else{
            node->next=auxnode->next;
        }
    }
    return new;
}

Produto *busca(Produto *list, void* chave){
    Produto *auxnode = list;
    while(auxnode!=NULL){
        if(auxnode->compara(auxnode->dado, chave)==0){
            return auxnode;
          }
        auxnode = auxnode->next;
    }
    return auxnode;

}

void print_list(Produto *list){
    Produto *auxnode = list;
    if(list == NULL) {
        printf("LISTA VAZIA!\n");
        return;}
    printf("\n");
    while (auxnode){
        auxnode->print(auxnode->dado);
        printf("\n");
        auxnode = auxnode->next;
    }
}

/*FUNÇÕES PARA A DESALOCAÇÃO DAS LISTAS E PILHAS */
void freeLista(Produto* list){
    Produto *aux = list;

    if(list==NULL) return;

    while(list!=NULL){
        aux = list->next; 
        freeProduto(list);       
        list = aux; 
    }
 
}

void freePilha(Pilha** pilha) {
    if (*pilha == NULL) return;  

    Pilha* atual = *pilha;
    Pilha* prox;
    Pilha* primeiro = *pilha;  

    do {
        prox = atual->next;  
        freeLista(atual->P);  
        atual->P = NULL;  
        free(atual);         
        atual = prox;        
    } while (atual != primeiro);  

    *pilha=NULL;  
}
