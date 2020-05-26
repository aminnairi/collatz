#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NO_ERROR 0
#define ERROR_EXPECTED_ONE_ARGUMENT 1
#define ERROR_TOO_MUCH_ARGUMENTS 2
#define ERROR_INVALID_COLLATZ 3

#define UNUSED(something) (void) something

unsigned int toUnsignedInteger(const char *string);
void printCollatz(unsigned int start);

// Our program takes arguments
int main(int argumentsCount, char **arguments) {
    UNUSED(argumentsCount);

    // If we didn't receive any arguments
    if (arguments[1] == NULL) {
        puts("Expected one argument.");

        return ERROR_EXPECTED_ONE_ARGUMENT;
    }

    // If we received too much arguments
    if (arguments[2] != NULL) {
        puts("Too much arguments.");

        return ERROR_TOO_MUCH_ARGUMENTS;
    }

    // If the --version option is provided
    if (strcmp(arguments[1], "--version") == 0) {
        puts("0.7.0");

        return NO_ERROR;
    }

    // We turn our argument into its integer representation
    unsigned int start = toUnsignedInteger(arguments[1]);

    // If it turns out our argument does not start at one
    if (start == 0) {
        puts("Invalid Collatz starting point.");

        return ERROR_INVALID_COLLATZ;
    }

    // We can now safely print our Collatz conjecture
    printCollatz(start);

    return NO_ERROR;
}

unsigned int toUnsignedInteger(const char *string) {
    unsigned int length = strlen(string);
    unsigned int integer = 0;

    // Loop through all of the characters
    for (unsigned int current = 0; current < length; current++) {
        // If the current character is not a digit (no signed numbers allowed)
        if ((current == 0 && string[current] == '-') || !isdigit(string[current])) {
            return 0;
        }

        // We get the current character
        char character = string[current];

        // We turn it into an integer
        int nextInteger = character - '0';

        // We add it to our integer and make room for the next one
        integer = (integer + nextInteger) * 10; 
    }

    // Needed, as we will make room for an unecessary integer in the end
    integer = integer / 10;

    return integer;
}

void printCollatz(unsigned int start) {
    // If the starting point is lower than one, don't print anything
    if (start < 1) {
        return;
    }

    // Printing the starting point of the sequence
    printf("%d ", start);

    // While we didn't reach the end of the sequence
    while (start != 1) {
        // If the current starting point is even
        if (start % 2 == 0) {
            start = start / 2;
        } else {
            start = start * 3 + 1;
        }

        // If we reach the end of the sequence
        if (start == 1) {
            printf("%d\n", start);
        } else {
            printf("%d ", start);
        }
    }
}
