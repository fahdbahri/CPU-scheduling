
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"

void sort_srtf(List* L){

     printf("Scheduling Method: Shortest job First Non Preemptive\n");
     printf("Process Waiting Times:\n");


        
  int totalWait_time;
  double avgWait_Time;
  int time = 0;
  int min = INT_MAX;
   Node* current;
   current=L->head;
  while(current != NULL)
    {
      current->info->remain_burst = current->info->burst;
      current = current->next;
    }
  while(time <= L->size)
  {
    Node* index = NULL;
   current = L->head;
    min =  INT_MAX;
    while(current != NULL)
    {
      if(current->info->arrival <= time && min > current->info->remain_burst)
      {
        min = current->info->remain_burst;
        index = current;
      }

    }
    current = current->next;

    if(index == NULL)
    {
      time++;
    } else
    {
      printf("P%d: %d ms\n",  index->info->pid + 1 , index->info->wait_time);
      time += 1;
      index->info->remain_burst -=1;
      index->info->wait_time = time - (index->info->arrival + index->info->burst);

      totalWait_time += index->info->wait_time;

    }
  }

       avgWait_Time = (double)totalWait_time / size(L);

      printf("Average waiting time is: %.2f\n", avgWait_Time); 


    
}

/*
void srtf_method(List* L)
{
    

      
        int current_time = 0;
        int count = 0;
       
        
        Node*p;
        p->info->iscompleted = false;
       


        while(count != L->size)
        {
          
          Node* index = NULL;
          int mini_value = INT_MAX;

          for(p = L->head; p->next!= NULL ;p = p->next )
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

                 
             


              totalWait_time +=  index->info->wait_time ;
              count++;
              p->info->iscompleted = true;
           
              
             }
          }
          p = p->next;
          
        }

        
     
        

}*/
