
//fcfs

#include <stdio.h>
#include <stdlib.h>
#include "process.h"

/*void fcfs_method(List* L)
{  
    printf( "Scheduling Method: First Come First Served\n");
    printf("Process Waiting Times:\n");
    if(empty(L)) printf("list is empty");

    if (L == NULL && L->size == 0 ) return;
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
       printf("P%d: %d ms\n", p->info->pid + 1, p->info->wait_time);
        p = p->next;
    }

   

    avgWait_Time = (double)totalWait_time / size(L);

   printf("Average waiting time is: %.2f\n", avgWait_Time); 
   
   
}*/


void fcfs_method(List* L, FILE *output_file)
{  
    fprintf(output_file, "Scheduling Method: First Come First Served\n");
    fprintf(output_file, "Process Waiting Times:\n");

    if (L == NULL && L->size == 0 ) return;
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
       fprintf(output_file, "P%d: %d ms\n", p->info->pid + 1, p->info->wait_time);
        p = p->next;
    }

   

    avgWait_Time = (double)totalWait_time / size(L);

   fprintf(output_file, "Average waiting time is: %.2f\n", avgWait_Time); 

  

}