typedef struct Node
{
    void **data;
    struct Node *next;
}node;

typedef struct List
{
    node *first;
}list;

list *criar();
int inserir(list *l, void* data);
int remover(list *l, int k);
int removerPorX(list *l, void* data);
int apagar(list *l);
void mostrar(list *l);
int contador(list *l);
int compara_listas(list *l1, list *l2);
list *uniao(list *a, list *b);
list *interesecao(list *a, list *b);
list *diferenca(list *a, list *b);
list *complementar(list *a, list *b);
int pesquisar(list*, void*);
int cmp(void*, void*);
