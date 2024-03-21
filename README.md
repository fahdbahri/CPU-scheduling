# CPU-scheduling

Project Overview:

This project is a simple CPU scheduling simulator designed to handle various scheduling methods including First Come, First Served Scheduling, Shortest-Job-First Scheduling, Priority Scheduling, and Round-Robin Scheduling. The program takes input data from a text file and provides output data to another text file as specified by command-line arguments. It also gathers statistics such as average waiting time and waiting time for each job in the queue.

Usage:

The program can be executed with the following command-line arguments:

          ./main -f src/input.txt -o src/output.txt


Functionality: 

1. Input File Format:

The input file should have three columns and unlimited rows, with fields delimited by the ":" character. The structure of the file should be as follows:

                         Burst Time:Arrival Time:Priority
    
Sample input file input.txt is provided in the Appendix section.

2. Scheduling Methods:
   
-After the first execution, the simulator prompts the user to choose a scheduling method from a menu with at least four options:

-None
-First Come, First Served Scheduling
-Shortest-Job-First Scheduling
-Priority Scheduling
-Round-Robin Scheduling (with time quantum value)

3. Preemptive and Non-preemptive Mode:

   -The simulator supports both preemptive and non-preemptive modes. In preemptive mode, 
   decisions are made on a clock-driven basis, while in non-preemptive mode, decisions are made 
   after a process has terminated.


4. Showing Results, Printing to File, and Ending Program:

 -Option to show results: The program displays reports on the screen.
 -Option to print to file and then end program: The program prints all implemented scheduling 
     results to the output file specified by the -o option and terminates.
 -Option to end the program directly: The program ends without printing to file.
 
5. Statistics Gathering:
    -The program gathers statistics including:
      -Average waiting time for all jobs in the queue.
      -Waiting time for each job in the queue.
   
6. Appendix:
    -Input File (input.txt):
             Burst Time:Arrival Time:Priority
              10:     0:           0
              5:      0:           0

Conclusion:

This simple CPU scheduling simulator provides a flexible and customizable platform for experimenting with various scheduling methods. By following the provided usage instructions and guidelines, users can easily simulate and analyze different scheduling scenarios.
