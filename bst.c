#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// função para criar a árvore a partir da raiz
Nodo* criarArvore(int chave_raiz) {
    return criaNodo(chave_raiz); // retorna um novo nó com a chave da raiz
}

// função para destruir a árvore
void destruirArvore(Nodo* raiz) {
    if (raiz != NULL) {
        destruirArvore(raiz->sae); // destrói a sae
        destruirArvore(raiz->sad); // destrói a sad
        free(raiz); // libera o nó atual
    }
}

// função para criar um novo nó com a chave especificada
Nodo* criaNodo(int chave) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL) {
        novo->chave = chave;
        novo->sae = NULL;
        novo->sad = NULL;
    }
    return novo;
}

// função para inserir um novo nó com a chave especificada na árvore
Nodo* inserir(Nodo* raiz, int chave) {
    if (raiz == NULL)
        return criaNodo(chave);
    else if (chave < raiz->chave) // inserção na sae
        raiz->sae = inserir(raiz->sae, chave);
    else if (chave > raiz->chave) // inserção na sad
        raiz->sad = inserir(raiz->sad, chave);
    return raiz;
}

// função para remover um nó com a chave especificada da árvore
Nodo* remover(Nodo* raiz, int chave) {
    // caso base: se a árvore está vazia, retorna NULL
    if (raiz == NULL) {
        return NULL;
    }

    // procura o nó a ser removido na árvore
    if (chave < raiz->chave) {
        raiz->sae = remover(raiz->sae, chave);
    } else if (chave > raiz->chave) {
        raiz->sad = remover(raiz->sad, chave);
    } else {
        // caso 1: nó não existe na árvore, não é necessário fazer nada
        if (raiz->sae == NULL && raiz->sad == NULL) {
            free(raiz);
            return NULL;
        }
        // caso 2: nó é uma folha / caso 3: nó possui apenas uma subárvore
        else if (raiz->sae == NULL) {
            Nodo* temp = raiz->sad;
            free(raiz);
            return temp;
        } else if (raiz->sad == NULL) {
            Nodo* temp = raiz->sae;
            free(raiz);
            return temp;
        }
        // caso 4: nó possui duas subárvores
        Nodo* temp = menorValor(raiz->sad);
        raiz->chave = temp->chave;
        raiz->sad = remover(raiz->sad, temp->chave);
    }
    return raiz;
}

// função para encontrar o menor valor em uma subárvore
Nodo* menorValor(Nodo* raiz) {
    Nodo* atual = raiz; // inicializa o nó atual com a raiz fornecida
    // enquanto houver um filho à esquerda, percorre para a esquerda
    while (atual->sae != NULL) {
        atual = atual->sae;
    }
    return atual;
}

// função para buscar um nó com a chave especificada na árvore
Nodo* buscar(Nodo* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave)
        return raiz; // nó encontrado ou árvore vazia
    else if (chave < raiz->chave) // procura na sae
        return buscar(raiz->sae, chave);
    else if (chave > raiz->chave) // procura na sad
        return buscar(raiz->sad, chave);

}

// função para percorrer a árvore em pré-ordem
void preOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->sae);
        preOrdem(raiz->sad);
    }
}

// função para percorrer a árvore em ordem
void emOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->sae);
        printf("%d ", raiz->chave);
        emOrdem(raiz->sad);
    }
}

// função para percorrer a árvore em pós-ordem
void posOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->sae);
        posOrdem(raiz->sad);
        printf("%d ", raiz->chave);
    }
}