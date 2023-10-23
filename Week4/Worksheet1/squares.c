#include <stdio.h>

int main() {
    char filename[] = "squares.dat";
    int n;

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("");
        return 1;
    }

    printf("Enter the value of n: ");
    scanf("%d", &n);
    
}
