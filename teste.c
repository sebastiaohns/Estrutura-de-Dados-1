#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tnode
{
    char data[2];
    struct Tnode* l;
    struct Tnode* r;
}tnode;

tnode* criar()
{
    return NULL;
}

void insert(tnode** t, char str[])
{
    if(*t == NULL)
    {
        *t = (tnode*)malloc(sizeof(tnode));
        (*t)->r = NULL;
        (*t)->l = NULL;
        strcpy((*t)->data, str);
    }
    else
    {
        if(strcasecmp((*t)->data,str)>0)
        {
            insert (&(*t)->r, str);
        }
        if(strcasecmp((*t)->data,str)<0)
        {
            insert (&(*t)->l, str);
        }
    }
}

char* abPreOrdem(tnode *t)
{
    static char str[5];
    if(t != NULL)
    {
        strcat(str, t->data);
        abPreOrdem(t->l);
        abPreOrdem(t->r);
        fflush(stdin);
    }
    return str;
}


void main(void)
{
    int i, h, x=1, v[]={ 8, 3, 1, 6, 4, 7, 10, 14, 13};
    char str[2], str2[5];

    tnode *t;

    t = criar();
    strcpy(str, "a");
    insert(&t, str);
    strcpy(str, "b");
    insert(&t, str);
    strcpy(str, "c");
    insert(&t, str);

    strcpy(str2, abPreOrdem(t));

    printf("%s", str2);

    abPreOrdem(t);
}

