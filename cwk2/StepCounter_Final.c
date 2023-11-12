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




// Complete the main function
int main() {
    FITNESS_DATA fitness[100];
    int buffer_size=250;
    char line[buffer_size];
    int counter = 0;
    char option[1];
    int repeat = 1;

    while (repeat = 1){
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter choice: ");
        scanf("%s", option);

        if (strcmp(option, "A") == 0){
            printf("A\n");
            break;
        }
        else if (strcmp(option, "B") == 0){
            printf("B\n");
            break;
        }
        else if (strcmp(option, "C") == 0){
            printf("C\n");
            break;
        }
        else if (strcmp(option, "D") == 0){
            printf("D\n");
            break;
        }
        else if (strcmp(option, "E") == 0){
            printf("E\n");
            break;
        }
        else if (strcmp(option, "F") == 0){
            printf("F\n");
            break;
        }
        else if (strcmp(option, "Q") == 0){
            printf("Q\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }


    FILE *input=fopen("FitnessData_2023.csv","r");
    char date[11];
    char time[6];
    char steps[10];

    while(fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date, time, steps);

        strcpy(fitness[counter].date, date);
        strcpy(fitness[counter].time, time);
        fitness[counter].steps = atoi(steps);
        counter++;
    }
    }

    
}
