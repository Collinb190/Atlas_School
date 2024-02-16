#include <stdio.h>
#include "shell.h"

#define MAX_TOKENS 64

extern char **environ;

/**
 * readInput - Gets input
 * 
 * Description: Gets a string input by the user and terminates it with a null character.
 * Return: returns a pointer containing the null terminated string.
*/
char *readInput(void) {
    char *input = NULL;
    size_t len = 0;
    size_t i;

    if (isatty(fileno(stdin)) && isatty(fileno(stdout))) { /* checks if input from terminal */
        printf("#cisfun$ ");
        fflush(stdout);
    }
    if (getline(&input, &len, stdin) == - 1) { /* handles the EOF */
        free(input);
        exit (0); 
    }
    i = strspn(input, " \t\n");
    if (i == strlen(input)) {
        free(input);
        return (NULL);
    }
    if (input[strlen(input) - 1] == '\n') { /* null terminates the string */ 
        input[strlen(input) - 1] = '\0';
    }
    if (strcmp(input, "exit") == 0) { /* handles the exit command */
            free(input);
            exit (0);
    }
    return (input);
}
/**
 * tokeInput - Tokenize the input.
 * @input: the input to be tokenized. 
 * 
 * Description: Turns each word in the string to a token and stores them in an array.
 * Return: An array containing the tokens. 
*/
char **tokeInput(char *input) {
    char **tokenArry;
    char *token;
    int tokenCount;
    tokenArry = malloc(MAX_TOKENS * sizeof(char *));
    if (tokenArry == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    tokenCount = 0;
    token = strtok(input, " ,\t\n");
    while (token != NULL) {
        tokenArry[tokenCount] = strdup(token);
        if (tokenArry[tokenCount] == NULL) {
            perror("strdup failed");
            exit(EXIT_FAILURE);
        }
        tokenCount++;
        if (tokenCount >= MAX_TOKENS) {
            perror("To many tokens");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ,\t\n"); 
    }
    tokenArry[tokenCount] = NULL; /* null terminate array */
    return (tokenArry);
}
/**
 * exeCommand - This will execute the command
 * @tokens: tokenized commands
 * 
 * Description: This will execute the command using execve
 */
void exeCommand(char **tokens){
    pid_t pid;
    int status;
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }else if (pid == 0) { /* child */
        if (execve(tokens[0], tokens, environ) == -1 ) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }else { /* parent */
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
    }
}
/**
 * freeArry - this will free my arrays
 * @a: pointer to a an array to be freed.
 * 
 * Description: function that frees the array passed to it
*/
void freeArry(char **a) {
    int i;
    if (a == NULL) return;
    for (i = 0; a[i] != NULL; i++) free(a[i]);
    free(a);
}
/**
 * exePath - handles the path
 * @tokens: tokenized input obtained from tokeCommand()
 *
 * Description: executes command without having to have full path
*/
void exePath(char **tokens) {
    char *path = getenv("PATH");
    char *pathCopy = strdup(path);
    char *dir = strtok(pathCopy, ":");
    char *commandPath;

    if (strchr(tokens[0], '/') != NULL) {
        exeCommand(tokens);
        free(pathCopy); 
        return;
    }

    while (dir != NULL) {
        commandPath = malloc(strlen(dir) + strlen(tokens[0]) + 2);
        sprintf(commandPath, "%s/%s", dir, tokens[0]);

        if (access(commandPath, X_OK) == 0) {
            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                if (execve(commandPath, tokens, environ) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            } else {
                int status;
                if (waitpid(pid, &status, 0) == -1) {
                    perror("waitpid");
                    exit(EXIT_FAILURE);
                }
            }

            free(commandPath);
            free(pathCopy);
            return;
        }

        free(commandPath);
        dir = strtok(NULL, ":");
    }

    fprintf(stderr, "%s: 1: %s: not found\n", "./hsh", tokens[0]);
    free(pathCopy);
}
