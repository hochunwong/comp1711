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
    printf("Enter choice: ");
    return;
}


int readFile() {
    char line[100];
    int i = 0;
    char temp[100];
    char fileName[100];

    printf("Input filename: ");
    scanf("%s", &fileName);

    // open file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(0);
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
    return i;
}


void findFewest(int recordArraySize) {
    FITNESS_DATA fewest;
    fewest.steps = 0;

    for (int i=0; i<=recordArraySize; i++) {
        if (recordArray[i].steps < fewest.steps) {
            fewest = recordArray[i];
        }
    }

    printf("Fewest steps: %s %s\n", fewest.date, fewest.time);
    return;
}


// Complete the main function
int main() {
    int fileNotOpen = 1; //has file been read?
    char option[100];
    int recordNum = 0;

    while (1) {
        printMenu();
        scanf("%s", &option);

        switch (option[0]) {
            case 'A': //import file
                recordNum = readFile();
                break;
            case 'B': //total num of records
                printf("Total records: %d\n", recordNum);
                break;
            case 'C': //fewest
                findFewest(recordNum);
                break;
            case 'D': //most
                break;
            case 'E': //mean
                break;
            case 'F': //longest >500
                break;
            case 'Q': //exit
                exit(1);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}









