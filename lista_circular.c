#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

CList *criarLista() {
    return NULL;
}

void destruirLista(CList *prim) {
    if (prim == NULL) {
        return; // Lista vazia, nada a destruir
    }

    CList *atual = prim->prox;
    while (atual != prim) {
        CList *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(prim);
}

CList *inserirInicio(CList *prim, CList **ult, int valor) {
    CList *novo = (CList *)malloc(sizeof(CList));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;

    if (prim == NULL) {
        novo->prox = novo; // Lista estava vazia, faz apontar para si mesma
        *ult = novo; // atualiza ponteiro ult
        return novo; // retorna ponteiro prim atualizado
    } else {
        novo->prox = prim;
        (*ult)->prox = novo; // atualiza ponteiro prox do ult
        return novo; // retorna ponteiro prim atualizado
    }
}

CList *removerElemento(CList *prim, CList **ult, int valor) {
    if (prim == NULL) {
        return NULL; // Lista vazia, nada a remover
    }

    CList *anterior = *ult;
    CList *atual = prim;

    do {
        if (atual->info == valor) {
            if (atual == prim) {
                if (prim->prox == prim) {
                    free(prim);
                    return NULL; // Único elemento na lista
                } else {
                    prim = atual->prox;
                }
            }

            anterior->prox = atual->prox;
            free(atual);
            return prim;
        }

        anterior = atual;
        atual = atual->prox;
    } while (atual != prim); // Percorre a lista circular

    return prim; // Elemento não encontrado, retorna a lista sem modificação
}

CList *buscarElemento(CList *prim, int valor) {
    if (prim == NULL) {
        return NULL; // Lista vazia, nada a buscar
    }

    CList *atual = prim;

    do {
        if (atual->info == valor) {
            return atual; // Elemento encontrado
        }

        atual = atual->prox;
    } while (atual != prim); // Percorre a lista circular

    return NULL; // Elemento não encontrado
}

void imprimirLista(CList *prim) {
    if (prim == NULL) {
        printf("Lista circular vazia\n");
        return;
    }

    CList *atual = prim;

    do {
        printf("%d ", atual->info);
        atual = atual->prox;
    } while (atual != prim); // Percorre a lista circular

    printf("\n");
}