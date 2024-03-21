#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../process/process.h"

void rr_method(List *L, FILE *output_file, int quantem)
{
    

    int current_time = 0;
    int total_Burst = 0;
    int total_waitTime = 0;
    double avg_waitTime = 0;
    Node *current = L->head;
    Node *index;
    for (size_t i = 0; i < L->size; i++)
    {
        current->info->remain_burst = current->info->burst;
        total_Burst += current->info->burst;
        current = current->next;
    }

    while (true)
    {
        int check = true;

        for (current = L->head; current != NULL; current = current->next)
        {

            if (current->info->remain_burst > 0)
            {
                check = false;

                if (current->info->remain_burst > quantem)
                {
                    current_time += quantem;

                    current->info->remain_burst -= quantem;
                }

                else
                {
                    current_time += current->info->remain_burst;

                    current->info->wait_time = current_time - (current->info->burst + current->info->arrival);

                    current->info->remain_burst = 0;
                }
            }
        }

        if (check == true)
        {
            break;
        }
    }

    // displaying the output...
    current = L->head;

    while (current != NULL)
    {
        fprintf(output_file, "P%d: %d ms\n", current->info->pid + 1, current->info->wait_time);

        total_waitTime += current->info->wait_time;
        current = current->next;
    }

    avg_waitTime = (double)total_waitTime / L->size;
    fprintf(output_file, "Average waiting time is: %.2f\n", avg_waitTime);
}
