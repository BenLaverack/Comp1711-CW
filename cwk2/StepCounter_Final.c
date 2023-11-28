#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

    }


int main() {
    FITNESS_DATA fitness[200];
    int buffer_size=250;
    char line[buffer_size];
    int counter = 0;
    char option;
    char name[100];
    int total = 0;
    int min = 0;
    int min_total = 0;
    int max = 0;
    int max_total = 0;
    int mean_total;
    int max_chain_length = 0;
    int current_chain_length = 0;
    int max_chain_start_index;
    int max_chain_end_index;
    int current_chain_start_index;

    while (1){
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");

        scanf(" %c", &option);

        switch(option)
        {
            case 'a':
            case 'A':
                printf("Input filename: ");
                scanf("%s", name);

                FILE *input;
                input=fopen(name,"r");
                // check if the file exists
                if (input == NULL){
                    printf("Error: Could not find or open the file.\n");
                    return 1;
                }
                // loops back to the menu if the file is correct
                else if (input != NULL) {
                    printf("File successfully loaded.\n");
                }

                char date[11];
                char time[6];
                char steps[10];

                while(fgets(line, buffer_size, input))
                {
                    tokeniseRecord(line,",",date, time, steps);

                    strcpy(fitness[counter].date, date);
                    strcpy(fitness[counter].time, time);
                    fitness[counter].steps = atoi(steps);
                    counter++;
                    // total is used as a counter for amount of structs in the array
                    total++;
                    }
                
                break;

            case 'b':
            case 'B':
                printf("Total records: %d\n", total);
                break;

            case 'c':
            case 'C':
                min = fitness[0].steps;
                min_total = 0;
                for (counter = 1; counter < total; counter++){
                    if (fitness[counter].steps < min){
                        min = fitness[counter].steps;
                        min_total = counter;
                    }
                }
                printf("Fewest steps: %s %s\n", fitness[min_total].date, fitness[min_total].time);
                break;

            case 'd':
            case 'D':
                max = fitness[0].steps;
                max_total = 0;
                for (counter = 1; counter < total; counter++){
                    if (fitness[counter].steps > max){
                        max = fitness[counter].steps;
                        max_total = counter;
                    }
                }
                printf("Largest steps: %s %s\n", fitness[max_total].date, fitness[max_total].time);
                break;

            case 'e':
            case 'E':
                mean_total = 0;
                for (counter = 0; counter < total; counter++){
                    mean_total += fitness[counter].steps;
                }
                printf("Mean step count: %.0f\n", ((float)mean_total/(float)total));
                break;

            case 'f':
            case 'F':
                for (counter = 0; counter < total; counter++){
                    if (fitness[counter].steps > 500){
                        current_chain_length += 1;
                        if (current_chain_length == 1){
                            current_chain_start_index = counter;
                        }
                    }
                    else {
                        current_chain_length = 0;
                    }

                    if (current_chain_length > max_chain_length){
                        max_chain_length = current_chain_length;
                        max_chain_start_index = current_chain_start_index;
                        max_chain_end_index = counter;
                    }
                }
                printf("Longest period start: %s %s\n", fitness[max_chain_start_index].date, fitness[max_chain_start_index].time);
                printf("Longest period end: %s %s\n", fitness[max_chain_end_index].date, fitness[max_chain_end_index].time);

                break;

            case 'q':
            case 'Q':
                return 0;
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}