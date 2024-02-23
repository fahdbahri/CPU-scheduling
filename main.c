//main

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FCFS.c"




void showResult(char *sc_method, Process *queue);
void endProgram(Process *queue);


int main(int argc,char *argv[])
{
    /*    if(argc != 5)
    {
        printf("Usage: %s -f input_file -o output_file\n", argv[0]);
        return 1;
    }

    const char *inputFile = NULL;
    const char *outputFile = NULL;

    for(int i = 1; i < argc; i += 2)
    {
        if(strcmp(argv[i], "-f") == 0)
        {
            inputFile = argv[i + 1];
        }
        else if(strcmp(argv[i], "-o") == 0)
        {
            outputFile = argv[i + 1];
        }
        else
        {
            printf("Invalid option: %s\n", argv[i]);
            return 1;
        }
    }



    if(inputFile == NULL || outputFile == NULL)
    {
        printf("Both -f and -o options are required.\n");
        return 1;
    }*/

    Process *queue = NULL;


    int option;
    char pre_mode[20];
    char sc_method[20];

    while (1)
    {
        // Display menu options
        printf("\nCPU Scheduler Simulator\n");

        printf("1) Set Scheduling Method\n");
        printf("2) Preemptive Mode (OFF / ON)\n");
        printf("3) Show Result\n");
        printf("4) End Program\n");
        printf("Option > ");

        // Get user input
        scanf("%d", &option);
        // Perform actions based on user choice
        switch (option)
        {
        case 1:
          printf("Enter your scheduling method:\n");
          scanf("%s", sc_method);
           if(strcasecmp(sc_method, "FCFS") == 0)
   {
          method_fcfs(queue, "input.txt");
   }
          break;

      
        case 2:

         

            break;
        case 3:
        //based on what the user select on the scheduling method the result will be printed here
           Result_FCFS(queue);
           break;

        case 4:

        //End Program: If user chooses this option, program show all (implemented) scheduling results on display
        

          fcfs_ToFile(queue, "output.txt");
      
         return 0;
  
            break;
        default:
            printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}



void showResult(char *sc_method, Process *queue)
{
    //if the scheduling method is selected showing the result of the specific scheduling method 
    if(strcmp(sc_method, "FCFS") == 0)
    {
        Result_FCFS(queue);

    }
     
   
}


