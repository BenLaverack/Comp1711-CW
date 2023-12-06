#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
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
    int int_temp;
    char char_temp[100];
    int i;
    int index;

    for(i=0;i<total;i++){
        for(index=0;index<total-1;index++){
            if(fitness[index].steps > fitness[index+1].steps){
                int_temp = fitness[index];
                fitness[index] = fitness[index+1];
                fitness[index+1] = char_temp;
            }
        }
    }

    for(i=0;i<total;i++){
        printf(fitness[i]);
    }

    
}