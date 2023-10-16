#include <stdio.h>

int main() {
    int option=0;

    while (option<=0 || option>5) {
        printf("Choices:\n1) Option 1\n2) Option 2\n3) Option 3\n4) Option 4\n5) Option 5\nEnter option: ");
        scanf("%d", &option);
    }

    switch (option)
    {
    case 1:
    printf("Option 1");
        /* code */
        break;
    case 2:
        printf("Option 2");
        /* code */
        break;
    case 3:
        printf("Option 3");
        /* code */
        break;
    case 4:
        printf("Option 4");
        /* code */
        break;
    case 5:
        printf("Option 5");
        /* code */
        break;
    
    default:
        break;
    }
}