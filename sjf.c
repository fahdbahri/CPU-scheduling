
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"




void sortList(List* L){

    Node* current;
    Node* index;
    Info* temp;
    
    if (L->head == NULL) {
        return;
    }

    for (current = L->head; current != NULL; current = current->next) {
        if(current->info->arrival == 0) 
            continue; //skip zero arrival time process
        for (index = current->next; index != NULL; index = index->next) {
            
            if (current->info->burst > index->info->burst) {
                temp = current->info;
                current->info = index->info;
                index->info = temp;
            }
            
           
           else if (current->info->burst == index->info->burst) {

                if(current->info->arrival > index->info->arrival)
                {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;

                }
                
            }
        }
    }
}    
        
    

/*
void sort_sjf(List* L)
{

    bool is_completed[L->size] = {false};
    memset(is_completed, 0, L->size*sizeof(bool));

    int current_time = 0;
    int completed = 0;
      Node* current = L->head;
    
    while(completed!=L->size)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for(int i = 0; i < L->size; i++) {
            if(current->info->arrival <= current_time && is_completed[i] == false) {
                if(current->info->burst  < minimum) {
                    minimum = current->info->burst ;
                    min_index = i;
                }
                if(current->info->burst == minimum) {
                    if(current->info->arrival < ps[min_index].at) {
                        minimum= current->info->burst ;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index==-1)
        {
            current_time++;
        }
}*/



void sjf_method(List* L)
{  
    printf("Scheduling Method: Shortest job First Non Preemptive\n");
    printf("Process Waiting Times:\n");

   double avgWait_Time = 0.;
    int totalWait_time = 0;
    int current_time = 0; 
    Node*  p   = L->head;
     for (size_t i = 0; i < L->size; i += 1)
    {  // here we have node data, one
        // at a time
         
        
        sortList(L);

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

   printf("Average waiting time is: %.2f\n", avgWait_Time); 
    

  

}


void printsjf_method(List* L, FILE *output_file)
{  
     fprintf(output_file, "Scheduling Method: Shortest job First Non Preemptive\n");
     fprintf(output_file, "Process Waiting Times:\n");

    if (L == NULL && L->size == 0 ) return;
    
    
    double avgWait_Time = 0.;
    int totalWait_time = 0;
    int current_time = 0;
    Node*  p   = L->head;
    p->info->pid = 0;
    //for (size_t i = 0; i < L->size; i += 1)
    while(p != NULL)
    {  // here we have node data, one
        // at a time
        sortList(L);
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

