#include <stdio.h>

int main()
{
    FILE *file;
    char line[100];

    file = fopen("FitnessData_2023.csv", "r");
    fgets(line, 100, file);

    printf("%s", line);

    return 0;
}
