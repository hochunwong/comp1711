#include <stdio.h>
#include <stdlib.h>

int readFile() {
    char fileName[] = "input.txt";
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int fileArray[300];
    int buffer_size = 10;
    char line_buffer[buffer_size];
    int linecount = 0;
    int count1000plus = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        fileArray[linecount] = atoi(line_buffer);
        printf("%d\n", fileArray[linecount]);
        
        if (fileArray[linecount] > 1000) {
            count1000plus += 1;
        }

        linecount = linecount + 1;
    }
    printf("%d numbers over 1000\n", count1000plus);

    fclose(file);

    find2020(&fileArray);

    return 0;
}

int find2020(int array[]) {
    for (int i=0; i<300; i++) {
        for (int j=0; j<300; j++) {
            if (array[i] + array[j] == 2020) {
                printf("Found 2020, %d + %d\n", array[i], array[j]);
            }
        }
    }
}

int main() {
    readFile();
}

