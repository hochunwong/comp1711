#include <stdio.h>

int main() {
    int i, j, k;

    for(i=0; i<10; i++) {
        printf("%d\n", i);
    }

    printf("-------------------\n");

    for (i=0; i<50; i=i+2) {
        printf("%d\n", i);
    }

    printf("-------------------\n");

    j = 11;
    i = 0;
    while ((j*i) <= 1000) {
        printf("%d\n", i*j);
        i++;
    }

    printf("-------------------\n");

    for (i=100; i>0; i=i-5) {
        printf("%d\n", i);
    }
}
