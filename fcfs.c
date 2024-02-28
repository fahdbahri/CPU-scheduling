
//fcfs

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


double fcfs_method(List* L)
{  
    printf("Scheduling Method: First Come First Served\n");
    printf("Process Waiting Times:\n");

    if (L == NULL) return -1;
    if (L->size == 0) return 0.;  // easy
    double avgWait_Time = 0.;
    int totalWait_time = 0;
    int current_time = 0;
    Node*  p   = L->head;
    for (size_t i = 0; i < L->size; i += 1)
    {  // here we have node data, one
        // at a time
        p->info->start_time = current_time;
        p->info->complete_time = p->info->start_time + p->info->burst;
        p->info->turn_around = p->info->complete_time - p->info->arrival;
        p->info->wait_time = p->info->turn_around - p->info->burst;


        totalWait_time += p->info->wait_time;
        current_time = p->info->complete_time;
       printf("P%ld: %d ms\n", i + 1, p->info->wait_time);
        p = p->next;
    }

   

    avgWait_Time = (double)totalWait_time / size(L);
    return avgWait_Time;

}