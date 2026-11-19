# include <stdio.h>
# include <stdlib.h>
# include "listaContatos.h"

struct Listacont{
    CLIENTE dados;
    struct Listacont *prox
}

Typedef struct Listacont* LISTA;

Lista *criaLista(){
    LISTA *li = (LISTA*) malloc(sizeof(LISTA));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    printf("Erro de alocação de memória. ");
    printf("Programa sera encerrado...\n\n\n");
    system("pause");
    exit(1);
}

void apagaLista(Lista *li){
    if(li != NULL){
        CLIENTE *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanhoLista(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    CLIENTE *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaVazia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insereOrdenado(Lista *li, CLIENTE cli){ //parte importante, insersão ordenada vai ser cobrada
    if(li == NULL){
        abortaPrograma();
    }
    CLIENTE *no = (CLIENTE*) malloc(sizeof(CLIENTE));
    if(no == NULL){
        return 0;
    }
    no->dados = cli;
    if(listaVazia(li)){ // essa parte insere novos dados no início(importante)
        no->prox = *li;
        *li = no;
        return cli.ID;
    }else{
        CLIENTE *ant, *atual = *li;
        while(atual != NULL && atual->dados.ID < cli.ID){
            ant = atual;
            atual = atual->prox;
        }
        // esse é pra caso o novo nó seja inserido no início da lista
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{ // insere em whatever posição,não só no começo
            no->prox = ant->prox;
            ant->prox = no;
        }
        return cli.ID;
    }
}

int removeOrdenado(Lista *li, int id){
    if(li == NULL){
        abortaPrograma();
    }
    CLIENTE *ant, *atual = *li;
    while(atual != NULL && atual->dados.ID != id){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL){ // não encontrou o ID
        return 0;
    }
    if(atual == *li){ // remove do início
        *li = atual->prox;
    }else{ // remove de qualquer outra posição
        ant->prox = atual->prox;
    }
    free(atual);
    return 1;
}