#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

DList *criarLista() {
    return NULL;
}

void destruirLista(DList *lista) {
    DList *atual = lista;

    while (atual != NULL) {
        DList *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

DList *inserirInicio(DList *lista, int valor) {
    DList *novo = (DList *)malloc(sizeof(DList));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }

    novo->info = valor;
    novo->ant = NULL;
    novo->prox = lista;

    if (lista != NULL) {
        lista->ant = novo;
    }

    return novo;
}

DList *removerElemento(DList *lista, int valor) {
    DList *atual = lista;

    while (atual != NULL && atual->info != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        return lista; // Elemento não encontrado, retorna a lista sem modificação
    }

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        lista = atual->prox;
    }

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }

    free(atual);
    return lista;
}

DList *buscarElemento(DList *lista, int valor) {
    DList *atual = lista;

    while (atual != NULL && atual->info != valor) {
        atual = atual->prox;
    }

    return atual;
}

void imprimirLista(DList *lista) {
    DList *atual = lista;

    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }

    printf("\n");
}