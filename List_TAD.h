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
int inserir(list*, void*);
int remover(list*, int);
int apagar(list*);
void mostrar(list*);
int contador(list*);
int compara_listas(list*, list*);
int pesquisar(list*, void*);
int vazio(list*);
