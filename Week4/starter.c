#include <stdio.h>

int main() {
    int array[5], sum=0;
    float mean;

    printf("Enter 5 numbers:\n");
    for (int i=0; i<5; i++) {
        scanf("%d", &array[i]);
        sum = sum + array[i];
    }

    printf("Total = %d\n", sum);
    mean = sum/5;
    printf("Mean = %f\n", mean);
}