// estrutura de um nó (nodo) da árvore
typedef struct Nodo {
    int chave;
    struct Nodo* sae;
    struct Nodo* sad;
} Nodo;

// protótipos das funções
Nodo* criarArvore(int chave_raiz);
void destruirArvore(Nodo* raiz);
Nodo* criaNodo(int chave);
Nodo* inserir(Nodo* raiz, int chave);
Nodo* remover(Nodo* raiz, int chave);
Nodo* menorValor(Nodo* raiz);
Nodo* buscar(Nodo* raiz, int chave);
void preOrdem(Nodo* raiz);
void emOrdem(Nodo* raiz);
void posOrdem(Nodo* raiz);