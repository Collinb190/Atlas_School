#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char *readInput(void);
char **tokeInput(char *input);
void exeCommand(char **tokens);
void freeArry(char **a);
void exePath(char **tokens);

#endif /*SHELL_H*/
