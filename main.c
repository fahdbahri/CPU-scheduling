//main

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "fcfs.c"



int main(int argc, char* argv[])
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






