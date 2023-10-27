#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
    FITNESS_DATA fitness[100]; // make an array of Fitness data Structs
    int buffer_size=250;
    char line[buffer_size];
    int counter = 0;

    FILE *input=fopen("FitnessData_2023.csv","r");
    char date[10];
    char steps[10];
    char time[10];

    while(fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date, time, steps);

        strcpy(fitness[counter].date, date);
        fitness[counter].steps = atoi(steps);
        strcpy(fitness[counter].time, time);
        counter++;

    }

    printf("There are %d lines in the file\n", counter);

    for(int i = 0; i < 3; i++){
        printf("%s/%s/%d\n", fitness[i].date, fitness[i].time, fitness[i].steps);
    }

}