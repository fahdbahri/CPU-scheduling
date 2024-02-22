
//fcfs

#include <stdio.h>
#include <stdlib.h>

#include "process.h"



int processNum = 0;

float avgWaitingTime = 0;



void insert_create(Process** p,int burst, int arriveTime, int priority)
{
    Process *q, *r = *p;
    
    q = (Process*)malloc(sizeof(Process));
    //set values
    
    q->burst_time = burst;
    q->arrive_time = arriveTime;
    q->priority = priority;
    q->next = NULL;

   
    if(*p == NULL)
    {
        *p = q;
    } else{
        while(r->next != NULL)
        {
            r = r->next;
          
        }
          r->next = q;
    }
      processNum++;


    
}

//function for taking the values



//create the process 
void method_fcfs(Process *queue, const char *input_File)
{
    Process *current = queue;
    FILE * inputFile = fopen(input_File, "r");
    if(inputFile == NULL)
    {  

        exit(1);
    }

     int burst, arrive, priority;

    while(fscanf(inputFile, "%d:%d:%d", &burst, &arrive, &priority) == 3)
    {
       
      insert_create(&queue, burst, arrive, priority);
    }
  fclose(inputFile);


    
    //while the cpu is executed
    int currentTime = 0;
    int totalWaitingTime = 0; 
     while(current != NULL)
     {
        
        current->waiting_time = currentTime - current->arrive_time; 
        totalWaitingTime += current->waiting_time; 
        currentTime += current->burst_time;
        current = current->next;

        
     }

     if(processNum <= 0)
     {
        printf("process number is zero");
     }
    
        avgWaitingTime = (float)totalWaitingTime / processNum;
     

      
    
      

}

void fcfs_ToFile(Process *queue, const char *output_File) {
     FILE * outputFile = fopen(output_File, "w");
    if (outputFile == NULL) {
        exit(1);
    }

    fprintf(outputFile, "Scheduling Method: First Come First Served\n");
    fprintf(outputFile, "Process Waiting Times:\n");
    for (Process *current = queue; current != NULL; current = current->next) {
        fprintf(outputFile, "P%d: %d ms\n", current->pid, current->waiting_time);
    }
    fprintf(outputFile, "Average Waiting Time: %.2f ms\n", avgWaitingTime);
    fclose(outputFile);
}

void Result_FCFS(Process *queue)
{

    printf("Scheduling Method:  First Come First Served");
    printf("Process Waiting Times:\n");
    for (Process *current = queue; current != NULL; current = current->next) {
        printf("P%d: %d ms\n", current->pid, current->waiting_time);
    }
    printf("Average Waiting Time: %.2f ms\n", avgWaitingTime);

     if(processNum == 0)
    {
        printf("N/A\n");
    }
    else
    {
        printf("%.2f ms\n", avgWaitingTime);
    }

}
