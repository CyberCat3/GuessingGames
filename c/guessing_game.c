#include <stdio.h> // For writing to the console.
#include <stdlib.h> // For converting strings to numbers and generating random numbers.
#include <time.h> // For getting time so we can seed our rng.
#include <string.h> // For getting length of string.
#include <ctype.h> // For detecting whitespace and making stuff lowercase.

#define MAX 256 // The size of out input buffer.
#define EVER (;;) // :-)

int is_no(char* input) { // checks if the input is "no-y"
    int len = strlen(input); // gets the length of the string

    for (int i = 0; i < len; ++i) {
        
        // skips all whitespace (effectively trimming)
        if (isspace(input[i])) {
            continue;
        }

        // checks the first char is 'n'
        return tolower(input[i]) == 'n';
    }
}

int main() {
    // seeds our rng with the amount of seconds since the Epoch. We pass NULL, because otherwise it
    srand(time(NULL)); // will fill the passed variable with the time information instead of returning it.

    char buf[MAX]; // The char buffer we will use for reading user input.
    char* eptr; // This is a pointer to the remaining charactes after a number has been parsed.

    for EVER { 
        int num = rand() % 100 + 1;
        int guess = -1;

        printf("Guess a number between 1 - 100!\n");
        
        while (guess != num) {
            printf("Guess: ");
            fgets(buf, MAX, stdin); // Reads from stdin into our inputbuffer char array.
            guess = strtol(buf, &eptr, 10); // Converts our inputbuffer to a number.
            
            // If buf points to the same place as eptr, then all characters were excess and parsing failed.
            if (eptr == buf) {
                printf("Please type a number!\n");
                continue;
            }

            if (guess < num) { printf("Higher!\n"); }
            else if (guess > num) { printf("Lower!\n"); }
        }
        printf("You guessed it!\n");
        printf("Play again?\n");
        printf("(Y/n): ");
        fgets(buf, MAX, stdin);
         // If the user doesn't want to play again, stop the game.
        if (is_no(buf)) {
            break;
        }
    }
    return 0;
}