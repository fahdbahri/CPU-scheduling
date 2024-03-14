#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"


void priority_method(List* L)
{

    printf("Scheduling Method: Priority Non Preemptive\n");
    printf("Process Waiting Times:\n");


    int current_time  = 0; // Current time of the CPU
    int min_priority = INT_MAX;
    int total_burst = 0;
    int totalWait_time = 0;
    double avgWait_Time = 0.;

    Node* current = L->head;
    Node* index;
     
     while (current != NULL)
     {
        total_burst += current->info->burst;
        current->info->execute_time = 0;
        current = current->next;
     }

     while(current_time <= total_burst)
     {
        index = NULL;
        current = L->head;
        min_priority = INT_MAX;
        while(current != NULL)
        {
            if(current->info->execute_time == 0)
            {
                if(min_priority > current->info->priority && current_time >= current->info->arrival)
                {
                    min_priority = current->info->priority;
                    index = current;
                }


            }
            current = current->next;
        }

        if(index == NULL)
        {
            current_time++;
        }
        else{
            index->info->execute_time += 1;
            current_time += index->info->burst;
            index->info->wait_time = current_time - (index->info->arrival + index->info->burst);
        }
     }
      current = L->head;

    while(current != NULL)
    {
       printf("P%d: %d ms\n",  current->info->pid + 1 , current->info->wait_time);

         totalWait_time += current->info->wait_time;
         current = current->next;

    }

      avgWait_Time = (double)totalWait_time / L->size;
      printf("Average waiting time is: %.2f\n", avgWait_Time); 


}

