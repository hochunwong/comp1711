#include <stdio.h>

int main() {
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    if (num==0) {
        printf("Number is Zero\n");
    } else if (num>0) {
        printf("Number is Positive\n");
    } else {
        printf("Number is Negative\n");
    }

    if ((num%4) == 0) {
        printf("Number is Divisible by 4\n");
    }

    if ((num%5) == 0) {
        printf("Number is Divisible by 5\n");
    } 
}