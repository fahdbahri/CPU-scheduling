//process.h

#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>

//Create the process

typedef struct Process{
   
   int pid;
   int arrive_time;
   int burst_time;
   int waiting_time;
   int turnaround_time;
   int currentTime;
   int priority;

   struct Process *next;
} Process;


void insert_end(Process** queue, int burstTime, int arriveTime, int priority);


#endif