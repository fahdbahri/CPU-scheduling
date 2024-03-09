
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"

void sort_srtf(List* L){

     Node* current = NULL;
     Node* index = NULL;
     Info* temp = NULL;

    if (L->head == NULL) {
        return;
    } else
    {
      for(current = L->head; current->next != NULL; current = current->next)
      {
        current->info->burst = current->info->remain_burst;
        if(current->info->arrival == 0) continue; // Skip the first node, which is Ar
        for(index = current->next; index->next != NULL; index = index->next)
        {
          if(current->info->burst > index->info->burst)
          {
            temp = current->info;
            current->info = index->info;
            index->info = temp;

          }
        }
      }
    }


    
}


void srtf_method(List* L)
{
     printf("Scheduling Method: Shortest job First Non Preemptive\n");
     printf("Process Waiting Times:\n");
        

      
        int current_time = 0;
        int count = 0;
        int totalWait_time;
        double avgWait_Time;
        sort_srtf(L);
        Node* p = L->head;
       


        while(count != L->size)
        {
          
          Node* index = NULL;
          int mini_value = INT_MAX;

          for(size_t i = 0; i < L->size; i++)
          {
            if(p->info->arrival <= current_time && p->info->iscompleted == false)
            {
              if(p->info->remain_burst < mini_value)
              {
                mini_value = p->info->remain_burst;
                index = p;
              }
              if(p->info->remain_burst == mini_value)
              {
                if(p->info->arrival < index->info->arrival)
                {
                  mini_value = p->info->remain_burst;
                  index = p;
                }
              }
            }
          }

          if(index == NULL)
          {

            current_time++;

          }else 
          {
            if(index->info->remain_burst == index->info->burst)
            {
              index->info->start_time = current_time;
            }

             index->info->remain_burst--;
             current_time++;

             if(index->info->burst == 0)
             {
              index->info->start_time = current_time;
              index->info->turn_around = index->info->complete_time - index->info->arrival;
              index->info->wait_time = index->info->turn_around - index->info->burst;

                 
              printf("P%d: %d ms\n",  p->info->pid + 1 , p->info->wait_time);


              totalWait_time +=  index->info->wait_time ;
              count++;
              index->info->iscompleted = true;
              p = p->next;
              
             }
          }
          
        }

        
      avgWait_Time = (double)totalWait_time / size(L);

      printf("Average waiting time is: %.2f\n", avgWait_Time); 
        

}