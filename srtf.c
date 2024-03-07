
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"

void sort_srtf(List* L){
     

     Node* current;
     

}


void srtf_method(List* L)
{
     printf("Scheduling Method: Shortest job First Non Preemptive\n");
     printf("Process Waiting Times:\n");

    int* bt_remaining = (int*)malloc(L->size * sizeof(int));
    if (bt_remaining == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    } 
    bool* is_completed = (bool*)malloc(L->size * sizeof(bool));
    if (is_completed == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
bool is_firstProcess = true;
   double avgWait_Time = 0.;
    int totalWait_time = 0;
    int current_time = 0, completed = 0; 
    Node*  p   = L->head;
    for(size_t i = 0; i < L->size; i++){bt_remaining[i] = p->info->burst;}
       
       while(completed != L->size)
       {
         Node*  current;
         current->info = NULL;
         int mini_value = INT_MAX;
         for(size_t i = 0; i < L->size; i++)
         {
            if(p->info->arrival <= current_time && is_completed[i] == false)
            {
                if(bt_remaining[i] < mini_value)
                {
                    mini_value = bt_remaining[i];
                    current->info = i;
                }

                if(bt_remaining[i] == mini_value)
                {
                    if(p->info->arrival < current->info->arrival)
                    {
                        mini_value = p->info->burst;
                        current->info = i;

                    }
                }
            }
         }
         if(current->info == NULL)
         {
            current_time++;
         } 
         else{
            if(bt_remaining[current->info] == current->info->burst)
            {
                current->info->start_time = current_time;
                is_firstProcess = false;

            }
            bt_remaining[current->info] -= 1;
            current_time++;
            if(bt_remaining[current->info] == 0)
            {
                current->info->complete_time = current_time;
                current->info->turn_around = current->info->complete_time - current->info->arrival;
                current->info->wait_time = current->info->turn_around - current->info->burst;

                totalWait_time +=  current->info->wait_time ;
                completed++;
                is_completed[current->info] = true;
            }
         }

       }
      



     /*
       for (size_t i = 0; i < L->size; i += 1)
    {  // here we have node data, one
        // at a time

        p->info->start_time = current_time;
        p->info->complete_time = p->info->start_time + p->info->burst;
        p->info->turn_around = p->info->complete_time - p->info->arrival;
        p->info->wait_time = p->info->turn_around - p->info->burst;


        totalWait_time += p->info->wait_time;
        current_time = p->info->complete_time;
        printf("P%d: %d ms\n",  p->info->pid + 1 , p->info->wait_time);
        p = p->next;
    }

   

    avgWait_Time = (double)totalWait_time / size(L);

   printf("Average waiting time is: %.2f\n", avgWait_Time); */
   
}