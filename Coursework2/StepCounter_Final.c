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
    scanf("%s", fileName);

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


void findFewest(int recordNum) {
    FITNESS_DATA fewest;
    fewest.steps = recordArray[0].steps;
    strcpy(fewest.date, recordArray[0].date);
    strcpy(fewest.time, recordArray[0].time);

    for (int i = 0; i < recordNum; i++) {
        if (recordArray[i].steps < fewest.steps) {
            strcpy(fewest.date, recordArray[i].date);
            strcpy(fewest.time, recordArray[i].time);
            fewest.steps = recordArray[i].steps;
        }
    }

    printf("Fewest steps: %s %s\n", fewest.date, fewest.time);
    return;
}


void findMost(int recordNum) {
    FITNESS_DATA most;
    most.steps = recordArray[0].steps;
    strcpy(most.date, recordArray[0].date);
    strcpy(most.time, recordArray[0].time);

    for (int i = 0; i < recordNum; i++) {
        if (recordArray[i].steps > most.steps) {
            strcpy(most.date, recordArray[i].date);
            strcpy(most.time, recordArray[i].time);
            most.steps = recordArray[i].steps;
        }
    }

    printf("Largest steps: %s %s\n", most.date, most.time);
    return;
}


void mean(int recordNum) {
    int totalSteps = 0;
    int meanSteps;

    for (int i = 0; i < recordNum; i++) {
        totalSteps = totalSteps + recordArray[i].steps;
    }

    meanSteps = totalSteps / recordNum;
    printf("Mean step count: %d\n", meanSteps);
}


void longestPeriod(int recordNum) {
    int longestPeriod = 0;
    int currentPeriod = 0;
    FITNESS_DATA start, end, tempStart, tempEnd;

    for (int i = 0; i < recordNum; i++) {
        if (recordArray[i].steps > 500) {
            if (currentPeriod == 0) {
                strcpy(tempStart.date, recordArray[i].date); //start current
                strcpy(tempStart.time, recordArray[i].time);
                currentPeriod = currentPeriod + 1;
            } else {
                strcpy(tempEnd.date, recordArray[i].date); //continue current
                strcpy(tempEnd.time, recordArray[i].time);
                currentPeriod = currentPeriod + 1;
            }
        } else {
            if (currentPeriod != 0) {
                if (currentPeriod > longestPeriod) { //update longest
                    longestPeriod = currentPeriod;
                    strcpy(start.date, tempStart.date);
                    strcpy(start.time, tempStart.time);
                    strcpy(end.date, tempEnd.date);
                    strcpy(end.time, tempEnd.time);
                    //kill
                    currentPeriod = 0;
                }
            }
        }
    }

    printf("Longest period start: %s %s\n", start.date, start.time);
    printf("Longest period end: %s %s\n", end.date, end.time);
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
                findMost(recordNum);
                break;
            case 'E': //mean
                mean(recordNum);
                break;
            case 'F': //longest >500
                longestPeriod(recordNum);
                break;
            case 'Q': //exit
                exit(1);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}









