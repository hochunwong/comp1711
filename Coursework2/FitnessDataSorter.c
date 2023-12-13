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

//Globals
FitnessData recordArray[1000];


int readFile() {
    char line[100];
    int i = 0;
    char temp[100];
    char fileName[100];

    printf("Enter Filename: ");
    scanf("%s", fileName);

    // open file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }

    // read file & save
    while (fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", recordArray[i].date, recordArray[i].time, temp);
        
        if ((recordArray[i].date=="") || (recordArray[i].time=="") || (temp=="")) {
            printf("Error: Incorrectly formatted file.\n");
            exit(1);
        }

        recordArray[i].steps = atoi(temp);
        i = i + 1;
    }
    fclose(file);
    return i;
}

int main() {

}
