

/*int main(int argc, char* argv[])
{
    char* input_filename = NULL;

    if(argc != 3 || strcmp(argv[1], "-f") != 0) {
        printf("Usage: %s -f input.txt\n",argv[0]); 
        return 1;
    }
      input_filename = argv[2];

      if(input_filename == NULL)
      {
        printf("input file name required.\n");
        return 1;
      }

   List* new_list = deserialize(input_filename);
  

    printf("average waiting time is %.2f\n", fcfs_method(new_list));

   new_list = destroy_l(new_list);

}
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fcfs.c" 
#include "sjf.c" 
#include "process.c"

// Function prototypes
void setSchedulingMethod();
void setPreemptiveMode();
void showResult(List* new_list);
void endProgram(List* new_list,  const char* output_filename);



// Global variables
char schedulingMethod[50] = "None";  // Default scheduling method
char preemptiveMode[20] = "Off";     // Default preemptive mode

int main(int argc, char* argv[]) {
    char* input_filename = NULL;
    char* output_filename = NULL;

    // Check command line arguments
    if (argc != 5 || strcmp(argv[1], "-f") != 0 || strcmp(argv[3], "-o") != 0) {
        printf("Usage: %s -f input.txt -o output.txt\n", argv[0]);
        return 1;
    }

    input_filename = argv[2];
    output_filename = argv[4];

    if (input_filename == NULL) {
        printf("input file name required.\n");
        return 1;
    } else if(output_filename == NULL)
    {
      printf("output file name required");
      return 1;
    }

    // Deserialize data from input file

   


    // Display menu and process user options
    int option;
    while (1) {
        List* new_list = deserialize(input_filename);
        

        printf("\nCPU Scheduler Simulator\n");
        printf("1) Scheduling Method (%s)\n", schedulingMethod);
        printf("2) Preemptive Mode (%s)\n", preemptiveMode);
        printf("3) Show Result\n");
        printf("4) End Program\n");
        printf("Option > ");
        scanf("%d", &option);  // Get user input

        // Perform actions based on user choice
        switch (option) {
            case 1:
                setSchedulingMethod();  // Set scheduling method
                break;
            case 2:
                setPreemptiveMode();  // Set preemptive mode
                break;
            case 3:
                 
               
                showResult(new_list); 
                   // Show result
                
                break;
            case 4:
                printf("Ending program.\n");
                endProgram(new_list, output_filename);
            
                destroy_l(new_list);  // Free memory
                return 0;
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}

// Function to set the scheduling method based on user input
void setSchedulingMethod() {
    printf("Enter scheduling method ('FCFS' for First Come First Served, 'None' for no scheduling method): ");
    scanf("%s", schedulingMethod);
    if(strcmp(schedulingMethod, "FCFS") == 0)
    {
        printf("Scheduling method set to: %s\n", schedulingMethod);

    }else if(strcmp(schedulingMethod, "SJF") == 0)
    {
        printf("Scheduling method set to: %s\n", schedulingMethod);
    }

    
}

// Function to set the preemptive mode based on user input
void setPreemptiveMode() {
    printf("Enter preemptive mode ('On' or 'Off'): ");
    scanf("%s", preemptiveMode);
    printf("Preemptive mode set to: %s\n", preemptiveMode);
}

// Function to show the result based on the chosen scheduling method
void showResult(List* new_list){

    if (strcmp(schedulingMethod, "FCFS") == 0) {

        fcfs_method(new_list);
     
    
        
    } else if (strcmp(schedulingMethod, "None") == 0) {
        printf("No scheduling method chosen.\n");
    } else if(strcmp(schedulingMethod, "SJF" ) == 0)
    {
        sjf_method(new_list);
  
   
     
    }
    else {
        printf("Invalid scheduling method.\n");
    }

     
}


void endProgram(List* new_list, const char* output_filename)
{
    FILE *output_file = fopen("output.txt", "w");

      if (strcmp(schedulingMethod, "FCFS") == 0) {
       
        printfcfs_method(new_list, output_file);
    } 
    else if(strcmp(schedulingMethod, "SJF" ) == 0)
    {   

        printsjf_method(new_list, output_file);
    }else if (strcmp(schedulingMethod, "None") == 0) {
        printf("No scheduling method chosen.\n");
    } else {
        printf("Invalid scheduling method.\n");
    }

    fclose(output_file);
}


