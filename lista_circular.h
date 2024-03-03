// definição da estrutura da lista encadeada circular
typedef struct CList {
    int info;
    struct CList *prox;
} CList;

// protótipos das funções
CList *criarLista();
void destruirLista(CList *prim);
CList *inserirInicio(CList *prim, CList **ult, int valor);
CList *removerElemento(CList *prim, CList **ult, int valor);
CList *buscarElemento(CList *prim, int valor);
void imprimirLista(CList *prim);