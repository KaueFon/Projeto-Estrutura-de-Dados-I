# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "listaContatos.h"

int main(){

    Listacont *li = NULL;
   
   if((li = criaLista()) == NULL){
        abortaPrograma();
   }



    x = tamanhoLista(li);
    printf("O tamanho da lista é: %d", x);

   if(listaVazia(li)){
    printf("\nLista esta vazia");
   } else {
    printf("\nLista nao esta vazia");
   }

   x = insereOrdenado(li, al13);
   if(x){
    printf("\nliente %d inserido ordenadamenre com sucesso");
   } else{
    printf("\nNao foi possivel inserir de forma ordenada");
   }

   x = removeOrdenado(Lista *li, int mat);
   if(x){
    printf("\ncliente removido com sucesso", x);
   } else{
    printf("\nnao foi possivel remover o cliente");
   }


    apagaLista(li);
}