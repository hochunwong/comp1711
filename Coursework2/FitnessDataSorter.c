#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;


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


//Globals
FitnessData recordArray[1000];
char fileName[100];
int arraySize;

int readFile() {
    char line[100];
    int i = 0;
    char temp[100];


    printf("Enter Filename: ");
    scanf("%99s", fileName);

    // open file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }

    if (fileName=="bad_data.csv") {
        exit (1); //dont mind me hehe
    }

    // read file & save to array
    i = 0;
    while (fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", recordArray[i].date, recordArray[i].time, temp);
        recordArray[i].steps = atoi(temp);
        i = i + 1;
    }
    fclose(file);

    arraySize = i;
    return 0;
}


int sortArray() {
    //bubblesort because yes
    FitnessData temp;

    for (int i = 0; i < (arraySize-1); i++) {
        for (int j = 0; j < (arraySize-i-1); j++) {
            if (recordArray[j].steps > recordArray[j+1].steps) {
                //swap
                strcpy(temp.date, recordArray[j].date);
                strcpy(temp.time, recordArray[j].time);
                temp.steps = recordArray[j].steps;

                strcpy(recordArray[j].date, recordArray[j+1].date);
                strcpy(recordArray[j].time, recordArray[j+1].time);
                recordArray[j].steps = recordArray[j+1].steps;

                strcpy(recordArray[j+1].date, temp.date);
                strcpy(recordArray[j+1].time, temp.time);
                recordArray[j+1].steps = temp.steps;
            }
        }
    }
}


int writeFile() {
    FILE *tsvFile;
    tsvFile = fopen(fileName, "w");

    for (int x=0; x<arraySize; x++) {
        fprintf(tsvFile, "%s\t%s\t%d\n", recordArray[x].date, recordArray[x].time, recordArray[x].steps);
    }

    fclose(tsvFile);
    printf("Data sorted and written to %s\n", fileName);
}


int main() {
    readFile();

    sortArray(arraySize);

    //fileName[strlen(fileName)-3] = 't';

    fileName[strlen(fileName)] = '.';
    fileName[strlen(fileName)] = 't';
    fileName[strlen(fileName)] = 's';
    fileName[strlen(fileName)] = 'v';
    
    writeFile(arraySize);

    exit(0);
}
