
#include <stdio.h>
#include <stdlib.h>
#include "list.c"



//deserialize  the data from file to linked list.

List* deserialize(const char* file)
{
    FILE* in = fopen(file,"r");
    if(in == NULL) return NULL;

    Info info = {0};
    List* new_l = create_l(); // here we create a new list;
    while(3 == fscanf(in,"%d:%d:%d", &info.burst, &info.arrival , &info.priority))
    {
       
        insert_n(&info, new_l); //inserting the date into the list
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


voi