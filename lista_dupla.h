// definição da estrutura da lista duplamente encadeada
typedef struct {
    int info;
    struct DList *prox;
    struct DList *ant;
} DList;

// protótipos das funções
DList *criarLista();
void destruirLista(DList *lista);
DList *inserirInicio(DList *lista, int valor);
DList *removerElemento(DList *lista, int valor);
DList *buscarElemento(DList *lista, int valor);
void imprimirLista(DList *lista);