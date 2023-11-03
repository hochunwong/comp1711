// Author: Ho Chun Wong [sc23hcw]

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

// Complete the main function
int main() {
    // main's variables
    char line[100];
    int i = 0;
    char temp[100];

    // open file
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        printf("Unable to open file");
        return 1;
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

    // output record count
    printf("Number of records in file: %d\n", i);

    // output first 3 records
    for (int x=0; x<3; x++) {
        printf("%s/%s/%d\n", recordArray[x].date, recordArray[x].time, recordArray[x].steps);
    }

    return 0;
}
