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
    FITNESS_DATA fitness[100];
    int buffer_size=250;
    char line[buffer_size];
    int counter = 0;
    char option;
    char name[100];
    int total;

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

        option = getchar();

        switch(option)
        {
            case 'a':
            case 'A':
                printf("Enter the filename to be imported: ");
                scanf("%s", name);

                FILE *input=fopen(name,"r");
                if (!input){
                    printf("Invalid file name detected ");
                }
                else {
                    printf("Filename entered correctly, please choose an option:\n");
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
                    total++;
                }
                break;

            case 'q':
            case 'Q':
                return 0;
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    
}
