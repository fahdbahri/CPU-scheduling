
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"

/*void sort_srtf(List* L){

     printf("Scheduling Method: Shortest job First Non Preemptive\n");
     printf("Process Waiting Times:\n");


        
  int totalWait_time;
  double avgWait_Time;
  int current_time = 0;
  int completed = 0;
  
  Node* current = L->head;
  while(current != NULL)
    {
      current->info->remain_burst = current->info->burst;
      current = current->next;
    }
  while(completed != L->size)
  {
    Node* index = NULL;
    int min =  INT_MAX;
    while(current != NULL)
    {
      if(current->info->remain_burst != 0)
      {
          if(current->info->arrival <= current_time && min > current->info->remain_burst)
        {
           min = current->info->remain_burst;
           index = current;
        }

      }
      
      current = current->next;

    }
    

    if(index == NULL)
    {
      current_time++;
    } else 
        {
          if(index->info->remain_burst == index->info->burst)
          {
            index->info->start_time = current_time;
          }
          index->info->remain_burst -= 1;
          current_time++;
          if(index->info->remain_burst == 0)
          {
            index->info->complete_time = current_time;
            index->info->turn_around = index->info->complete_time - index->info->arrival;
            index->info->wait_time = index->info->turn_around - index->info->arrival;
             printf("P%d: %d ms\n",  current->info->pid + 1 ,current->info->wait_time);

            totalWait_time += index->info->wait_time;
            completed++;
          }
        }
     }

    

       avgWait_Time = (double)totalWait_time / size(L);

      printf("Average waiting time is: %.2f\n", avgWait_Time); 


    
}
*/


void print_srtf(List* L)
{

}

void srtf_method(List* L)
{
     printf("Scheduling Method: Shortest job First Preemptive\n");
     printf("Process Waiting Times:\n");
    
int current_time = 0;
int total_Burst = 0;
int total_waitTime = 0;
double  avg_waitTime = 0;
Node* current = L->head;
Node* index;
Node* temp;
for(size_t i = 0; i < L->size; i++)
{
  current->info->remain_burst = current->info->burst;
  total_Burst += current->info->burst;
  current = current->next;
}
 int min = total_Burst;
     while(current_time <= total_Burst)
     {
       index = NULL;
       temp = L->head;
       min = total_Burst;
       while(temp != NULL)
       {
        if(temp->info->remain_burst != 0)
        {
            if(current_time >= temp->info->arrival && min > temp->info->remain_burst)
          {
          min = temp->info->remain_burst;
          index = temp;
          }
  
        }
      
       
       temp = temp->next;
     }
     if(index == NULL)
     {
      current_time++;
     }
     else{
         current_time += 1;
         index->info->remain_burst -= 1;
         index->info->wait_time = current_time - (index->info->arrival + index->info->burst);
        
     }
     
    }
    temp = L->head;

    while(temp != NULL)
    {
       printf("P%d: %d ms\n",  temp->info->pid + 1 , temp->info->wait_time);

         total_waitTime += temp->info->wait_time;
         temp = temp->next;

    }

      avg_waitTime = (double)total_waitTime / L->size;
      printf("Average waiting time is: %.2f\n", avg_waitTime); 
    
}
