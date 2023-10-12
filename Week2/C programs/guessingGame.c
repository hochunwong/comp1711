#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randNum, guess, count;
    srand(time(NULL));
    randNum = rand() % 100;
    count = 0;

    printf("Random number generated between 0-100\n");
    while (guess != randNum) {
        printf("Guess: ");
        scanf("%d", &guess);
        if (guess>randNum){
            printf("Lower\n");
        } else if (guess<randNum) {
            printf("Higher\n");
        }
        count = count + 1;
    }
    printf("Congrats! You got the number! It was %d!\n", randNum);
    printf("You got it in %d guesses.\n", count);
}
