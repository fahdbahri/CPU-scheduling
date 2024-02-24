
#include <string.h>
#include "process.h"

List* destroy_l(List* L)
{
    if (L == NULL) return NULL;
    Node* p = L->head;
    for (size_t i = 0; i < L->size; i += 1)
    {  // remove one by one
        Node* nx = p->next;
        free(p->info);  // free data
        free(p);        // free node
        p = nx;
    };            // for
    free(L);      // free list
    return NULL;  // to invalidate pointer
}

int empty(List* L)
{
    if (L == NULL) return 0;
    return (L->size == 0);
}

List* create_l()
{
    List* nv = (List*)malloc(sizeof(List));
    if (nv == NULL) return NULL;
    nv->size = 0;  // vazia
    nv->head = NULL;
    nv->tail = NULL;
    return nv;
}

int insert_n(Info* info, List* L)
{  // inserts at the end of list
    static unsigned seq = 1000;
    if (L == NULL) return -1;
    // new node here
    Node* nv = (Node*)malloc(sizeof(Node));
    // new data here: always copy
    nv->info      = (Info*)malloc(sizeof(Info));
    *(nv->info)   = *info;
    nv->info->seq = seq++;  // USN
    nv->prev      = L->tail;
    nv->next      = NULL;
    // ajusta os ponteiros da lista
    L->size += 1;  // conta o novo
    if (L->size == 1)
        L->head = nv;
    else { L->tail->next = nv; }
    L->tail = nv;
    return (int)L->size;
}

int remove_n(List* L)
{  // remove from start
    if (L == NULL) return -1;
    if (L->size == 0) return -2;
    Node* p = L->head->next;
    free(L->head->info);  // data
    free(L->head);        // node
    L->head = p;
    L->size -= 1;
    if (L->size == 0) L->tail = NULL;
    return (int)L->size;
}
/*
int show_l(List* L, const char* tit)
{
    if (L == NULL) return -1;
    if (tit != NULL) printf("%s", tit);
    if (L->size == 0)
        printf("  no elements\n");
    else
        printf("  %zd elements:\n", L->size);
    if (L->head != NULL)
        printf("  [First seq: %d", L->head->info->seq);
    if (L->tail != NULL)
        printf("  Last seq: %d]\n", L->tail->info->seq);

    Node* p = L->head;
    for (size_t i = 0; i < L->size; i += 1)
    {
        show_i(p->info, "\t");
        p = p->next;
    }
    printf("\n");
    return 0;
}*/

int size(List* L)
{
    if (L == NULL) return 0;
    return (int)L->size;
}