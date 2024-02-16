#include <stdio.h>
#include "shell.h"

int main (void) {
    while (1) {
        char *input;
        char **tokens;

        input = readInput();
        if (input == NULL) continue; /* resets loop if user just hits enter */
        tokens = tokeInput(input);
        exePath(tokens);
        freeArry(tokens);
        free(input);
    }
    return (0);
}