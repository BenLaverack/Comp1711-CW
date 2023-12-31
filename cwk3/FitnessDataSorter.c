#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

// function written for bubble sort to swap the position of two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function written for bubble sort to swap two characters
void swap_char(char *str1, char *str2) 
{ 
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
} 


// write a function to determine if a series of chars are digits
int areAllDigits(int number) {

    char str[20];
    // breaks the input down into an array of chars
    snprintf(str, sizeof(str), "%d", number);

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int allAreDigitsStr(char * character) {
    for (int i = 0; character[i] != '\0'; i++) {
        if (!isdigit(character[i])) {
            return 1;
        }
    }
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

    FILE *input=fopen(filename, "r");

    if(input == NULL){
        printf("Invalid file name\n");
        return 1;
    }

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

    // check for errors in the file
    for(i=0;i<total;i++){

        // check that date and time are the correct lengths
        if(strlen(fitness[i].date) != 10){
            return 1;
        }
        if(strlen(fitness[i].time) != 5){
            return 1;
        }

        // check that date and time are in the correct format
        if(fitness[i].date[4] != '-' || fitness[i].date[7] != '-'){
            return 1;
        }
        if(fitness[i].time[2] != ':'){
            return 1;
        }

        // split the date up
        char brokenDate[10];
        char * token = strtok(brokenDate, "-");
        // check that all of the characters in the data are digits
        while (token != NULL){
            allAreDigitsStr(token);
            token = strtok(NULL, "-");
        }

        char brokenTime[10];
        // split up the time
        char * token2 = strtok(brokenTime, ":");
        while (token2 != NULL){
            // check that all of the characters in the time are digits
            allAreDigitsStr(token);
            token2 = strtok(NULL, ":");
        }

        // check that all of the characters in steps are digits
        if(areAllDigits(fitness[i].steps) == 0 && fitness[i].steps < 10000 && fitness[i].steps >= 0){
        }
        else {
            return 1;
        }

        if(fitness[i].steps == '\0'){
            return 1;
        }
    }
    
    
    FILE *fptr;
    // add '.tsv' to the filename and open it
    fptr = fopen(strcat(filename, ".tsv"), "w");

    // write the data to the file
    for(int j = total-1; j >= 0; j--){
        fprintf(fptr, "%s\t%s\t%d\n", fitness[j].date, fitness[j].time, fitness[j].steps);
    }
    printf("Data sorted and written to %s\n", filename);

}
