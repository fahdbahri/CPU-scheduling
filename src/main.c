

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/algorithms/fcfs.c"
#include "../src/algorithms/sjf.c"
#include "../src/algorithms/srtf.c"
#include "../src/algorithms/Priority.c"
#include "../src/algorithms/pre_Priority.c"
#include "../src/algorithms/round_robin.c"
#include "../src/process/process.c"

int quantem; // quantum of round robin method

// Function prototypes
void setSchedulingMethod();
void setPreemptiveMode();
void showResult(List *new_list);
void endProgram(List *new_list, const char *output_filename);

// Global variables
char schedulingMethod[50] = "None"; // Default scheduling method
char preemptiveMode[20] = "Off";    // Default preemptive mode

int main(int argc, char *argv[])
{
    char *input_filename = NULL;
    char *output_filename = NULL;

    // Check command line arguments
    if (argc != 5 || strcmp(argv[1], "-f") != 0 || strcmp(argv[3], "-o") != 0)
    {
        printf("Usage: %s -f input.txt -o output.txt\n", argv[0]);
        return 1;
    }

    input_filename = argv[2];
    output_filename = argv[4];

    if (input_filename == NULL)
    {
        printf("input file name required.\n");
        return 1;
    }
    else if (output_filename == NULL)
    {
        printf("output file name required");
        return 1;
    }

    // Deserialize data from input file

    // Display menu and process user options
    int option;
    while (1)
    {
        List *new_list = deserialize(input_filename); // get the file inputs

        printf("\nCPU Scheduler Simulator\n");
        printf("1) Scheduling Method (%s)\n", schedulingMethod);
        printf("2) Preemptive Mode (%s)\n", preemptiveMode);
        printf("3) Show Result\n");
        printf("4) Print To File\n");
        printf("5) End Program\n");
        printf("Option > ");
        scanf("%d", &option); // Get user input

        // Perform actions based on user choice
        switch (option)
        {
        case 1:
            setSchedulingMethod(); // Set scheduling method
            break;
        case 2:
            setPreemptiveMode(); // Set preemptive mode
            break;
        case 3:

            showResult(new_list); // Show result

            break;
        case 4:
            printf("Printing to File\n");
            endProgram(new_list, output_filename);

            destroy_l(new_list); // Free memory
            break;

        case 5:
            printf("Ending Program..\n");
            return 0; // Exit program
        default:
            printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}

// Function to set the scheduling method based on user input
void setSchedulingMethod()
{
    printf("Enter scheduling method ('FCFS' for First Come First Served, 'SJF' for Short Job First 'PRIORITY', for Priority, 'RR' for Round Robin, 'None' for no scheduling method): ");
    scanf("%s", schedulingMethod);
    if (strcmp(schedulingMethod, "FCFS") == 0)
    {
        printf("Scheduling method set to: %s\n", schedulingMethod);
    }
    else if (strcmp(schedulingMethod, "SJF") == 0)
    {
        printf("Scheduling method set to: %s\n", schedulingMethod);
    }
     else if (strcmp(schedulingMethod, "PRIORITY") == 0)
 {
           printf("Scheduling method set to: %s\n", schedulingMethod);
 }
    else if (strcmp(schedulingMethod, "RR") == 0)
    {
        printf("Scheduling method set to: %s\n", schedulingMethod);

        printf("\nEnter the value of quantem:\n");
        scanf("%d", &quantem);
    }else if (strcmp(schedulingMethod, "None") == 0)
    {
       printf("Scheduling method set to: %s\n", schedulingMethod);
    } else
    {
        printf("Incorrect Value\n");
    }
}

// Function to set the preemptive mode based on user input
void setPreemptiveMode()
{
    printf("Enter preemptive mode ('On' or 'Off'): ");
    scanf("%s", preemptiveMode);
    printf("Preemptive mode set to: %s\n", preemptiveMode);
}

// Function to show the result based on the chosen scheduling method
void showResult(List *new_list)
{

    if (strcmp(schedulingMethod, "FCFS") == 0)
    {

        if (strcmp(preemptiveMode, "Off") == 0 || strcmp(preemptiveMode, "On") == 0)
        {

            fcfs_method(new_list, stdout);
        }
    }
    else if (strcmp(schedulingMethod, "None") == 0)
    {
        printf("No scheduling method chosen.\n");
    }
    else if (strcmp(schedulingMethod, "SJF") == 0)
    {
        if (strcmp(preemptiveMode, "Off") == 0)
        {
            sjf_method(new_list, stdout);
        }
        else if (strcmp(preemptiveMode, "On") == 0)
        {

            srtf_method(new_list, stdout);
        }
    }
    else if (strcmp(schedulingMethod, "PRIORITY") == 0)
    {
        if (strcmp(preemptiveMode, "Off") == 0)
        {
            priority_method(new_list, stdout);
        }
        else if (strcmp(preemptiveMode, "On") == 0)
        {

            pre_Priority(new_list, stdout);
        }
    }
    else if (strcmp(schedulingMethod, "RR") == 0)
    {

        rr_method(new_list, stdout, quantem);
    }
     else if (strcmp(schedulingMethod, "None") == 0)
    {
        printf("No scheduling method chosen.\n");
    }
    else
    {
        printf("Invalid scheduling method.\n");
    }
}

void endProgram(List *new_list, const char *output_filename)
{
    FILE *output_file = fopen("output.txt", "w");

    if (strcmp(schedulingMethod, "FCFS") == 0)
    {

        fcfs_method(new_list, output_file);
    }
    else if (strcmp(schedulingMethod, "SJF") == 0)
    {

        if (strcmp(preemptiveMode, "Off") == 0)
        {
            sjf_method(new_list, output_file); // print sjf
        }
        else if (strcmp(preemptiveMode, "On") == 0)
        {

            srtf_method(new_list, output_file);
        }
    }
    else if (strcmp(schedulingMethod, "PRIORITY") == 0)
    {
        if (strcmp(preemptiveMode, "Off") == 0)
        {
            priority_method(new_list, output_file);
        }
        else if (strcmp(preemptiveMode, "On") == 0)
        {

            pre_Priority(new_list, output_file);
        }
    }
    else if (strcmp(schedulingMethod, "RR") == 0)
    {
         rr_method(new_list, output_file, quantem);
    } 
    else if (strcmp(schedulingMethod, "None") == 0)
    {
        printf("No scheduling method chosen.\n");
    }
    else
    {
        printf("Invalid scheduling method.\n");
    }

    fclose(output_file);
}
