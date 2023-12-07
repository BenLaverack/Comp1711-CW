#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
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

    FITNESS_DATA fitness[1000]; // make an array of Fitness data Structs
    int buffer_size=250;
    char line[buffer_size];
    int counter = 0;
    int total = 0;

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
        total++;

    }

    // bubble sort algorithm
    // bubble sort algorithm
    int i;
    int index;
    int temp_steps;
    char temp_time[10];
    char temp_date[10];

    for(i=0;i<total;i++){
        for(index=0;index<total-1;index++){
            if(fitness[index].steps > fitness[index+1].steps){
                temp_steps = fitness[index].steps;
                temp_time = fitness[index].time;
                temp_date = fitness[index].date;
                fitness[index].steps = fitness[index+1].steps;
                fitness[index].date = fitness[index+1].date;
                fitness[index].time = fitness[index+1].time;
                fitness[index+1].steps = temp_steps;
                fitness[index+1].date = temp_date;
                fitness[index+1].time = temp_time;
            }
        }
    }
    
}