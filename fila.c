#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct Fila{
    No *ini;
    No *fim;
}Fila;

void inicializa(Fila *f){
    f->ini = NULL;
    f->fim = NULL;
}

void adiciona(int dado, Fila *f){
    No *ptr = (No*) malloc(sizeof(No));
    if(ptr==NULL){
        printf("Erro de alocação");
        return;
    }
    else{
        ptr->dado = dado;
        ptr->prox = NULL;
        if(f->ini == NULL){
            f->ini=ptr;
        } else{
            f->fim->prox = ptr;
        }

        f->fim = ptr;
    }
    free(ptr);
    free(f);
};


void exclui(Fila *f){
    No *ptr = f->ini;
    int dado;
    if (ptr != NULL){
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if(f->ini == NULL){
            f->fim = NULL;
        }
        return dado;
    } else {
        printf("Fila vazia");
        return;
    }
}


void imprime(Fila *f){
    No *ptr = f->ini;
    if (ptr != NULL){
        while(ptr != NULL){
            printf("%d", ptr->dado);
            ptr = ptr->prox;
        }
    }
    else{
        printf("Fila vazia");
        return;
    }
}


int main(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL){
        printf("Erro de alocaçao");
        exit(-1);
    } else {
        inicializa(fila);
        adiciona(1, fila);
        adiciona(2, fila);
        adiciona(3, fila);
        imprime(fila);

        exclui(fila);
        imprime(fila);
    }
}
