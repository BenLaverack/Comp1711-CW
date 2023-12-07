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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *str1, char *str2) 
{ 
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
} 

int main() {

    FITNESS_DATA fitness[1000]; // make an array of Fitness data Structs
    int buffer_size=250;
    char line[buffer_size];
    int counter = 0;
    int total = 0;
    char filename[100];

    printf("Enter Filename: ");
    scanf("%s", filename);

    if(filename == NULL){
        printf("Invalid Filename ");
        return 1;
    }

    FILE *input=fopen(filename, "r");
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
    int i, index;

    for(i=0;i<total;i++){
        for(index=0;index<total-1;index++){
            if(fitness[index].steps > fitness[index+1].steps){
                swap(&fitness[index].steps, &fitness[index+1].steps);
                swap_char(fitness[index].date, fitness[index+1].date);
                swap_char(fitness[index].time, fitness[index+1].time);
            }
        }
    }
    

    FILE *fptr;
    fptr = fopen(strcat(filename, ".tsv"), "w");

    for(int j = total-1; j > 0; j--){
        fprintf(fptr, "%s\t%s\t%d\n", fitness[j].date, fitness[j].time, fitness[j].steps);
    }
    printf("Data sorted and written to %s\n", filename);

}
