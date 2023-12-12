#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FITNESS_DATA recordArray[1000];


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


void printMenu() {
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    return;
}

int readFile(char *fileName) {
    char line[100];
    int i = 0;
    char temp[100];

    // open file
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        printf("Unable to open file");
        return 0;
    }

    // read file & save to ara ara
    while (fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", recordArray[i].date, recordArray[i].time, temp);
        // printf("%s", temp);
        recordArray[i].steps = atoi(temp);
        i = i + 1;
    }

    // close file
    fclose(file);
    return 1;
}



// Complete the main function
int main() {
   int fileRead = 0;

}









