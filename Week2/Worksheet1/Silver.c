#include <stdio.h>

int main() {
    int mark=-1;

    while (mark<=0 || mark>100) {
        printf("Enter mark: ");
        scanf("%d", &mark);
    }

    if (mark>=70) {
        printf("Distinction\n");
    } else if (mark>=50) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }
}