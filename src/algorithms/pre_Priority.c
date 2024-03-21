#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../process/process.h"



void pre_Priority(List* L, FILE* output_file)
{
    fprintf(output_file, "Scheduling Method: Priority Preemptive\n");
    fprintf(output_file, "Process Waiting Times:\n");

    int current_time = 0;
    int min_value = INT_MAX;
    int total_burst = 0;
    int total_waitTime = 0;
    double avg_waitTime  = 0.;
    Node* current = L->head;
    Node* index;
    while(current != NULL)
    {
        current->info->remain_burst = current->info->burst;
        total_burst += current->info->burst;
        current = current->next;
    }
     while(current_time <= total_burst)
     {
        index = NULL;
        current = L->head;
        min_value = INT_MAX;
        while(current != NULL)
        {
            if(current->info->remain_burst != 0)
            {
                if(current_time >= current->info->arrival && min_value > current->info->priority)
                {
                    min_value = current->info->priority;
                    index = current;
                }
            }
            current = current->next;
        }

        if(index == NULL)
        {
            current_time++; //the idle 
        } else 
        {
            current_time += 1;
            index->info->remain_burst -= 1;
            index->info->wait_time = current_time - (index->info->arrival + index->info->burst);
        }

     }

     current = L->head;
     while(current != NULL)
    {
       fprintf(output_file, "P%d: %d ms\n",  current->info->pid + 1 , current->info->wait_time);

         total_waitTime += current->info->wait_time;
         current = current->next;

    }

      avg_waitTime = (double)total_waitTime / L->size;
      fprintf(output_file, "Average waiting time is: %.2f\n", avg_waitTime); 


}