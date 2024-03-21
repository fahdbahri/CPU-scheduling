
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../process/process.h"


void sjf_method(List* L, FILE* output_file)
{  
    fprintf(output_file, "Scheduling Method: Shortest job First Non Preemptive\n");
    fprintf(output_file, "Process Waiting Times:\n");


   Node* current = L->head;
   int total_burst = 0;
   while(current != NULL)
   {
      total_burst += current->info->burst;
      current->info->execute_time = 0;
      current = current->next; 
   }

   int min = total_burst;
   int current_time = 0;
   int totalWait_time = 0;
   double avgWait_Time = 0.;

   while (current_time <= total_burst)
   {
        Node* index = NULL;
        current = L->head;
        min = total_burst;
        while (current != NULL)
        {
            if(current->info->execute_time == 0)
            {
                if(current_time>=current->info->arrival && min > current->info->burst)
                {
                    min = current->info->burst;
                    index = current;

                }
            }
            current = current->next;
        }

        if(index == NULL)
        {
            current_time++; //idle time for the process
        }
        else {

            current_time += index->info->burst;
            index->info->execute_time += 1;
            index->info->wait_time = current_time - (index->info->arrival + index->info->burst);
        }
    
   }

   current  = L->head;

    while(current != NULL)
    {
       fprintf(output_file, "P%d: %d ms\n",  current->info->pid + 1 , current->info->wait_time);

         totalWait_time += current->info->wait_time;
         current = current->next;

    }
   

    avgWait_Time = (double)totalWait_time / size(L);

   fprintf(output_file, "Average waiting time is: %.2f\n", avgWait_Time); 
    

}