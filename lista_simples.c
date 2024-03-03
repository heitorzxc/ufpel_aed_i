#include <stdio.h>
#include <stdlib.h>
#include "lista_simples.h"

// função para criar uma nova lista vazia
List *criarLista() {
    return NULL;
}

// função para destruir a lista e liberar memória
void destruirLista(List *lista) {
    List *atual = lista;
    List *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

// função para inserir um elemento no início da lista
List *inserirInicio(List *lista, int valor) {
    List *novo = (List *)malloc(sizeof(List));

    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }

    novo->info = valor;
    novo->prox = lista;

    return novo;
}

// função para remover um elemento da lista
List *removerElemento(List *lista, int valor) {
    List *anterior = NULL;
    List *atual = lista;

    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            // Remover o primeiro elemento
            lista = atual->prox;
        } else {
            // Remover elemento no meio ou final
            anterior->prox = atual->prox;
        }
        free(atual);
    }

    return lista;
}

// função para buscar um elemento na lista
List *buscarElemento(List *lista, int valor) {
    List *atual = lista;

    while (atual != NULL && atual->info != valor) {
        atual = atual->prox;
    }

    return atual;
}

// função para imprimir os elementos da lista
void imprimirLista(List *lista) {
    List *atual = lista;

    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }

    printf("\n");
}