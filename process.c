
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "process.h"


 static unsigned pid = 1;

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
    if (L == NULL) return -1;
    // new node here
    Node* nv = (Node*)malloc(sizeof(Node));
    // new data here: always copy
    nv->info      = (Info*)malloc(sizeof(Info));
    *(nv->info)   = *info;
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

/*int insert_n(Info* info, List* L)
{
    if (L == NULL) return -1; // Input validation
    
    // Allocate memory for the new node
    Node* nv = (Node*)malloc(sizeof(Node));
    if (nv == NULL) return -1; // Check for memory allocation failure
    
    // Allocate memory for the data and copy it
    nv->info = (Info*)malloc(sizeof(Info));
    if (nv->info == NULL)
    {
        free(nv); // Free the allocated node if data allocation fails
        return -1;
    }
    *(nv->info) = *info; // Copy the data
    
    // Assign the PID value
    nv->info->pid = L->size + 1; // Increment the PID based on the current size of the list
    
    // Adjust pointers for the new node
    nv->prev = NULL; // Since the new node will be the first node, its prev pointer should be NULL
    nv->next = L->head; // The new node's next pointer should point to the current head of the list
    
    // Update the list pointers
    if (L->size == 0) // If the list is empty
    {
        L->tail = nv; // The new node becomes both the head and the tail
    }
    else
    {
        L->head->prev = nv; // Update the prev pointer of the current head to point to the new node
    }
    L->head = nv; // Update the head pointer to point to the new node
    
    L->size++; // Increment the list size
    
    return (int)L->size; // Return the updated list size
}
*/

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

List* deserialize(const char* file)
{
    FILE* in = fopen(file,"r");
    if(in == NULL) return NULL;

    Info info = {0};
    List* new_l = create_l(); // here we create a new list;
    while(3 == fscanf(in,"%d:%d:%d", &info.burst, &info.arrival , &info.priority))
    {
       
        insert_n(&info, new_l); //inserting the date into the list
        info.pid++;            // incrementing pid for each process
        
    };

    fclose(in);
    return new_l; // return the list with the data into the file 
}

int serialize(List* L, const char* file)
{
    if (L == NULL) return -1;
    if (file == NULL)
    {
        printf("Missing file name\n");
        return -2;
    }
    if (L->size == 0)
    {
        printf("Dataset is empty\n");
        return -3;
    }
    FILE* out = fopen(file, "w");
    if (out == NULL) return -3;

    fprintf(
        stderr,
        "serialize(): writing %d elements into \"%s\"\n",
        size(L), file);
    Node* p = L->head;
    for (size_t i = 0; i < L->size; i += 1)
    {
        fprintf(
            out, "%d:%d:%d\n", p->info->burst,
            p->info->arrival, p->info->priority); // edit this section for the output
        p = p->next;
    }
    fprintf(out, "\n");
    fclose(out);
    fprintf(stderr, "\"%s\" closed\n", file);
    return 0;
}


int show_i(Info* info, const char* msg)
{
    if (info == NULL) return -1;
    if (msg != NULL) printf("%s", msg);
    printf(
        "#%4d: B:%4d A:%4d P:%4d\n", info->pid, info->burst,
        info->arrival, info->priority);
    return 0;
}



int show_l(List* L, const char* tit)
{
    if (L == NULL) return -1;
    if (tit != NULL) printf("%s", tit);
    if (L->size == 0)
        printf("  no elements\n");
    else
        printf("  %zd elements:\n", L->size);
    if (L->head != NULL)
        printf("  [First process: %d", L->head->info->pid);
    if (L->tail != NULL)
        printf("  Last process: %d]\n", L->tail->info->pid);

    Node* p = L->head;
    for (size_t i = 0; i < L->size; i += 1)
    {
        show_i(p->info, "\t");
        p = p->next;
    }
    printf("\n");
    return 0;
}



int size(List* L)
{
    if (L == NULL) return 0;
    return (int)L->size;
}